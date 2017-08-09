#include "SnakePosition.hpp"

SnakePosition::SnakePosition() {
	x = 0;
	y = 0;
}

SnakePosition::SnakePosition(int col, int row) {
	x = col;
	y = row;
}

SnakePosition::~SnakePosition() {

}

//SnakePosition::SnakePosition(SnakePosition const &src) {
//    this->operator=(src);
//}

//SnakePosition &SnakePosition::operator=(SnakePosition const &rhs) {
//    return *this;
//}

