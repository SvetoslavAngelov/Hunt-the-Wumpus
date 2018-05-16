#include "stdafx.h"
#include "Game.h"
#include "Cave.h"
#include "Room.h"
#include "Player.h"
#include "Wumpus.h"
#include <iostream>

Game::Game(const std::string& player_name)
{
	cave = new Cave;
	player = new Player{ player_name };
	wumpus = new Wumpus;
	
	arrow.count = 5; 
	arrow.target_location = 0;
	arrow.fired = false;

	int player_location = cave->set_player_location();
	player->move_to(player_location);

	int wumpus_location = cave->set_random_location(player_location);
	wumpus->move_to(wumpus_location);
}

void Game::run()
{
	while (player->is_alive() && wumpus->is_alive())
	{
		display_output();
		handle_input();
		update_player_state();
		update_wumpus_state();
	}
}

void Game::display_output() const
{
	const Room* room = cave->get_room_at(player->get_position());
	int wumpus_position = wumpus->get_position();

	std::cout << *room << "You have " << arrow.count << " arrows left!\n";

	if (		room->get_prev()->get_hazard() == Room::Hazard::Bats
			||	room->get_next()->get_hazard() == Room::Hazard::Bats
			||	room->get_adj()->get_hazard() == Room::Hazard::Bats)
	{
		std::cout << "Your hear bats!\n";
	}
	else if (	room->get_prev()->get_hazard() == Room::Hazard::Abyss
			||	room->get_next()->get_hazard() == Room::Hazard::Abyss
			||	room->get_adj()->get_hazard() == Room::Hazard::Abyss)
	{
		std::cout << "You feel a breeze!\n";
	}
	else if (	wumpus_position == room->get_prev()->get_index()
			||	wumpus_position == room->get_next()->get_index()
			||	wumpus_position == room->get_adj()->get_index())
	{
		std::cout << "You smell the Wumpus!\n";
	}
}

void Game::handle_input()
{
	std::cout	<< "Move or shoot?\n"
				<< "To move type M and to shoot type S:\n";

	char ch;
	std::cin >> ch;

	switch (ch)
	{
	case 'M' : case 'm' : 
		player_move();
		break;
	case 'S' : case 's' : 
		player_shoot();
		break;
	default:
		std::cout << "Invalid input! Try again.\n";
		break;
	}
}

void Game::update_player_state()
{
	int player_position = player->get_position();
	int wumpus_position = wumpus->get_position(); 
	Room::Hazard player_room_hazard = cave->get_room_at(player_position)->get_hazard(); 

	if (player_room_hazard == Room::Hazard::Abyss
		|| player_position == wumpus_position)
	{
		player->kill();
		std::cout << "You died!\n";
	}
	else if (player_room_hazard == Room::Hazard::Bats)
	{
		player_position = cave->set_random_location(player_position);
		player->move_to(player_position);
		std::cout << "You got picked up by bats! They will now take you to an unknown room!\n";
	}
}

void Game::update_wumpus_state()
{
	int wumpus_location = wumpus->get_position();

	if (wumpus_location == arrow.target_location)
	{
		wumpus->kill();
		std::cout << "You made it! You've slain the Wumpus!\n";
	}
	else if (arrow.fired && wumpus->is_alive())
	{
		wumpus->move_to(cave->set_random_location(player->get_position())); // TODO replace with a choice of three rooms 
		arrow.fired = false;
	}
}

void Game::player_move()
{
	std::cout << "Where to?\n";

	int new_position;
	std::cin >> new_position;

	const Room* room = cave->get_room_at(player->get_position());

	if (new_position == room->get_prev()->get_index()
		|| new_position == room->get_next()->get_index()
		|| new_position == room->get_adj()->get_index())
	{
		player->move_to(new_position);
	}
	else
	{
		std::cout << "You can't go there! Try again.\n";
	}
}

void Game::player_shoot()
{
	if (arrow.count == 0)
	{
		std::cout << "You are out of arrows!\n";
		return;
	}

	std::cout << "Shoot towards?\n";

	int shoot_location;
	std::cin >> shoot_location;

	const Room* room = cave->get_room_at(player->get_position());

	if (shoot_location == room->get_prev()->get_index()
		|| shoot_location == room->get_next()->get_index()
		|| shoot_location == room->get_adj()->get_index())
	{
		--arrow.count;
		arrow.fired = true;
		arrow.target_location = shoot_location;
	}
	else
	{
		std::cout << "You can't see that room, you can't shoot at it! Try again.\n";
	}
}

Game::~Game()
{
	delete player;
	delete wumpus;
	delete cave;
}

