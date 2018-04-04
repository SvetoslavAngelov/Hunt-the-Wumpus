#pragma once
#include <string>

class World
{
public:
	World(const std::string& player_name);
	void run();

	~World();
protected:
	void position_output();
	void command_input(); 
	bool is_valid(const std::string&);
	
private:
	class Cave* cave;
	class Player* player;
	class Wumpus* wumpus;
	
};

