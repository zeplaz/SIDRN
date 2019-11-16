

#pragma once

#include <iostream>
#include <math.h>       /* pow */
#include <ratio>

#include "Indeterminate.h"
/*
template<
    std::intmax_t Num,
    std::intmax_t Denom = 1
>
auto ratio_ = std::ratio<Num, Denom>{};*/
        template<typename nomi_type>
        struct p_nomi
        {
          nomi_type coefficient;
          //  int degree;
            Indeterminate<nomi_type> inter_name;
            //typedef std::ratio<Num,Denom> power;
            int* power;
            //p_nomi()
            p_nomi(int ind_name, auto powr,auto in_cof)
            {
              inter_name.set_inter_name(ind_name);
            //  power = powr;
              coefficient= in_cof;
              }

                p_nomi(Indeterminate<nomi_type> ind_name, int* powr,auto in_cof)
                {
                  inter_name =ind_name;
                 power =powr;
                coefficient  =in_cof;

                }
            inline int return_degree() const
            {
              return(power[0]);
            }
            friend p_nomi<nomi_type> operator+( const p_nomi<nomi_type> &a, const p_nomi<nomi_type> &b);
            friend p_nomi<nomi_type> operator*(const p_nomi<nomi_type> &a, const p_nomi<nomi_type> &b);
            friend p_nomi<nomi_type> operator-(const p_nomi<nomi_type> &a, const p_nomi<nomi_type> &b);
            //ovrloaded opratorz

              // thiking about changing this so 2x*4y^2 =aintmdary 8(xy^2)aka pulling out coffienz
              //to thus do manluation on the new algebic expressooin
              nomi_type operator()(nomi_type in_value)
              {
               auto inder_part=pow(in_value,power[0]/power[1]);

                return (this->coefficient*inder_part);
              }
        };

template<typename nomi_type>
        p_nomi<nomi_type> operator+( p_nomi<nomi_type> &a,  p_nomi<nomi_type> &b)
        {
            p_nomi<nomi_type> temp_pn;
            if(a.power[0] != b.power[0])
            {
              std::cerr << "degree is not equail no addtion possable";
                //temp_pn.power = -1;
                temp_pn.inter_name.set_error();
              return temp_pn;
            }
            if(a.inter_name != b.inter_name)
              {
                  std::cerr << "nonmatching intermidary is not equail no addtion possable";
                //temp_pn.power = -1;
                temp_pn.inter_name.set_error();
                  return temp_pn;
              }

              temp_pn = a;
              temp_pn.coefficient=(a.coefficient+b.coefficient);
              return temp_pn;
            }

            template<typename nomi_type>
                  p_nomi<nomi_type> operator-(const p_nomi<nomi_type> &a, const p_nomi<nomi_type> &b)
                  {
                    p_nomi<nomi_type> temp_pn;
                    if(a.power[0] != b.power[0])
                    {
                        std::cerr << "degree is not equail no addtion possable";
                        //temp_pn.power = -1;
                        temp_pn.inter_name.set_error();
                      return temp_pn;
                    }
                    if(a.inter_name != b.inter_name)
                      {
                          std::cerr << "nonmatching intermidary is not equail no addtion possable";
                      //  temp_pn.power = -1;
                        temp_pn.inter_name.set_error();
                          return temp_pn;
                      }

                      temp_pn = a;
                      temp_pn.coefficient=(a.coefficient-b.coefficient);
                      return temp_pn;
                  }



template<typename nomi_type>
        p_nomi<nomi_type> operator*(const p_nomi<nomi_type> &a, const p_nomi<nomi_type> &b)
        {
            p_nomi<nomi_type> temp_pn;
            if(a.inter_name != b.inter_name)
            {
                  std::cerr << "nonmatching intermidary is not equail no addtion possable";
                //temp_pn.power = -1;
                temp_pn.inter_name.set_error();
                  return temp_pn;
            }

            temp_pn =a;
          //  std::ratio_add <temp_pn.power,b.power> ;
            temp_pn.coefficient =*b.coefficient;
          return temp_pn;
      }


            /* p_nomi p_nomi:: operator+() const;
            p_nomi p_nomi:: operator+(const p_nomi& a);
            {
              a->
            }

            //template <int...power,auto...cof>
          //  struct p_nomi


          //  p_nomi p_nomi:: operator-() const;
          //  p_nomi p_nomi:: operator-(const p_nomi &a);
          //  p_nomi p_nomi:: operator-(const p_nomi &a, const p_nomi &b);

          //  p_nomi p_nomi:: operator*(const p_nomi &b) const;
        //    p_nomi p_nomi:: operator*(const p_nomi &a, const p_nomi &b);


          //  bool p_nomi::operator ==(const p_nomi &b) const;
        //    bool p_nomi::operator !=(const p_nomi &b) const;


          //  p_nomi& p_nomi::operator =(const p_nomi& b);
        //    p_nomi& p_nomi::operator +=(const p_nomi& b);
        //    p_nomi& p_nomi::operator -=(const p_nomi& b);



            */
