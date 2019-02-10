//Data_StreamLOader.h

#define sym_data_stram Data_StreamLOader::Instance()

 class Data_StreamLOader
 {

     private:

       Data_StreamLOader(const Sym_Map&);
       Data_StreamLOader& operator = (const Sym_Map&);

      public :

        static Data_StreamLOader* Instance();

        Data_StreamLOader(){}; // deal with id latr.
        ~Data_StreamLOader(){};

      bool   iz_Binary_T_ASCI_F(std::ifstream &in_img);

        Image_Procees_inlizar();

 }

 //Data_StreamLOader::Data_StreamLOader();

  bool Data_StreamLOader::iz_Binary_T_ASCI_F(std::ifstream &in_img)

    {
        uint8_t readbytechar = ' ';

        if  (!(in_img >> readbytechar) || ( readbytechar != 'P' ))
          {
              printf("faile to find 'p' file is unreadable");
              return 101;
      	  }


        if  (!(inFile >> readChar) ||
          ( readChar != '2' && readChar != '5'))
          {
            printf("faild to accepted file formates P5 or P2")
            return 102;
          }

        if(readChar == '5') return true;

        else return false;

}

void Data_StreamLOader::Image_Procees_inlizar(std::ifstream& in_img,
                      std::ofstream& out_stream)
{

    printf("please Enter file Name:\n");

    char[50] user_input_img_name ="";

    std::cin.getline(user_input_img_name,50);


      in_img.open(user_input_img_name, ios::binary | ios::in);



     user_input_img_name[1] = '0';

      out_stream.open(user_input_img_name, ios::binary
                      | ios::out
                      | ios::trunc);


    }
