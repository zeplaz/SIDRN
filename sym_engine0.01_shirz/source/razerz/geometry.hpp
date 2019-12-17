#pragma once

#include "shader_parser.hpp"
#include "geometry_parser.hpp"
#include "lenz.hpp"

class wavefornt_parser2;

typedef struct model_ajustment_type
{
  glm::vec3 posz_ajust;
  glm::vec3 rotation_ajust;
  glm::vec3 scale_ajust;

  model_ajustment_type& operator +=(const model_ajustment_type& inmodel)
  {

    posz_ajust     += inmodel.posz_ajust;
    rotation_ajust += inmodel.rotation_ajust;
    scale_ajust    += inmodel.scale_ajust;
    return *this;
  }
}model_ajustment;

struct texture_paramz_pak
{
  WarpMode wm_s;
  WarpMode wm_t;
  Filter mag;
  Filter min;
  std::string path;
  int channels;
  std::string unform_name;
  M_Tex_Flag text_type_flag;
  int tex_unit_index;
};


 struct Texture_gl
    {
        GLuint texture_ID;
        int texture_indexUnit = 0;
        unsigned char* image;

        unsigned int internal_ID;
        std::string type;
        std::string path;

        int width, height,n;

        GLint minFiler = GL_LINEAR;
        GLint magFiler = GL_LINEAR;
        GLint wrapMode_S = GL_CLAMP_TO_EDGE;
        GLint wrapMode_T = GL_CLAMP_TO_EDGE;

        Format formate_internal;
        Format formate_external;
        bool used_vglLoader = false;

        GLuint  TBO_Buffer_Handle;
        void init_texture();

        GLenum return_TextureFormat(Format formate);

        Texture_gl()
        {
          formate_external =  Format::Format_RGB;
          formate_internal =  Format::Format_RGB8;
          glGenTextures(1,&texture_ID);
        }

        inline void activate()
        {
          glActiveTexture(GL_TEXTURE0+texture_indexUnit);
        }

        inline void set_texture_sampler_uniform(gl_shader_t* s_in,std::string uniform_name,int unit)
        {
          glBindTexture(GL_TEXTURE_2D,texture_ID);
          glUniform1i(glGetUniformLocation(s_in->program_ID, uniform_name.c_str()), unit);
        }

        void set_Tex_paramz()
        {
          activate();
          glBindTexture(GL_TEXTURE_2D,texture_ID);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFiler);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFiler);
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode_S); //GL_REPEAT//GL_CLAMP_TO_EDGE//GL_CLAMP_TO_BORDER//GL_MIRRORED_REPEAT
          glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode_T);
        }

        inline void  set_texture_unit_index(int index)
        {
          texture_indexUnit +=index;
        }

        void load_texture(std::string path,int force_channel,int text_unitindex);

        void set_min_Mag_Filter(Filter filt,char min_mag);

        void load_texture(std::string path)
        {
          //vglLoadTexture(path.c_str(),texture_ID,&vglimage);
          used_vglLoader = true;
        }

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
};

struct Meterialz
{
    glm::vec3 emission;
    glm::vec3 ambient_reflect;
    glm::vec3 diffuse_reflect;
    glm::vec3 specular_reflect;
    float shininess;
    bool is_normalmap=false;
    float alpha;
    //GLint diffuse_texture;
    //GLint spekular_texture;

  };

class mesh
{
  private :
  glm::vec3 posz_base;
  glm::vec3 rotation_base;
  glm::vec3 scale_base;
  model_ajustment current_ajustmentz;

  glm::mat4 base_model_matrix;
  glm::mat4 m_v_p;

  Meterialz meterial;

  unsigned int VAO_mesh, buff_mesh, EBO;
  unsigned int vertex_buf, uv_buf, normal_buf,element_buf;
  std::string res_path;

  M_Tex_Flag tex_flagz     = M_Tex_Flag::TEXTYR_NULL;
  M_Model_Flag Model_flagz = M_Model_Flag::MODEL_NULL;

  bool cal_lightz= false;

  public :

  std::shared_ptr<std::vector<mesh_vertex>> m_vertices;
  std::shared_ptr<std::vector<unsigned int>> m_v_indices;
  //std::pair<std::array<Texture_gl,3>,std::array<std::string,3>> textture_pair;
  std::array<Texture_gl,3> m_texture_array;
  std::array<std::string,3> m_tex_uniform_array;

  void bindmesh_buf();

