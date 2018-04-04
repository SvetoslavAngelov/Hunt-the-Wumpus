// Hunt the Wumpus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "World.h"
#include <iostream>
#include <string>

int main()
{
	std::cout << "Welcome to Hunt the Wumpus! Please enter your character's name:\n";  // TODO add full game welcome note and game instructions 
	
	std::string player_name; 
	std::cin >> player_name; 

	World world{ player_name };
	world.run();
	 
	std::cout << "Thank you for playing my version of Hunt the Wumpus!\n"; // TODO add a leaving note
	

	return 0;
}

