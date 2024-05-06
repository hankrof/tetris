#ifndef __TETRIS_GAME_SCREEN_SDL_H__
#define __TETRIS_GAME_SCREEN_SDL_H__
#include "view/gamescreen.h"
#include <memory>
class Map;
class SDL_Window;
class SDL_Renderer;
namespace tetris
{
    class GameScreenSDL : public GameScreen
    {
    public:
        GameScreenSDL(int width, int height);
        ~GameScreenSDL();
        void setController(std::shared_ptr<Controller> controller) override;
        int handleEvent(int elapsedMilliseconds) override;
        void drawScore(int score) override;
        void drawMap(std::shared_ptr<Map> map, Block *current) override;
    private:
        void dispatchKeyEvent(int keyCode);
        int _width, _height;
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        std::shared_ptr<Controller> _controller;
    };
}
#endif
