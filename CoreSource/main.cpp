#include "Snake.hpp"
#include <dlfcn.h>
#include "../Lib1Source/Gui.hpp"
typedef Gui * (*create_t)();

int main(int argc, char **argv) {
	if (argc != 0 && argc != 3)
	{
		std::cout << "Oops it looks like you have entered the wrong amount of arguments.";
		return (0);
	}
	if (atoi(argv[1]) > 100 || atoi(argv[2]) > 50 || atoi(argv[1]) < 0 || atoi(argv[2]) < 0
			|| !atoi(argv[1]) || !atoi(argv[2]))
	{
		std::cout << "Window size must be between 100 X 50 and 0 X 0";
		return (0);
	}
	void	*lib;
	lib = dlopen("../lib1.so", RTLD_NOW);
	create_t create;
	void (*destroy)(Gui*);

	create = reinterpret_cast<create_t>(dlsym(lib, "create_object"));
	Gui *var = create();
	destroy = ((void (*)(Gui*))dlsym(lib, "destroy_object"));

	Snake snake_game(*var);

	snake_game.startGame();
	return (0);
}
