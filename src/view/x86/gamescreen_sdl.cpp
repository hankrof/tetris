#include "view/gamescreen_sdl.h"
#include "controller/controller.h"
#include "SDL_keycode.h"
#include "model/block/map.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_timer.h>
#include <unistd.h>
#include <iostream>
namespace tetris
{
    GameScreenSDL::GameScreenSDL(int width, int height)
        : GameScreen(width, height),
           _window(nullptr), _renderer(nullptr)
    {
        if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
            throw std::runtime_error("Could not initialize SDL library.");

        _window = SDL_CreateWindow("Tetris",
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED
            ,width,height,0);

        if(!_window)
            throw std::runtime_error("Could not create SDL Window.");

        _renderer = SDL_CreateRenderer(_window,-1,
            SDL_RENDERER_ACCELERATED |
            SDL_RENDERER_PRESENTVSYNC
            );

        if(!_renderer)
            throw std::runtime_error("Could not create renderer from SDL window.");
    }

    GameScreenSDL::~GameScreenSDL()
    {
        SDL_DestroyWindow(_window);
        SDL_DestroyRenderer(_renderer);
        SDL_Quit();
    }

    void GameScreenSDL::setController(std::shared_ptr<Controller> controller)
    {
        _controller = controller;
    }

    void GameScreenSDL::dispatchKeyEvent(int keyCode)
    {
        if (keyCode == SDL_KeyCode::SDLK_LEFT)
            _controller->handleKeyLeft();
        else if (keyCode == SDL_KeyCode::SDLK_RIGHT)
            _controller->handleKeyRight();
        else if (keyCode == SDL_KeyCode::SDLK_UP)
            _controller->handleKeyUp();
        else if (keyCode == SDL_KeyCode::SDLK_SPACE)
            _controller->handleKeySpace();
    }

    int GameScreenSDL::handleEvent(int elapsedMilliseconds)
    {
        SDL_Event event;
        if (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                return 0;
            if (event.type == SDL_KEYDOWN)
                dispatchKeyEvent((int)event.key.keysym.sym);
        }
        return 1;
    }

    void GameScreenSDL::drawScore(int score)
    {

    }

    void GameScreenSDL::drawMap(std::shared_ptr<Map> map, Block *current)
    {
        SDL_RenderClear(_renderer);

        //Paint the map
        SDL_Rect Block = {0, 0, 30, 30};
        for (int x = 0; x < 10; ++x)
        {
            for (int y = 0; y < 20; ++y)
            {
                if (map->tetrisMap[x][y] == 0)
                {
                    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0);
                    SDL_RenderFillRect(_renderer, &Block);
                }
                else
                {
                    SDL_SetRenderDrawColor(_renderer, 0, 0, 180, 0);
                    SDL_RenderFillRect(_renderer, &Block);
                }
                Block.y += 30;
            }
            Block.y = 0;
            Block.x += 30;
        }

        //Paint the controlled object
        if (current)
        {
            SDL_SetRenderDrawColor(_renderer, 0, 0, 180, 0);
            for (size_t i = 0; i < current->DotsLen; ++i)
            {
                Block.x = current->Dots[i].x * BLOCK_SIZE;
                Block.y = current->Dots[i].y * BLOCK_SIZE;
                SDL_RenderFillRect(_renderer, &Block);
            }
        }
        SDL_RenderPresent(_renderer);
    }
}

