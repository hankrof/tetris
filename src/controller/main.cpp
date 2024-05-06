#include <iostream>
#include <memory>
#include "controller/controller.h"
#include "model/score/default_score.h"
#include "view/screenBuilder.h"
using namespace std;
int main(int argc, char **argv)
{
    tetris::ScreenBuilder builder;
    std::shared_ptr<tetris::GameScreen> screen(builder.build());
    std::shared_ptr<Score> score(new DefaultScore());
    std::shared_ptr<Game> game(new Game(score));
    std::shared_ptr<tetris::Controller> controller(new tetris::Controller(game, screen));
    return controller->messageLoop();
}

