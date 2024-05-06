#include "block.h"
Map *Block::map = nullptr;
Block::Block(int size)
{
    rotation_mode = 0;
    Dots.resize(size);
}

Block::Block(const vector<Dot> &dv)
{
    DotsLen = dv.size();
    Dots.resize(DotsLen);
    rotatable.resize(DotsLen);
    for (size_t i = 0; i < DotsLen; ++i)
        Dots[i] = dv[i];
}

Block::~Block()
{

}

void Block::setMap(Map &map)
{
    Block::map = &map;
}

bool Block::isTouched()
{
    for (size_t i = 0; i < DotsLen; ++i)
    {
        if (map->getValue(Dots[i].x, Dots[i].y) != 0) //unsuccessful
            return true;
    }
    return false;
}

bool Block::isTouched(vector<Dot> tdots)
{
    for (size_t i = 0; i < DotsLen; ++i)
    {
        if (map->getValue(tdots[i].x, tdots[i].y) != 0) //unsuccessful
            return true;
    }
    return false;
}

void Block::move(BlockMove moveDir)
{
    int i;
    switch (moveDir)
    {
    case UP:
        rotate();
        break;
    case LEFT:
        for (i = 0; i < 4; ++i)
            Dots[i].x--;

        if (isTouched())
            for (i = 0; i < 4; ++i)
                Dots[i].x++;

        break;
    case RIGHT:
        for (i = 0; i < 4; ++i)
            Dots[i].x++;

        if (isTouched())
            for (i = 0; i < 4; ++i)
                Dots[i].x--;
        break;
    case DOWN:
        for (i = 0; i < 4; ++i)
            Dots[i].y++;
        if (isTouched())
            for (i = 0; i < 4; ++i)
                Dots[i].y--;
        break;
    case SPACE:
        fallDown();
        break;
    }
}

bool Block::fall()
{
    for (size_t i = 0; i < DotsLen; ++i)
        Dots[i].y++;
    if (isTouched())
    {
        for (size_t i = 0; i < DotsLen; ++i)
            Dots[i].y--;
        return false;
    }
    else
        return true;
}

void Block::fallDown()
{
    bool touched = true;
    while (touched)
    {
        touched = fall();
    }
}

