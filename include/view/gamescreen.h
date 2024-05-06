#ifndef __TETRIS_GAME_SCREEN_H__
#define __TETRIS_GAME_SCREEN_H__
#include <memory>
class Map;
class Block;
namespace tetris
{
    class Controller;
    class GameScreen
    {
    public:
        GameScreen(int width, int height) : _width(width), _height(height) {}
        virtual ~GameScreen() {}
        virtual void setController(std::shared_ptr<Controller> controller) = 0;
        virtual int  handleEvent(int elapsedMilliseconds) = 0;
        virtual void drawScore(int score) = 0;
        virtual void drawMap(std::shared_ptr<Map> map, Block *current) = 0;
        int width() const  { return _width;  }
        int height() const { return _height; }
    private:
        int _width;
        int _height;
    };
}

#endif
