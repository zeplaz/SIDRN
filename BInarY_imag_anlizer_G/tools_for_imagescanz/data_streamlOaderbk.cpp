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
