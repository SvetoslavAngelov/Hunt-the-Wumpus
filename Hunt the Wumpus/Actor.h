#pragma once

class Actor
{
protected:
	inline Actor() {}
	inline virtual ~Actor() {}

	virtual void move_to(int) = 0;
	virtual int get_position() const = 0;

};
