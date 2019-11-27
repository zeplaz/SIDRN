
#include "geometry.hpp"

#define STBI_FAILURE_USERMSG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


std::ostream& operator << (std::ostream &out, const M_Tex_Flag &f)
{
     unsigned char  flag;
    flag  =(unsigned char) f;
    out << flag <<'\n';
    return out;
}

  void mesh::pack_mesh_vertex(std::vector<glm::vec3>&in_v,std::vector< glm::vec3>&in_n,
                        std::vector< glm::vec2>&in_tc)
  {
    for(size_t i = 0; i<in_v.size(); i++ )
    {
      mesh_vertex temp_mv;
      temp_mv.v_position = in_v[i];
      temp_mv.v_normal = in_n[i];
      temp_mv.v_textcord = in_tc[i];
      m_vertices->push_back(temp_mv);
    }
  }

  void mesh::draw(gl_shader_t* shader)
  {
    shader->use_shader();
    glBindVertexArray(VAO_mesh);

    //model drawing
    if(Model_flagz==M_Model_Flag::MODEL_UNIFORM)
    {
      glUniformMatrix4fv(glGetUniformLocation(shader->program_ID,"model_matrix"),
                                  1,GL_FALSE,glm::value_ptr(base_model_matrix));
    }

    // texture drawing
    if(tex_flagz == M_Tex_Flag::TEXTYR_BASIC)
    { //std::cout <<"only basic texutre" << '\n';
      m_texture_array[0].activate();
      m_texture_array[0].set_texture_sampler_uniform(shader,m_tex_uniform_array[0]);

    }
    else if ((tex_flagz & (M_Tex_Flag::TEXTYR_BASIC|M_Tex_Flag::TEXTYR_NORMAL))
            == (M_Tex_Flag::TEXTYR_BASIC|M_Tex_Flag::TEXTYR_NORMAL))
    {
      m_texture_array[0].activate();
      m_texture_array[0].set_texture_sampler_uniform(shader,m_tex_uniform_array[0]);
      m_texture_array[1].activate();
      m_texture_array[1].set_texture_sampler_uniform(shader,m_tex_uniform_array[1]);
    }
    else if ((tex_flagz & (M_Tex_Flag::TEXTYR_BASIC|M_Tex_Flag::TEXTYR_NORMAL|M_Tex_Flag::TEXTYR_SPEKTURAL))
            == (M_Tex_Flag::TEXTYR_BASIC|M_Tex_Flag::TEXTYR_NORMAL|M_Tex_Flag::TEXTYR_SPEKTURAL))
    {
      m_texture_array[0].activate();
      m_texture_array[0].set_texture_sampler_uniform(shader,m_tex_uniform_array[0]);
      m_texture_array[1].activate();
      m_texture_array[1].set_texture_sampler_uniform(shader,m_tex_uniform_array[1]);
      m_texture_array[2].activate();
      m_texture_array[2].set_texture_sampler_uniform(shader,m_tex_uniform_array[1]);
    }

    else if ((tex_flagz & (M_Tex_Flag::TEXTYR_BASIC|M_Tex_Flag::TEXTYR_SPEKTURAL))
            == (M_Tex_Flag::TEXTYR_BASIC|M_Tex_Flag::TEXTYR_SPEKTURAL))
    {
      m_texture_array[0].activate();
      m_texture_array[0].set_texture_sampler_uniform(shader,m_tex_uniform_array[0]);
      m_texture_array[2].activate();
      m_texture_array[2].set_texture_sampler_uniform(shader,m_tex_uniform_array[1]);
    }

    glDrawArrays(GL_TRIANGLES, 0, m_vertices->size());
    //glBindVertexArray(0);
  }


