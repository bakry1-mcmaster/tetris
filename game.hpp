#include "gamegrid.hpp"
#include <random>


enum blockType {CUBE, LONG, S_SHAPE, Z_SHAPE, T_SHAPE, J_SHAPE, L_SHAPE};

struct blocks
{
    int x, y;
};

class game
{
    private:
        gamegrid* gridreference;
        blockType currentBlock;
        blocks activeBlock[4];
        int offset;

        //List of current block?

    public:
        game(gamegrid* gridref);
        ~game();
        void chooseRandBlock();
        void moveBlockDown();

        void placeBlock();

        void rotateBlock(blockType block);




};