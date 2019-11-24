#version 330 core
//out vec4 FragColor;
out vec3 FragColor;
in vec2 UV;

in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)
uniform vec4 ourColor;
uniform sampler2D myTextureSampler;

void main()
{
    //FragColor = vertexColor*ourColor;
    FragColor = texture( myTextureSampler, UV ).rgb;
}
