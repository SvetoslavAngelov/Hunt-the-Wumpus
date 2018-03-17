#pragma once
#include "Actor.h"
#include <string>

class Player : public Actor
{
public:
	Player(int position, const std::string& name);
	~Player();

	void move_to(int) override;
	int get_position() const override;

	// TODO shoot arrow 
	// TODO output player position

private:
	int position;
	std::string name;

};