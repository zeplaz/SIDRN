




#include "image_Byte8.h"
#include <string>


void load_img_tomatrx(ifstream &in_img)
{
	if (!in_img)

	{
		printf("eroror in imgloder fileread\n");
	}
uint8_t * img_byte_matrx = new uint8_t[image_area_pix+1];

}

bool skipChar(string discart_com){

	for(unsigned int i = 0; i < discart_com.length(); i++){

		if(discart_com[i] == '#') return true;

		if(!isspace(discart_com[i])) return false;

	}

	return true;


{
  uint8_t * byte_Array_pix = new uint8_t[image_size+1];

  byte_Array_pix[image_size] ='\0';


}
