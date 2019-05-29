


#include <iostream>
#include <ratio>
#include "Indeterminate.h"
#include "p_nomi_withoutratio.h"


using namespace polyz;

int main(int argc, char* argv[])
{
Indeterminate<double> newidz;
int cube_deg[2];
cube_deg[0]=3;
cube_deg[1]=1;
double cof_=3;


newidz.set_inter_name(_y);
p_nomi<double> test_sing_poli(newidz,cube_deg,cof_);
//  Indeterminate<double>  newidz(_x);



 printf("shz\n");
return 0;
}
