#pragma once
#include <vector>

class Cave
{
public:
	/*Constructor
	 *First creates a cave with 20 rooms, assigning each room number from 1 to 20
	 *Then randomly scrambles the rooms, so that the room number does not correspond to position in array
	 *Assigns hazards to each room, 50% with no hazard, 25% with bats and 25% with abyss
	 *Scrambles rooms in array, so hazards are not associated with room position in array
	 *Lastly links rooms, so each room connects to three more*/
	Cave();

	/*Finds the first safe (no hazard) room and sets it as the player's starting location*/
	int set_player_location();

	/*Takes an int as a random number generator seed and returns a random location between 1 and 20*/
	int set_random_location(const int);

	/*Takes a number and returns a pointer to a room in the cave with the corresponding room number*/
	const class Room* get_room_at(const int) const;

	/*Destructor*/
	~Cave();
	
private:
	/*Creates an array of rooms with room numbers from 1 to 20*/
	void create_rooms(const int);

	/*Sets a hazard for each room in the array 
	 *50% of rooms with no hazard, 25% with bats and 25% with abyss*/
	void set_hazards(const int);

	/*Links rooms together in the array, such that:
	 *prev			next
	 *20 <->  1   <-> 2  ...
     *|	      |adj    |
     *10 <->  11  <-> 12 ...*/
	void link_rooms(const int);

	/*Member types*/
	std::vector <class Room*> rooms;

};

