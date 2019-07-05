
/*
//test for clock ultiz
->compilewith g++ -std=c++17 tst_clk_main.cpp -lpthread  -o clk_out

*/

#include "clock_utility.hpp"
#include <thread>

void threadFunc()
{
	int i = 0;
	while (i < 2)
	{
		// Print Thread ID and Counter i
		std::cout<<std::this_thread::get_id()<<" :: "<<i++<<std::endl;

		// Sleep this thread for 200 MilliSeconds
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
	}
}

int main(int argc, char* argv[])
{

  int clockvec_pos[10];

  clock_utility* start_new_clocksym = new clock_utility();

  clockvec_pos[0] = start_new_clocksym->start_new_dbl_clocksym();
  clockvec_pos[1] = start_new_clocksym->start_new_u64_clocksym();
  //start_new_clocksym->out_diffrence_double_now();
  //start_new_clocksym->out_diffrence_u64_now();

  std::thread th(&threadFunc);
  th.join();

  clockvec_pos[3] = start_new_clocksym-> start_new_u64_clocksym();
  clockvec_pos[2] = start_new_clocksym->start_new_dbl_clocksym();

  start_new_clocksym->out_diffrence_u64_now();
  start_new_clocksym->out_diffrence_double_now();


return 0;
}
