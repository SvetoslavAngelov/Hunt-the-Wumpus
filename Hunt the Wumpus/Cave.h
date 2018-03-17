#pragma once
#include <vector>

class Cave
{
public:
	Cave();
	~Cave();

private:
	void create_rooms(int);
	void set_hazards(int);
	void link_rooms(int);

private:
	std::vector <class Room*> rooms;

};

