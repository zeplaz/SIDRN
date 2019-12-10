

#pragma once

#include "gl_lib_z.hpp"
static bool screen_beenresized = false;
void APIENTRY GLAPIENTRY glDebugOutput(GLenum source,
                         GLenum type,
                         GLuint id,
                         GLenum severity,
                         GLsizei length,
                         const GLchar *message,
                         const void *userParam);


void process_input_glfw(GLFWwindow* window);

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int opengl_context_settup();

int run_opengl_setup(GLFWwindow* out_window);



struct offset_table
{
  static const size_t bool_offset = sizeof(GLboolean);
  static const size_t float_offset = sizeof(GLfloat);
  static const size_t int_offset = sizeof(GLint);
  static const size_t vec3_offset = 3*4;

  struct light_offsetz
  {
    size_t enbl= 0;
    size_t l_pos     = bool_offset;
    size_t l_intz    = l_pos+vec3_offset;
    size_t l_amb     = l_intz+vec3_offset;
    size_t l_spotcon = l_amb+vec3_offset;

    size_t dr_srengh=l_spotcon+vec3_offset;
    size_t con_atten=dr_srengh+float_offset;
    size_t qadr_atten=con_atten+float_offset;
    size_t lin_atten=qadr_atten+float_offset;
    size_t spot_cut=lin_atten+float_offset;
    size_t spot_exp =spot_cut+float_offset;
    size_t gamma_c =spot_exp+float_offset;
    size_t l_type = gamma_c+float_offset;
  }l_offset;
};
