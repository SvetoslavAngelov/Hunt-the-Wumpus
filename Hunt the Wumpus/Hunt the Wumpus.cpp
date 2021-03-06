// Hunt the Wumpus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include <string>

int main()
{
	std::cout << "Welcome to my version of Hunt the Wumpus! You find yourself in a dark cave,\n"
		<< "consisting of connected rooms. There is a smelly monster which lives in the cave\n"
		<< "called the Wumpus. Your job is to slay the Wumpus using a bow and arrow! In addition\n"
		<< "to the Wumpus, the cave has two hazards - an abyss and giant bats. If you enter a room\n"
		<< "with an abyss, the ends for you. If you enter a room with giant bats, you get transported\n"
		<< "to a random room in the cave! If you enter a room with the Wumpus, or it enters your room,\n"
		<< "it eats you and the game is over for you! When you enter a room, you will be told if a hazard\n"
		<< "is nearby:\n"
		<< "     You smell the Wumpus! - The Wumpus is in a room nearby.\n"
		<< "     You feel a breeze! - there is an abyss in a room nearby.\n"
		<< "     You hear a bat! - there are giant bats in a room nearby.\n"
		<< "Every room is connected by tunnels to three other rooms. You can either go to one of the next\n"
		<< "rooms, or shoot at one of them. Be careful though! If you use your bow and arrow, the Wumpus \n"
		<< "will move to the next room, which could be yours!\n"
		<< "GOOD LUCK\n\n"
		<< "Enter your character's name:";

	std::string player_name; 
	std::cin >> player_name; 

	Game game{ player_name };
	game.run();
	 
	std::cout << "Thank you for playing my version of Hunt the Wumpus!\n";
	
	return 0;
}

