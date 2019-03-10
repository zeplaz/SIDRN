


#ifndef HISTAGRAMZ_H
#define HISTAGRAMZ_H

//clibz
#include <string>
#include <ostream>
#include <vector>

class Histagramz{

  private :

  int type;
  int Num_binz;
  std::vector<uint32_t> vec_binz;

  public :

    inline  void set_type(int in_type)
      {type = in_type;}


    inline  int size_of_hista()
      {return (vec_binz.size());}

    inline  void insert_to_bin(int bin_in)
      {
          if (bin_in > vec_binz.size())
          {
            printf("error_bin is not avalble out of boundz\n");

          }
        vec_binz.at(bin_in) = +1;
      }


   inline  void create_empty_hista(int num_bucketz)
      { printf(" in createemptyyz\n");
        for (uint8_t i = 0; num_bucketz<i; i++)
            {vec_binz.push_back(0);}

      }

    inline void read_hista_cml_L()
     { printf(" in readhista\n" );
       std::vector<std::string> hista_str_symbz;

       for (int i =0; i< vec_binz.size(); i++)
         {         std::string tempstring;
                                tempstring = i + "|";
              hista_str_symbz.push_back(tempstring);

            for (uint32_t j = 0; j<vec_binz.at(i); j++)
                {
                  hista_str_symbz.at(i) =+ "#";
                }
         }

        std::cout << "Hisagram_cml_readsamp:" << std::endl
                  << "||__________________||" << std::endl;

                  for ( int k = 0; hista_str_symbz.size(); k++)
                      {
                        std::cout << hista_str_symbz.at(k) << std::endl;
                      }
       }

};
#endif
