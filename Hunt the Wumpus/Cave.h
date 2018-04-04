#pragma once
#include <vector>

class Cave
{
public:
	Cave();

	int set_player_location();
	int set_wumpus_location(const int);
	const class Room* room_index(const int) const;

	~Cave();
	
private:
	void create_rooms(const int);
	void set_hazards(const int);
	void link_rooms(const int);
	
	// TODO debug function, remove
	void debug_print();

private:
	std::vector <class Room*> rooms;

};

