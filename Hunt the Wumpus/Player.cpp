#include "stdafx.h"
#include "Player.h"
#include <iostream>


Player::Player(const std::string& name) : alive{ true }, position { 0 }, name{ name }
{
	std::cout << "Welcome " << name << "!\n";
}
