#ifndef __SCREEN_BUILDER_H__
#define __SCREEN_BUILDER_H__
#include <memory>
namespace tetris
{
    class GameScreen;
    class ScreenBuilder
    {
    public:
        ScreenBuilder();
        ScreenBuilder(int width, int height);
        std::shared_ptr<GameScreen> build();
    private:
        int _width;
        int _height;
    };
}
#endif
