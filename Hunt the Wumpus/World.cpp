#include "stdafx.h"
#include "World.h"
#include "Player.h"
#include "Wumpus.h"
#include "Cave.h"

World::World(const std::string& player_name)
{
	// TODO determine player and monster location 
	player = new Player{ 1, player_name };
	wumpus = new Wumpus{ 2 };
	cave = new Cave;

}

World::~World()
{
	delete player;
	delete wumpus;
	delete cave;

}