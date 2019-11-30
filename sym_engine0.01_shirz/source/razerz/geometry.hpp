#pragma once

#include "gl_lib_z.hpp"
#include "shader_parser.hpp"
#include "geometry_parser.hpp"
#include "lenz.hpp"

class wavefornt_parser2;



typedef struct model_ajustment_type
{
  glm::vec3 posz_ajust;
  glm::vec3 rotation_ajust;
  glm::vec3 scale_ajust;
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

 struct Texture_gl
    {
        GLuint texture_ID;
        int texture_indexUnit = 0;
        unsigned char* image;

        int width, height,n;

        GLint minFiler = GL_LINEAR;
        GLint magFiler = GL_LINEAR;
        GLint wrapMode_S = GL_CLAMP_TO_EDGE;
        GLint wrapMode_T = GL_CLAMP_TO_EDGE;

        Format formate_internal;
        Format formate_external;
        bool used_vglLoader = false;


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

        inline void set_texture_sampler_uniform(gl_shader_t* s_in,std::string uniform_name)
        {
          glBindTexture(GL_TEXTURE_2D,texture_ID);
          glUniform1i(glGetUniformLocation(s_in->program_ID, uniform_name.c_str()), 0);
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

class mesh
{
  private :
  glm::vec3 posz_base;
  glm::vec3 rotation_base;
  glm::vec3 scale_base;
  glm::mat4 base_model_matrix;
  glm::mat4 m_v_p;

  unsigned int VAO_mesh, buff_mesh, EBO;
  unsigned int vertex_buf, uv_buf, normal_buf,element_buf;
  std::string res_path;

  M_Tex_Flag tex_flagz     = M_Tex_Flag::TEXTYR_NULL;
  M_Model_Flag Model_flagz = M_Model_Flag::MODEL_NULL;

  bool cal_lightz= false;

  public :

  std::shared_ptr<std::vector<mesh_vertex>> m_vertices;
  std::shared_ptr<std::vector<unsigned int>> m_v_indices;
  std::array<Texture_gl,3> m_texture_array;
  std::array<std::string,3> m_tex_uniform_array;

  void bindmesh_buf();

  void draw(gl_shader_t* shader,view_lenz* active_lenz);

  void model_init();

  void update_mesh_model(model_ajustment ajust_in);

  void set_mesh_model_origin(model_ajustment intial_model);

  inline void set_tex_flags(M_Tex_Flag t_flag)
  {
    std::cout <<"flagsetter texture set::" << (int)t_flag <<'\n';
    tex_flagz  |=t_flag;
    std::cout << "current texture flagz::" << (int)tex_flagz <<'\n';
  }

  void init(wavefornt_parser2* wp, std::string res_path);
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

    /*
      template<typename... Args>
       void flag_ORer(Args &&... flag_pack)//static
      {
           //unsigned char arg_array[]=  {((void) flag_ORer(std::forward<Args>(flag_pack)), ...)};
          int dummyflag_array[] = { ( (void) set_tex_flags(std::forward<Args>(flag_pack)),0) ... };
           std::cout <<  "size of dummy araybytz" << sizeof(dummyflag_array) <<'\n';
           std::cout <<  "data of dummy araybytz" << dummyflag_array[0] <<'\n';
      }*/
  /*  void init(std::pair<std::vector<mesh_vertex>*,std::vector<unsigned int>*> in_vertx_data,M_Model_Flag mm_flag)
    {
      //m_vertices =in_vertx_data.first;
    //  m_v_indices = in_vertx_data.second;
      Model_flagz |=mm_flag;
      posz_base    =glm::vec3(0.f);
      rotation_base=glm::vec3(0.f);
      scale_base   =glm::vec3(0.2f);

      model_init();
    }*/
};
