
#pragma once

#include <GL/glew.h>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
//#include <glm.hpp> // glm::mat4

#include <glm/glm.hpp> // glm::mat4
#include <glm/ext.hpp> // perspective, translate, rotate

#include <vector>
#include <string>
#include <fstream>

#include "colour.hpp"
//#include "mathII.hpp"
static const int MAIN_SCREEN_WIDTH = 1200;
static const int MAIN_SCREEN_HIGHT = 800;

template<typename Enum>
struct EnableBitMaskOperators
{
      static const bool enable = false;
};

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type
operator |(Enum lhs, Enum rhs)
{
    using underlying = typename std::underlying_type<Enum>::type;
    return static_cast<Enum> (
        static_cast<underlying>(lhs) |
        static_cast<underlying>(rhs)
    );
};

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type&
operator |=(Enum &org,Enum rhs)
{
    using underlying = typename std::underlying_type<Enum>::type;
    return org =static_cast<Enum> (static_cast<underlying>(org) |  static_cast<underlying>(rhs));

};

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type
operator ~(Enum rhs)
{
    using underlying = typename std::underlying_type<Enum>::type;
    return  static_cast<Enum> (~static_cast<underlying>(rhs));
};

template<typename Enum>
typename std::enable_if<EnableBitMaskOperators<Enum>::enable, Enum>::type
operator &(Enum lhs,Enum rhs)
{
    using underlying = typename std::underlying_type<Enum>::type;
    return  static_cast<Enum> (static_cast<underlying>(lhs)& static_cast<underlying>(rhs));
};

enum class shader_type : unsigned char {
     SHADER_NULL         = 0x00,
     COMPUTE_SHADER      = 0x02,
     VERTEX_SHADER       = 0x04,
     FRAGMENT_SHADER     = 0x08,
     TESS_CONTROL_SHADER = 0x10,
     TESS_EVAL_SHADER    = 0x20,
     GEOMETRY_SHADER     = 0x40

};

template<>
struct EnableBitMaskOperators<shader_type>
{
    static const bool enable = true;
};


enum class Format {
    Format_Grayscale = 1, /**< one channel: grayscale */
    Format_GrayscaleAlpha = 2, /**< two channels: grayscale and alpha */
    Format_RGB = 3, /**< three channels: red, green, blue */
    Format_RGBA = 4, /**< four channels: red, green, blue, alpha */
    Format_RGBA8 = 5
};

