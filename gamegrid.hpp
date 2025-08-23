//Properties of grid: length, width, square
#include "src/include/SDL2/SDL.h"
#include <iostream>

struct gridspace
{
    bool occupiedspace;
    bool movingspace;
    SDL_Rect gridsquare;

};


class gamegrid
{
    private:
        int gridHeight;
        int gridWidth;
        int screenHeight;
        int screenWidth;
        int spacing;
        gridspace** grids;
        SDL_Renderer* gridrender;
    
    public:
        gamegrid();
        gamegrid(int Length, int Width, SDL_Renderer* gamerender, int slength, int swidth);
        ~gamegrid();

        void setParameters(int height, int width);
        void setBoardScreenSetup(int height, int width);
        void renderReference(SDL_Renderer* gamerender);
        void createBoard();
        void renderBoard();

        void clearRow(int rowindex);
        void pushRowDown(int rowindex);
        void clearAll();


        gridspace** getGrid();
        int getGridHeight();
        int getGridWidth();

        bool checkRowFull();




};

