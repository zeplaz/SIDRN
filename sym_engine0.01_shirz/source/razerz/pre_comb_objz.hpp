//pre_comb_objz
#pragma once



namespace lookup_objkz
{
  const std::string ship_A01 = "ship_A01";
  const std::string ship_A03 = "ship_A03";
}


namespace pre_comb_objz{

GLuint  index_buf_triagle[]
= {0,1,2,1,3,4,2,4,5,1,4,2};

GLfloat triangle_vertixz_01[] =
{
  0.0f ,0.05f,0.04f,
  -0.33f,0.01f,0.0f,
  0.31f,-0.0f, 0.4f,
  -0.5f,-0.4f,-0.2f,
  0.5f,-0.5f,-0.8f
};

GLfloat trang_01_colour[]=
{
  0.0f,  1.0f,  0.3f, 0.5f,
  1.0f,  1.0f,  1.0f, 0.8f,
  0.1f,  0.2f,  1.0f, 0.5f,
  0.0f, 0.5f,  1.0f, 0.3f,
  1.0f, 0.2f,  0.0f, 0.5f,
  0.2f, 0.6f,  0.4f, 0.8f
};

GLfloat base_colour_sampz[24]
{
   1.0f,  1.0f,  0.0f, 0.5f,
   1.0f,  1.0f,  1.0f, 0.3f,
   1.0f,  1.0f,  1.0f, 0.5f,
   1.0f, 1.0f,  1.0f, 0.3f,
   1.0f, 0.2f,  0.0f, 0.3f,
   0.2f, 0.6f,  0.4f, 0.8f
};
//other primitiz
GLuint g_Indices_cube01[24] = {
    0, 1, 2, 3,                 // Front face
    7, 4, 5, 6,                 // Back face
    6, 5, 2, 1,                 // Left face
    7, 0, 3, 4,                 // Right face
    7, 6, 1, 0,                 // Top face
    3, 2, 5, 4,                 // Bottom face
};


GLfloat polygonVertices[] =
 {
     320, 240, 12,
     370, 290, 55,
     420, 240, 200,
     370, 190, 0
 };

//skyboxstuff

std::vector<std::string> sky_box_sample
{
    "skybox_exmp/right.jpg",
    "skybox_exmp/left.jpg",
    "skybox_exmp/top.jpg",
    "skybox_exmp/bottom.jpg",
    "skybox_exmp/front.jpg",
    "skybox_exmp/back.jpg"
};
GLfloat samplecube_02[]=
{
  -1.0f,  1.0f, -1.0f,
  -1.0f, -1.0f, -1.0f,
   1.0f, -1.0f, -0.5f,
   1.0f, -1.0f, -1.0f,
   1.0f,  1.0f, -1.0f,
  -1.0f,  1.0f, -1.0f,

  -0.3f, -0.0f,  1.0f,
  -0.4f, -1.0f, -1.0f,
  -0.2f,  0.3f, -0.5f,
  -0.2f,  0.4f, -0.1f,
  -0.5f,  1.0f,  1.0f,
  -1.0f, -0.2f,  0.0f,

   1.0f, -1.0f, -0.0f,
   1.0f, -0.0f,  1.0f,
   0.8f,  0.0f,  1.0f,
   0.2f,  0.56f, 0.5f,
   0.0f,  0.0f, -0.2f,
   1.0f, -1.0f, -1.0f,

  -1.0f, -1.0f,  1.0f,
  -0.4f,  1.0f,  0.0f,
   1.0f,  0.0f,  6.0f,
   0.0f,  0.0f,  0.0f,
   0.0f, -0.2f,  0.0f,
  -1.0f,  1.0f, -0.3f
};

float skyboxVertices[] = {
        // positions
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f
    };

    GLfloat panelVertices[] = {
        -1.0f,  1.0f,  0.0f, 1.0f,
         1.0f,  1.0f,  1.0f, 1.0f,
         1.0f, -1.0f,  1.0f, 0.0f,

         1.0f, -1.0f,  1.0f, 0.0f,
        -1.0f, -1.0f,  0.0f, 0.0f,
        -1.0f,  1.0f,  0.0f, 1.0f
    };

    GLfloat cubeVertices_01[] = {
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
         0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,
         0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
         0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 1.0f,

        -1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
         1.0f,  1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
         1.0f,  1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f,
        -1.0f,  1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
        -1.0f, -1.0f, -0.5f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f
    };

    float rando_colour_data[] =
    {
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,

      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,

      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,

      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,

      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,

      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,

      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,

      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
      0.1f, 1.0f, 1.0f, 1.0f,
      0.2f, 1.0f, 0.3f, 1.0f,
      1.0f, 0.4f, 0.7f, 1.0f,
    };
  };
