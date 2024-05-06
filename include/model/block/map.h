#ifndef __MAP_H__
#define __MAP_H__
#include <array>
#define MAX_EDGE_X 9
#define MAX_EDGE_Y 19
#define MIN_EDGE_X 0
#define MIN_EDGE_Y 0
class Map
{
public:
    Map();
    void clear();
    int getValue(int x, int y);
    int checkLines(); //for earning score
    friend class CTetrisGame; //Just for painting
    std::array<std::array<int, 20>, 10> tetrisMap;
};
#endif
