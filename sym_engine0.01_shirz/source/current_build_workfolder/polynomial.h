
//polynomial.h
#pragma once


#include <cstdarg>//going to be used to constuct large polyz on the fly
#include <iostream>
#include <math.h>       /* pow */
#include <stack>
#include <ratio>
#include "Indeterminate.h"
#include "p_nomi.h"
    //  template <typename cons_type>
  //  enum Ind_name{ _error=-1, x=1,_y=2, _z=3,_alpha=4};



template<nametype base_type>
  class polynomial
  {
    private :
    int degree;

    //  std::touple<Indeterminate,Coefficient,int> polynomi;
    std::stack<p_nomi<base_type>> polnymstack;

    public :

    void add_polni( int var_name, std::ratio<base_type,base_type> _power,auto coeffent )
    {
      if(_power::num > degree)
      {
        degree =_power::num;
      }

      p_nomi new_pli(var_name,_power,coeffent);
      polnymstack.push(new_pli);
    }

    void* solutionval(auto in_var)
    {
      if(polnymstack.size()!=0)
      { p_nomi<base_type> temp_poli = polnymstack.peek();
      for (i=1; i<polnymstack.size(); i++ )
      {
        auto solution =+temp_poli(in_var);
        polnymstack.pop();
        temp_poli = polnymstack.peek();
      }
      return solution;
      }
      return nullptr;
    }

  constexpr auto operator()(auto...p,auto..cof){return polynomal(p...,auto...cof);}
  polynomal polynomal() {

  std::stack<auto> values = {values.push(power...)};
  std::stack<auto> values = {values.push(cof...)};


    std::for_each(values.begin(), values.end(), [&](int power)
    {b[n]

      ;});
    return b;


    polynomal(int num_polyz, paramz..)
  {  std::va_list varblist;
    for (i=0; i<num_polyz i++ )
    {
      std::va_start(varblist,num_polyz)
      p_nomi  temp_poiln (varblist,p_nomi);
    if(temp_poiln. >)  
        polnymstack.push
    }
  }
};



    sf::Vector2f operator()(auto...p)
    {
        for p..
       return sf::Vector2f(x,y);
    }
  }
  std::array<bool, SIZE>


  };

  //sf::Vector2f polynomal() {
//  sf::Vector2f b = {};





                constexpr auto operator()(auto...p){return polynomal(p...);}


                    sf::Vector2f operator()(auto...p)
                    {
                        for p..
                       return sf::Vector2f(x,y);
                    }

                    template <int... A>

                      sf::Vector2f func() {
                      sf::Vector2f b = {};
                        auto values = {A...};

                        std::for_each(values.begin(), values.end(), [&](int n)
                        {b[n]

                          ;});
                        return b;
                    }
                    std::array<bool, SIZE>


                  polynomal operator+(const Coefficient& co2)
                  {

                  }

              };

                    typedef struct polynomal
                    {




                      polynomal(auto...p)
                      {
              //testbvrbc
                      }

                      template <typename coe_type>
                       struct Coefficient{
                           coe_type coeff_var;

                        //   + - * /

                           Coefficient operator+(const Coefficient& co2)
                           {
                             Coefficient.coeff_var = this->coeff_var+co2.coeff_var;
                           }
                        //   Coefficient operator+(const Coefficient&,const Coefficient&);

                      };
                            template <typename cons_type>
                            struct parameter_constant
                            {
                              const cons_type  constan_var;
                            };



          polynomal operator+(const Coefficient& co2)
          {

          }

      };

      typedef struct polynomal
      {
        int numberofterms;
        std::touple<Indeterminate,Coefficient,double> polynomi;
        std::stack<polynomi> polnymstack;

        polynomal(auto...p)
        {

        }
