


#include <iostream>
#include <ratio>
#include "Indeterminate.h"
#include "p_nomi.h"
#include "polynomial.h"

using namespace polyz;

int main(int argc, char* argv[])
{
Indeterminate<double> newidz;
int cube_deg[2];
cube_deg[0]=3;
cube_deg[1]=2;
double cof_=3;

double somevalue=0;

newidz.set_inter_name(_y);
p_nomi<double> test_sing_poli(newidz,cube_deg,cof_);
polynomial<double> new_polynomalz(1,test_sing_poli);


//  Indeterminate<double>  newidz(_x);
for (int i=0; i<30; i++)
{
  std::cout << "the soltion to value:" << somevalue << " to polyz iz: " << new_polynomalz.solutionval(somevalue) << '\n';
  somevalue =somevalue+1;
}
 printf("shz\n");
return 0;
}
