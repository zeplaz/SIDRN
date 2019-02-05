
//

/*

other sorces
jelouodsa


ortable BitMap[1] 	P1 	P4 	.pbm 	0–1 (white & black)
Portable GrayMap[2] 	P2 	P5 	.pgm 	0–255 (gray scale)
Portable PixMap[3] 	P3 	P6 	.ppm 	0–255 (RGB)
*/
void ()




void erode (image_z* img, int p_w, int p_h)

{
 int area = p_w*p_h;
int i;
for (i=w; i<area-w;i++)
  {

    for ()

  }
}




#include <stdlib>
mask_z


class vrt_mask
{


}


bool done_file_read = false;
char c;
int num_img_columns, Num_img_rows;

bool is_binnary(ifstream &infilez)

if (re)





void Image_pgm::read_in_pgm_image(ifstream &infile)

{
if(!infile)
{

  printf("read_error_0z\n");

}

done_file_read && (c =(char))




switch (c)
{
  case 'P';
  c = (char) fgetc(fpot);

}
default : printf("errorfilenot recoginzed")
break;

}


c = (char?)
if(c!=)

fgets(string,file)

ungetc(c,filename)

case '#' :
fgets(string, size,fpin);
break;

case : '1' :
case : ''

fscanf(filename"%d %d %d",this->num_img_columns,)







infile.read(byte_Array,image_size);
if (infile.fail())
{

printf("error:Pixel_read_in_arayserror\n");
}


byte_Array_pix[image_size] ='\0';




delate[] byte_Array_pix;
}



  void Image_pgm::read_header(ifstream &infile)


  {
    std::stringstream st_stream;
    std::string inpu_line;
    uint8_t read_byte;

      if(!infile)
        {
          printf("error infileload header");
        }



    std::getline(infile,inpu_line);


    uint8_t size_line = inpu_line.length();


    for (uint8_t i =0; i<size_line;i++)

    {
        if(!is_space(line[i]))
        {
         printf("error majic number or line currptionz\n");

        }
    }

      while(getline(infile, inpu_line))
      {
        if(!(is_comment(inpu_line))) break;

      }

    st_stream << inpu_line;

    if (!(st_stream >> pic_width))

      {
      printf("error cannot read width\n");
            }

            if (!(st_stream >> pic_hight))

              {
              printf("error cannot read width\n");
                    }



while (st_stream >> read_byte)
{

        if !(std::isspace(read_byte)))
        {
          printf("erorro courption after dimention data\n");

        }
}

      if (pic_width<=0|| pic_hight <=0)
      {
        printf("error with dimention data not postive\n");
        }

}


while (getline(infile,inpu_line))

{
 if(!(is_comment(input_line))) break;

}

st_stream.str("");
st_stream.clear();
st_stream << input_line;


 if(!(st_stream >> Max_pixel_value))

 {
    printf("error max value\n");

 }

  while (st_stream >> read_byte)

    {
      if (!(is_space(read_byte)))

      {
      printf("eror after maxvalue courptionz!\n");
      }





    }





    }



//
function sobel(A : as two dimensional image array)
	Gx=[-1 0 1; -2 0 2; -1 0 1]
	Gy=[-1 -2 -1; 0 0 0; 1 2 1]

	rows = size(A,1)
	columns = size(A,2)
	mag=zeros(A)

	for i=1:rows-2
		for j=1:columns-2
			S1=sum(sum(Gx.*A(i:i+2,j:j+2)))
			S2=sum(sum(Gy.*A(i:i+2,j:j+2)))

			mag(i+1,j+1)=sqrt(S1.^2+S2.^2)
		end for
	end for

	threshold = 70 %varies for application [0 255]
	output_image = max(mag,threshold)
	output_image(output_image==round(threshold))=0;
	return output_image
end function



}
