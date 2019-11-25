
#include "geometry.hpp"

#define STBI_FAILURE_USERMSG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void mesh::init(wavefornt_parser2* wp, std::string res_path)
{
  wp->read_file(res_path);
  std::vector< glm::vec3 > vertices;
  std::vector< glm::vec3 > normals;
  std::vector< glm::vec2 > uvs;

  wp->return_data(vertices,uvs,normals);
  pack_mesh_vertex(vertices,normals,uvs);

  posz_base    =glm::vec3(0.f);
  rotation_base=glm::vec3(0.f);
  scale_base   =glm::vec3(0.2f);
  //base_model_matrix = glm::mat4(1.0f);
  model_init();
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

    void Texture_gl::init_texture()
    {
      glActiveTexture(GL_TEXTURE0+texture_indexUnit);
      glBindTexture(GL_TEXTURE_2D,texture_ID);
      glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
      glTexImage2D(GL_TEXTURE_2D, 0, return_TextureFormat(), width, height, 0, return_TextureFormat(), GL_UNSIGNED_BYTE, image);
      stbi_image_free(image);
      glBindTexture(GL_TEXTURE_2D,0);
    }

    void Texture_gl::load_texture(std::string path,int force_channel)
    {
      image = stbi_load(path.c_str(),&width,&height,&n,force_channel);
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
