#version 430 core

struct Phong_reflection
{
  //ambient light
  vec3 ambient;

//directiona light
  float drectional_srength;

//Point light
float const_attenuation;
float quadr_attenuation;
float linear_attenuation;

//spot light
  vec3 spot_cone_drection;
  float spot_cos_cutoff;
  float spot_exponent;

  //
  float gamma_c;
};

struct light_propertyz
{
  bool is_enabled;
  int  Light_type;

  vec3 position;
  vec3 intensity;

  Phong_reflection phong_light;
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

uniform light_propertyz lightz[MAX_Lightz];

layout (std140,binding = 5) uniform light_blockz
{
  light_propertyz lightzblock[MAX_Lightz];
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

for(int i =0; i<MAX_Lightz;i++)
{
  if(!lightz[i].is_enabled)
    continue;

    switch(lightz[i].Light_type)
    {
      case 0 :
      {
        break;
      }
      //ambient light
      case 1 :
      {
        ambient =lightz[i].phong_light.ambient*meterial.ambient_reflect;
      }
      //diffuse
      case 2 :
      {
        vec3  surface_to_light = normalize(lightz[i].position-frag_pos.xyz);
        float diffuseCoefficient =max(0.0,dot(frag_normal,surface_to_light));

        scatterd += diffuseCoefficient*lightz[i].intensity*meterial.diffuse_reflect;

        break;
      }

      //speckular
      case 3 :
      {
         vec3 spek_cal  = calculate_specular(frag_normal,frag_pos,lightz[i],meterial);
         spektral_reflect +=spek_cal*lightz[i].intensity;
        break;
      }

      //drectional
      case 4 :
      {
        vec3 spek_cal=vec3(0.0);
        vec3 defuz   =vec3(0.0);
        vec3  surface_to_light = normalize(lightz[i].position-frag_pos.xyz);
        float diffuseCoefficient =max(0.0,dot(frag_normal,surface_to_light));

        if(diffuseCoefficient !=0)
        {
          defuz       =  diffuseCoefficient*lightz[i].intensity;
          scatterd   +=  defuz*meterial.diffuse_reflect;

          spek_cal =calculate_specular(frag_normal,frag_pos,lightz[i],meterial);
          spektral_reflect += lightz[i].phong_light.drectional_srength*spek_cal*lightz[i].intensity;
         }
        break;
      }
        //pointlight
      case 5 :
        {
          vec3 light_drection = lightz[i].position;
          light_drection = light_drection- frag_pos.xyz;
          float light_distance = length(light_drection);
          light_drection = light_drection/light_distance;


          float total_attenuation = 1.0/(lightz[i].phong_light.const_attenuation+
                                         lightz[i].phong_light.linear_attenuation*light_distance+
                                         lightz[i].phong_light.quadr_attenuation*light_distance*light_distance);
         vec3 half_vec    = normalize(light_drection+vertx_lenz_VM);

         float diffz = max(0.0,dot(frag_normal,light_drection));

         float skplr;
         if(diffz !=0.0)
         {
           float skplr = max(0.0,dot(frag_normal,half_vec));
           skplr = pow(skplr,meterial.shininess)*lightz[i].phong_light.drectional_srength;

           spektral_reflect += meterial.specular_reflect*skplr*lightz[i].intensity*total_attenuation;
           scatterd         += meterial.diffuse_reflect*diffz*lightz[i].intensity*total_attenuation;
         }

        break;
        }


        //spot
      case 6 :
      {
        vec3 light_drection = lightz[i].position;
        light_drection = light_drection- frag_pos.xyz;
        float light_distance = length(light_drection);
        light_drection = light_drection/light_distance;

        float followspot_cos = dot(light_drection,-lightz[i].phong_light.spot_cone_drection);
        float total_attenuation;
        if(followspot_cos<lightz[i].phong_light.spot_cos_cutoff)
        {
          total_attenuation = 0.0;
        }
        else
        {
           total_attenuation = 1.0/(lightz[i].phong_light.const_attenuation+
                                      lightz[i].phong_light.linear_attenuation*light_distance+
                                      lightz[i].phong_light.quadr_attenuation*light_distance*light_distance);

          total_attenuation *=pow(followspot_cos,lightz[i].phong_light.spot_exponent);
          float defuziz = max(0.0,dot(frag_normal,light_drection));

          if(defuziz!=0)
          {
            vec3 skklr = calculate_specular(frag_normal,frag_pos,lightz[i],meterial)*
                         lightz[i].phong_light.drectional_srength;


            spektral_reflect += skklr*lightz[i].intensity*total_attenuation;
            scatterd         += meterial.diffuse_reflect*defuziz*lightz[i].intensity*total_attenuation;
          }
        }

        break;
      }
    }//endlightswitch
  }//end lightloop

  vec4 texture_colour = texture(myTextureSampler, frag_uv);
  scatterd +=ambient;
  vec3 result = min((texture_colour.rgb*scatterd)+spektral_reflect,vec3(1.0f));
  Frag_colour = vec4(result,texture_colour.a);
}
