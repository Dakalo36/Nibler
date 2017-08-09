#include <iostream>
#include <vector>
#include <cstdlib>
#include <ncurses.h>

#ifndef SNAKEPOSITION_HPP
#define SNAKEPOSITION_HPP

class SnakePosition {
public:
	SnakePosition();
	SnakePosition(int col, int row);
	~SnakePosition();
//    SnakePosition(SnakePosition const &src);
//    SnakePosition &operator=(SnakePosition const &rhs);
	int x, y;
};

#endif