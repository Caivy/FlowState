# Features
- A Simple time counting from user specify of hr/min/sec display in the middle.
- Keyboarding and Mouse Integration ( < Space > to stop the timer / < B > to go to break ?)
- Colors and UI

# Logs

18:07 Finish setting up the Project Environment and integrate Cmake-Nvim with Neovim.
The Terminal Pop up from the bottom feel kinda weird but i will get used to it.

22:24 Setup Debug with nvim-dap and CMake-Nvim using gdb instead of clangd or codelldb due to issue with the two mentions. So have to use gdb as it's easier.
So the first issue that make it work with the plugin CMake-Nvim is that whatever i specify in the CMake-dap i also need to specify that in Nvim-Dap also.

Saturday, May 25, 07:57 Implemented a simple timer where user can specify the amount of sec then the program sleep that amount and using the chrono library we start the clock before the sleep and end the clock after we sleep
Then we use the code below to count the time in durations.

```sh
const std::chrono::duration<double> elapsed_seconds{end - start};
```

8:13 Now take all of that code and put it into a function called timer where the function take in user_time in sec then do the above and return std::chrono::duration<double> type.
When invoke the function i have to before I have to create auto variable first then cout it using that variable then I realize that stupid and just invoke the function in the cout and no need that bullshit LMAO.


May, 26, 14:25 I kinda figure out how to print the second ticking by but it's very messy and it's take alot of cpu resource too although it's an improvement as before it's way higher like 60% or sth like that.

this is a bunch of code i tried :

````cpp
for (int i = 0; i <= u_time; i++) {
}

int user_time = 0;

// Taking the user input in secs
std::cout << "Start Timer: ";
std::cin >> user_time;

for (int i = 0; i <= user_time; i++) {
  std::cout << "\rTimers(s): " << i << "s" << std::flush;
  std::this_thread::sleep_for(std::chrono::seconds(user_time));
  // std::cout << "Current Seconds : " << i << "\n";
}

std::cout << std::endl;

auto start_time = std::chrono::steady_clock::now();
auto end_time = start_time + std::chrono::seconds(user_time);

// Countdown timer without delay
while (std::chrono::steady_clock::now() <= end_time) {
  auto current_time = std::chrono::steady_clock::now();
  auto elapsed_seconds = std::chrono::duration<double>(current_time - start_time);

  std::cout << "\rTimer: " << (int)elapsed_seconds.count() << "s" ;
}
std::cout << "\rTimer: " << user_time << "s" << std::flush;
std::cout << std::endl;
std::cout << "Timer completed!" << std::endl;

// Now we just print the time that user sleep
std::cout << timer_in_seconds(user_time).count() << '\n';
```

Now by adding a sleep_for timer to a 10 milliseconds i reduce the cpu usage to only 10% ish now instead of 40%.

I really need to improve the performance of the code and also find a more efficient way to implement the counter and also make it useable in different section of code like a function or class instead of only in main.
