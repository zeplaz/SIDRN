/*specs for the image scan and applicationz
this hsould also inlcue->matrix math for econtools//econ tools for function construction
some spects on the kinds of objects, and process needed, some outlines of some fucntions to caputr
data on the image and process it. as well as draw onto the image updating itetc
*/



//imagescaning tools


//processingtools();

    Deftype int Graphic_matrix_array[255][255] GM_array;

    //Matrix_image
      GM_array gm_input;
      GM_array gm_output;

      GM_array g_mined_image;


let g = imagematrix


  GM_array create_mined_normilzed_matrix(g)
      {
        return gm_min(g);
      }

  gm_min(g)
  {
  find min in matrix

  }


  create_scalled_255bands(g)
  {

  gmind/(max(gmind)+1)


    1/mn*sum(f(r,c))
    return
  }

  max(g)
  {
  find max value return
  return
  }



  //corner alanziez

  //objctz.
  Mask_corner_outside();
  Mask_corner_interor();

//functions

  //nabourhood
  //Nabour_4th
    n_hod_4();
    bottom[r-1,c]
    top[r+1,c]
    west[r,c-1]
    east[r,c+1]

    -bit Directional Values

        North = 20 = 1
        West = 21 = 2
        East = 22 = 4
        South = 23 = 8

    n_hod_8();
      n4[r,c] union SW[r-1,c-1]

      NW[r+1,c-1],SE[r-1,c+1],NE[r+1,c+1]
      8-bit Directional Values

          North West = 20 = 1
          North = 21 = 2
          North East = 22 = 4
          West = 23 = 8
          East = 24 = 16
          South West = 25 = 32
          South= 26 = 64
          South East = 27 = 128




//Dilation
  //dilate sstructte_mask
    GM_array  Bimputimage

  grmatrix_mask s_mask;

      GM_array   dilate(Bimputimage,s_mask);


//erode



  /*
  classes of entities
  */
  //bridges_

  //object:
      bridge()

  //functions:





  /*
  toolsgenal
  */
//

Listing 3:  Efficient Hilbert 2D state computation in C++.
uint64_t getState(uint64_t level, uint64_t position) {
uint64_t lowerMask = 0x5555555555555555ul; // binary: 01010101...
uint64_t flipMask = lowerMask >> (64 - 2 * level);
uint64_t a = position & lowerMask;
uint64_t b = (position >> 1) & lowerMask;
uint64_t aband = a & b;
uint64_t abnor = flipMask ^ (a | b);
uint64_t n_3 = __builtin_popcount(aband);
uint64_t n_0 = __builtin_popcount(abnor);
return 2 * (n_3 % 2) + (n_0 % 2);
};
(Universit ̈
at Stuttgart
Efficient Neighbor-Finding on
Space-Filling Curves
Bachelor Thesis
Author:
David Holzm ̈uller
*)


  //painttools

Paintnew_object_to_canvus();


//maping


//drawingrender ops.
