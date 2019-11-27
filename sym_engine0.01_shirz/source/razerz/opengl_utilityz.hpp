

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
