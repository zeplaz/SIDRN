#version 330 core
layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
layout (location = 1) in vec3 aColor;
layout(location = 2) in vec2 vertexUV;

out vec4 vertexColor; // specify a color output to the fragment shader
out vec4 vs_pos_world;
out vec2 UV;

uniform mat4 view;
uniform mat4 projection;
uniform mat4 model;
uniform mat4 model_matrix;

void main()
{   //vs_pos_world = vec4(model_matrix*vec4(aPos,1.f)).xyz;

    gl_Position = model_matrix*vec4(aPos,1.0);//*view*projection; // see how we directly give a vec3 to vec4's constructor
    vertexColor = vec4(aColor,1.0); // set the output variable to a dark-red color
    UV = vertexUV;
}
