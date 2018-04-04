#include "stdafx.h"
#include "World.h"
#include "Cave.h"
#include "Room.h"
#include "Player.h"
#include "Wumpus.h"
#include <iostream>

World::World(const std::string& player_name)
{
	cave = new Cave;
	player = new Player{ player_name };
	wumpus = new Wumpus;
	
	int player_location = cave->set_player_location();
	player->move_to(player_location);

	int wumpus_location = cave->set_wumpus_location(player_location);
	wumpus->move_to(wumpus_location);

}

bool World::is_valid(const std::string& input)
{
	// TODO add input checks 
	std::string temp = input; 
	return true; 
}

void World::position_output()
{
	std::cout << *cave->room_index(player->get_position())
		<< "Move or shoot?\n";
}

void World::command_input()
{
	std::string input; 
	std::cin >> input;  
	
	if (is_valid(input))
	{
		std::string temp;
		for (std::string::const_iterator cit = input.begin() + 1; cit != input.end(); ++cit)
		{
			temp.push_back(*cit);
		}

		int room_number = std::stoi(temp);

		switch (input[0])
		{
		case 'm': case 'M':
			player->move_to(room_number);
			break;
		case 's': case 'S':
			player->shoot_at(room_number, cave, wumpus);
			break;
		default:
			std::cout << "Incorrect input!\n";
			break;
		}
	}
}


void World::run()
{
	while (player->is_alive() && wumpus->is_alive())
	{
		position_output();
		command_input();
		// TODO
	}
	
	/*main game loop
		 while player and wumpus alive 
			each loop update output - are you near an abyss or a wumpus? 
			ask player for input move or shoot? 
			if move change player position and determine action
				is it abyss? - player dead, break loop
				is it bats? - change player location, then determine action 
				is it wumpus? - player dead, break loop 
				is it no hazard? - fine continue 
			if shoot 
				determine arrow room range 
					is wumpus hit? 
						if no, wumpus moves
							determine new location 
						if yes, game won and break loop*/
}

World::~World()
{
	delete player;
	delete wumpus;
	delete cave;
}

