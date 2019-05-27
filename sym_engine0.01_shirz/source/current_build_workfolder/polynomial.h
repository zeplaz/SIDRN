
//polynomial.h


#include <cstdarg>
#include <math.h>       /* pow */

    //  template <typename cons_type>
  //  enum Ind_name{ _error=-1, x=1,_y=2, _z=3,_alpha=4};

      struct Indeterminate
      {
        public :

        int indeterminate_name;
        auto* passed_value;

        //  const cons_type  constan_var;

        Indeterminate()
        {
            indeterminate_name =_x;
        }

        Indeterminate(int namedvar)
        {
          indeterminate_name =  namedvar;
        }


      auto operator()(auto* paz_val)
      {
          passed_value =paz_val;
          return *this;
      }

      inline  void set_error()
      {
        indeterminate_name =-1;
      }

      inline void set_inter_name(int nename)
      {
        indeterminate_name=nename;
      }

      friend bool operator ==(const  Indeterminate &in1, const Indeterminate &in2);
      friend bool operator !=(const  Indeterminate &in1, const Indeterminate &in2);

      };

      bool operator == (const  Indeterminate &in1, const Indeterminate &in2)
      {
        return ( in1.indeterminate_name ==in2.indeterminate_name  );
      }

       bool operator !=(const  Indeterminate &in1, const Indeterminate &in2);
      {
        return!(Indeterminate==Indeterminate)
      }



      template<typename nomi_type>
      struct p_nomi{

          nomi_type coefficient;
        //  int degree;
          Indeterminate inter_name;
          nomi_type power;

          p_nomi()
          p_nomi(int ind_name, auto powr,auto coefficient)

          auto oprator()(auto in_value)
          {
             auto inder_part=pow(in_value,power);
            return (this->coefficient*inder_part)
          }

        };

        p_nomi operator+(const p_nomi &a, const p_nomi &b)
        {
            p_nomi temp_pn;
            if(a->power != b->power)
            {
              cerr >> "degree is not equail no addtion possable";
                temp_pn.power = -1;
                temp_pn.inter_name.set_error();
              return temp_pn;
            }
            if(a->inter_name != b->inter_name)
              {
                cerr >> "nonmatching intermidary is not equail no addtion possable";
                temp_pn.power = -1;
                temp_pn.inter_name.set_error();
                  return temp_pn;
              }

              temp_pn = a;
              temp_pn.coefficient=(a->coefficient+b->coefficient);
              return temp_pn;
            }
            // thiking about changing this so 2x*4y^2 =aintmdary 8(xy^2)aka pulling out coffienz
            //to thus do manluation on the new algebic expressooin
            p_nomi operator*(const p_nomi &a, const p_nomi &b)
            {
                p_nomi temp_pn;
                if(a.inter_name != b.inter_name)
                {
                    cerr >> "nonmatching intermidary is not equail no addtion possable";
                    temp_pn.power = -1;
                    temp_pn.inter_name.set_error();
                      return temp_pn;
                }

                temp_pn =a;
                temp_pn.power =+b.power;
                temp_pn.coefficient =*b.coefficient;
              return temp_pn;
          }

          p_nomi p_nomi:: operator+() const;
          p_nomi p_nomi:: operator+(const p_nomi& a);
          {
            a->
          }

          template <int...power,auto...cof>
          struct p_nomi









          p_nomi p_nomi:: operator-() const;
          p_nomi p_nomi:: operator-(const p_nomi &a);
          p_nomi p_nomi:: operator-(const p_nomi &a, const p_nomi &b);

          p_nomi p_nomi:: operator*(const p_nomi &b) const;
          p_nomi p_nomi:: operator*(const p_nomi &a, const p_nomi &b);


          bool p_nomi::operator ==(const p_nomi &b) const;
          bool p_nomi::operator !=(const p_nomi &b) const;


          p_nomi& p_nomi::operator =(const p_nomi& b);
          p_nomi& p_nomi::operator +=(const p_nomi& b);
          p_nomi& p_nomi::operator -=(const p_nomi& b);




        };







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








      typedef struct polynomal
      {


        parameter_constant(paramz..)
std::va_list varblist;
        for (i=0; )

    };

        polynomal(auto...p)
        {
//testbvrbc
        }



class polynomial
{
  private :
  int degree;
  std::touple<parameter_constant,Coefficient,int> polynomi;
  std::stack<p_nomi> polnymstack;


public :



constexpr auto operator()(auto...p,auto..cof){return polynomal(p...,auto...cof);}


sf::Vector2f polynomal() {
sf::Vector2f b = {};
std::stack<int> values = {values.push(power...)};
std::stack<auto> values = {values.push(cof...)};


  std::for_each(values.begin(), values.end(), [&](int power)
  {b[n]

    ;});
  return b;



  sf::Vector2f operator()(auto...p)
  {
      for p..
     return sf::Vector2f(x,y);
  }
}
std::array<bool, SIZE>


};

          polynomal operator+(const Coefficient& co2)
          {

          }

      };


class curve_handler()
{
  private :

};
