#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 anormal;
layout (location = 2) in vec3 aUV;

out vec4 frag_uv;
out vec4 frag_normal;
out vec4 frag_pos;

uniform mat4 model_view;
uniform mat4 model_proj_View;
uniform mat3 normal_matrix;

void main()
{

   frag_uv     = aUV;
   frag_normal = normalize(normal_matrix*anormal);

   frag_pos    =
   gl_Position =
    frag_pos    =
    //frag_normal = mat3(transpose(inverse(model)))*anormal;

    frag_normal = (view*model*vec4(anormal,0)).xyz;
    frag_uv     =
    frag_light_drec = (view*vec4(light_position,1)).xyz;
}
