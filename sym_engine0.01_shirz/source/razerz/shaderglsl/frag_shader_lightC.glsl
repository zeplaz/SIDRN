#version 450 core

struct Phong_reflection
{
  //ambient light
  vec3 ambient;
  vec3 spot_cone_drection;

//directiona light
  float drectional_srength;

//Point light
float const_attenuation;
float quadr_attenuation;
float linear_attenuation;

//spot light

  float spot_cos_cutoff;
  float spot_exponent;

  //
  float gamma_c;
};

struct light_propertyz
{
  bool is_enabled;
  vec3 position;
  vec3 intensity;

  Phong_reflection phong_light;
  int  Light_type;
};


struct Meterialz
{
  vec3 emission;
  vec3 ambient_reflect;
  vec3 diffuse_reflect;
  vec3 specular_reflect;
  float shininess;

  //sampler2D diffuse_texture;
  //sampler2D spekular_texture;

};

const int MAX_Lightz = 5;

out vec4 Frag_colour;

in vec2 frag_uv;
in vec3 frag_normal;
in vec4 frag_pos;
in vec3 vertx_lenz_VM;

uniform Meterialz meterial;

uniform sampler2D myTextureSampler;

//uniform light_propertyz lightz[MAX_Lightz];
/*
layout (binding = 1,std430) buffer light_blockz
{
  light_propertyz lightzblock[MAX_Lightz];
};*/

layout (binding = 1,std430) buffer light_blockz2
{
  light_propertyz light;
};

vec3 calculate_specular(vec3 vk_normz,vec4 vk_pos,light_propertyz light ,Meterialz material)
{
  vec3 light_to_loc   = normalize(vk_pos.xyz-light.position);
  vec3 reflect_drect  = normalize(reflect(light_to_loc,normalize(vk_normz)));
  vec3 pos_toview_dirc= normalize(vertx_lenz_VM-vk_pos.xyz);
  float spek_angle    = max(0.0,dot(pos_toview_dirc,reflect_drect));
  vec3 spk_final      = material.specular_reflect*pow(spek_angle,material.shininess);
  return spk_final;
}


