#pragma once
#include "Actor.h"
#include <string>

class Player : public Actor
{
public:
	/* Constructor*/
	explicit Player(const std::string& name);

	/* Destructor*/
	inline ~Player() {}
	
	/* Sets the player's state to "dead"*/
	inline void kill() override { alive = false; }

	/* Returns the player's current state, dead or alive*/
	inline bool is_alive() const override{ return alive; }

	/* Returns the room number the player is currently in*/
	inline int get_position() const override { return position; }

	/* Moves the player to the chosen location*/
	inline void move_to(int room_number) override { position = room_number; }
	
private:
	bool alive;
	int position;
	std::string name;

};