void mesh::pack_mesh_vertex(parsed_paket_type* par_pak)
{
  mesh_vertex temp_mv;
  for(size_t i = 0; i<par_pak->vertices.size(); i++ )
  {
    temp_mv.v_position   =par_pak->vertices[i];
    temp_mv.v_normal     =par_pak->normals[i];
    temp_mv.v_textcord   =par_pak->uvs[i] ;
    m_vertices->push_back(temp_mv);
  }
}

  void mesh::model_init()
  {
    base_model_matrix = glm::mat4(1.0f);
    base_model_matrix = glm::translate(base_model_matrix, posz_base);
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.x),glm::vec3(1.f,0.f,0.f));
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.y),glm::vec3(0.f,1.f,0.f));
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.z),glm::vec3(1.f,0.f,1.f));
    base_model_matrix = glm::scale(base_model_matrix,scale_base);
  }

  void mesh::update_mesh_model(model_ajustment ajust_in)
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

  void mesh::set_mesh_model_origin(model_ajustment intial_model)
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


  void mesh::bindmesh_buf()
  {
    glGenVertexArrays(1, &VAO_mesh);
    glBindVertexArray(VAO_mesh);

    glGenBuffers(1,&buff_mesh);

    glBindBuffer(GL_ARRAY_BUFFER, buff_mesh);

    glBufferData(GL_ARRAY_BUFFER, sizeof(mesh_vertex)*m_vertices->size(),
                 &m_vertices->front(),GL_STATIC_DRAW);

                //std::vector<mesh_vertex> meshv = *m_vertices;
                /*
                std::cout << "size of meshvertz" << m_vertices->size() <<'\n';
                for(size_t i = 0; i<m_vertices->size(); i++)
                {
                  std::cout << "vdata::" << m_vertices->at(i) <<'\n';
                }
                std::cout << "enddata \n \n";
                std::vector<glm::vec3> pos_vec;
                std::vector<glm::vec3> vnormz;
                std::vector<glm::vec2> tex_vec;

                  for(size_t i = 0; i<m_vertices->size(); i++)
                  {   mesh_vertex* mv_ptr = & m_vertices->at(i);
                      pos_vec.push_back(mv_ptr->v_position);
                      vnormz.push_back(mv_ptr->v_normal);
                      tex_vec.push_back(mv_ptr->v_textcord);
                  }*/
/*
   glBufferSubData(GL_ARRAY_BUFFER,0,m_vertices->size() * sizeof(glm::vec3),&pos_vec.front());
   glBufferSubData(GL_ARRAY_BUFFER,m_vertices->size() * sizeof(glm::vec3)
                  ,m_vertices->size() * sizeof(glm::vec3),&vnormz.front());

   glBufferSubData(GL_ARRAY_BUFFER,m_vertices->size() * sizeof(glm::vec3)+m_vertices->size() * sizeof(glm::vec3)
                  ,m_vertices->size() * sizeof(glm::vec2),&tex_vec.front());*/

   glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,sizeof(mesh_vertex), 0);
   glEnableVertexAttribArray(0);
   glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE,sizeof(mesh_vertex),BUFFER_OFFSET(sizeof(glm::vec3)));
   glEnableVertexAttribArray(1);
   glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,sizeof(mesh_vertex),BUFFER_OFFSET(sizeof(glm::vec3)+sizeof(glm::vec3)));
   glEnableVertexAttribArray(2);

   glBindVertexArray(0);

  }

    void Texture_gl::init_texture()
    {
      glActiveTexture(GL_TEXTURE0+texture_indexUnit);
      glBindTexture(GL_TEXTURE_2D,texture_ID);
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glTexImage2D(GL_TEXTURE_2D, 0, return_TextureFormat(formate_internal), width, height, 0, return_TextureFormat(formate_external), GL_UNSIGNED_BYTE, image);
      stbi_image_free(image);
      glBindTexture(GL_TEXTURE_2D,0);
    }

    void Texture_gl::load_texture(std::string path,int force_channel,int text_unitindex)
    {
      image = stbi_load(path.c_str(),&width,&height,&n,force_channel);
      set_texture_unit_index(text_unitindex);
    }

    void Texture_gl::set_min_Mag_Filter(Filter filt,char min_mag)
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


    /*
    void mesh::init(wavefornt_parser2* wp, std::string res_path)
    {
      std::pair<std::vector<vertex_type>*,
              std::vector<unsigned int>*> pars_vertex_data;
       pars_vertex_data= wp->read_file(res_path);
       m_vertices = pars_vertex_data.first;
       m_v_indices = pars_vertex_data.second;
      std::vector< glm::vec3 > vertices;
      std::vector< glm::vec3 > normals;
      std::vector< glm::vec2 > uvs;

      //wp->return_data(vertices,uvs,normals);
      //wp->gen_parse_parket(pars_pak_ptr);
      //pack_mesh_vertex(vertices,normals,uvs);


      posz_base    =glm::vec3(0.f);
      rotation_base=glm::vec3(0.f);
      scale_base   =glm::vec3(0.2f);
      //base_model_matrix = glm::mat4(1.0f);
      model_init();
    }*/