  constexpr static const GLchar * material_namez[7] =
  {
    "Meterialz.emission",
    "Meterialz.ambient_reflect"
    "Meterialz.diffuse_reflect"
    "Meterialz.specular_reflect"
    "Meterialz.shininess"
    "Meterialz.is_normalmap"
    "Meterialz.alpha"
  };
  GLuint uniformMeterial_indicatz[7];
  GLuint meterial_index;
  void set_meterial_indicates(gl_shader_t* shader)
  {
    glGetUniformIndices(shader->program_ID,7,material_namez,uniformMeterial_indicatz);
    meterial_index= glGetUniformBlockIndex(shader->program_ID,"Meterialz");

  //  glBindBufferBase(GL_UNIFORM_BUFFER,meterial_index)
  }
/*  void write_mesh()
  {
    ofstream outmesh;

    outmesh.open("scene01.bin");

    if(std::FILE* outfile = std::fopen("scene01.bin","wb"))
    {
      std::fwrite(m_texture_array.data(),sizeof m_texture_array[0],m_texture_array.size(), outfile );
      std::fwrite(m_tex_uniform_array.data(),sizeof m_tex_uniform_array[0],m_tex_uniform_array.size(), outfile );
    }
  }*/

  void draw(gl_shader_t* shader,glm::mat4& view,glm::mat4& proj);
  void draw_element(gl_shader_t* shader,glm::mat4& view,glm::mat4& proj);

  void model_init();

  void update_mesh_model(model_ajustment ajust_in);
  void set_mesh_model_origin(model_ajustment intial_model);

  void buff_setup_viaAssimp();

  inline void set_tex_flags(M_Tex_Flag t_flag)
  {
    std::cout <<"flagsetter texture set::" << (int)t_flag <<'\n';
    tex_flagz  |=t_flag;
    std::cout << "current texture flagz::" << (int)tex_flagz <<'\n';
  }

  void init(wavefornt_parser2* wp, std::string res_path);

  void set_light_bool(bool is_light)
  {
    cal_lightz=is_light;
  }
  void set_model_flag(M_Model_Flag mm_flag)
  {
    Model_flagz |=mm_flag;
  }

  void compute_tangetspace();

  void create_mesh_via_assimp(std::vector<mesh_vertex> in_mesh_vertex, std::vector<unsigned int> in_indz)
  {
    std::shared_ptr<std::vector<mesh_vertex>> mesh_ptr = std::make_shared<std::vector<mesh_vertex>>(in_mesh_vertex);
    std::shared_ptr<std::vector<unsigned int>> mesh_indz =  std::make_shared<std::vector<unsigned int>>(in_indz);
    m_vertices = mesh_ptr;
    m_v_indices=mesh_indz;
    posz_base    =glm::vec3(1.5f,1.5,0.2);
    rotation_base=glm::vec3(-90.0,10.5,0.5);
    scale_base   =glm::vec3(0.8f);
    model_init();
    buff_setup_viaAssimp();
  }

  void init(std::pair<std::shared_ptr<std::vector<mesh_vertex>>,
            std::shared_ptr<std::vector<unsigned int>>> in_vertx_data,
            M_Model_Flag mm_flag,bool is_avec_lightz)
  {
    m_vertices =in_vertx_data.first;
    m_v_indices = in_vertx_data.second;
    Model_flagz |=mm_flag;
    posz_base    =glm::vec3(0.f);
    rotation_base=glm::vec3(0.f);
    scale_base   =glm::vec3(0.2f);
    cal_lightz = is_avec_lightz;
    model_init();
  }

  void texture_setup(texture_paramz_pak in_text_pak);

  void pack_mesh_vertex(parsed_paket_type* par_pak);

  void pack_mesh_vertex(std::vector<glm::vec3>&in_v,std::vector< glm::vec3>&in_n,
                        std::vector< glm::vec2>&in_tc);

  void pass_meterial_data(gl_shader_t* shader);
  void set_meterial(glm::vec3 emis, glm::vec3 amb_ref, glm::vec3 diff_ref,
                    glm::vec3 spektral_reflect, float shinyz,float alpha)
  {
    meterial.emission=emis;
    meterial.ambient_reflect=amb_ref;
    meterial.diffuse_reflect=diff_ref;
    meterial.specular_reflect=spektral_reflect;
    meterial.shininess=shinyz;
    meterial.alpha = alpha;
  //  GLint diffuse_texture;
  //  GLint spekular_texture;

  }

  inline unsigned int return_elment_buf()
  {
    return element_buf;
  }

  inline size_t return_num_indices()
  {
    return m_v_indices->size();
  }

  inline void set_render_mode(P_Render_STYZ new_mode, Poly_face face)
  {

       if(new_mode==P_Render_STYZ::WIREFRAME)
         glPolygonMode(face,GL_LINE);

       if(new_mode==P_Render_STYZ::FILL)
         glPolygonMode(face,GL_FILL);

       if(new_mode==P_Render_STYZ::POINT)
        glPolygonMode(face,GL_POINT);
  }

};
