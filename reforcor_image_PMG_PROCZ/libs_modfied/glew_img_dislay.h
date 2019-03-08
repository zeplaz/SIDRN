
// USe of glew for img rendering output. authoer ; -Benjamin Steenkamer
//
#ifndef G_IMG_DISP_H
#define G_IMG_DISP_H

#include <vector>
#include <GL/glew.h>
#include <SFML/Window.hpp>
#include <iostream>


class  glew_img_dislay{

    //private :


      public :

      glew_img_dislay(){};
      ~glew_img_dislay(){};

        void displayImage(std::vector<std::vector<uint32_t>> imageData, int width, int height);
        void   printShaderCompileStatus(GLuint shader, std::string name);

        const GLchar* vertexSource =
                    "#version 150 core\n"
                    "in vec2 position;"//0
                    "in vec2 texcoord;"//sizeof(float) * 2

                    "out vec2 Texcoord;"
                    "void main() {"
                        "Texcoord = texcoord;"
                        "gl_Position = vec4(position, 0.0, 1.0);"
                    "}";

        const GLchar* fragmentSource =
                    "#version 150 core\n"
                    "in vec2 Texcoord;"

                    "out vec4 outColor;"
                    "uniform sampler2D tex;"
                    "void main(){"
                        "outColor = texture(tex, Texcoord);"
                    "}";
};

#endif
