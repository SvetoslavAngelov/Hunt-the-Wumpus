#pragma once
#include "Actor.h"
#include <string>

class Player : public Actor
{
public:
	explicit Player(const std::string& name);
	~Player();
	
	
	inline void kill() override { state = false; }
	inline bool is_alive() const override { return state; }
	inline int get_position() const override { return position; }
	inline void move_to(const int room_number) override { position = room_number; }// TODO
	
	void shoot_at(const int room_number, const class Cave* cave, class Wumpus* wumpus) const;

private:
	int position;
	std::string name;
	bool state; 
};