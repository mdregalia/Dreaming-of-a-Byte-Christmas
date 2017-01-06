#include "building.h"

#include <iostream>
#include <vector>
#include <sstream>

building::building(){
	floors = -1;
	chipTypes = -1;

	return;
}

building::~building(){
	return;
}

building::building(string inputstr, int floors_in, int chips_in, unsigned long int idin, bool print){
	//assembles building info here

	//string should resemble
	//[1]000010101010001010010101010101 for example but not exactly that

	floors = floors_in;
	chipTypes = chips_in;

	previd = idin;

	//default unchangable for this problem
	elevatorContains = "xx";
	elevCapacity = 2;

	//get the current floor
	int startingPlace = 0;
	string currentFloorStr;
	for (int i = 0; i < inputstr.length(); i++){
		if (inputstr[i] == ']'){
			//assumes that first place is a '['
			currentFloorStr = inputstr.substr(1,i - 1);
			//cout << inputstr << "\n";
			startingPlace = i + 1;
			break;
		}
	}

	//cout << "[" << currentFloorStr << "]\n";

	currentFloor = stoi(currentFloorStr);

	//setup the rest of the floor strings
	for (int i = 0; i < floors; i++){
		floorGen.push_back(inputstr.substr(i*chipTypes*2 + startingPlace,chipTypes));
		floorChips.push_back(inputstr.substr(i*chipTypes*2 + startingPlace + chipTypes, chipTypes));
		if (print){
			cout << "Gen " << floorGen[i] << " Chips " << floorChips[i] << "\n";
		}
	}

}

string building::stringifybuild(){
	//first part

	string retstr = "[";

	stringstream ssnew;
	ssnew << currentFloor;
	retstr += ssnew.str();

	retstr += "]";

	//bulk of string
	for (int i = 0; i < floorGen.size(); i++){
		retstr += floorGen[i] + floorChips[i];
	}

	return retstr;
}

string building::stringifynext(){
	//first part

	string retstr = "[";

	stringstream ssnew;
	ssnew << nextfloor;
	retstr += ssnew.str();

	retstr += "]";

	//bulk of string
	for (int i = 0; i < nextFloorGen.size(); i++){
		retstr += nextFloorGen[i] + nextFloorChips[i];
	}

	retstr += "[";

	stringstream ssnew2;
	ssnew2 << previd;
	retstr += ssnew2.str();

	retstr += "]";

	//cout << retstr << "\n";

	//printbuild();
	//cout << retstr << "\n";

	return retstr;
}


bool building::isSolution(){
	bool finished = true;
	for (int i = 0; i < chipTypes; i++){
		if (nextFloorGen[floors-1][i] != '1'){
			finished = false;
			break;
		}
		if (nextFloorChips[floors-1][i] != '1'){
			finished = false;
			break;
		}
	}

	return finished;
}

bool building::checkBuild(){
	//any amount of microchips with other microchips are ok
	//any amount of generators with other generators are okay
	//if there is a microchip then there must be 1) no generator or 2) it's corresponding generator

	//count the number of generators
	//for each microchip if more than one generator, valid if matching generator
	bool correctness = true;

	for (int j = 0; j < floors; j++){

		bool genCount = false;

		for (int i = 0; i < chipTypes; i++){
			if (nextFloorGen[j][i] == '1'){
				genCount = true;
			}
		}

		//if there are generators on that floor, then the chips had better have their own matching generator
		if (genCount){
			for(int i = 0; i < chipTypes; i++){
				if (nextFloorChips[j][i] == '1' && nextFloorGen[j][i] != '1'){
					//cout << "Floor: " << j << " Chip: " << i << "\n";
					//cout << nextFloorChips[j] << " " << nextFloorGen[j] << "\n";
					correctness = false;
				}
			}
		}
	}

	return correctness;
}

