#pragma once

/* Abstract class which provides an interface for the Player and Wumpus derived classes via pure virtual functions*/
class Actor
{
public:
	virtual void kill() = 0;
	virtual bool is_alive() const = 0;
	virtual void move_to(int) = 0;
	virtual int get_position() const = 0;
	inline virtual ~Actor() {}

};
