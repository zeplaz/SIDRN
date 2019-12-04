//#include "render_objk_cmd.hpp"
#include "opengl_utilityz.hpp"
#include "scene.hpp"


#include "lenz.hpp"

float delta_time = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

void process_input_glfw(GLFWwindow* window);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

float lastX = MAIN_SCREEN_WIDTH / 2.0f;
float lastY = MAIN_SCREEN_HIGHT / 2.0f;
bool firstMouse = true;
bool is_cursor_captured = false;
//lenz at global to allow mouse/keybord callback. put into some kindamap.
view_lenz prim_lenz;

/*
* MAIN!
*/
  int main(int argc, char* argv[])
  {
  /*
  GLM AND OPENGL AND GLFW inailzaiton
  */
    int errocode;
    GLFWwindow* glfw_window;

    std::cout << "launching Main Window\n";
    errocode = opengl_context_settup();

    std::cout << "###openglcontexcode::"<< errocode <<'\n';

    glfw_window = glfwCreateWindow(MAIN_SCREEN_WIDTH,MAIN_SCREEN_HIGHT,"cmdz_toolGlfz",NULL,NULL);
    glfwSetCursorPosCallback(glfw_window, mouse_callback);
    glfwSetScrollCallback(glfw_window, scroll_callback);

// tell GLFW to capture our mouse

    errocode = run_opengl_setup(glfw_window);
    std::cout << "\n ###openglsetupcode::"<< errocode;

  /*
  * SHADER SETUPZ
  */

  gl_shader_t* shader_3_basic= new gl_shader_t();
  gl_shader_t* shader_lightA01= new gl_shader_t();

  std::vector<gl_shader_t*> shader_prt_vec;

  shader_prt_vec.push_back(shader_3_basic);
  shader_prt_vec.push_back(shader_lightA01);

//run paser
  int errcode = run_parse();

  shader_3_basic->test_flags();
  shader_lightA01->test_flags();


  //shader datastucz
  std::vector<shader_tuple_type*>*  shader_TV_ptr = return_ptr_shader_TV();
  std::vector<int> shdr_3_list;
  std::vector<int> shdr_lightA01_list;

  //shader_setupz
std::cout <<"shader number" << shader_TV_ptr->size();
  shader_3_basic->setup_shader_code(shader_TV_ptr->at(1));
  shader_3_basic->setup_shader_code(shader_TV_ptr->at(0));
  shdr_3_list.push_back(SHD_BASICA02_VERTEX);
  shdr_3_list.push_back(SHD_BASIC_FRAG);

  shader_3_basic->create_link_program(shdr_3_list);
  shader_3_basic->test_flags();

  shader_lightA01->setup_shader_code(shader_TV_ptr->at(2));
  shader_lightA01->setup_shader_code(shader_TV_ptr->at(3));

  shdr_lightA01_list.push_back(SHD_LIGHTA1_VERTEX);
  shdr_lightA01_list.push_back(SHD_LIGHTA1_FRAG);

  shader_lightA01->create_link_program(shdr_lightA01_list);
  shader_lightA01->test_flags();
std::cout << "##SHADER settup COMPLEATE\n";

  /*
  working DATA for current test.
  */
    model_ajustment test_ajustship;
    model_ajustment test_ajustship2;

    test_ajustship.rotation_ajust = glm::vec3(0.f);
    test_ajustship.posz_ajust  = glm::vec3(0.f);
    test_ajustship.scale_ajust = glm::vec3(0.f);
    test_ajustship2.rotation_ajust = glm::vec3(0.f);
    test_ajustship2.posz_ajust  = glm::vec3(0.f);
    test_ajustship2.scale_ajust = glm::vec3(0.f);

    model_ajustment ship_2_orgin;

    ship_2_orgin.posz_ajust.x=0.9f;
    ship_2_orgin.posz_ajust.y=0.5f;
    ship_2_orgin.posz_ajust.z= -0.1f;

    ship_2_orgin.scale_ajust = glm::vec3(0.1f);
    ship_2_orgin.rotation_ajust.y = 120.f;
    ship_2_orgin.rotation_ajust.x = 0.f;
    ship_2_orgin.rotation_ajust.z = 0.f;

    /*
     *BUFFERZ MGMT CMDZ
    */

  /*
  *meshsettup
  */
  std::cout <<"setupmeshz \n";
  wavefornt_parser2 wp2;

  std::string shipA2_path = {"data_extrn/boat_Base_2.obj"};
  std::pair<std::shared_ptr<std::vector<mesh_vertex>>,
            std::shared_ptr<std::vector<unsigned int>>>
            shipA2_mesh_vertex_DATA = wp2.read_file(shipA2_path);

  mesh shipA3;

  shipA3.init(shipA2_mesh_vertex_DATA,M_Model_Flag::MODEL_UNIFORM,HAS_LIGHTS);
  shipA3.bindmesh_buf();

  glm::vec3 shipA2_emis            =glm::vec3(0.0f);
  glm::vec3 shipA2_amb_ref         =glm::vec3(0.5);
  glm::vec3 shipA2_diff_ref        =glm::vec3(0.5);
  glm::vec3 shipA2_spektral_reflect=glm::vec3(0.5);
  float     shipA2_shinyz          =6;

  shipA3.set_meterial(shipA2_emis,shipA2_amb_ref,shipA2_diff_ref,
                        shipA2_spektral_reflect,shipA2_shinyz);

  mesh ship_basic;
  ship_basic.init(shipA2_mesh_vertex_DATA,M_Model_Flag::MODEL_UNIFORM,NO_LIGHT);
  ship_basic.bindmesh_buf();
  ship_basic.set_mesh_model_origin(ship_2_orgin);


 /*
* gemomenty_lighting
*/

  gl_lightz test_lightz;


//light ambient
  glm::vec3 amb = glm::vec3(0.3,0.3,0.3);

  test_lightz.set_ambient(amb);

//light diffuz
  glm::vec3 light_pos_d1(1.2f,1.0f,1.0f);
  glm::vec3 lcol_d1(0.8,0.0f,0.0f);

  float d_strgth = 3.f;

  test_lightz.set_light_diffuse(light_pos_d1,lcol_d1,d_strgth);

//light point
  std::array<float,3> attun;
  attun[0]=4.f;
  attun[1]=3.f;
  attun[2]=2.f;
  glm::vec3 light_pos_ss2(1.2f,1.0f,1.0f);
  glm::vec3 lcol_ss2(0.0f,0.8f,0.0f);
  float drecional_strgth;
  test_lightz.set_light_point(attun,light_pos_ss2,lcol_ss2,drecional_strgth);

  //light spot
  glm::vec3 light_pos_ss1(1.2f,1.0f,1.0f);
  glm::vec3 lcol_ss1(0.f,0.0f,0.8f);
  glm::vec3 cone_dir(1.f,1.f,1.f);
  float cos_cutoff =0.98;
  float exp =12;
  float catten = 3;

  test_lightz.set_light_spot(attun,light_pos_ss1,lcol_ss1,cone_dir,cos_cutoff,
                              exp,catten);

  /*
  texture setuptest_move to mesh
  */

  std::cout << "load texturez\n";

    //vglLoadTexture("data_extrn/ship_base_A03.bmp");
  texture_paramz_pak ship_tex_A3_parmz;
  ship_tex_A3_parmz.wm_s    = WarpMode::REPEAT;
  ship_tex_A3_parmz.wm_t    = WarpMode::REPEAT;
  ship_tex_A3_parmz.mag     = Filter::LINEAR;
  ship_tex_A3_parmz.min     = Filter::LINEAR;
  ship_tex_A3_parmz.path    = "data_extrn/ship_base_A03.bmp";
  ship_tex_A3_parmz.channels= 3;
  ship_tex_A3_parmz.unform_name = "active_texture_sampler";
  ship_tex_A3_parmz.tex_unit_index = 0;
  ship_tex_A3_parmz.text_type_flag = M_Tex_Flag::TEXTYR_BASIC;

  shipA3.texture_setup(ship_tex_A3_parmz);
  ship_basic.texture_setup(ship_tex_A3_parmz);

  /*
  *LENZ SETUP>>>deal with it being gobalz?
  */

  std::cout << "load_lenz\n";

  glm::vec3 world_up(0.f,1.f,0.f);
  glm::vec3 lenz_front(0.f,0.f,-1.f);
  glm::vec3 lenz_pos(0.f,0.f,1.f);
  float fov= 90.f;
  float near_plane = 0.1f;
  float far_plane = 1000.f;
  float lenz_radius = 10.0f;


  /*
  *MATRIX INILAZATION SETZ
  */
  glm::mat4  view_projection =glm::mat4(1.f);
  glm::mat4 view_matrix(1.f);
  glm::mat4 Projection(1.f);

  view_matrix =  prim_lenz.return_lenz_view();
  Projection  = prim_lenz.lenz_projection();
  view_projection = Projection*view_matrix;



  /*
  * UNIFORM SETTUPzzz.
  */


  //itunformz!

  std::array<GLuint,3> lightA1_uniform_array;

  GLuint mv_loc_light, mpv_loc_light,norm_mat_loc_light;
  GLuint v_poj_loc, view_loc, m_loc, m_v_p_basic;


   glm::mat4 model_matrix;

  //shader_3.use_shader();

  shader_lightA01->use_shader();
  mv_loc_light      = glGetUniformLocation(shader_lightA01->program_ID,"model_view");
  mpv_loc_light     = glGetUniformLocation(shader_lightA01->program_ID,"model_proj_View");
  norm_mat_loc_light= glGetUniformLocation(shader_lightA01->program_ID,"normal_matrix");

  shader_lightA01->add_uniform("model_view",mv_loc_light);
  shader_lightA01->add_uniform("model_proj_View",mpv_loc_light);
  shader_lightA01->add_uniform("normal_matrix",norm_mat_loc_light);


  shader_3_basic->use_shader();
  //m_v_p_basic= glGetUniformLocation(shader_3_basic->program_ID,"model_view_projection");
  //shader_3_basic->add_uniform("model_view_projection",m_v_p_basic);
  //v_poj_loc= glGetUniformLocation(shader_3_basic->program_ID,"view_projection");
  //glUniformMatrix4fv(v_poj_loc,1,GL_FALSE,glm::value_ptr(view_projection));


/*
* SCENE setupz and load
*/
scene scene_01;

scene_01.insert_shader(Scene_Mesh_RDR::LIGHT_SHADER_SCENE01,shader_lightA01);

scene_01.insert_shader(Scene_Mesh_RDR::BASIC_SHADER_SCENE01,shader_3_basic);

scene_01.insert_light_ctler(Scene_Mesh_RDR::LIGHT_SHADER_SCENE01,test_lightz);

scene_01.insert_mesh(Scene_Mesh_RDR::LIGHT_SHADER_SCENE01,&shipA3);
scene_01.insert_mesh(Scene_Mesh_RDR::BASIC_SHADER_SCENE01,&ship_basic);

scene_01.insert_lenz(Scene_Mesh_RDR::LIGHT_SHADER_SCENE01,&prim_lenz);
scene_01.insert_lenz(Scene_Mesh_RDR::BASIC_SHADER_SCENE01,&prim_lenz);
/*
* GOBAL OPEN GL ENABLEZ
*/

GLint frame_buf_width,frame_buf_hight;

 glEnable(GL_DEPTH_TEST);
 glClearColor(0.2f, 0.3f, 0.3f, 1.0f);


 /*
 Mainloopz!
 */
 test_lightz.test_size();
  std::cout <<"#####entering main loop setup compleate;\n \n";

  while(!glfwWindowShouldClose(glfw_window))
  {
    //process keyz
    float currentFrame = glfwGetTime();
    delta_time = currentFrame - lastFrame;
    lastFrame = currentFrame;
    process_input_glfw(glfw_window);

    /*
    BEGIN RENDER CYCLE! OHHH
    */
    glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    //set projectionz
    glfwGetFramebufferSize(glfw_window,&frame_buf_width,&frame_buf_hight);

    view_matrix =  prim_lenz.return_lenz_view();
    Projection  = prim_lenz.lenz_projection();


    view_projection = glm::mat4(1.f);
    view_projection = Projection*view_matrix;

  //  glUniformMatrix4fv(v_poj_loc,1,GL_FALSE,glm::value_ptr(view_projection));

    //glfwGetFramebufferSize(glfw_window,&frame_buf_width,&frame_buf_hight);

    /*
    * MODEL TRANFORMZ
    */
    test_ajustship.rotation_ajust.y =0.09f;
    test_ajustship2.posz_ajust.x=-0.001f;
    //test_ajustship2.rotation_ajust.y=-0.01f;
    //test_ajustship2.posz_ajust.x = -0.08f;
    //shipA3.update_mesh_model(test_ajustship);
    ship_basic.update_mesh_model(test_ajustship2);


  /*
  * DRAW CALLZ
  */
    //scene_01.draw_scene(Scene_Mesh_RDR::LIGHT_SHADER_SCENE01);
    scene_01.draw_scene(Scene_Mesh_RDR::BASIC_SHADER_SCENE01);
    //test_mesh.draw(shader_lightA01,&prim_lenz);
    //test_mesh2.draw(shader_3_basic,&prim_lenz);
    //ship_basic.draw(shader_3_basic,&prim_lenz);
    //ship_basic.draw(shader_3_basic,view_matrix,Projection);
    //ship_basic.draw(shader_3_basic);
    glfwSwapBuffers(glfw_window);

      //[postopz]
      //and poll glfw
      glfwPollEvents();
/*
      if(screen_beenresized ==true)
      {
        prim_lenz.update_aspec_ratio(frame_buf_width,frame_buf_hight);
        screen_beenresized = false;
      }*/

    }//endmain loop
/*
* CLEANUP GOES HERE
*/


  return 0;
      }


      void mouse_callback(GLFWwindow* window, double xpos, double ypos)
      {
        if(firstMouse)
        {
          lastX = xpos;
          lastY= ypos;
          firstMouse = false;
        }
        float xoffset = xpos- lastX;
        float yoffset = lastY-ypos;
        lastX=xpos;
        lastY=ypos;
        prim_lenz.process_mouse(xoffset,yoffset);
      }

      void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
      {
        prim_lenz.process_scroll(yoffset);
      }

      void process_input_glfw(GLFWwindow* window)
      {
          if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
              {glfwSetWindowShouldClose(window, true);}

          if(glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
                {
                  if(is_cursor_captured)
                  {
                    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
                    is_cursor_captured=false;
                  }
                  else
                  {
                    is_cursor_captured= true;
                    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
                  }
                  }


      //  float lenz_speed = 2.5*delta_time;

        if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        {
          prim_lenz.lenz_move(delta_time,'w');
        }

        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        {
          prim_lenz.lenz_move(delta_time,'s');
        }
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        {
          prim_lenz.lenz_move(delta_time,'a');
        }

        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        {
          prim_lenz.lenz_move(delta_time,'d');
        }
      }
