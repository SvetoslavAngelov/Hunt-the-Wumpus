#include "stdafx.h"
#include "Room.h"


Room::Room(int n)
	: index{ n }, hazard{ Room::Hazard::None }, prev{ nullptr }, next{ nullptr }, adj{ nullptr } {}

Room::Room(int index, Hazard hazard = Room::Hazard::None, Room* prev = nullptr, Room* next = nullptr, Room* adj = nullptr)
	: index{ index }, hazard{ hazard }, prev{ prev }, next{ next }, adj{ adj } {}

Room::Room(const Room& r)
{
	index = r.index;
	hazard = r.hazard;
	prev = r.prev;
	next = r.next;
	adj = r.adj;
}

Room& Room::operator=(const Room& r)
{
	index = r.index;
	hazard = r.hazard;
	prev = r.prev;
	next = r.next;
	adj = r.adj;
	return *this;
}

Room* Room::add_room(Room* n)
{
	if (n == nullptr) return this; 

	next = n;
	n->prev = this; 
	
	return this; 
}

Room* Room::add_room_vertical(Room* a)
{
	if (a == nullptr) return this; 

	adj = a; 
	a->adj = this; 

	return this; 
}

Room::~Room()
{
	if (prev != nullptr && prev->next != nullptr)
	{
		prev->next = nullptr;
		prev = nullptr;
		delete prev;
	}
	else delete prev;

	if (next != nullptr && next->prev != nullptr)
	{
		next->prev = nullptr;
		next = nullptr;
		delete next;
	}
	else delete prev;

	if (adj != nullptr && adj != nullptr)
	{
		adj->adj = nullptr;
		adj = nullptr;
		delete adj;
	}
	else delete adj;
}

std::ostream& operator<<(std::ostream& os, const Room& r)
{
	os << "Current " << r.index << " previous " << r.prev->index << " next " 
		<< r.next->index << " adjacent " << r.adj->index << " with " << r.hazard << '\n';
	return os;
}

std::ostream& operator<<(std::ostream& os, const Room::Hazard& h)
{
	switch (h)
	{
	case Room::Hazard::None :
		os << "no hazard";
		break;
	case Room::Hazard::Abyss :
		os << "abyss"; 
		break;
	case Room::Hazard::Bats :
		os << "bats";
		break;
	default: 
		os << "unknown hazard";
		break;
	}
	return os; 
}