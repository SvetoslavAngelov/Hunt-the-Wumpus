#pragma once
#include <vector>
#include <random>

class Cave
{
public:
	Cave();
	~Cave();

private:
	void create_rooms(const int);
	void set_hazards(const int);
	void link_rooms(const int);

	// TODO remove
	void debug_print();

private:
	std::vector <class Room*> rooms;

};

