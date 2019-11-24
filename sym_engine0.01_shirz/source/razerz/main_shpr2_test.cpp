#include "geometry.hpp"
#include "pre_comb_objz.hpp"
#include "render_objk_cmd.hpp"

void process_input_glfw(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);

}

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
/*
* MAIN!
*/
  int main(int argc, char* argv[])
  {
  /*
  GLM AND OPENGL AND GLFW inailzaiton
  */

    GLFWwindow * glfw_window;
    glewExperimental = GL_TRUE;
    //launch gluitInit
    if (!glfwInit())
  {
    std::cout << "flfwinit faild :()\n";
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
  std::cout << "launching Main Window\n";

  glfw_window = glfwCreateWindow(MAIN_SCREEN_WIDTH,MAIN_SCREEN_HIGHT,"cmdz_toolGlfz",NULL,NULL);
  if(!glfw_window)
  {
    glfwTerminate();
    std::cout <<"windowfailureload\n";
    return -3;
  }

  glfwMakeContextCurrent(glfw_window);
  glfwSetFramebufferSizeCallback(glfw_window, framebuffer_size_callback);

  GLenum glewErr = glewInit();
  std::cout << "glew_code::" << glewErr <<'\n' <<'\n';
  glViewport( 0, 0, MAIN_SCREEN_WIDTH, MAIN_SCREEN_HIGHT );

  /*
  * SHADER SETUPZ
  */
  gl_shader_t shader_3;

  int errcode = run_parse();
  shader_3.test_flags();
  std::vector<shader_tuple_type*>*  shader_TV_ptr = return_ptr_shader_TV();

  shader_3.setup_shader_code(shader_TV_ptr->at(6));
  shader_3.setup_shader_code(shader_TV_ptr->at(5));
  std::vector<int> base_shader_idz;
  base_shader_idz.push_back(6);
  base_shader_idz.push_back(5);
  shader_3.create_link_program(base_shader_idz);
  shader_3.test_flags();

  std::vector<gl_shader_t*> shader_prt_vec;
  shader_prt_vec.push_back(&shader_3);

  /*
  working DATA for current test.
  */

    /*
     *BUFFERZ MGMT CMDZ
    */
    std::vector<GLuint> buffarry_obk_vec_01;
    std::vector<std::vector<GLuint>> encaple_vaoz;
    //encaple_vaoz.push_back(buffarry_obk_vec_01);

  /*
  *meshsettup and gemomenty_lighting
  */
  wavefornt_parser2 wp2;

  std::string ship_res_textA2 = {"data_extrn/boat_Base_2.obj"};
  mesh test_mesh;
  test_mesh.init(&wp2,ship_res_textA2);
  test_mesh.bindmesh_buf();

  glm::vec3 lpos(1.2f,1.0f,2.0f);
  glm::vec3 lcol(0.6f,0.2f,0.8f);

  gl_lightz light_01;
  light_01.set_light(lpos,lcol);

  /*
  texture setuptest_move to mesh
  */

  Texture_gl ship_test_texture;
  ship_test_texture.set_texture_ST(WarpMode::REPEAT,'s');
  ship_test_texture.set_texture_ST(WarpMode::REPEAT,'t');
  ship_test_texture.set_min_Mag_Filter(Filter::LINEAR,'i');
  ship_test_texture.set_min_Mag_Filter(Filter::LINEAR,'a');
  ship_test_texture.load_texture("data_extrn/ship_base_A03.bmp",3);
  ship_test_texture.init_texture();

  //texturez to shader
ship_test_texture.set_texture_sampler_uniform(&shader_3);
ship_test_texture.set_Tex_paramz();

  /*
  lenz and other last min setupz or orgz.
  */

  view_lenz vl_01;

  glm::vec3 world_up(0.f,1.f,0.f);
  glm::vec3 lenz_front(0.f,0.f,-1.f);
  glm::vec3 lenz_pos(0.f,0.f,1.f);

  glm::mat4 view_matrix(1.f);
  view_matrix = glm::lookAt(lenz_pos,lenz_pos+lenz_front,world_up);

  float fov= 90.f;
  float near_plane = 0.1f;
  float far_plane = 1000.f;

  glm::mat4 projection(1.f);
  glm::perspective(glm::radians(fov),(float)MAIN_SCREEN_WIDTH /
                                     (float)MAIN_SCREEN_HIGHT,near_plane,far_plane);

  //shader_3.set_glm_mat4("projection",projection);
  float lenz_radius = 10.0f;
  //initbase controzfactoz
  glm::vec3 posz_base(0.f);
  glm::vec3 rotation_base(0.f);
  glm::vec3 scale_base(0.2f);

  glm::mat4 base_model_matrix(1.0f);
  base_model_matrix = glm::translate(base_model_matrix, posz_base);
  base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.x),glm::vec3(1.f,0.f,0.f));
  base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.y),glm::vec3(0.f,1.f,0.f));
  base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.z),glm::vec3(1.f,0.f,1.f));
  base_model_matrix = glm::scale(base_model_matrix,scale_base);

  /*
  * UNIFORM SETTUPzzz.
  */

  //itunformz!
  GLint frame_buf_width,frame_buf_hight;
  shader_3.use_shader();
  glUniformMatrix4fv(glGetUniformLocation(shader_3.program_ID,"model_matrix"),
                                1,GL_FALSE,glm::value_ptr(base_model_matrix));

  glUniformMatrix4fv(glGetUniformLocation(shader_3.program_ID,"projection"),
                                1,GL_FALSE,glm::value_ptr(projection));

  glUniformMatrix4fv(glGetUniformLocation(shader_3.program_ID,"view"),
                                1,GL_FALSE,glm::value_ptr(view_matrix));

