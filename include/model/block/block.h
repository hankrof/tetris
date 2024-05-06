#ifndef __BLOCK_H__
#define __BLOCK_H__
#include <vector>
#include <array>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include "map.h"

#define BLOCK_SIZE 30
using namespace std;
/*
Note that:
All boolean operation
    True means: success
    False means: failure
*/
enum BlockMove
{
    LEFT,
    UP,
    RIGHT,
    DOWN,
    SPACE
};
struct Dot
{
    Dot(int xv=0, int yv=0) :x(xv), y(yv){}
    int x, y;
};

class Block
{
public:
    Block(int size=4);
    Block(const vector<Dot> &dv);
    virtual ~Block();
    static void setMap(Map &map);
    virtual void rotate() = 0;
    virtual bool isRotatable() = 0;
    void move(BlockMove moveDir);
    bool fall();
    void fallDown();
    bool isTouched();
    bool isTouched(vector<Dot> tdots);
    friend class CTetrisGame; //Just for painting
    static Map *map;
    vector<Dot> Dots;
    vector<Dot> rotatable;
    size_t DotsLen;
    int rotation_mode;
};
#endif

