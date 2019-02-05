


class Vrt_mask
{
public :
erode_mask(){}
~erode_mask()


struct erode_mask3x3{
  const mask_orin[1][1]
   #define north
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

int r;
int c;
for (r=1; r< image->get_h_rs()-1; r++)
 for (c =1; c < get_h_rs()-1; c ++)
 {
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


   uint8_t by3x3_erodemask[3][3]=
  {
    {0,1,0}
    {1,1,1}
    {0,1,0}

  };


const uint8_t  by3x3_dilatemask[3][3] =
      {
        {0,1,0}
        {1,1,1}
        {0,1,0}
      };



};
