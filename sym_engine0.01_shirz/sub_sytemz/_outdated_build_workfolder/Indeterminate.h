//nobasictz
#pragma once



    //  template <typename cons_type>
namespace polyz{
enum Ind_name{ _error=-1, _x=1,_y=2, _z=3,_alpha=4};
}


template<typename ind_type>
      struct Indeterminate
      {

        int indeterminate_name;
        ind_type passed_value;

//template<typename ind_type>
        Indeterminate()
        {
            indeterminate_name =polyz::_x;
            passed_value= 0;
        }

        Indeterminate(int namedvar)
        {
          indeterminate_name =  namedvar;
        }

        //  const cons_type  constan_var;
        inline  void set_error()
        {
          indeterminate_name =-1;
        }

      auto operator()(auto paz_val)
      {
          passed_value =paz_val;
          return *this;
      }


      inline void set_inter_name(int nename)
      {
        indeterminate_name=nename;
      }

      friend bool operator ==(const  Indeterminate<ind_type> &in1, const Indeterminate<ind_type> &in2);
      friend bool operator !=(const  Indeterminate<ind_type> &in1, const Indeterminate<ind_type> &in2);

      };

      template<typename ind_type>
      bool operator == (const  Indeterminate<ind_type> &in1, const Indeterminate<ind_type> &in2)
      {
        return ( in1.indeterminate_name ==in2.indeterminate_name  );
      }

      template<typename ind_type>
       bool operator !=(const  Indeterminate<ind_type> &in1, const Indeterminate<ind_type> &in2)
      {
        return!(in1==in2);
      }
