#include "controller/game.h"
#include "model/score/score.h"
#include "model/block/block.h"
#include "model/block/blockI.h"
#include "model/block/blockJ.h"
#include "model/block/blockL.h"
#include "model/block/blockO.h"
#include "model/block/blockS.h"
#include "model/block/blockT.h"
#include "model/block/blockZ.h"

Game::Game(std::shared_ptr<Score> score)
    : _score(score)
{
    _map = std::shared_ptr<Map>(new Map);
    Block::setMap(*_map);
}

Game::~Game()
{

}

bool Game::fall()
{
    if (current)
    {
        if( !current->fall() )
        {
            if (isEnd())
                return false;
            for(size_t i=0;i<current->DotsLen;++i)
                _map->tetrisMap[current->Dots[i].x][current->Dots[i].y] = 1;
            delete current;
            createBlockObject();
            int numberOfDeletedLines = scanLines();
            _score->accumulate(numberOfDeletedLines);
            std::cout << "score = " << _score->point() << std::endl;
        }
        return true;
    }
    else
    {
        throw runtime_error("An unexcepted error has occurred.(The current is null)");
        return false;
    }
}

void Game::move(BlockMove dir)
{
    if (current)
        current->move(dir);
}

void Game::rotate()
{
    if (current)
        current->rotate();
}

void Game::createBlockObject()
{
    static bool isFirst = true;
    int val;
    if (isFirst)
    {
        srand(static_cast<unsigned int>(time(NULL)));
    }
    val = rand() % 7;
    switch (val)
    {
    case 0:
        current = (Block*) (new BlockI());
        break;
    case 1:
        current = (Block*) (new BlockJ());
        break;
    case 2:
        current = (Block*) (new BlockO());
        break;
    case 3:
        current = (Block*) (new BlockL());
        break;
    case 4:
        current = (Block*) (new BlockS());
        break;
    case 5:
        current = (Block*) (new BlockT());
        break;
    case 6:
        current = (Block*) (new BlockZ());
        break;
    default:
        cout << "val:" << val << " is out from BlockType.\n";
        current = NULL;
        break;
    }
}

Block* Game::currentBlock()
{
    return current;
}

int Game::scanLines()
{
    bool foundAnySolidLine;
    int lines = 0;
    for (int y = 0;y < 20; ++y)
    {
        foundAnySolidLine = true;
        for (int x = 0;x < 10; ++x)
        {
            if(_map->tetrisMap[x][y] == 0)
                foundAnySolidLine = false;
        }
        if (foundAnySolidLine)
        {
            for(int i=0;i<10;++i)
                _map->tetrisMap[i][y] = 0;
            moveDownMap(y);

            lines++;
        }
    }
    return lines;
}

void Game::moveDownMap(int n)
{
    for (int y = n ; y > 0 ; --y)
        for (int x = 0; x < 10; ++x)
            _map->tetrisMap[x][y] = _map->tetrisMap[x][y - 1];
}

void Game::startGame()
{

}

void Game::terminateGame()
{

}

void Game::restart()
{
    _map->clear();
    _score->reset();
}

bool Game::isEnd()
{
    for (size_t i = 0; i < current->DotsLen; ++i)
    {
        if (current->Dots[i].y <= -1)
            return true;
    }
    return false;
}

int Game::score()
{
    return _score->point();
}

std::shared_ptr<Map> Game::map()
{
    return _map;
}

