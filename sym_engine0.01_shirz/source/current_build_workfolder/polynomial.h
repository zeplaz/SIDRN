
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



template<typename base_type>
  class polynomial
  {
    private :
    int degree;

    //  std::touple<Indeterminate,Coefficient,int> polynomi;
    std::stack<p_nomi<base_type>> polnymstack;

    public :

    polynomial<base_type>(int num_polyz,...)
  {  va_list varblist;
    for (int i=0; i <num_polyz; i++ )
    { //int current_degree;
      va_start(varblist,num_polyz);
      p_nomi<base_type> temp_poiln =  va_arg(varblist,p_nomi<base_type>);

    if(temp_poiln.return_degree() > degree )
        {
          degree =temp_poiln.return_degree();
        }
        polnymstack.push(temp_poiln);
    }
  }

    void add_polni( int var_name, int* _power,auto coeffent )
    {
      if(_power[0]> degree)
      {
        degree =_power[0];
      }

      p_nomi<base_type> new_pli(var_name,_power,coeffent);
      polnymstack.push(new_pli);
    }

    base_type solutionval(auto in_var)
    {
      if(polnymstack.size()!=0)
      { p_nomi<base_type> temp_poli = polnymstack.top();

          auto solution =temp_poli(in_var);
      for (int i=1; i<polnymstack.size(); i++ )
      {

        polnymstack.pop();
        temp_poli = polnymstack.top();
        solution =+temp_poli(in_var);
      }
      return solution;

      }
      return '\n';
    }
/*
  constexpr auto operator()(auto...power,auto..cof){return polynomal(power...,auto...cof);}
  polynomal polynomal() {

  std::stack<auto> stk_powerz = {stk_powerz.push(power...)};
  std::stack<auto> stk_coeff = {stk_coeff.push(cof...)};

    std::cout<< "You Have utilized the polymofpic legth, you must now assign Indetermintz" << '\n'
            << "you must now give the inderment a name" << '\n';
              for

                  }
    //std::for_each(values.begin(), values.end(), [&](int power)
  //  {b[n]

      //;});
    //return b;
*/

};

/*

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
*/
