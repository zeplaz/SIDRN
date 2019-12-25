
## razerz
is a the testbed of a opengl graphics rendering engine.


### Ship_testz folder
first tests in opengl, buffers, test of baisc lighting{kinda broken}, shaders and static model loader, obj files.  (current build has an  unstable fragment shader deadly loop!. plus alot of the files nessary where moved to the "basez" folder to test animation as i did not want lots of duplicates.. however you can move then back and should comple fine. through i am modifying then currently one they are more stable will unify....

#### Current complie line:
g++ -std=c++17  -Wall -Wextra  main_shpr2_test.cpp   shader_parser.cpp  geometry.cpp opengl_utilityz.cpp geometry_parser.cpp  `pkg-config --cflags gldw3 ` -lSDL2_image -lGL -lglut -lGLEW -lglfw3 -pthread -ldl -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lassimp


### animation folder
building up a test of riged models... under devlopment no tests thus far

### shaderglsl folder
some examples and unspifed shaders

### test_rezultz
example binaries backups as well as images of tests

### test_rezultz oldcode_backupz
reivsion control backup of iterations.

### lib_othr
just bits of files, and examples and notes
