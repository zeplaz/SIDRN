#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aUV;
layout (location = 2) in vec3 anormal;

out vec2 frag_uv;
out vec3 frag_pos;
out vec3 frag_normal;
out vec3 frag_light_drec;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;

uniform vec3 light_position;

void main()
{
    frag_pos    = model*vec4(aPos,1.0).xyz;
    //frag_normal = mat3(transpose(inverse(model)))*anormal;
    gl_Position = projection*view*vec4(frag_pos,1.0);
    frag_normal = (view*model*vec4(anormal,0)).xyz;
    frag_uv     = aUV;
    frag_light_drec = (view*vec4(light_position,1)).xyz;
}
