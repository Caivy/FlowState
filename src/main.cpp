#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>


int main(int argc, char *argv[]) {
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "Failed to initialize SDL_mixer: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    const char* audioPath = "/home/zpay/Music/alarm.mp3";
    Mix_Music* audio = Mix_LoadMUS(audioPath);
    if (!audio) {
        std::cerr << "Failed to load audio: " << Mix_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_Quit();
        return 1;
    }

    Mix_VolumeMusic(MIX_MAX_VOLUME / 2); // Set volume to 50%

    std::cout << "\n**************************\n";
    std::cout << "1. Start | 2. Restart | 3. End";
    std::cout << "\n**************************\n";

    int input = 0;
    std::cin >> input;

    switch (input) {
        case 1: {
            int u_time = 0;
            std::cout << "\nInput Amount of Time (seconds):\n";
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

                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            };

            if (Mix_PlayMusic(audio, 1) == -1) { // Play the music once
                std::cerr << "Mix_PlayMusic: " << Mix_GetError() << std::endl;
                Mix_FreeMusic(audio);
                Mix_CloseAudio();
                SDL_Quit();
                return 1;
            }

            while (Mix_PlayingMusic() == 1) { // Wait for the music to finish playing
                SDL_Delay(100);
            }

            Mix_FreeMusic(audio);
            Mix_CloseAudio();
            SDL_Quit();
            break;
        }
        case 2:
            std::cout << "To Be Implemented";
            break;
        case 3:
            break;
        default:
            std::cout << "\nPlease Enter a Valid Command";
            break;
    }

    return 0;
}
