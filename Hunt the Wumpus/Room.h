#pragma once

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

	int room_index() const;

private:
	int index;
	Hazard hazard;
	const Room* prev;
	const Room* next;
	const Room* adj;

};

