// Tetris.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SDL.h>
#include "Pieces.h"

using namespace std;

int main(int argc, char* args[])
{
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    unsigned long mTime1 = SDL_GetTicks();

    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, 0, 0);

    bool isRunning = true;
    SDL_Event ev;

    
    SDL_Rect rect = {0,0,50,50};

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    //          int color[9][3] = 
    //          {
    //  Yellow      255     255     0
    //  Cyan        0       255     255
    //  Purple      126     0       255
    //  Orange      255     126     0
    //  Blue        0       0       255
    //  Green       0       255     0
    //  Red         255     0       0
    //  White       255     255     255
    //  Black       0       0       0
    //                                  };

    Pieces piece1;
    int rotation = 0;
    int type = 0;

    while (isRunning) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (piece1.getBlockType(type, rotation, i, j) != 0) {
                    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                    SDL_RenderFillRect(renderer, &rect);
                }
                rect.x += 50;
            }
            rect.x = 0;
            rect.y += 50;
        }
        rect.x = 0;
        rect.y = 0;

        SDL_RenderPresent(renderer);

        while (SDL_PollEvent(&ev) != 0) {
            if (ev.type == SDL_QUIT) {
                isRunning = false;
            }else if (ev.type == SDL_KEYDOWN) {
                if (ev.key.keysym.sym == SDLK_RIGHT) {
                    rotation++;                    
                }
                if (ev.key.keysym.sym == SDLK_LEFT) {
                    rotation--;
                }
                if (ev.key.keysym.sym == SDLK_SPACE) {
                    type++;
                }
                rotation = (rotation+4) % 4;
                type %= 7;
            }
            rotation = abs(rotation) % 4;
        }
        
        unsigned long mTime2 = SDL_GetTicks();
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
