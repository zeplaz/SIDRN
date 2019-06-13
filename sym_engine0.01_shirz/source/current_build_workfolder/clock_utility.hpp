
#include <chrono>

#define steady 0U
#define high_rez 1U
#define sytm 2U

class clock_utility
{
  private :
    std::chrono::steady_clock::time_point steady_clock_time_point_str;
    std::chrono::high_resolution_clock::time_point high_res_timePoint_srt;
    std::chrono::system_clock::time_point sytm_time_point_srt;

    std::chrono::duration<uint64_t, std::milli> check_point_64;


    std::chrono::steady_clock::time_point steady_clock_time_chk;
    std::chrono::high_resolution_clock::time_point high_res_timePoint_chk;
    std::chrono::system_clock::time_point sytm_time_point_srt_chk;
  public :

   void activate_timepointz()
   {
     steady_clock_time_point_str = std::chrono::steady_clock::now();
     high_res_timePoint_srt      = std::chrono::high_resolution_clock::now();
     sytm_time_point_srt         = std::chrono::system_clock::now();

   }


/*
   uint64_t time_fromStart(uint8_t clkrez)
  {   using cast = std::chrono::duration<uint64_t>;
      uint64_t duration_since_start=0;

     switch  (clkrez)
       {

         case steady :
                                    //std::chrono::duration_cast< cast >(now).count();
           duration_since_start = steady_clock_time_point_str-std::chrono::steady_clock::now();
           break;

         case  high_rez :
          duration_since_start = high_res_timePoint_srt-std::chrono::high_resolution_clock::now();
          break;

         case sytm :
          duration_since_start = sytm_time_point_srt-std::chrono::system_clock::now();
          break;
        default : printf("invaild clock type, reutrned zero\n");
        }
   return duration_since_start;
  }
  */

  void set_checkpoint_now(uint8_t clkrez)
  {
   switch  (clkrez)
   {
     case steady :
      steady_clock_time_chk = std::chrono::steady_clock::now();
      break;

     case  high_rez :
      high_res_timePoint_chk = std::chrono::high_resolution_clock::now();
      break;

     case sytm :
      sytm_time_point_srt_chk = std::chrono::system_clock::now();
      break;

     default : printf(" clock Type invaild.\n");

    }
   }

   void set_checkpoint(std::chrono::duration<uint64_t, std::milli> chkp)
   {
      check_point_64 = chkp;
   }


/*

  bool duration_met(std::chrono::duration<uint64_t, std::milli> dt, uint8_t clock_type)
  { //using cast = std::chrono::duration<uint64_t>;
    bool met = false;
    //std::chrono::duration<uint64_t, std::milli> curtime;

   switch  (clock_type)
   {
     case steady :
     //std::chrono::duration<uint64_t, std::milli>
    // using cast = std::chrono::duration<std::uint64_t>;
    //
    // std::uint64_t ticks = std::chrono::duration_cast< cast >(nowst).count();
    //  curtime = std::chrono::duration_cast< cast >(now).count();

      auto curtime = std::chrono::steady_clock::now();
        if(dt.count()>(steady_clock_time_chk - curtime))
        {
          met= true;
          steady_clock_time_chk=curtime;
        }
       break;

     case  high_rez :
    //  std::chrono::high_resolution_clock::time_point nowhr = std::chrono::high_resolution_clock::now();
    //  curtime = std::chrono::duration_cast< cast >(now).count();
        auto curtime = std::chrono::high_resolution_clock::now();
      if(dt>(high_res_timePoint_chk -curtime))
       {
        met= true;
        high_res_timePoint_chk=curtime;
       }
      break;

     case sytm :
     auto curtime = std::chrono::system_clock::now();
        //std::chrono::system_clock::time_point nowsc = std::chrono::system_clock::now();
      //  curtime = std::chrono::duration_cast<cast>(now).count();
      if(dt>(sytm_time_point_srt_chk -curtime))
       {
        met= true;
        sytm_time_point_srt_chk=curtime;
       }
      break;

     default : printf("invalided time type reutn false\n");

    }
  return met;
  }
*/
};
