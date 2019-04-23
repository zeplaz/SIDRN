

#include "image_Byte8.h"
#include <string>



		bool skipChar(std::string discart_com)
		{
			for(int i = 0; i < discart_com.length(); i++)
			 {
					if(discart_com[i] == '#') return true;
					if(!isspace(discart_com[i])) return false;
				}
	  		return true;
			}

			void image_Byte8::Image_Procees_inlizar(std::ifstream& in_img)
			{
				printf("please Enter file Name:\n");

				std::cin >> user_input_img_name;

				in_img.open(user_input_img_name.c_str(), std::ifstream::in);

				printf("ImageOPen\n");

				if  (!(in_img >> readbytechar) || ( readbytechar != 'P' ))
							{
								printf("faile to find 'p' file is unreadable");
							  //return 101;
							}

				if  (!(in_img >> readbytechar) ||
						( readbytechar != '2' && readbytechar != '5'))
							{
								printf("faild to accepted file formates P5 or P2");
							//	return 102;
							}
			//skip commontz
				while(getline(in_img, linez))
						{
							if(!(skipChar(linez))) break;
						}

						//setup inport
				string_imgstrm << linez;

				if(!(string_imgstrm >> img_width_colums))
				{
					printf("error width\n");
				}


				if(!(string_imgstrm >> img_height_rows))
				{
					printf("error hightz\n");
				}

				if(img_width_colums <= 0 || img_height_rows <= 0)
				{
					printf("errohight/width not postive");
				}

				while(getline(in_img, linez))
				{
					if(!(skipChar(linez))) break;
				}

			string_imgstrm.str("");
			string_imgstrm.clear();

			string_imgstrm << linez;

			if(!(string_imgstrm >> maxPixelValue))
				{
					printf("could not read maxpixelz\n");
				}

			if(maxPixelValue < 0 || maxPixelValue > 255)
				{
					printf("could not read maxpixelz not proper formate\n");
				}

				image_area_pix = img_width_colums*img_height_rows;

	 		std::cout << "image area: " << image_area_pix <<std::endl;

			int row=0;
			 	while(row<img_height_rows+1)
				{
					getline(in_img, linez);
																				//	printf("loadingimage_data1\n");
					std::string temp_s;
						string_imgstrm.str("");
						string_imgstrm.clear();
						string_imgstrm <<linez;
						std::vector<int> b_imgArray2;

						for (int collom=0 ;collom<img_width_colums+1; collom++)
								{
								//	printf("loadingimage_data2\n");
						  	string_imgstrm>> temp_s;
								b_imgArray2.push_back(std::stoi(temp_s));
						  	}

							b_imgArray.push_back(b_imgArray2);
							row++;
						//		std::cout << b_imgArray[row][0] << std::endl;

			}
		 printf("Image_data_loaded to vector\n");
		 in_img.close();

																	//debugforimageloading
																	/*
												for (int c= 0; c < b_imgArray.size() ; c++)
												{
													for (int b = 0 ; b< b_imgArray[c].size(); b++)
												{ std::cout<< b_imgArray[c][b];
														}
													}
													*/
}


			void  image_Byte8::write_image(std::ofstream& out_img)
			{
					printf("writing Image");

					out_img << "P2" << ' ' <<
					img_width_colums << ' ' <<
					img_height_rows << ' ' <<
					maxPixelValue << '\n';

				//Write the contents of pixels to the output file
				for( int i = 0; i < img_height_rows; i++)
					{
				  	for (int j = 0; i < img_width_colums; j++){
								//Add a '\n' at the end of each row
				   	if(i % img_width_colums == 0 && i != 0) out_img << '\n';
			   		out_img << b_imgArray[i].at(j) << '\t';
							}
						}
					}


//	for (int i = 0; i<img_width_colums; i++)
//	{
 //   for (int j=0; j<img_height_rows; j++)
//			{

//		}}

/*

//	user_input_img_name[1] = '0';
//	out_stream.open(user_input_img_name, std::ios::binary
			//						| std::ios::out
			//					 	| std::ios::trunc);

			//	fiimgIn = fopen(user_input_img_name, "r");
			//	char	c = (char) fgetc(fiimgIn) != '\0';
						//printf("imagecc3\n");


//	int * b_imgArray = new int[img_width_colums + 1][img_height_rows+1];

//std::vector<int> temp_1d_array;S

void image_Byte8::read_image_to_matrex(std::ifstream &in_img)
{

	if (!in_img)

	{
		printf("eroror in imgloder fileread\n");
	}
int* img_byte_matrx = new int[image_area_pix+1];

}
	void load_img_tomatrx(std::ifstream &in_img)
	{
		in_img.read(byteArray, image_area_pix);


	}

	{
		uint8_t * byte_Array_pix = new uint8_t[image_size+1];

		byte_Array_pix[image_size] ='\0';


	}

	bool image_Byte8::iz_Binary_T_ASCI_F(std::ifstream &in_img)
		{
				if(readbytechar == '5') return true;
				else return false;
	}

*/
