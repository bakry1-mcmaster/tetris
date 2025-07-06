#define SDL_MAIN_HANDLED

#include "src/include/SDL2/SDL.h"
#include <iostream>

SDL_Window* mainwindow = nullptr;
SDL_Surface* background = nullptr;
SDL_Renderer* backgroundrender = nullptr;

const int screenLength = 990;
const int screenWidth = 570;


int main(int argc, char *argv[])
{


    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        printf("Failed to initialize. Exiting....");
        return -1;
    }
    else
    {
        bool gamerunning = true;

        
        mainwindow = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenLength, screenWidth, SDL_WINDOW_SHOWN);
        SDL_Surface* appicon = nullptr;


        appicon = SDL_LoadBMP("imageresources/larry.bmp");  
        SDL_SetWindowIcon(mainwindow,appicon);

        SDL_FreeSurface(appicon);

        backgroundrender = SDL_CreateRenderer(mainwindow, -1, SDL_RENDERER_ACCELERATED);
        SDL_SetRenderDrawColor(backgroundrender, 0, 50, 255, 255);
        SDL_RenderClear(backgroundrender);
        SDL_RenderPresent(backgroundrender);


        if(mainwindow = NULL)
        {
            printf("Failed to create window. Exiting....");
            return -1;
        }

        while(gamerunning)
        {
            SDL_Event e;
            while(SDL_PollEvent(&e))
            {
                switch(e.type)
                {
                    case SDL_QUIT:
                        gamerunning = false;
                        break;
                    
                    default:
                        break;
                }
            }
        }

        SDL_DestroyWindow(mainwindow);
        SDL_DestroyRenderer(backgroundrender);
        SDL_Quit();

        mainwindow = nullptr;
        backgroundrender = nullptr;

        return 0;
    }
}