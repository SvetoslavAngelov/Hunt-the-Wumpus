#include "stdafx.h"
#include "Player.h"
#include <iostream>


Player::Player(int position, const std::string& name) : position{ position }, name{ name }
{
	std::cout << "Player character " << name << " created!\n";
}

Player::~Player()
{
	std::cout << "Player killed!\n";
}

void Player::move_to(int new_pos)
{
	position = new_pos;
}

int Player::get_position() const
{
	return position;
}