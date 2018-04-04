#include "stdafx.h"
#include "Player.h"
#include "Cave.h"
#include "Room.h"
#include "Wumpus.h"
#include <iostream>


Player::Player(const std::string& name) : position{ 0 }, name{ name }, state{ true }
{
	std::cout << "Player character " << name << " created!\n";
}

Player::~Player()
{
	std::cout << "Player killed!\n";
}

void Player::shoot_at(const int room_number, const Cave* cave, Wumpus* wumpus) const
{
	const Room* room = cave->room_index(room_number);
	int wumpus_pos = wumpus->get_position(); 
	
	// TODO add random arrow path
	// Arrow range of 3 rooms
	if (wumpus_pos == room->get_index() ||
		wumpus_pos == room->get_next()->get_index() ||
		wumpus_pos == room->get_next()->get_next()->get_index())
	{
		std::cout << "Wumpus hit!\n";
		wumpus->kill();
	}
	else
	{
		std::cout << "You missed!\n";
		const Room* wumpus_room = cave->room_index(wumpus->get_position());
		wumpus->move_to(wumpus_room->get_next()->get_index());
	}
}
