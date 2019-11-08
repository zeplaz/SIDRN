

#include <iostream>
//forloading texturez

#include "gl_lib_z.hpp"

#define STBI_FAILURE_USERMSG
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


void gl_shader::create_shader(shader_type shad_type)
{
  if(shad_type ==shader_type::VERTEX_SHADER)
  {vertex_shader_ID = glCreateShader(GL_VERTEX_SHADER);}

  if(shad_type ==shader_type::FRAGMENT_SHADER)
  {frag_shader_ID = glCreateShader(GL_FRAGMENT_SHADER);}

}

  void  gl_shader::set_attrabutes(GLuint&gl_prgm)
   {
     shader_pos = glGetAttribLocation(gl_prgm,"positions");
     shader_colour = glGetAttribLocation(gl_prgm,"vertexColour");
   }

  void gl_shader::get_shader_code(const std::string &path,shader_type type)
  {
     std::ifstream file(path);
     std::string ret = "";
     std::string line_buff ="";
     if(file.is_open())
     {
      ret= std::string(std::istreambuf_iterator<char>(file),std::istreambuf_iterator<char>());
        /*
           while (gfile)
           { std::getline(file,line_buff);
             ret += line_buff+"\n";
           }
           */
         //  {ret+line+'\n';}
       std::cout << ret;
       file.close();
     }
     s_type =type;
     if(type ==shader_type::VERTEX_SHADER)
      shader_code_vertex = ret;

     else if(type ==shader_type::FRAGMENT_SHADER)
       shader_code_fragment = ret;
   }

   void gl_shader::load_shader_complie()
   {

     GLint vertex_compiled;
     GLint fragment_complied;
     GLchar* log_shader;
     std::cout << "loading newshader:\n";
     if(s_type ==shader_type::VERTEX_SHADER)
     {
       const GLchar*  sh_gl_vrx = shader_code_vertex.c_str();
       glShaderSource(vertex_shader_ID,1,&sh_gl_vrx,NULL);
       glCompileShader(vertex_shader_ID);
       glGetShaderiv(vertex_shader_ID, GL_COMPILE_STATUS, &vertex_compiled);

       if (vertex_compiled != GL_TRUE)
       {
        GLint logsize;
        std::cout <<"falure to vertix_complie";
        glGetShaderiv(vertex_shader_ID,GL_INFO_LOG_LENGTH,&logsize);
        log_shader = new GLchar[logsize+1];

        glGetShaderInfoLog(vertex_shader_ID, logsize, NULL, log_shader);
        // Write the error to a log
        std::cout << log_shader<< '\n';
        delete log_shader;
       }
     }
     else if(s_type ==shader_type::FRAGMENT_SHADER)
     {
       const GLchar*  sh_gl_frag = shader_code_vertex.c_str();

       glShaderSource(frag_shader_ID,1,&sh_gl_frag,NULL);
       glCompileShader(frag_shader_ID);
       glGetShaderiv(frag_shader_ID, GL_COMPILE_STATUS, &fragment_complied);

       if (fragment_complied == GL_TRUE)
       {
        GLint logsize;
        std::cout <<"falure to vertix_complie";
        glGetShaderiv(frag_shader_ID,GL_INFO_LOG_LENGTH,&logsize);
        log_shader = new GLchar[logsize+1];

        glGetShaderInfoLog(frag_shader_ID, logsize, NULL, log_shader);
        // Write the error to a log
        std::cout << log_shader<< '\n';
        delete log_shader;
       }
     }
   }



  void view_lenz::Process_keyboard(Camera_Movement direction_move, float delta_time)
      {
        float velocity = MovementSpeed*delta_time;

        switch(direction_move)
        {
          case Camera_Movement::FORWARD :
          std::cout << Position;
          Position +=Front*velocity;

          std::cout << "Velocity::" <<velocity<< "newPOs" << Position << "front"<<Front <<'\n';
          break;

          case  Camera_Movement::BACKWARD :
          Position -=Front*velocity;
          break;

          case  Camera_Movement::LEFT :
          Position -=Right*velocity;
          break;

          case  Camera_Movement::RIGHT :
          Position =Right*velocity;
          break;
        }
      }
      
  GLuint Texture_gl::load_bitmap_to_GL()
    {
      _originalWidth = (GLfloat)bitmap.width;
      _originalHeight = (GLfloat)bitmap.hight;
       glGenTextures(1, &_object);
       glBindTexture(GL_TEXTURE_2D, _object);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minMagFiler);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, minMagFiler);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
       glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);
       glTexImage2D(GL_TEXTURE_2D,
                    0,
                    TextureFormatForBitmapFormat(formate),
                    (GLsizei)bitmap.width,
                    (GLsizei)bitmap.hight,
                    0,
                    TextureFormatForBitmapFormat(formate),
                    GL_UNSIGNED_BYTE,
                    bitmap.buffer_pixelz);
      glBindTexture(GL_TEXTURE_2D, 0);
      return _object;
     }


    void Texture_gl::load_bitmap_to_texture(std::string& text_path)
    {
      int width, height, channels;
      bitmap.buffer_pixelz = stbi_load(text_path.c_str(),
                                       &width, &height, &channels, 4);
    bitmap.width = width;
    bitmap.hight = height;
    bitmap.number_bytes=sizeof(bitmap.buffer_pixelz);
    bitmap.attrabutes = ATTR_TEXTURE;
    }



