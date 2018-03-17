#include "stdafx.h"
#include "Room.h"

Room::Room() {}

Room::Room(int index)
	: index{ index }, hazard{ Hazard::None }, prev{ nullptr }, next{ nullptr }, adj{ nullptr } {}

Room::Room(int index, Hazard hazard)
	: index{ index }, hazard{ hazard }, prev{ nullptr }, next{ nullptr }, adj{ nullptr } {}

Room::Room(int index, Hazard hazard, const Room* prev, const Room* next, const Room* adj)
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

Room::~Room()
{
	delete prev;
	delete next;
	delete adj;
}

void Room::set_prev(const Room* r)
{
	prev = r;
}

void Room::set_next(const Room* r)
{
	next = r;
}

void Room::set_adj(const Room* r)
{
	adj = r;
}

void Room::set_hazard(Hazard h)
{
	hazard = h;
}

const Room* Room::get_prev() const
{
	return prev; 
}
const Room* Room::get_next() const
{
	return next;
}

int Room::room_index() const
{
	return index;
}

std::ostream& operator<<(std::ostream& os, const Room& r)
{
	os << "Current " << r.index << " previous " << r.prev->index << " next " << r.next->index << " adjacent " << r.adj->index << '\n';
	return os;
}