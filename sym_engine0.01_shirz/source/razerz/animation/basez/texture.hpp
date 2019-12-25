#pragma once

#include "shader_parser.hpp"


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
