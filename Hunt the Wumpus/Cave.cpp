#include "stdafx.h"
#include "Cave.h"
#include "Room.h"
#include <algorithm>
#include <random>
#include <ctime>
#include <iostream>

Cave::Cave()
{
	constexpr int dungeon_size{ 20 }; // TODO add custom size rooms, current default room size set to 20

	create_rooms(dungeon_size);
		
	// Seed the random generator and scramble the room numbers in the sequence
	std::srand(static_cast<int>(std::time(0)));
	std::random_shuffle(rooms.begin(), rooms.end());

	set_hazards(dungeon_size);

	// Scramble rooms again, so hazards are not associated with room posiiton 
	std::random_shuffle(rooms.begin(), rooms.end());

	link_rooms(dungeon_size);

	//debug_print();

	std::cout << "Dungeon with size " << dungeon_size << " created!\n";
}

int Cave::set_player_location()
{
	int player_location{ 0 };

	for (std::vector<Room*>::const_iterator cit = rooms.begin(); cit != rooms.end(); ++cit)
	{
		if ((*cit)->get_hazard() == Room::Hazard::None)
		{
			player_location = (*cit)->get_index();
			break;
		}
	}
	return player_location;
}

int Cave::set_wumpus_location(const int player_location)
{
	int wumpus_location{ 0 };

	auto randint = [](int min, int max)->int
	{
		static std::default_random_engine ran;
		return std::uniform_int_distribution<>{min, max}(ran);
	};

	// TODO remove when custom size dungeons are added
	int dungeon_size = static_cast<int>(rooms.size());
	
	// Find a random number between the player's location and the cave size
	int temp_location = randint(player_location, dungeon_size);

	if (player_location != temp_location) 
		wumpus_location = temp_location;
	else if (player_location == temp_location && player_location == dungeon_size)
		wumpus_location = temp_location - 1; 
	else 
		wumpus_location = temp_location + 1; 

	return wumpus_location;
}

const Room* Cave::room_index(const int index) const 
{
	const Room* room = rooms[0];

	for (std::vector<Room*>::const_iterator cit = rooms.begin(); cit != rooms.end(); ++cit)
	{
		if (index == (*cit)->get_index())
			room = *cit; 
	}

	return room; 
}

void Cave::create_rooms(const int dungeon_size)
{
	for (int i{ 1 }; i < dungeon_size + 1; ++i)
	{
		rooms.push_back(new Room{i});
	}
}

void Cave::set_hazards(const int dungeon_size)
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

/* Links rooms as follows, assuming a cave size of 20:
prev			next
20 <->  1   <-> 2  ...
|		|adj	|
10 <->  11  <-> 12 ... */
void Cave::link_rooms(const int dungeon_size) 
{
	// Linking next and previous rooms first 
	for (int i{ 0 }; i < dungeon_size; ++i)
	{
		if (i == dungeon_size - 1)
		{
			rooms[i]->add_room(rooms[0]);
		}
		else
		{
			rooms[i]->add_room(rooms[i + 1]);
		}
	}

	/* Linking the two halfs together
		Room 1 links to 11 and 2 to 12, etc, */
	for (int i{ 0 }; i < dungeon_size / 2; ++i)
	{
		rooms[i]->add_room_vertical(rooms[i + (dungeon_size / 2)]);
	}
}

void Cave::debug_print()
{
	for (std::vector<Room*>::const_iterator cit = rooms.begin(); cit != rooms.end(); ++cit)
		std::cout << **cit; 
}

Cave::~Cave()
{
	for (std::vector<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it)
		delete *it; 

	std::cout << "Dungeon destroyed!\n";
}