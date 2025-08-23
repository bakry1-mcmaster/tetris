#include "game.hpp"
#include <random>
#include <time.h>


game::game(gamegrid* gridref)
{
    gridreference = gridref;
    offset = 0;
}

game::~game()
{

}

void game::chooseRandBlock()
{
    srand(time(NULL));


    blockType chosenBlock = blockType(rand()%7);

    while(chosenBlock == currentBlock)
    {
        chosenBlock = blockType(rand()%7);
    }

    currentBlock == chosenBlock;

}



/*  maingrid[0][5].occupiedspace = true;
    maingrid[0][5].movingspace = true;
    maingrid[0][6].occupiedspace = true;
    maingrid[0][6].movingspace = true;
    maingrid[1][5].occupiedspace = true;
    maingrid[1][5].movingspace = true;
    maingrid[1][6].occupiedspace = true;
    maingrid[1][6].movingspace = true;*/

void game::placeBlock()
{
    gridspace** maingrid = gridreference->getGrid();



    switch(currentBlock)
    {
        case CUBE:
            activeBlock[0].x = 5;
            activeBlock[0].y = 0;
            activeBlock[1].x = 6;
            activeBlock[1].y = 0;
            activeBlock[2].x = 5;
            activeBlock[2].y = 1;
            activeBlock[3].x = 6;
            activeBlock[3].y = 1;
            break;

        case LONG:
            
            break;

        case S_SHAPE:

            break;

        case Z_SHAPE:

            break;

        case T_SHAPE:

            break;

        case J_SHAPE:

            break;

        case L_SHAPE:

            break;



    }
}


void game::moveBlockDown()
{
    for(int i = 0; i<4; i++)
    {
        activeBlock[i].y+=1;
    }

    offset++;
}


void game::rotateBlock(blockType block)
{
    blocks originalmatrix[5][5] = {0};
    blocks transposematrix[5][5] = {0};
    
    int x, y;



    switch(block)
    {
        case CUBE:
            //nothing to rotate
            return;
            break;

        case LONG:
            originalmatrix[2][2] = activeBlock[3];
            x = originalmatrix[2][2].x;
            y = originalmatrix[2][2].y;
            break;

        case S_SHAPE:
            originalmatrix[2][2] = activeBlock[2];
            x = originalmatrix[2][2].x;
            y = originalmatrix[2][2].y;
            break;

        case Z_SHAPE:
            originalmatrix[2][2] = activeBlock[2];
            x = originalmatrix[2][2].x;
            y = originalmatrix[2][2].y;
            break;

        case T_SHAPE:
            originalmatrix[2][2] = activeBlock[2];
            x = originalmatrix[2][2].x;
            y = originalmatrix[2][2].y;
            break;

        case J_SHAPE:
            originalmatrix[2][2] = activeBlock[3];
            x = originalmatrix[2][2].x;
            y = originalmatrix[2][2].y;
            break;

        case L_SHAPE:
            originalmatrix[2][2] = activeBlock[3];
            x = originalmatrix[2][2].x;
            y = originalmatrix[2][2].y;
            break;
    }

    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<5; j++)
        {
            if(i != j)
            {
                int xdifference = 2-i;
                int ydifference = 2-j;

                originalmatrix[i][j].x = originalmatrix[2][2].x-xdifference;
                originalmatrix[i][j].y = originalmatrix[2][2].y-ydifference;

            }
        }
    }


    //transposing the matrix
    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            transposematrix[j][i] = originalmatrix[i][j];
        }
    }

    //flipping columns to complete clockwise rotation 
    for(int i = 0; i<5; i++)
    {
        blocks temp = transposematrix[i][0];
        transposematrix[i][0] = transposematrix[i][4];
        transposematrix[i][4] = temp;
    }

    for(int i = 0; i<5; i++)
    {
        blocks temp = transposematrix[i][1];
        transposematrix[i][1] = transposematrix[i][2];
        transposematrix[i][3] = temp;
    }

}