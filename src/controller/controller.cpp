#include "controller/controller.h"
#include <ctime>
#include <system_error>
#include <thread>
#include <chrono>
using namespace tetris;

Controller::Controller(std::shared_ptr<Game> game, std::shared_ptr<GameScreen> screen)
    : _game(game), _screen(screen), _intervalNextUpdateTime(std::chrono::system_clock::now())
{
    _screen->setController(std::shared_ptr<Controller>(this, [](Controller*){}));
    _game->createBlockObject();
    _game->startGame();
}

void Controller::handleKeyLeft()
{
    _game->move(BlockMove::LEFT);
}

void Controller::handleKeyRight()
{
    _game->move(BlockMove::RIGHT);
}

void Controller::handleKeyUp()
{
    _game->rotate();
}

void Controller::handleKeySpace()
{
    while (!_game->isEnd())
        _game->fall();
}

void Controller::intervalUpdate()
{
    bool isPlaying(true);
    if (std::chrono::system_clock::now() >= _intervalNextUpdateTime)
    {
        _intervalNextUpdateTime = std::chrono::milliseconds(500) + std::chrono::system_clock::now();
        isPlaying = _game->fall();
        _screen->drawScore(_game->score());
    }
    if (isPlaying == false)
        _game->restart();
}

int Controller::messageLoop()
{
    int duration = 5;
    while (_screen->handleEvent(duration))
    {
        _screen->drawMap(_game->map(), _game->currentBlock());
        intervalUpdate();
        std::this_thread::sleep_for(std::chrono::milliseconds(duration));
    }
    return 0;
}

