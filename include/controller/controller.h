#ifndef __TETRIS_CONTROLLER_H__
#define __TETRIS_CONTROLLER_H__
#include "view/gamescreen.h"
#include "controller/game.h"
#include <memory>
#include <chrono>
namespace tetris
{
    class Controller
    {
    public:
        Controller(std::shared_ptr<Game> game, std::shared_ptr<GameScreen> screen);
        void handleKeyLeft();
        void handleKeyRight();
        void handleKeyUp();
        void handleKeySpace();
        void intervalUpdate();
        int messageLoop();
    private:
        std::shared_ptr<Game> _game;
        std::shared_ptr<GameScreen> _screen;
        decltype(std::chrono::milliseconds(1) + std::chrono::system_clock::now()) _intervalNextUpdateTime;
    };
}
#endif