GLuint load_texture_GL(const GLchar* text_path)
{
  GLuint gl_texture;
  glGenTextures(1, &gl_texture);

  int h,w;
  unsigned char* raw_image;

  //load_bitmap_to_texture()
  //glBindTexture(GL_TEXTURE_2D, gl_texture);
  raw_image = stbi_load(text_path, &w, &h, 0, 4);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGBA8, GL_UNSIGNED_BYTE, raw_image);
  stbi_image_free(raw_image);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  return gl_texture;
}

unsigned int load_skybox_GL(std::vector<std::string> face_paths)
{
  unsigned int textureID;
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);
  int w, h, nrChannels;

  for (unsigned int i =0; i<face_paths.size(); i++)
  {
     unsigned char *data = stbi_load(face_paths[i].c_str(), &w, &h, &nrChannels, 4);
       if (data)
        {
          glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,
                       0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data
          );
          stbi_image_free(data);
          std::cout <<"->##TEXTTURE FACELOADED\n";
        }
        else
        {
            std::cout << "Cubemap texture failed to load at path: " << face_paths[i] << '\n';
            stbi_image_free(data);
        }
      }

    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

    std::cout <<"->##TEXTTURE CUDE::" <<textureID << '\n';
    return textureID;
}


//sample shape
// Panel vertices


  //glm::mat4 GetViewMatrix()
//{
    //return glm::lookAt(Position, Position + Front, Up);
//}
/*
  void updateCameraVectors()
    {

    }
*/







/*
vertexLoc = glGetAttribLocation(MyShader, "InVertex");
 texCoord0Loc = glGetAttribLocation(MyShader, "InTexCoord0");
 normalLoc = glGetAttribLocation(MyShader, "InNormal");
*/
/*
//Vertices, XYZ, FLOAT. We give GL_FALSE since we don't want normalization
glVertexAttribPointer(vertexLoc, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex),
BUFFER_OFFSET(0));
//Normals, XYZ, FLOAT.
glVertexAttribPointer(normalLoc, 3, GL_FLOAT, GL_FALSE, sizeof(MyVertex),
 BUFFER_OFFSET(sizeof(float)*3));
//TexCoord0, XY (Also called ST. Also called UV), FLOAT.
glVertexAttribPointer(texCoord0Loc, 2, GL_FLOAT, GL_FALSE, sizeof(MyVertex),
 BUFFER_OFFSET(sizeof(float)*6));

void glVertexAttribPointer( 	GLuint index,
  	GLint size,
  	GLenum type,
  	GLboolean normalized,
  	GLsizei stride,
  	const void * pointer);
*/
