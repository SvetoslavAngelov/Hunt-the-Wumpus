#pragma once
#include <string>

class World
{
public:
	World(const std::string&);

	~World();

private:
	class Player* player;
	class Wumpus* wumpus;
	class Cave* cave;

};

