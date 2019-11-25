#pragma once

#include "gl_lib_z.hpp"
#include "shader_parser.hpp"
#include "geometry_parser.hpp"

class wavefornt_parser2;

typedef struct vertex_type
{
  glm::vec3 v_position;
  glm::vec3 v_normal;
  glm::vec2 v_textcord;

  bool operator<(const vertex_type that) const{
		return memcmp((void*)this, (void*)&that, sizeof(vertex_type))>0;}
} mesh_vertex;

typedef struct model_ajustment_type
{
  glm::vec3 posz_ajust;
  glm::vec3 rotation_ajust;
  glm::vec3 scale_ajust;
}model_ajustment;

typedef struct Texture_gl
    {
        BitMap bitmap;
        GLuint texture_ID;
        int texture_indexUnit = 0;
        unsigned char* image;

        int width, height,n;

        GLint minFiler = GL_LINEAR;
        GLint magFiler = GL_LINEAR;
        GLint wrapMode_S = GL_CLAMP_TO_EDGE;
        GLint wrapMode_T = GL_CLAMP_TO_EDGE;

        Format formate;

        GLuint _object;
        GLfloat _originalWidth;
        GLfloat _originalHeight;

        GLenum return_TextureFormat()
        {
          switch (formate)
           {
              case Format::Format_Grayscale: return GL_LUMINANCE;
              case Format::Format_GrayscaleAlpha: return GL_LUMINANCE_ALPHA;
              case Format::Format_RGB: return GL_RGB;
              case Format::Format_RGBA: return GL_RGBA;
              case Format::Format_RGBA8: return GL_RGBA8;
              default: throw std::runtime_error("Unrecognised Bitmap::Format");
          }
        }

        Texture_gl()
        {
          formate =  Format::Format_RGB;
          glGenTextures(1,&texture_ID);
        }
        void set_texture_sampler_uniform(gl_shader_t* s_in)
        {
          glBindTexture(GL_TEXTURE_2D,texture_ID);
          glUniform1i(glGetUniformLocation(s_in->program_ID, "active_texture_sampler"), 0);
        }

        void set_Tex_paramz()
        {
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFiler);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFiler);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode_S); //GL_REPEAT//GL_CLAMP_TO_EDGE//GL_CLAMP_TO_BORDER//GL_MIRRORED_REPEAT
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode_T);
        }
        void init_texture();

        void  set_texture_unit_index(int index)
        {
          texture_indexUnit +=index;
        }

        void load_texture(std::string path,int force_channel);

        void set_texture_ST(WarpMode mode, char st)
        {
          if(st =='t')
          {
            wrapMode_T =mode;
          }
          else{
            wrapMode_S =mode;
          }
        }
        void set_min_Mag_Filter(Filter filt,char min_mag);

};

class mesh
{

  private :
  glm::vec3 posz_base;
  glm::vec3 rotation_base;
  glm::vec3 scale_base;
  glm::mat4 base_model_matrix;

  unsigned int VAO_mesh, buff_mesh, EBO;
  unsigned int vertex_buf, uv_buf, normal_buf,element_buf;
  std::string res_path;

  public :
  std::vector<mesh_vertex> m_vertices;
  std::vector<unsigned int> m_indices;
  std::vector<Texture_gl> m_textures;

  void init(wavefornt_parser2* wp, std::string res_path);

  void model_init();

  void pack_mesh_vertex(std::vector<glm::vec3>&in_v,std::vector< glm::vec3>&in_n,
                        std::vector< glm::vec2>&in_tc)
  {
    for(size_t i = 0; i<in_v.size(); i++ )
    {
      mesh_vertex temp_mv;
      temp_mv.v_position = in_v[i];
      temp_mv.v_normal = in_n[i];
      temp_mv.v_textcord = in_tc[i];
      m_vertices.push_back(temp_mv);
    }
  }

