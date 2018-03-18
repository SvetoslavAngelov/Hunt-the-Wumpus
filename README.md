# Hunt-the-Wumpus
March 18th 2018
Principles and Practice Using C++ Exercise 18.12

This is a little project which implements a version of the text adventure game "Hunt the Wumpus", invented by Gregory Yob in 1975.
This version of the game is based on exercise 18.12, from the book "Programming Principles and Practice Using C++" by Bjarne Stroustrup.

Description taken from the book: 
"The basic premise is that a rather smelly monster lives in a dark cave consisting of connected rooms. Your job is to slay the wumpus
using bow and arrow. In addition to the wumpus, the cave has two hazards: bottomless pit and giant bats. If you enter a room with a
bottomless pit, it's the end of the game for you. If you enter a room with a bat, the bat picks you and drops you into another room. 
If you enter a room with the wumpus, or he enters into yours, he eats you. When you enter a room you will be told if a hazard is nearby:
    "I smell the wumpus": It's in an adjoining room. 
    "I feel a breeze": One of the adjoining rooms is a bottomless pit. 
    "I hear a bat": A giant bat is in the adjoining room.
For your convenience rooms are numbered. Every room is connected by tunnels to three other rooms. When entering a room, you are told 
something like "You are in room 12; there are tunnels to rooms 1, 13, and 4; move or shoot?" Possible answers are m13 ("Move to room
13") and s13-4-3 ("Shoot an arrow through rooms 13, 4 and 3"). The range of an arrow is three rooms. At the start of the game, you 
have five arrows. The snag about shooting is that it wakes the wumpus and he moves to a room adjoining the one he was in - that could be
your room. "
