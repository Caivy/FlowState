#include <iostream>
#include <chrono>
#include <unistd.h>
#include <thread>

using namespace std;
using namespace std::chrono_literals;

// void timer(time_duration) {
//
// }

int main (int argc, char *argv[]) {
  int user_time = 0;

  // Taking the user input in secs
  std::cout << "Start Timer: ";
  cin >> user_time;

  // Now we start the monotonic clock that will never be adjusted and count it as start
  const auto start = std::chrono::steady_clock::now();

  // we use the sleep function to sleep the allocated time by user
  sleep(user_time);

  // Now we end the monotonic clock and count it as end
  const auto end{std::chrono::steady_clock::now()};

  // This is to output the durations (secs) of the end and start;
  const std::chrono::duration<double> elapsed_seconds{end - start};

  // Now we just print the time that user sleep
  std::cout << elapsed_seconds.count() << '\n';

  return 0;
}


