

using u64_millis = duration<uint64_t, milli>;
static std::chrono::time_point<std::chrono::high_resolution_clock, u64_millis> u64_to_time(uint64_t timestamp)
{
  return time_point<std::chrono::high_resolution_clock, u64_millis>{u64_millis{timestamp}};
}
//if your epoch is different than the one for system_clock, this would be the place to fix it. It would probably also work to use milliseconds instead of u64_millis, but the representation type for milliseconds isn't explicitly defined and doing it the above way ensures that the types match up correctly.
//Now, the code that you posted becomes something like:
{
  auto now = system_clock::now();
  bool is_old = now - u64_to_time(data_holder->getTimestamp()) > minutes{2};
  auto value = now;
  while (now - u64_to_time(data_holder->getTimestamp()) < seconds{80}
  && now - value < seconds{80}) {
  this_thread::sleep_for(milliseconds{100});
  now = system_clock::now();
}



  uint64_t uptime = 0;
  using time_point = std::chrono::system_clock::time_point;
time_point uptime_timepoint{std::chrono::duration_cast<time_point::duration>(std::chrono::nanoseconds(uptime))};
std::time_t t = std::chrono::system_clock::to_time_t(timepoint_uptime);
