#include "Gui.hpp"
#include "../CoreSource/Snake.hpp"
extern "C" Gui* create_object()
{
	Gui *gui = new Gui;
	return gui;
}

extern "C" void destroy_object( Gui* object )
{
	delete object;
}

Gui::Gui() {
	//initialize screen
	initscr();
	//starts immediately
	nodelay(stdscr, true);
	//initialize keypad
	keypad(stdscr, true);
	//mute key preses
	noecho();
	curs_set(0);
	//get window size
	getmaxyx(stdscr, max_height, max_width);
	//print border
	for (int i = 0; i < 30; i++) {
		printC(0, i, '#');
	}
	for (int i = 0; i < 30; i++) {
		printC(i, 0, '#');
	}
	for (int i = 0; i < 10; i++) {
		printC(max_height, i -1, '#');
	}
	for (int i = 0; i < 10; i++) {
		printC(i, max_width - 2, '#');
	}
}

Gui::~Gui() {}

Gui::Gui(Gui const & copy) {
	*this = copy;
}
char Gui::keyStroke(char direction) {
	int temp;

	temp = getch();
	switch (temp) {
		case KEY_LEFT:
			if (direction != 'r')
				return ('l');
			break;
		case KEY_UP:
			if (direction != 'd')
				return ('u');
			break;
		case KEY_DOWN:
			if (direction != 'u')
				return ('d');
			break;
		case KEY_RIGHT:
			if (direction != 'l')
				return ('r');
			break;
		case KEY_BACKSPACE:
			return ('q');
			break;
	}
	return (0);
}



void Gui::printSnakeHead(int x, int y) {
	printC(x, y, '@');
}

void Gui::printC(int x, int y, char c) {
	move(x, y);
	addch(c);
	refresh();
}

void Gui::printSnakeInit(std::vector<SnakePosition> Snakey) {
//print snake
	for (std::string::size_type i = 0; i < 5; i++) {
		printC(Snakey[i].x, Snakey[i].y, 'O');
	}
}

void Gui::printFood(SnakePosition foods) {
	printC(foods.x, foods.y, '*');
}

void Gui::updateScore(int points) {
	move(max_height - 1, 0);
	printw("%d", points);
	refresh();
}

void Gui::printEmpty(int x, int y) {
	move(y, x);
	addch(' ');
	refresh();
}

void Gui::moveSnakeHead(int x, int y) {
	printC(x, y, ' ');
}

int Gui::getMaxHeight() {
	return (max_height);
}

int Gui::getMaxWidth() {
	return (max_width);
}