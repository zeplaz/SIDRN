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
        void set_min_Mag_Filter(Filter filt,char min_mag)
        {
          switch (filt)
          {
            case Filter::LINEAR :
            {
             if(min_mag == 'i')
             minFiler = GL_LINEAR;
             if(min_mag == 'a')
             magFiler = GL_LINEAR;
             break;
            }
            case Filter::NEAREST :
            {
              if(min_mag == 'i')
              minFiler = GL_NEAREST;
              if(min_mag == 'a')
              magFiler = GL_NEAREST;
              break;
            }
            case Filter::MIPMAP :
            {
              if(min_mag == 'i')
              minFiler = GL_MIPMAP;
              if(min_mag == 'a')
              magFiler = GL_MIPMAP;
              break;
            }

            default : throw std::runtime_error("Unrecognised Bitmap::Filter");
          }
        }
};

class mesh
{
  public :
  std::vector<mesh_vertex> m_vertices;

  std::vector<unsigned int> m_indices;
  std::vector<Texture_gl> m_textures;

  std::vector<glm::vec3> indexed_vertices;
	std::vector<glm::vec2> indexed_uvs;
	std::vector<glm::vec3> indexed_normals;



  void init(wavefornt_parser2* wp, std::string res_path);


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

  private :
  unsigned int VAO_mesh, buff_mesh, EBO;
  unsigned int vertex_buf, uv_buf, normal_buf,element_buf;
  std::string res_path;
  void setup_mesh_4buf();
  void setup_mesh_packed();
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

bool get_sim_vertex_index(mesh_vertex& mv_pack, std::map<mesh_vertex,unsigned int>& vertex_outindex,
                          unsigned int &result);

void index_VBO_packed (std::vector<mesh_vertex> in_vec_vertex,
                std::vector<unsigned int> & out_indices,
                std::vector<glm::vec3> & out_vertices,
                std::vector<glm::vec2> & out_uvs,
                std::vector<glm::vec3> & out_normals);


void index_VBO(std::vector<glm::vec3> & in_vertices,
               std::vector<glm::vec2> & in_uvs,
               std::vector<glm::vec3> & in_normals,
               std::vector<unsigned int> & out_indices,
               std::vector<glm::vec3> & out_vertices,
               std::vector<glm::vec2> & out_uvs,
               std::vector<glm::vec3> & out_normals
);
