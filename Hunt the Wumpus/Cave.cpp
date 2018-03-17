#include "stdafx.h"
#include "Cave.h"
#include "Room.h"
#include <algorithm>
#include <iostream>

Cave::Cave()
{
	constexpr int dungeon_size{ 20 }; // TODO add custom size rooms, current default room size set to 20

	create_rooms(dungeon_size);

	// Scramble rooms, so hazards when added are not associated with room numbers
	std::random_shuffle(rooms.begin(), rooms.end());

	set_hazards(dungeon_size);

	// Scramble rooms, so hazards are not associated with room posiiton 
	std::random_shuffle(rooms.begin(), rooms.end());

	link_rooms(dungeon_size);

	std::cout << "Dungeon with size " << dungeon_size << " created!\n";

	// TODO print out debug dungeon layout

}

void Cave::create_rooms(int dungeon_size)
{
	// Room index to start from 1
	for (int i{ 1 }; i < dungeon_size + 1; ++i)
		rooms.push_back(new Room{ i });
}

void Cave::set_hazards(int dungeon_size)
{
	for (int i{ 0 }; i < dungeon_size; ++i)
	{
		if (i < dungeon_size * 0.5)
			rooms[i]->set_hazard(Room::Hazard::None); // 50% of rooms have no hazard 

		else if (i >= dungeon_size * 0.5 && i < dungeon_size * 0.75)
			rooms[i]->set_hazard(Room::Hazard::Bats); // 25% of rooms have Bats 

		else
			rooms[i]->set_hazard(Room::Hazard::Abyss); // 25% of rooms contain an Abyss
	}
}

/**
Links rooms as follows, assuming default dungeon size of 20 rooms:

prev		   next
9 <-> 0 <-> 1 <-> 2  ...  9 <-> 0
|	  | adj |     |		  |		|
19	  10	11    12 ...  19	10

**/
void Cave::link_rooms(int dungeon_size)
{
	int half = dungeon_size / 2;

	// Linking first half of rooms 
	for (int i{ 0 }; i < half; ++i)
	{
		if (i == 0)
		{
			rooms[i]->set_prev(rooms[half - 1]);
			rooms[i]->set_next(rooms[i + 1]);
			rooms[i]->set_adj(rooms[i + half]);
		}
		else if (i == half - 1)
		{
			rooms[i]->set_prev(rooms[i - 1]);
			rooms[i]->set_next(rooms[0]);
			rooms[i]->set_adj(rooms[i + half]);
		}
		else
		{
			rooms[i]->set_prev(rooms[i - 1]);
			rooms[i]->set_next(rooms[i + 1]);
			rooms[i]->set_adj(rooms[i + half]);
		}

	}

	// Linking second half of rooms
	for (int i{ half }; i < dungeon_size; ++i)
	{
		if (i == 0)
		{
			rooms[i]->set_prev(rooms[half - 1]);
			rooms[i]->set_next(rooms[i + 1]);
			rooms[i]->set_adj(rooms[i + half]);
		}
	}
}

Cave::~Cave()
{
	for (size_t i{ 0 }; i < rooms.size(); ++i)
		delete rooms[i];

	std::cout << "Dungeon destroyed!\n";
}