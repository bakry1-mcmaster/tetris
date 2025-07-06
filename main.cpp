#define SDL_MAIN_HANDLED

#include "src/include/SDL2/SDL.h"
#include <iostream>

SDL_Window* mainwindow = nullptr;
SDL_Surface* background = nullptr;
SDL_Renderer* backgroundrender = nullptr;

const int length = 1024;
const int width = 768;


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


        mainwindow = SDL_CreateWindow("Testing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, SDL_WINDOW_SHOWN);
        SDL_Surface* appicon = nullptr;
        appicon = SDL_LoadBMP("imageresources/larry.bmp");  
        SDL_SetWindowIcon(mainwindow,appicon);

        SDL_FreeSurface(appicon);


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
        SDL_Quit();

        mainwindow = nullptr;

        return 0;
    }
}