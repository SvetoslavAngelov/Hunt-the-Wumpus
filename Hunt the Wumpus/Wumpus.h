#pragma once
#include "Actor.h"
#include <string>

class Wumpus : public Actor
{
public:
	explicit Wumpus(int position);
	~Wumpus();

	void move_to(int) override;
	int get_position() const override;

	// TODO output Monster state, i.e. has it moved? 

private:
	int position;
	std::string name;

};

