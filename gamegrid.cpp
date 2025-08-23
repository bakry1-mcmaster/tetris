#include "gamegrid.hpp"

gamegrid::gamegrid()
{
    grids = nullptr;
    gridWidth = 0;
    gridHeight = 0;
    screenHeight = 0;
    screenWidth = 0;
    spacing = 0;

}


gamegrid::gamegrid(int length, int width, SDL_Renderer* gamerender, int slength, int swidth)
{
    gridWidth = length;
    gridHeight = width;
    gridrender = gamerender;
    screenHeight = slength;
    screenWidth = swidth;
    spacing = 2;

    createBoard();
}

gamegrid::~gamegrid()
{
    if(grids)
    {
        for(int i = 0; i<gridWidth; i++)
        {
            delete[] grids[i];
        }

        delete[] grids;
        grids = nullptr;
    }
    
    printf("grid succesfully deleted\n");

}

void gamegrid::setBoardScreenSetup(int length, int width)
{
    screenHeight = length;
    screenWidth = width;
    

}

void gamegrid::renderReference(SDL_Renderer* gamerender)
{
    gridrender = gamerender;
}

void gamegrid::setParameters(int length, int width)
{
    gridHeight = length;
    gridWidth = width;

}


void gamegrid::createBoard()
{
    grids = new gridspace*[gridWidth];

    for(int i = 0; i<gridWidth; i++)
    {
        grids[i] = new gridspace[gridHeight];
    }

    int widthSpaceSegment = (screenWidth/2)/10;
    int HeightSpaceSegment = screenHeight/22;
    
    int segment = std::min(widthSpaceSegment, HeightSpaceSegment);
    
    if(gridWidth*segment + 2*gridWidth > screenHeight)
    {
        segment-=3;
    }

    int totalGridWidth = segment*10;
    int totalGridHeight = screenHeight;


    int originX = (screenWidth/2-totalGridWidth/2);
    int originY = 0;

    printf("%d\n",widthSpaceSegment);
    printf("%d\n",HeightSpaceSegment);


    for(int row = 0; row<gridWidth; row++)
    {
        for(int col = 0; col<gridHeight; col++)
        {
            grids[row][col].occupiedspace = false;
            grids[row][col].movingspace = false;
            grids[row][col].gridsquare.h = segment;
            grids[row][col].gridsquare.w = segment;
            grids[row][col].gridsquare.x = originX+col*segment + spacing*col;
            grids[row][col].gridsquare.y = originY+row*segment + spacing*row;

        }
    }

    renderBoard();
}


void gamegrid::renderBoard()
{
    SDL_SetRenderDrawColor(gridrender, 0, 0, 0, 0);

    for(int i = 0; i<gridWidth; i++)
    {

        for(int j = 0; j<gridHeight; j++)
        {
            SDL_RenderFillRect(gridrender, &grids[i][j].gridsquare);
        }
    }

    SDL_RenderPresent(gridrender);
}

gridspace** gamegrid::getGrid()
{
    return grids;
}


int gamegrid::getGridHeight()
{
    return gridHeight;
}



int gamegrid::getGridWidth()
{
    return gridWidth;
}


void gamegrid::clearRow(int rowindex)
{
    for(int i = 0; i<gridHeight; i++)
    {
        grids[rowindex][i].occupiedspace = false;
        grids[rowindex][i].movingspace = false;
    }
}

void gamegrid::pushRowDown(int rowindex)
{
    for(int i = 0; i<gridWidth; i++)
    {
        if(grids[rowindex+1][i].occupiedspace)
        {
            grids[rowindex+1][i].occupiedspace = true;
            grids[rowindex][i].occupiedspace = false;
        }
    }
}

void gamegrid::clearAll()
{
    for(int row = 0; row<gridWidth; row++)
    {
        for(int col = 0; col<gridHeight; col++)
        {
            grids[row][col].occupiedspace = false;
            grids[row][col].movingspace = false;
        }
    }

}


bool gamegrid::checkRowFull()
{
    bool isRowFull = true;
    for(int i = 0; i<gridHeight; i++)
    {
        for(int j = 0; j<gridWidth; j++)
        {
            if(!(grids[i][j].occupiedspace))
            {
                isRowFull = false;
                break;
            }
        }
        
        if(isRowFull == true)
        {
            clearRow(i);
            pushRowDown(i-1);

        }
    }
}