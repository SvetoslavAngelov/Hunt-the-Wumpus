#include "stdafx.h"
#include "Wumpus.h"
#include <iostream>

Wumpus::Wumpus() : position{ 0 }, name{ "Wumpus" }, state{ true }
{
	std::cout << "Wumpus spawned in the level!\n";
}

Wumpus::~Wumpus()
{
	std::cout << "Wumpus slain!\n";
}
