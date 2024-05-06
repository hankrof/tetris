#include "view/screenBuilder.h"
using namespace tetris;
ScreenBuilder::ScreenBuilder()
    : _width(0), _height(0)
{

}

ScreenBuilder::ScreenBuilder(int width, int height)
    : _width(width), _height(height)
{

}

#ifdef x86
#include "view/gamescreen_sdl.h"
std::shared_ptr<GameScreen> ScreenBuilder::build()
{
    return std::shared_ptr<tetris::GameScreenSDL>(new tetris::GameScreenSDL(300, 600));
}
#endif
