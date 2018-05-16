#include "stdafx.h"
#include "Wumpus.h"
#include <iostream>

Wumpus::Wumpus() : alive{ true }, position { 0 }, name{ "Wumpus" }
{
	std::cout << "Wumpus roams the cave!\n";
}
