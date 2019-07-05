

  #pragma once

  #include <chrono>
  #include <vector>
  #include <tuple>
  #include <iostream>

  #define steady 0U
  #define high_rez 1U
  #define sytm 2U


// settup of need glob defypez
  using u64_millis = std::chrono::duration<uint64_t, std::milli>;

  typedef std::chrono::high_resolution_clock            hr_clock;
  typedef std::chrono::time_point<hr_clock, u64_millis> t_point_hr_u64_mili;

// static helpers



 static t_point_hr_u64_mili u64_to_time(uint64_t timestamp)
  {
   return t_point_hr_u64_mili{u64_millis{timestamp}};
  }


  static t_point_hr_u64_mili new_tp_u64mili()
   {
    t_point_hr_u64_mili tp_now =
    std::chrono::time_point_cast<u64_millis>(hr_clock::now());

    return tp_now;
   }



  class clock_utility
  {
    private :
     typedef std::tuple<hr_clock*,t_point_hr_u64_mili> clk_prt_w_u64Start;
     typedef std::tuple<hr_clock*,double>              clock_prt_wdoubleStart;

    private :
     static int posz_id_clck_dbl;
     static int posz_id_clck_u64;

     std::chrono::duration<double, std::milli>  mili_duble_dur;
     std::chrono::duration<float, std::chrono::milliseconds::period> mili_float_dur;

     std::vector<clock_prt_wdoubleStart> clock_doublearray_vec;
     std::vector<clk_prt_w_u64Start> clock_u64array_vec;

      //debu testz
      double test_1;
      double test_2;
      t_point_hr_u64_mili test_3;
      t_point_hr_u64_mili test_4;

     public :
      clock_utility() = default;
      ~clock_utility()
       {
        for(size_t i = 0; i< clock_u64array_vec.size(); i++)
         {
          clk_prt_w_u64Start* tmrp_tp =&clock_u64array_vec.at(i);
          delete std::get<0>(*tmrp_tp);
         }

         for(size_t i = 0; i< clock_doublearray_vec.size(); i++)
          {
           clock_prt_wdoubleStart* tmrp_tp =&clock_doublearray_vec.at(i);
           delete std::get<0>(*tmrp_tp);
          }
        }

       int start_new_u64_clocksym()
        {
          hr_clock* prt_newdbl_clock = new hr_clock();
          clock_u64array_vec.push_back(std::make_tuple(prt_newdbl_clock,new_tp_u64mili()));
          posz_id_clck_u64++;
          return posz_id_clck_u64;
        }

        int start_new_dbl_clocksym()
        {
          hr_clock* prt_newdbl_clock = new hr_clock();

          auto  current_new_time = prt_newdbl_clock->now();
          auto   dur_in_milz     =  std::chrono::duration<double, std::milli>(current_new_time.time_since_epoch());
          double dbl_current_time =  dur_in_milz.count();

          clock_doublearray_vec.push_back(std::make_tuple(prt_newdbl_clock, dbl_current_time));
          posz_id_clck_dbl++;
          return posz_id_clck_dbl;
        }

        void out_diffrence_double_now()
        {
          for(size_t i =0; i < clock_doublearray_vec.size(); i++)
          {
             clock_prt_wdoubleStart* prt_cur =  & clock_doublearray_vec.at(i);
              hr_clock*  prt_hi_res_clk = std::get<0>(*prt_cur);

            // mili_duble_dur  dif =  (-prt_hi_res_clk->now())
            std::cout << "-----OUT_CLOCKdoubleINFO------" << '\n'
                      << "START DOUBLE:" << std::get<1>(*prt_cur) <<  '\n' << '\n';

                        if(clock_doublearray_vec.size() >= 2)
                        {
                          if(i==0)
                          {
                            test_1 =std::get<1>(*prt_cur);
                          }
                          else
                          {
                            test_2 =std::get<1>(*prt_cur);
                          }
                          if(i>0)
                          {
                            double dif  =  test_1-test_2;
                            std::cout << "DIFRENTdoublez: " << dif << '\n' <<'\n';
                          }


                        }
          }
        }


        void out_diffrence_u64_now()
          {
           for(size_t i =0; i < clock_u64array_vec.size(); i++)
            {
              clk_prt_w_u64Start* prt_cur = & clock_u64array_vec.at(i);
              hr_clock*  prt_hi_res_clk = std::get<0>(*prt_cur);


                      //  << "START u64z:" << std::get<1>(*prt_cur) <<  '\n'

                        if(clock_u64array_vec.size() >= 2)
                        {  std::cout << "-----OUT_CLKu64INFO------" << '\n';
                          if(i==0)
                          {
                            test_3 =std::get<1>(*prt_cur);
                          }
                          else
                          {
                            test_4 =std::get<1>(*prt_cur);
                          }
                          if(i>0)
                          {
                            u64_millis dif_dur=  u64_millis (test_3-test_4);
                            std::cout << "DIFRZ TIMEPOT TO DURAZK: " <<dif_dur.count()
                            << '\n' <<'\n';
                          }

                        }

            }}


        bool trigger_double()
        {
            using dbl_mili_sec = std::chrono::duration<double, std::chrono::milliseconds::period>;
            //  clock_prt_wStart.at(0);
            //deltaTime = std::chrono::duration_cast<dbl_mili_sec>(prt_newdbl_clock->now() - ).count();
          return true;
        }

    };




          //  = chrono::duration_cast<double, std::milli>(now.time_since_epoch()).count();

            // A floating point milliseconds type
              //using FpMilliseconds =
  /*
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
