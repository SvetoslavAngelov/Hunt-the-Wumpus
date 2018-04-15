#pragma once
#include <iostream>

class Room
{
public:
	enum class Hazard {
		None = 0, Bats, Abyss
	};
	
	/*Constructors*/
	explicit Room(int);
	Room(int, Hazard, Room*, Room*, Room*);

	/*Copy constructor*/
	Room(const Room&);

	/*Copy assignment constructor*/
	Room& operator=(const Room&);

	/*Adds a link to a "previous" and "next" room object*/
	Room* add_room(Room*);

	/*Adds a link to "adjacent" room object*/
	Room* add_room_vertical(Room*);

	/*Returns the room number as integer*/
	inline int get_index() const { return index; }

	/*Returns the type of hazard the room has*/
	inline Hazard get_hazard() const { return hazard;  }

	/*Sets the room hazard to the type that is being passed, i.e. no hazard, abyss or bats*/
	inline void set_hazard(Hazard h) { hazard = h; }

	/*Returns a pointer to a room object linked as "previous" (prev)*/
	inline const Room* get_prev() const { return prev; }

	/*Returns a pointer to a room object linked as "next" (next)*/
	inline const Room* get_next() const { return next; }

	/*Returns a pointer to a room object linked as "adjacent" (adj)*/
	inline const Room* get_adj() const { return adj; }

	/*Destructor*/
	~Room(); 

	/*Custom operator which outputs the room's current number and the room numbers of all objects it's linked to*/
	friend std::ostream& operator<<(std::ostream&, const Room&);

private:
	int index;
	Hazard hazard;
	Room* prev;
	Room* next;
	Room* adj;

};

