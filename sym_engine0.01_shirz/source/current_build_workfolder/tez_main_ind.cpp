


#include <iostream>
#include <ratio>
#include "Indeterminate.h"
#include "p_nomi.h"


using namespace polyz;

int main(int argc, char* argv[])
{
Indeterminate<double> newidz;
std::ratio<3,1> cube_deg;
double cof_=3;

newidz.set_inter_name(_y);
p_nomi test_sing_poli(newidz,cube_deg,cof_);
//  Indeterminate<double>  newidz(_x);



 printf("shz\n");
return 0;
}
