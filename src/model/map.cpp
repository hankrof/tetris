#include "map.h"
#include <iostream>
#include <stdexcept>
using namespace std;

Map::Map()
{
	clear();
}

void Map::clear()
{
	for (auto iter = tetrisMap.begin(); iter != tetrisMap.end(); ++iter)
		iter->fill(0);
}

int Map::getValue(int x,int y)
{
	try
	{
        if(x > MAX_EDGE_X || y > MAX_EDGE_Y ||
           x < MIN_EDGE_X || y < MIN_EDGE_Y )
        {
            throw "Out from array length";
        }
		return tetrisMap.at(x).at(y);
	}
	catch (const char *msg)
	{
        cout << '(' << x << ',' << y << ") " <<msg;
        cout << "(0,0)->";
        cout << '(' << MAX_EDGE_X << ',' << MAX_EDGE_Y << ")\n";
        return -1;
	}
}

