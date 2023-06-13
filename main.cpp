// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
using namespace std;

int main(int argc, char* args[])
{
    SDL_Window* window = nullptr;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);

    bool isRunning = true;
    SDL_Event ev;

    while (isRunning) {
        while (SDL_PollEvent(&ev) != 0) {
            if (ev.type == SDL_QUIT) {
                isRunning = false;
            }
        }
        SDL_UpdateWindowSurface(window);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;

    //SDL_Renderer* renderer = nullptr;
    //SDL_Init(SDL_INIT_EVERYTHING);
    //SDL_CreateWindowAndRenderer(640,480,0,&window,&renderer);
    /*
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawPoint(renderer, 640 / 2, 480 / 2);

        SDL_Rect rect[4][4];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                rect[i][j].w = 50;
                rect[i][j].h = 50;
                rect[i][j].x = 50*j;
                rect[i][j].y = 50*i;

                SDL_SetRenderDrawColor(renderer, ((i*4)+j)*10, ((i*4)+j)*10, ((i*4)+j)*10, 255);
                SDL_RenderFillRect(renderer, &rect[i][j]);
            }
        }



        SDL_RenderPresent(renderer);
        SDL_Delay(10000);
    */
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
