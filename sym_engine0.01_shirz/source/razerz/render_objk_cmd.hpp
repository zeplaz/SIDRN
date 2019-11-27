
#pragma once

#include "geometry.hpp"
#include "pre_comb_objz.hpp"

void gl_run_render(GLFWwindow* glfwwindow, std::vector<gl_shader_t*>& in_shaderz,
                   std::vector<std::vector<GLuint>>& vetex_array_objkz)
{
  //std::cout <<"\n ###nummof shaders to process" << in_shaderz.size() << "  num of objket packagez::" << vetex_array_objkz.size() << '\n' << '\n';
float timeValue = glfwGetTime();
float sin_green = sin(timeValue);
float colour_angluretime = pow((sin(timeValue)*sin(timeValue)/tan(timeValue)*tan(timeValue)),2);
float sin_tsnz = sin(timeValue)*sin(timeValue)/tan(timeValue)*tan(timeValue);

for (size_t i =0; i<in_shaderz.size();i++)
{
  in_shaderz.at(i)->use_shader();
  int vertexColorLocation = glGetUniformLocation(in_shaderz.at(i)->program_ID, "ourColor");
  //std::cout << "vertex_colour_unform at::" << vertexColorLocation << "  Progamid::"
        //    << in_shaderz.at(i)->program_ID << "ourColor" << '\n';
  std::vector<GLuint> vao_vec  =  vetex_array_objkz.at(i);
  glUniform4f(vertexColorLocation, sin_tsnz, sin_green, colour_angluretime, 1.f);

  for(size_t k=0; k<vao_vec.size();k++)
  {
   //std::cout << "binding:voa:" << vao_vec.at(k) << '\n';
   if(k==1)
   {
     glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
   }
   else {
      glPolygonMode( GL_FRONT_AND_BACK, GL_FILL);
   }
   glBindVertexArray(vao_vec.at(k));
  // glDrawArrays(GL_TRIANGLES, 0, 12*3);
  }
  }
  }
