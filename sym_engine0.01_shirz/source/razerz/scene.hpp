
#pragma once

#include "geometry.hpp"

#define L_AMBIENT 1
#define L_DIFFUSE 2
#define L_SPEKLER 3
#define L_DRECTION 4
#define L_POINT 5
#define L_SPOT 6


struct Phong_reflection
{
  //ambient light
  glm::vec3 ambient;

//directiona light
  float drectional_srength;

//Point light
float const_attenuation;
float quadr_attenuation;
float linear_attenuation;

//spot light
  glm::vec3 spot_cone_drection;
  float spot_cos_cutoff;
  float spot_exponent;

  //
  float gamma_c;
};

struct light_propertyz
{
  bool is_enabled;
  int  Light_type;

  glm::vec3 position;
  glm::vec3 intensity;

  Phong_reflection phong_light;
};


class gl_lightz
{
  public :
  std::vector<light_propertyz> light_list;

  void test_size()
  {
    std::cout << "lightpropy struct size::" << sizeof(light_propertyz)
    << "\n is multiof vec4:" << sizeof(light_propertyz)/sizeof(glm::vec4) <<'\n';
  }

  void set_ambient(glm::vec3 amb)
  {
    light_propertyz light_proper;
    light_proper.is_enabled = true;
    light_proper.Light_type =L_AMBIENT;

    light_proper.phong_light.ambient = amb;

    light_list.push_back(light_proper);
  }

  void set_light_diffuse(glm::vec3 lpos,glm::vec3 intezy,
                          float d_strgth)
  {
    light_propertyz light_proper;
    light_proper.is_enabled = true;
    light_proper.Light_type  =L_DIFFUSE;

    light_proper.position    =lpos;
    light_proper.intensity   =intezy;
    light_proper.phong_light.drectional_srength=d_strgth;

    light_list.push_back(light_proper);
  }

  void set_light_point(std::array<float,3> attenuation,glm::vec3 lpos,
    glm::vec3 intezy,float strenth)
  {
    light_propertyz light_proper;
    light_proper.is_enabled = true;
    light_proper.Light_type  =L_POINT;

    light_proper.position =lpos;
    light_proper.phong_light.drectional_srength =strenth;

    light_proper.phong_light.const_attenuation = attenuation[0];
    light_proper.phong_light.quadr_attenuation = attenuation[1];
    light_proper.phong_light.linear_attenuation= attenuation[2];

    light_list.push_back(light_proper);
  }

  void set_light_spot(std::array<float,3> annut,glm::vec3 lpos, glm::vec3 intezy,glm::vec3 cone_dir,
                        float cos_cutoff,float exp,float catten)
  {
    light_propertyz light_proper;
    light_proper.is_enabled = true;
    light_proper.Light_type                    =L_SPOT;

    light_proper.position                      =lpos;
    light_proper.intensity                     =intezy;
    light_proper.phong_light.const_attenuation =catten;
    light_proper.phong_light.spot_exponent     =exp;
    light_proper.phong_light.spot_cos_cutoff   =cos_cutoff;
    light_proper.phong_light.spot_cone_drection=cone_dir;

    light_proper.phong_light.const_attenuation = annut[0];
    light_proper.phong_light.quadr_attenuation = annut[1];
    light_proper.phong_light.linear_attenuation= annut[2];

    light_list.push_back(light_proper);
  }
};

enum class Scene_Mesh_RDR{
  LIGHT_SHADER_SCENE01,
  BASIC_SHADER_SCENE01
};

class scene{

  private :
  std::unordered_map<Scene_Mesh_RDR,gl_shader_t*> shader_map;
  std::unordered_map<Scene_Mesh_RDR,gl_lightz> light_crt_map;
  std::unordered_map<Scene_Mesh_RDR,view_lenz*> lenz_map;

  std::multimap<Scene_Mesh_RDR,mesh*> mesh_multi_map;

  typedef std::multimap<Scene_Mesh_RDR, mesh*>::iterator MMAPIterator;
  typedef std::unordered_map<Scene_Mesh_RDR,gl_shader_t*>::const_iterator SHAD_Iter;
  typedef std::unordered_map<Scene_Mesh_RDR,view_lenz*>::const_iterator LENZ_Iter;
  typedef std::unordered_map<Scene_Mesh_RDR,gl_lightz>::iterator LIGHT_Iter;

  public :

  void insert_shader(Scene_Mesh_RDR scene,gl_shader_t* in_shdr)
  {
    shader_map.insert(std::make_pair(scene,in_shdr));
  }

  void insert_light_ctler(Scene_Mesh_RDR scene,gl_lightz in_light)
  {
    light_crt_map.insert(std::make_pair(scene,in_light));
  }

  void insert_lenz(Scene_Mesh_RDR scene,view_lenz* in_lenz)
  {
    lenz_map.insert(std::make_pair(scene,in_lenz));
  }

  void insert_mesh(Scene_Mesh_RDR scene,mesh* in_mesh)
  {
    mesh_multi_map.insert(std::make_pair(scene,in_mesh));
  }


void draw_scene(Scene_Mesh_RDR to_draw_scene)
{
  gl_shader_t* current_shader;
  view_lenz* active_lenz;

   SHAD_Iter s_it = shader_map.find(to_draw_scene);
   if ( s_it == shader_map.end())
   {
     std::cerr <<"#!!scene_shader not foundz\n";
   }
   else
   {
     current_shader=s_it->second;
     current_shader->use_shader();
   }
   LENZ_Iter lez_it= lenz_map.find (to_draw_scene);
    if ( lez_it == lenz_map.end())
    {
      std::cerr<< "#!!scen_lenz not foundz\n";
    }
    else
    {
      active_lenz=lez_it->second;
    }
//setuo matrixz
  glm::mat4 active_projection = active_lenz->lenz_projection();
  glm::mat4 active_view       = active_lenz->return_lenz_view();

//pass light unifrmz or data..
if(Scene_Mesh_RDR::BASIC_SHADER_SCENE01 !=to_draw_scene)
{
  LIGHT_Iter li_it = light_crt_map.find (to_draw_scene);
 if ( li_it == light_crt_map.end())
 {
   std::cerr <<"#!!ligth_arrgment not foundz\n";
 }
 else
 {
  gl_lightz* light_scene_ptr=   &li_it->second;
  //light_scene_ptr->update_lightz();
  //light_scene_ptr->pass_datato_shader(current_shader);
}}

std::pair<MMAPIterator, MMAPIterator> result = mesh_multi_map.equal_range(to_draw_scene);

for (MMAPIterator it = result.first; it != result.second; it++)
{
 mesh* mesh_ptr = it->second;
 mesh_ptr->draw(current_shader,active_view,active_projection);
}

}

};