enum class Camera_Movement {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

enum class render_mode{
      WIREFRAME,
      FILL
};

const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;
const float MAX_V_ANGLE = 88.0f;

//typedefzforeasz

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

const uint32_t positionAttributeIndex = 0, colorAttributeIndex = 1;

// Create variables for storing the ID of our VAO and VBO
//const int ATTRBUT_DYNAMIC_DRAW 0x0010;
//const int ATTRBUT_STATIC 0x0020;
constexpr unsigned char ATTRBUT_DYNAMIC_DRAW{0b0000'0010};
constexpr unsigned char ATTRBUT_STATIC      {0b0000'0100};
constexpr unsigned char ATTRBUT_STREAM      {0b0000'1000};

  GLuint load_texture_GL(const GLchar* text_path);
  unsigned int load_skybox_GL(std::vector<std::string> face_paths);

/*
static char* read_shader_file(const char* file_name)
{
  FILE* fp = fopen(file_name,"r");
  fseek(fp,0,SEEK_END);
  long file_len =ftell(fp);
  fseek(fp,0,SEEK_SET);
  char* contents = new char[file_len+1];
  fread(contents,1,file_len,fp);
  contents[file_len] = '\0';
  fclose(fp);
}*/

class view_lenz
{
  private :
  mathz::vector3_vala<float> Position;
  mathz::vector3_vala<float> Front;
  mathz::vector3_vala<float> Up;
  mathz::vector3_vala<float> Right;
  mathz::vector3_vala<float> WorldUp;

  glm::vec3 lenz_pos = glm::vec3(0.0f,0.0f,3.0f);
  glm::vec3 lenz_target =  glm::vec3(0.0f,0.0f,0.0f);
  glm::vec3 lenz_up = glm::vec3(0.0f,1.0f,0.0f);
  glm::vec3 lenz_front = glm::vec3(0.0f,0.0f,-1.0f);
  glm::mat4 view = glm::mat4(1.0f);

  float MovementSpeed;
  float Yaw;
  float Pitch;
  float Zoom;

  float feild_of_view;
  float near_plane;
  float far_plane;
  float view_aspec_ratio;

  glm::vec3 get_lenz_reverse_drection()
  {
    return glm::normalize(lenz_pos-lenz_target);
  }

  glm::vec3 lenz_right()
  {
    return glm::normalize(glm::cross(lenz_up,get_lenz_reverse_drection()));
  }

  glm::vec3 get_lenz_up()
  {
    return glm::cross(get_lenz_reverse_drection(),lenz_right());
  }

  void set_view_basic()
  {
    view = glm::lookAt(lenz_right(),get_lenz_up(),get_lenz_reverse_drection());
  }

  void set_view_movement()
  {
    view = glm::lookAt(lenz_pos,lenz_pos+lenz_front,lenz_up);
  }

  void normalize_anglez()
  {
    Pitch = fmodf(Pitch,360.0f);
    if(Pitch<0.0f)
    {
      Pitch+360.0f;
    }
    if(Yaw>MAX_V_ANGLE)
    {
      Yaw = MAX_V_ANGLE;
    }
      else if (Yaw<-MAX_V_ANGLE)
      {
        Yaw =-MAX_V_ANGLE;
      }
    }

  public :
  void set_lenz();
  void Process_keyboard(Camera_Movement direction_move, float delta_time);

  view_lenz(mathz::vector3_vala<float> position = mathz::vector3_vala<float>(0.0f, 0.0f, 0.0f),
            mathz::vector3_vala<float> up = mathz::vector3_vala<float>(0.0f, 1.0f, 0.0f),
            float yaw = YAW,float pitch = PITCH)
            : Front(mathz::vector3_vala<float>(0.0f, 0.0f, -1.0f)),
              MovementSpeed(SPEED), Zoom(ZOOM)
      {
          Position = position;
          WorldUp = up;
          Yaw = yaw;
          Pitch = pitch;
        //  updateCameraVectors();
         feild_of_view=50.0f;
         near_plane=0.01f;
         far_plane = 100.0f;
         view_aspec_ratio=(float)MAIN_SCREEN_WIDTH/(float)MAIN_SCREEN_HIGHT;
       }

    void camera_transform(const mathz::vector3_vala<float>& Target,const mathz::vector3_vala<float>& Up)
    {
      mathz::vector3_vala<float> targ_n = Target;
      targ_n.normalize();
      mathz::vector3_vala<float> up = Up;
      up.normalize();
      mathz::vector3_vala<float> vec = targ_n.cross(up);
      glm::mat4 lenz_mat;
      lenz_mat[0][0] = up[0];     lenz_mat[0][1]=up[1];       lenz_mat[0][2] = up[2];     lenz_mat[0][3] = 0.0f;
      lenz_mat[1][0] = vec[0];    lenz_mat[1][1] = vec[1];    lenz_mat[1][2] = vec[2];    lenz_mat[1][3] = 0.0f;
      lenz_mat[2][0] = targ_n[0]; lenz_mat[2][1] = targ_n[1]; lenz_mat[2][2] = targ_n[2]; lenz_mat[2][3] = 0.0f;
      lenz_mat[3][0] = 0.0f;      lenz_mat[3][1] = 0.0f;      lenz_mat[3][2] = 0.0f;      lenz_mat[3][3] = 1.0f;
    }

  glm::mat4 Get_view_eulrz()
    {
        return glm::lookAt(get_position_glm(), get_position_glm() +
                           get_front_glm(), get_up_glm());
    }
  void faceing_position(glm::vec3 posz)
  {
    glm::vec3 direction = glm::normalize(posz-get_position_glm());
    Pitch = glm::radians(asinf(-direction.y));
    Yaw   = glm::radians(atan2f(-direction.x,-direction.z));
    normalize_anglez();
  }

  void set_postion();

  glm::vec3 get_position_glm()
  {
    glm::vec3 temp_pos(Position[0],Position[1],Position[2]);
    return temp_pos;
  }
  glm::vec3 get_up_glm()
  {
    glm::vec3 temp_pos(Up[0],Up[1],Up[2]);
    return temp_pos;
  }
  glm::vec3 get_front_glm()
  {
    glm::vec3 temp_pos(Front[0],Front[1],Front[2]);
    return temp_pos;
  }
  void set_feild_of_view(float fov)
  {
    feild_of_view=fov;
  }
  float aspect_ratio_cal();

  glm::mat4 return_orientation() const
  {
      glm::mat4 orientation;
      orientation = glm::rotate(orientation, glm::radians(Pitch), glm::vec3(1,0,0));
      orientation = glm::rotate(orientation, glm::radians(Yaw), glm::vec3(0,1,0));
    return orientation;
  }

  glm::mat4  translation_rotation()
  {
    return return_orientation()*glm::translate(glm::mat4(),-get_position_glm());
  }

  void update_cam_front()
  {
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw))*cos(glm::radians(Pitch));
  }

  glm::mat4 vertex_matrix_final()
  {
    return lenz_projection()*translation_rotation();
  }

  void move_lenz(const glm::vec3& changevec)
  {
     Position[0] += changevec.x;
     Position[1] += changevec.y;
     Position[2] += changevec.z;
  }

  glm::mat4 lenz_projection()
  {
    glm::mat4 projection = glm::perspective(glm::radians(Zoom),
                                            view_aspec_ratio, near_plane, far_plane);
   return projection;
  }
};

typedef struct Texture_gl
    {
        BitMap bitmap;
        GLint minMagFiler = GL_LINEAR;
        GLint wrapMode = GL_CLAMP_TO_EDGE;
        Format formate;

        GLuint _object;
        GLfloat _originalWidth;
        GLfloat _originalHeight;

        static GLenum TextureFormatForBitmapFormat(Format formate)
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
          formate =  Format::Format_RGBA8;
        }

        void load_bitmap_to_texture(std::string& text_path);
        GLuint load_bitmap_to_GL();
};
