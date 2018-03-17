#include "stdafx.h"
#include "Wumpus.h"
#include <iostream>

Wumpus::Wumpus(int position) : position{ position }, name{ "Wumpus" }
{
	std::cout << "Wumpus spawned in the level!\n";
}

Wumpus::~Wumpus()
{
	std::cout << "Wumpus slain!\n";
}

void Wumpus::move_to(int new_pos)
{
	position = new_pos;
}

int Wumpus::get_position() const
{
	return position;
}