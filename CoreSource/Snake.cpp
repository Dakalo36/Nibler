#include "Snake.hpp"
#include "../Lib1Source/Gui.hpp"

Snake::Snake(Gui & gui) {
	guio = &gui;
	direction = 'l';
	snake_head = 'O';
	border = '#';
	food_char = '*';
	food.x = 0;
	food.y = 0;
	snake_eat = false;

	//determines the snakes position on the screen
	for (int i = 0; i < 4; i++)
		snake.push_back(SnakePosition(40 + i, 10));
	points = 0;
	delay = 110000;
	srand(time(0));
	foodPosition();
	guio->printSnakeInit(snake);
	guio->printFood(food);
	guio->updateScore(points);
}

Snake::~Snake() {
	nodelay(stdscr, false);
	getch();
	endwin();
}


SnakePosition Snake::getFood() {
	return (food);
}


void Snake::foodPosition() {
	while (1) {
		int temp_x, temp_y;

		temp_x = rand() % guio->getMaxWidth() + 1;
		temp_y = rand() % guio->getMaxHeight() + 1;
		for (std::string::size_type i = 0; i < snake.size(); i++)
			if (snake[i].x == temp_x && snake[i].y == temp_y)
				continue;
		if (temp_x >= guio->getMaxWidth() - 2 || temp_y >= guio->getMaxHeight() - 3)
			continue;
		food.x = temp_x;
		food.y = temp_y;
		break;
	}
	guio->printFood(food);
}

bool Snake::collision() {
	//if it collides with the borders
	if (snake[0].x == 0 || snake[0].x == guio->getMaxWidth() - 1
		|| snake[0].y == 0 || snake[0].y == guio->getMaxHeight() - 2)
		return true;
	//if it collides with itself
	for (std::string::size_type i = 2; i < snake.size(); i++)
		if (snake[0].x == snake[i].x && snake[i].y == snake[0].y)
			return true;
	//if it eats food, add points and change foods position
	if (snake[0].x == food.x && snake[0].y == food.y) {
		snake_eat = true;
		foodPosition();
		points += 10;
		guio->printFood(food);
		guio->updateScore(points);
		if ((points % 50) == 0)
			delay -= 20000;
	} else
		snake_eat = false;
	return false;
}

void Snake::startGame() {
	while (1) {
		moveSnake();
		collision();
		if (direction == 'q')
			break;
		usleep(delay);
	}
}

//void Snake::moveSnake() {
//	if (!snake_eat) {
//		printEmpty(snake[snake.size() - 1].x, snake[snake.size() - 1].y);
//		snake.pop_back();
//	}
//	if (direction == 'l')
//		snake.insert(snake.begin(), SnakePosition(snake[0].x - 1, snake[0].y));
//	else if (direction == 'r')
//		snake.insert(snake.begin(), SnakePosition(snake[0].x + 1, snake[0].y));
//	else if (direction == 'u')
//		snake.insert(snake.begin(), SnakePosition(snake[0].x, snake[0].y - 1));
//	else if (direction == 'd')
//		snake.insert(snake.begin(), SnakePosition(snake[0].x, snake[0].y + 1));
//
//}

void Snake::setDirection(char c) {
	direction = c;
}

Snake::Snake(Snake const &copy) {
	*this = copy;
}

std::ostream &operator<<(std::ostream &o, Snake const &rhs) {
	Snake copy(rhs);
	o << "snake";
	return o;
}

//Snake& Snake::operator=( Snake const & copy ) {
//	*copy = NULL;
//    return *this;
//}

//Snake::Snake(Snake const &src) {
//    this->operator=(src);
//    return;
//}

//Snake &Snake::operator=(Snake const &rhs) {
//    return *this;
//}

void Snake::moveSnake() {
	//if it doesn't get food, the last part of the snake it deleted and
	//a new snake part gets popped onto the front.
	direction = guio->keyStroke(direction);
	if (!snake_eat) {
		guio->moveSnakeHead(snake[snake.size() - 1].y, snake[snake.size() - 1].x);
		snake.pop_back();
	}
	if (direction == 'l')
		snake.insert(snake.begin(), SnakePosition(snake[0].x - 1, snake[0].y));
	else if (direction == 'r')
		snake.insert(snake.begin(), SnakePosition(snake[0].x + 1, snake[0].y));
	else if (direction == 'u')
		snake.insert(snake.begin(), SnakePosition(snake[0].x, snake[0].y - 1));
	else if (direction == 'd')
		snake.insert(snake.begin(), SnakePosition(snake[0].x, snake[0].y + 1));
	guio->printC(snake[0].x, snake[0].y, 'O');
}