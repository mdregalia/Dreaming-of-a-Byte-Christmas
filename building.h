#ifndef BUILDING_H
#define BUILDING_H

#include <string>
#include <vector>

using namespace std;

class building
{
public:
	building();
	building(string, int, int, unsigned long int, bool);
	~building();

	//returns all valid BFS configurations
	//but duplicates might be possible - main needs to check for that
	//main has to put in a check to see if the next level produces a solution
	vector<string> nextLevelOptions(bool &);

private:
	int floors;
	int chipTypes;
	int elevCapacity;
	int currentFloor;
	unsigned long int previd;
	string elevatorContains;
	vector< string > floorGen;
	vector< string > floorChips;

	int nextfloor;
	vector< string > nextFloorGen;
	vector< string > nextFloorChips;


	//returns a string version of the building
	string stringifybuild();

	string stringifynext();

	//sees if the next build is a valid configuration
	bool checkBuild();

	//sees if the build solves the puzzle
	bool isSolution();

	//makes the next floor version of the elevator
	bool moveElevator(bool);

	void printbuild();

	bool checkElevator();

};

#endif