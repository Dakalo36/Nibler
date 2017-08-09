
#ifndef SNAKE_HPP
#define SNAKE_HPP
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string>
#include "SnakePosition.hpp"
#include "../Lib1Source/Gui.hpp"
class Snake {
private:
	int							points, delay;
	char						direction, snake_head, border, food_char;
	bool						snake_eat;
	SnakePosition				food;
	std::vector<SnakePosition>	snake;
	Gui *guio;

public:
	Snake(Gui & gui);
	Snake(Snake const & copy);
	~Snake();
//	Snake& operator=( Snake const & copy );
	void						startGame();
	void						setDirection(char c);
	std::vector<SnakePosition>	getSnakeVec();
	SnakePosition 				getFood();
	void						foodPosition();
	void						moveSnake();
	bool						collision();
};
std::ostream & operator<<(std::ostream & o, Snake const & rhs);
#endif
