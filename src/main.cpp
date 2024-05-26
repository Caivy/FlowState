#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>

int main (int argc, char *argv[]) {
  std::cout << "\n**************************\n";
  std::cout << "1. Start | 2. Restart | 3. End";
  std::cout << "\n**************************\n";

  int input = 0;
  std::cin >> input;

  switch (input) {
    { case 1:
      auto u_time = 0;
      std::cout << "\nInput Amount of Times(seconds) :\n";
      std::cin >> u_time;

      auto start = std::chrono::steady_clock::now();
      auto end = start + std::chrono::seconds(u_time);

      while (std::chrono::steady_clock::now() <= end) {
        auto current_time = std::chrono::steady_clock::now();
        auto elapsed_seconds = std::chrono::duration<double>(current_time - start);
        system("clear");
        std::cout << "\n**************************\n";
        std::cout << "Seconds : " << (int)elapsed_seconds.count() << " s\n";
        std::cout << "\n**************************\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
      };
      break; }
    case 2:
      std::cout << "To Be Implemented";
      break;
    case 3:
      break;
    default:
      std::cout << "\n Please Enter a Valid Commands";
      break;
  }


  return 0;
}


