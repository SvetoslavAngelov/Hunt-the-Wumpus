#pragma once
#include <iostream>

class Room
{
public:
	enum class Hazard {
		None = 0, Bats, Abyss
	};

	Room();
	explicit Room(int);
	Room(int, Hazard);
	Room(int, Hazard, const Room*, const Room*, const Room*);

	Room(const Room&);
	Room& operator=(const Room&);

	~Room();

	void set_prev(const Room*);
	void set_next(const Room*);
	void set_adj(const Room*);
	void set_hazard(Hazard);

	//TODO rewrite, too many getters and setters 
	const Room* get_prev() const;
	const Room* get_next() const;
	int room_index() const;

	friend std::ostream& operator<<(std::ostream&, const Room&);

private:
	int index;
	Hazard hazard;
	const Room* prev;
	const Room* next;
	const Room* adj;

};