  void bindmesh_buf()
  {
    glGenVertexArrays(1, &VAO_mesh);
    glGenBuffers(1,&buff_mesh);
    glBindVertexArray(VAO_mesh);
    glBindBuffer(GL_ARRAY_BUFFER, buff_mesh);

    glBufferData(GL_ARRAY_BUFFER, sizeof(mesh_vertex)*m_vertices.size(),
                 0,GL_STATIC_DRAW);

   glBufferSubData(GL_ARRAY_BUFFER,0,m_vertices.size() * sizeof(mesh_vertex),&m_vertices[0]);
   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,sizeof(mesh_vertex), 0);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,sizeof(mesh_vertex),BUFFER_OFFSET(sizeof(glm::vec3)+sizeof(glm::vec3)));
   glEnableVertexAttribArray(2);
   //glBufferSubData(GL_ARRAY_BUFFER,vertices.size() * sizeof(glm::vec3),uvs.size() *sizeof(glm::vec2),&uvs[0]);
  }

  void draw(gl_shader_t* shader)
  {
    shader->use_shader();

    glUniformMatrix4fv(glGetUniformLocation(shader->program_ID,"model_matrix"),
                                  1,GL_FALSE,glm::value_ptr(base_model_matrix));
    glBindVertexArray(VAO_mesh);
    glDrawArrays(GL_TRIANGLES, 0, m_vertices.size());
  }

  unsigned int return_elment_buf()
  {
    return element_buf;
  }

  size_t return_num_indices()
  {
    return m_indices.size();
  }

  void set_render_mode(render_mode new_mode, Poly_face face)
  {

       if(new_mode==render_mode::WIREFRAME)
         glPolygonMode(face,GL_LINE);

       if(new_mode==render_mode::FILL)
         glPolygonMode(face,GL_FILL);

       if(new_mode==render_mode::POINT)
        glPolygonMode(face,GL_POINT);
  }

  void update_mesh_model(model_ajustment ajust_in)
  {
    rotation_base.x +=ajust_in.rotation_ajust.x;
    rotation_base.y +=ajust_in.rotation_ajust.y;
    rotation_base.z +=ajust_in.rotation_ajust.z;
    posz_base.x     +=ajust_in.posz_ajust.x;
    posz_base.y     +=ajust_in.posz_ajust.y;
    posz_base.z     +=ajust_in.posz_ajust.z;
    scale_base.x    +=ajust_in.scale_ajust.x;
    scale_base.y    +=ajust_in.scale_ajust.y;
    scale_base.z    +=ajust_in.scale_ajust.z;

    base_model_matrix = glm::mat4(1.f);
    base_model_matrix = glm::translate(base_model_matrix, posz_base);
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.x),glm::vec3(1.f,0.f,0.f));
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.y),glm::vec3(0.f,1.f,0.f));
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.z),glm::vec3(1.f,0.f,1.f));
    base_model_matrix = glm::scale(base_model_matrix,scale_base);

  }

  void set_mesh_model_origin(model_ajustment intial_model)
  {
    rotation_base.x =intial_model.rotation_ajust.x;
    rotation_base.y =intial_model.rotation_ajust.y;
    rotation_base.z =intial_model.rotation_ajust.z;
    posz_base.x     =intial_model.posz_ajust.x;
    posz_base.y     =intial_model.posz_ajust.y;
    posz_base.z     =intial_model.posz_ajust.z;
    scale_base.x    =intial_model.scale_ajust.x;
    scale_base.y    =intial_model.scale_ajust.y;
    scale_base.z    =intial_model.scale_ajust.z;

    base_model_matrix =glm::mat4(1.f);
    base_model_matrix = glm::translate(base_model_matrix, posz_base);
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.x),glm::vec3(1.f,0.f,0.f));
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.y),glm::vec3(0.f,1.f,0.f));
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.z),glm::vec3(1.f,0.f,1.f));
    base_model_matrix = glm::scale(base_model_matrix,scale_base);
  }

};



class gl_lightz
{
  public :
  glm::vec3 light_pos;
  glm::vec3 light_colour;

  void set_light(glm::vec3 lp, glm::vec3 lc)
  {
    this->light_pos    =lp;
    this->light_colour =lc;
  }
};