//this changes the value of nextElevator
bool building::moveElevator(bool upordown){ //1 is up, 0 is down

	//cout << "Moving Elevator\n";

	int addition = 1;
	if (!upordown){ //down
		addition = -1;
	}

	nextfloor = addition + currentFloor;

	//cout << nextfloor << "\n";

	if (nextfloor < 0 || nextfloor >= floors){
		return false;
	}

	//copy existing building info to next building
	nextFloorGen = floorGen;
	nextFloorChips = floorChips;
 
	//set both previous places to zero
	for (int i = 0; i < elevCapacity; i++){
		
		if (elevatorContains[i] == 'x'){
			continue;
		}

		int place = elevatorContains[i] - '0';
		//cout << place << "\n";
		if (place >= chipTypes){ //then it is a chip
			//cout << currentFloor << "," << place - chipTypes << " is " << nextFloorChips[currentFloor][place - chipTypes] << "\n";
			nextFloorChips[currentFloor][place - chipTypes] = '0';
			nextFloorChips[nextfloor][place - chipTypes] = '1';
		}
		else{ //then it is a generator
			nextFloorGen[currentFloor][place] = '0';
			nextFloorGen[nextfloor][place] = '1';
		}
	}

	//**** changing what the elevator contains here might not be valid***

	//elevatorContains = "xx";
	//printbuild();

	//cout << checkBuild() << "\n";

	return checkBuild();

	//set new places to one

}

vector<string> building::nextLevelOptions(bool &input){ //input == true if a valid format
	//make all combos of elevators
	input = false;

	vector<string> possiblenextfloors;

	elevatorContains = "xx";

	//try nothing
	if (moveElevator(true)){
		//printbuild();
		if (checkBuild()){
			possiblenextfloors.push_back(stringifynext());
			if (isSolution()){
				printbuild();
				input = true;
			}
		}
	}

	if (moveElevator(false)){
		//printbuild();
		if (checkBuild()){
			possiblenextfloors.push_back(stringifynext());
		}
	}

	for (int i = 0; i < chipTypes*2; i++){
		//try with only one
		elevatorContains = "";
		elevatorContains += (char) i + '0';
		elevatorContains += "x";

		//in order to put things on the elevator the things must be on the right floor
		if (!checkElevator()){
			continue;
		}

		if (moveElevator(true)){
			//printbuild();
			if (checkBuild()){
				possiblenextfloors.push_back(stringifynext());
				if (isSolution()){
					printbuild();
					input = true;
				}
			}
		}

		if (moveElevator(false)){
			//printbuild();
			if (checkBuild()){
				possiblenextfloors.push_back(stringifynext());
			}
		}

		//exit(0);

		//try with 
		for (int j = i + 1; j < chipTypes*2; j++){
			elevatorContains = "";
			elevatorContains += (char) i + '0';
			elevatorContains += (char) j + '0';

			//in order to put things on the elevator they have to be on the floor
			if (!checkElevator()){
				continue;
			}

			if (moveElevator(true)){
				//printbuild();
				if (checkBuild()){
					possiblenextfloors.push_back(stringifynext());
					if (isSolution()){
						printbuild();
						input = true;
					}
				}
			}

			if (moveElevator(false)){
				//printbuild();
				if (checkBuild()){
					possiblenextfloors.push_back(stringifynext());
				}
			}
		}
	}

	return possiblenextfloors;
}

void building::printbuild(){
	cout << "[" << nextfloor << "] " << elevatorContains << "\n";

	for (int i = 0; i < floors; i++){
		cout << "Gen " << nextFloorGen[i] << " Chips " << nextFloorChips[i] << "\n";
	}

	cout << stringifynext() << "\n";
}

bool building::checkElevator(){ //elevator contains must be updated before this
	for (int i = 0; i < elevCapacity; i++){
		if (elevatorContains[i] != 'x'){
			int place = elevatorContains[i] - '0';
			if (place > chipTypes){ //then it is a chip
				if(floorChips[currentFloor][place - chipTypes] == '0'){
					return false;
				}
			}
			else{ //then it is a generator
				if (floorGen[currentFloor][place] == '0'){
					return false;
				}
			}
		}
	}

	return true;
}