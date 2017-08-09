#ifndef NIB_GUI_CLASS_HPP
#define NIB_GUI_CLASS_HPP
#include "../CoreSource/SnakePosition.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <string>
#include <ncurses.h>
class Gui{
private:
	int max_width, max_height;

public:
	Gui();
	~Gui();
	Gui(Gui const & copy);
	void moveSnake();
	char keyStroke(char direction);
	void printC(int x, int y, char c);
	void printSnakeInit(std::vector<SnakePosition> Snakey);
	void printSnakeHead(int x, int y);
	void updateScore(int points);
	void printEmpty(int x, int y);
	int getMaxWidth();
	int getMaxHeight();
	void moveSnakeHead(int x, int y);
	void printFood(SnakePosition foods);
};
#endif //NIB_GUI_CLASS_HPP