/*
* GOBAL OPEN GL ENABLEZ
*/

 glEnable(GL_DEPTH_TEST);
 glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
 /*
 Mainloopz!
 */
  std::cout <<"#####entering main loop setup compleate;\n \n";

  while(!glfwWindowShouldClose(glfw_window))
  {

    //process keyz
    process_input_glfw(glfw_window);


    /*
    BEGIN RENDER CYCLE! OHHH
    */
    glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // shaders to use globalyz
    shader_3.use_shader();

    //set projectionz
    glfwGetFramebufferSize(glfw_window,&frame_buf_width,&frame_buf_hight);

    projection = glm::mat4(1.f);
    projection =glm::perspective(glm::radians(fov),(float)frame_buf_width /
                                      (float)frame_buf_hight,near_plane,far_plane);

    glUniformMatrix4fv(glGetUniformLocation(shader_3.program_ID,"projection"),
                                           1,GL_FALSE,glm::value_ptr(projection));

    //do movmentz and tranformz on models
    rotation_base.y +=0.08f;
    rotation_base.z -=0.01f;

    //loadchanges into model matrix
    base_model_matrix =glm::mat4(1.f);
    base_model_matrix = glm::translate(base_model_matrix, posz_base);
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.x),glm::vec3(1.f,0.f,0.f));
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.y),glm::vec3(0.f,1.f,0.f));
    base_model_matrix = glm::rotate(base_model_matrix,glm::radians(rotation_base.z),glm::vec3(1.f,0.f,1.f));
    base_model_matrix = glm::scale(base_model_matrix,scale_base);

    //set the model matrix
    glUniformMatrix4fv(glGetUniformLocation(shader_3.program_ID,"model_matrix"),
                                  1,GL_FALSE,glm::value_ptr(base_model_matrix));


      glPolygonMode( GL_FRONT_AND_BACK, GL_FILL);
      //gl_run_render(glfw_window,shader_prt_vec,encaple_vaoz);
      test_mesh.draw(&shader_3);


      glfwSwapBuffers(glfw_window);
      //[postopz]
      //and poll glfw
      glfwPollEvents();

    }//endmain loop
/*
* CLEANUP GOES HERE
*/

  return 0;
      }
