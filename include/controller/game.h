#ifndef __CONTROLLER_GAME_H__
#define __CONTROLLER_GAME_H__
#include <vector>
#include <array>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <ctime>
#include "block.h"

class Score;
class Game
{
public:
	Game(std::shared_ptr<Score> score);
	~Game();
	void move(BlockMove dir);
    bool fall(); // false while the game is end
	void rotate();
	void createBlockObject();
    Block* currentBlock();
    int scanLines();
	void moveDownMap(int n); //moving down from top line to n line
	void startGame();
	void terminateGame();
	void restart();
	bool isEnd();
    int score();
    std::shared_ptr<Map> map();
private:
    std::shared_ptr<Map> _map;
    std::shared_ptr<Score> _score;
	Block *current;
};
#endif

