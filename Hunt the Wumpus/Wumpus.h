#pragma once
#include "Actor.h"
#include <string>

class Wumpus : public Actor
{
public:
	Wumpus();
	~Wumpus();

	inline void move_to(const int new_position) override { position = new_position; }
	inline void kill() override { state = false; }
	inline bool is_alive() const override { return state; }
	inline int get_position() const override { return position; }

	// TODO output Monster state, i.e. has it moved? 

private:
	int position;
	std::string name;
	bool state; 
};

