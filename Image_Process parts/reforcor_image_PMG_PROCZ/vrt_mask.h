


//vrt_mask.h

#ifndef VRT_MASK_H
#define VRT_MASK_H

class Vrt_mask
  {

    public :
    //erode_mask(){}
    //~erode_mask()

    //const uint8_t mask_orin[1][1];


    double Gauss_blurr_3x3[3][3] =
    {
      {1,2,1},
      {2,4,2},
      {1,2,1}

    };

  double maskLOG_2nd_derivative[3][3] =
  {
    {0,1,0},
    {1,-4,1},
    {0,1,0}
  };

  double edge_8cent[3][3] =
  {
    {-1,-1,-1},
    {-1,8,-1},
    {-1,-1,-1}
  };

  double colum_derivate[3][3] =
  {
    { -1,0,-1 },
    {-1,0,-1},
    {-1,0,-1}
  };
  double row_derivate[3][3] =
  {
    { -1,-1,-1 },
    {1,0,0},
    {-1,-1,-1}
  };

  double Sobel_x[3][3] =
  {
    {1,0,-1},
    {2,0,-2},
    {1,0,-1}

  };

  double Sobel_y[3][3] =
  {
    {-1,-2,-1},
    {0,0,0},
    {1,2,1}

  };

  double Laplacian_outer[3][3] =
  {
  {-2,1,-2},
    {1,4,1},
  {-2,1,-2}
  };

  double Laplacian_inter[3][3] =
  {
    {1,-2,1},
    {-2,4,-2},
    {1,-2,1}
  };

};
  #endif

/*


    uint8_t by3x3_erodemask[3][3]=
    {
     {0,1,0},
     {1,1,1},
     {0,1,0}

   }

  uint8_t  by3x3_dilatemask[3][3] =
     {
       {0,1,0},
       {1,1,1},
       {0,1,0}
     }
struc Laplacian_inter
{
  double ratio = 1/6;
  int LP_in[3][3] =
    {

    }
  };
double Laplacian_inter[3][3] =
{
};


/*
};
/*
inline applyMask(int type)
{

        switch (type)

        case 1 :

        case 2 :


        default :
        printf("Defult run all Masks and output\n");



};

inline  dilate_mask3x3(Image_PGM_P2* image)
{
  int r;
  int c;
  Image_PGM_P2 lapnceouter
    for (r=1; r< image->get_h_rs()-1; r++)
    {  for (c =1; c < image->get_h_rs()-1; c ++)
          {

            = image->b_imgArray[r-1].at(c-1) *  Laplacian_outer[r-1][c-1]

            image->b_imgArray[r][c]   = by3x3_erodemask[r+1][c];
            image->b_imgArray[r+1][c+2] = by3x3_erodemask[r+1][c+2];
            image->b_imgArray[r+2][c+1] = by3x3_erodemask[r+2][c+1];

  inline void dilate_mask3x3(Image_PGM_P2* image)
  {
    int r;
    int c;
      for (r=1; r< image->get_h_rs()-1; r++)
      {  for (c =1; c < image->get_h_rs()-1; c ++)
            {
              if (image->b_imgArray[r][c] !=0)
                {
                    image->b_imgArray[r][c+1]  = by3x3_erodemask[r][c+1];
                    image->b_imgArray[r+1][c]   = by3x3_erodemask[r+1][c];
                    image->b_imgArray[r+1][c+2] = by3x3_erodemask[r+1][c+2];
                    image->b_imgArray[r+2][c+1] = by3x3_erodemask[r+2][c+1];

                }
              }
      }
  }

inline   void erode_mask3x3(image_Byte8* image){

    int r;
    int c;
      for (r=1; r< image->get_h_rs()-1; r++)
      {  for (c =1; c < image->get_h_rs()-1; c ++)
            {
              if (
                image->pixelz[r][c+1] != by3x3_erodemask[r][c+1] &&
                image->pixelz[r+1][c]  != by3x3_erodemask[r+1][c]  &&
                image->pixelz[r+1][c+2] != by3x3_erodemask[r+1][c+2] &&
                image->pixelz[r+2][c+1] != by3x3_erodemask[r+2][c+1]
                )
              {image->pixelz[r][c]=0;}
            }
          }
      }

#endif
/* #define north
 #define east
 #define south
 #define west
 #define NE
  #define NW
   #define SE
    #define SW


        struct N4hood{
         const uint8_t north[1] ={1,0};
         const uint8_t south[1] = {-1,0};
         const uint8_t west[1]= {-1,-1};
         const uint8_t est[1]= {0,1};
       };

    struct N8hood{
        const uint8_t SW[1] ={0,-1};
        const uint8_t NE[1] ={1,1};
        const uint8_t NW[1] ={1,-1};
        const uint8_t SE[1] ={-1,1};
    };
    */
