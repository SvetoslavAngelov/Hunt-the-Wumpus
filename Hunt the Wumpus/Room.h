#pragma once
#include <iostream>

class Room
{
public:
	enum class Hazard {
		None = 0, Bats, Abyss
	};
	
	explicit Room(int);
	Room(int, Hazard, Room*, Room*, Room*);

	const Room(const Room&);
	Room& operator=(const Room&);

	Room* add_room(Room*);
	Room* add_room_vertical(Room*);

	inline void set_index(const int n) { index = n; }
	inline void set_hazard(Hazard h) { hazard = h; }
	
	~Room(); 

	friend std::ostream& operator<<(std::ostream&, const Room&);
	friend std::ostream& operator<<(std::ostream&, const Hazard&);

private:
	int index;
	Hazard hazard;
	Room* prev;
	Room* next;
	Room* adj;

};

