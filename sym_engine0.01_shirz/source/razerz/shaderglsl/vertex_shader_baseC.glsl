#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 anormal;
layout (location = 2) in vec2 aUV;


out vec2 frag_uv;
out vec3 frag_normal;
out vec4 frag_pos;
out vec3 vertx_lenz_VM;


uniform mat4 model_view;
uniform mat4 model_proj_View;
uniform mat3 normal_matrix;

void main()
{
   vertx_lenz_VM   = vec3(model_view*vec4(aPos,1.0f));
   frag_uv         = aUV;
   frag_normal     = normalize(normal_matrix*anormal);
   frag_pos        = model_view*vec4(aPos,1.0);

   gl_Position =model_proj_View*vec4(aPos,1.0);

  }
