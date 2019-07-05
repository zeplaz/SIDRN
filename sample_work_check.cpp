

template <class comp_type>

class Sym_physics_comp_Mrk1001 ()
{

std::vector<>

collition_sytm_basic




};

sf::CircleShape user_circle;

user_loc(sf::Vector2f positionxy, )


bool collition_sytm_disc_pathg(unit* agt);
if (sqrt(pow()))


struc Pixel_Perfect_Collision_comp
{
test_colltion(unit* unita, unit* b)
{ double col_south,col_north,col_west,col_east;

col_south= std::min( south_point)
}

};


bool collition_sytm_Sphrical_3d(double)
{
/*
(x-h1)^2 +(y-k1)^2 + (z-l1)^2
= r1^2
(x-h2)^2 +(y-k2)^2 + (z-l2)^2
= r2^2

if (h2-h1)^2
+(k2-k1)^2
+ (l2-l1)^2 <= (r1+r2)^2
return true;
*/


double h1,h2,htotal;
double k1,k2,ktotal;
double l1,l2, ltotal;

double r1,r2,r_sqtroot,rtotal;

//r2*=r2;
//r1*=r1;

r_sqtroot= r2*r2 +r1*r1;
r_sqtroot = sqrt(r_sqtroot);

htotal =h2-h1;
ktotal= k2-k1;
ltotal = k2-k2;

htotal *=htotal;
ktotal  *= ktotal;
ltotal  *= ltotal;

rtotal= htotal +ktotal+ltotal;
rtotal= sqrt(rtotal);

  if(rtotal <= r_sqtroot)
    {return true;}
  else
  {return false;}


  };
