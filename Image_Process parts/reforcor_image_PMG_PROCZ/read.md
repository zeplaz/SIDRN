complies on
Debian based systems with  libglew-dev and libsfml-dev

gcc I_P_main.cpp Image_PGM_P2.cpp image_procczor_mrk_1022.cpp -lGLU -lGL -lm -lglut -L/usr/lib64 -lstdc++ -o outputfilenae


gcc I_P_main.cpp Image_PGM_P2.cpp libs_modfied/glew_img_dislay.cpp -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-network -lsfml-system -lGLU -lGL -lm -lglut -L/usr/lib64 -lstdc++ -o outputfilenae

possy uses for complie sfmlz etc guulz


PFNGLCLIENTACTIVETEXTURE PROC
PFNGLCLIENTACTIVETEXTURE ARBPROC
’?
 GLEW_FUN_EXPORT
  __glewClientActiveTexture;
                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~

                 PFNGLCLIENTACTIVETEXTUREARBPROC