void main()
{

  //vec3 ambient= vec3(0.13);
  vec3 scatterd = vec3(0.0);
  vec3 spektral_reflect = vec3(0.0);
  vec3 ambient= vec3(0.0);

  light_propertyz l_test;
  l_test.is_enabled= true;
  l_test.position=vec3 (1.1,1.1,1.1);
  l_test.intensity=vec3(0.8,0.7,0.1);

  l_test.Light_type=1;

  l_test.phong_light.ambient=vec3(0.0,0.0,0.5);
  l_test.phong_light.spot_cone_drection=vec3(1.0,1.1,0.5);

  //directiona light
  l_test.phong_light. drectional_srength=3;

  //Point light
  l_test.phong_light.const_attenuation=-20;
  l_test.phong_light.quadr_attenuation=-20;
  l_test.phong_light.linear_attenuation=-20;

  //spot light

  l_test.phong_light.spot_cos_cutoff=0.91;
  l_test.phong_light.spot_exponent=2;
//lightzblock[0]=l_test;
/*
for(int i =0; i<MAX_Lightz;i++)
{
  if(!lightzblock[i].is_enabled)
    continue;

    switch(lightzblock[i].Light_type)
    {
      case 0 :
      {
        break;
      }
      //ambient light
      case 1 :
      {
        ambient =lightzblock[i].phong_light.ambient*meterial.ambient_reflect;
      }
      //diffuse
      case 2 :
      {
        vec3  surface_to_light = normalize(lightzblock[i].position-frag_pos.xyz);
        float diffuseCoefficient =max(0.0,dot(frag_normal,surface_to_light));

        scatterd += diffuseCoefficient*lightzblock[i].intensity*meterial.diffuse_reflect;

        break;
      }

      //speckular
      case 3 :
      {
         vec3 spek_cal  = calculate_specular(frag_normal,frag_pos,lightzblock[i],meterial);
         spektral_reflect +=spek_cal*lightzblock[i].intensity;
        break;
      }

      //drectional
      case 4 :
      {
        vec3 spek_cal=vec3(0.0);
        vec3 defuz   =vec3(0.0);
        vec3  surface_to_light = normalize(lightzblock[i].position-frag_pos.xyz);
        float diffuseCoefficient =max(0.0,dot(frag_normal,surface_to_light));

        if(diffuseCoefficient !=0)
        {
          defuz       =  diffuseCoefficient*lightzblock[i].intensity;
          scatterd   +=  defuz*meterial.diffuse_reflect;

          spek_cal =calculate_specular(frag_normal,frag_pos,lightzblock[i],meterial);
          spektral_reflect += lightzblock[i].phong_light.drectional_srength*spek_cal*lightzblock[i].intensity;
         }
        break;
      }
        //pointlight
      case 5 :
        {
          vec3 light_drection = lightzblock[i].position;
          light_drection = light_drection- frag_pos.xyz;
          float light_distance = length(light_drection);
          light_drection = light_drection/light_distance;


          float total_attenuation = 1.0/(lightzblock[i].phong_light.const_attenuation+
                                         lightzblock[i].phong_light.linear_attenuation*light_distance+
                                         lightzblock[i].phong_light.quadr_attenuation*light_distance*light_distance);
         vec3 half_vec    = normalize(light_drection+vertx_lenz_VM);

         float diffz = max(0.0,dot(frag_normal,light_drection));

         float skplr;
         if(diffz !=0.0)
         {
           float skplr = max(0.0,dot(frag_normal,half_vec));
           skplr = pow(skplr,meterial.shininess)*lightzblock[i].phong_light.drectional_srength;

           spektral_reflect += meterial.specular_reflect*skplr*lightzblock[i].intensity*total_attenuation;
           scatterd         += meterial.diffuse_reflect*diffz*lightzblock[i].intensity*total_attenuation;
         }

        break;
        }


        //spot
      case 6 :
      {
        vec3 light_drection = lightzblock[i].position;
        light_drection = light_drection- frag_pos.xyz;
        float light_distance = length(light_drection);
        light_drection = light_drection/light_distance;

        float followspot_cos = dot(light_drection,-lightzblock[i].phong_light.spot_cone_drection);
        float total_attenuation;
        if(followspot_cos<lightzblock[i].phong_light.spot_cos_cutoff)
        {
          total_attenuation = 0.0;
        }
        else
        {
           total_attenuation = 1.0/(lightzblock[i].phong_light.const_attenuation+
                                      lightzblock[i].phong_light.linear_attenuation*light_distance+
                                      lightzblock[i].phong_light.quadr_attenuation*light_distance*light_distance);

          total_attenuation *=pow(followspot_cos,lightzblock[i].phong_light.spot_exponent);
          float defuziz = max(0.0,dot(frag_normal,light_drection));

          if(defuziz!=0)
          {
            vec3 skklr = calculate_specular(frag_normal,frag_pos,lightzblock[i],meterial)*
                         lightzblock[i].phong_light.drectional_srength;


            spektral_reflect += skklr*lightzblock[i].intensity*total_attenuation;
            scatterd         += meterial.diffuse_reflect*defuziz*lightzblock[i].intensity*total_attenuation;
          }
        }

        break;
      }
    }//endlightswitch
  }//end lightloop
  */
  //vec3 ambient_reflect;
//  vec3 diffuse_reflect;
//  vec3 specular_reflect;

vec3 light_drection = l_test.position;
light_drection = light_drection- frag_pos.xyz;
float light_distance = length(light_drection);
light_drection = light_drection/light_distance;
  vec3 ambent_test = light.phong_light.ambient;

float total_attenuation = 1.0/(l_test.phong_light.const_attenuation+
                               l_test.phong_light.linear_attenuation*light_distance+
                               l_test.phong_light.quadr_attenuation*light_distance*light_distance);
vec3 half_vec    = normalize(light_drection+vertx_lenz_VM);

float diffz = max(0.0,dot(frag_normal,light_drection));

float skplr;
if(diffz !=0.0)
{
 float skplr = max(0.0,dot(frag_normal,half_vec));
 skplr = pow(skplr,meterial.shininess)*l_test.phong_light.drectional_srength;

spektral_reflect += meterial.specular_reflect*skplr*l_test.intensity*total_attenuation;
 scatterd         += meterial.diffuse_reflect*diffz*l_test.intensity*total_attenuation;
}

//spot
float followspot_cos = dot(light_drection,-l_test.phong_light.spot_cone_drection);


if(followspot_cos<l_test.phong_light.spot_cos_cutoff)
{
  total_attenuation = 0.0;
}
total_attenuation =pow(followspot_cos,l_test.phong_light.spot_exponent);
float defuziz = max(0.0,dot(frag_normal,light_drection));

if(defuziz!=0)
{
  vec3 skklr = calculate_specular(frag_normal,frag_pos,l_test,meterial)*
               l_test.phong_light.drectional_srength;


  spektral_reflect += skklr*l_test.intensity*total_attenuation;
  scatterd         += meterial.diffuse_reflect*defuziz*l_test.intensity*total_attenuation;

}
  vec3 spek_cal  = calculate_specular(frag_normal,frag_pos,l_test,meterial);
  vec4 texture_colour = texture(myTextureSampler, frag_uv);

  vec3  surface_to_light2 = normalize(l_test.position-frag_pos.xyz);
  float diffuseCoefficient2 =max(0.0,dot(frag_normal,surface_to_light2));

  scatterd += diffuseCoefficient2*l_test.intensity*meterial.diffuse_reflect;

  scatterd +=meterial.ambient_reflect*l_test.phong_light.ambient;
spektral_reflect = spektral_reflect+spek_cal;
  //vec3 result = min((texture_colour.rgb*scatterd)+spektral_reflect,vec3(1.0f));
  vec3 result = min((texture_colour.rgb*scatterd),vec3(1.0f));
  Frag_colour = vec4(result,1);
}
