#pragma once
#include <string>
	
struct Arrow {
	int count; 
	int target_location;
	bool fired;
};

class Game{
public:
	/*Constructor*/
	Game(const std::string& player_name);

	/*Runs the main game loop*/
	void run();

	/*Destructor*/
	~Game();

private:
	/*Outputs player position and nearby hazards to the console*/
	void display_output();

	/*Handles console input and depending on player choice 
	 *delegates to either player_move() or player_shoot()*/
	void handle_input();

	/*Checks if player is still alive after last player action*/
	void update_player_state();

	/*Checks if wumpus is alive after last player action*/
	void update_wumpus_state();

	/*Queries player for target location to move to and then changes player position*/
	void player_move();

	/*Queries player for a target location and then shoots an arrow at said location*/
	void player_shoot();
	
	/*Member types*/
	bool player_is_alive; 
	bool wumpus_is_alive;
	Arrow arrow;
	class Cave* cave;
	class Player* player;
	class Wumpus* wumpus;

};
