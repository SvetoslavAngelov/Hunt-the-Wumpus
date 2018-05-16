#include "stdafx.h"
#include "Cave.h"
#include "Room.h"
#include <random>
#include <ctime>

Cave::Cave() : dungeon_size{20}
{
	create_rooms();

	std::srand(static_cast<int>(std::time(0)));
	std::random_shuffle(rooms.begin(), rooms.end());

	set_hazards();

	std::random_shuffle(rooms.begin(), rooms.end());

	link_rooms();
}

int Cave::set_player_location()
{
	int player_location{ 0 };

	for (auto cit = rooms.begin(); cit != rooms.end(); ++cit)
	{
		if ((*cit)->get_hazard() == Room::Hazard::None)
		{
			player_location = (*cit)->get_index();
			break;
		}
	}
	return player_location;
}

int Cave::set_random_location(int player_location)
{
	int wumpus_location{ 0 };

	auto randint = [](int min, int max)->int
	{
		static std::default_random_engine ran;
		return std::uniform_int_distribution<>{min, max}(ran);
	};
	
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

const Room* Cave::get_room_at(int index) const 
{
	const Room* room = rooms[0];

	for (auto cit = rooms.begin(); cit != rooms.end(); ++cit)
	{
		if (index == (*cit)->get_index())
			room = *cit; 
	}

	return room; 
}

Cave::~Cave()
{
	for (auto it = rooms.begin(); it != rooms.end(); ++it)
		delete *it;
}

void Cave::create_rooms()
{
	for (int i{ 1 }; i < dungeon_size + 1; ++i)
	{
		rooms.push_back(new Room{i});
	}
}

void Cave::set_hazards() const
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

void Cave::link_rooms() const
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
	 * Room 1 links to 11 and 2 to 12... */
	for (int i{ 0 }; i < dungeon_size / 2; ++i)
	{
		rooms[i]->add_room_vertical(rooms[i + (dungeon_size / 2)]);
	}
}

