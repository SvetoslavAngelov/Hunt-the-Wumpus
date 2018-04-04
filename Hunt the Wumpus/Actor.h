#pragma once

class Actor
{
public:
	virtual void move_to(int) = 0;
	virtual void kill() = 0;
	virtual bool is_alive() const = 0;
	virtual int get_position() const = 0;
	
protected:
	inline Actor() {}
	inline virtual ~Actor() {}

};
