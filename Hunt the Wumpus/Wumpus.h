#pragma once
#include "Actor.h"
#include <string>

class Wumpus : public Actor
{
public:
	/*Constructor*/
	Wumpus();

	/*Destructor*/
	~Wumpus();

	/*Sets the wumpus' state to "dead"*/
	inline void kill() override { alive = false; }

	/*Returns the wumpus' current state, dead or alive*/
	inline bool is_alive() const override { return alive; }

	/*Returns the room number the wumpus is currently in*/
	inline int get_position() const override { return position; }

	/*Moves the player to the chosen location*/
	inline void move_to(const int new_position) override { position = new_position; }

private:
	bool alive;
	int position;
	std::string name;
};

