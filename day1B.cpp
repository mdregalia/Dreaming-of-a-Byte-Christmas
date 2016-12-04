#include <iostream>
#include <string>

#include <cmath>
#include <unordered_map>
#include <sstream>

using namespace std;

string inputstr = "R4, R5, L5, L5, L3, R2, R1, R1, L5, R5, R2, L1, L3, L4, R3, L1, L1, R2, R3, R3, R1, L3, L5, R3, R1, L1, R1, R2, L1, L4, L5, R4, R2, L192, R5, L2, R53, R1, L5, R73, R5, L5, R186, L3, L2, R1, R3, L3, L3, R1, L4, L2, R3, L5, R4, R3, R1, L1, R5, R2, R1, R1, R1, R3, R2, L1, R5, R1, L5, R2, L2, L4, R3, L1, R4, L5, R4, R3, L5, L3, R4, R2, L5, L5, R2, R3, R5, R4, R2, R1, L1, L5, L2, L3, L4, L5, L4, L5, L1, R3, R4, R5, R3, L5, L4, L3, L1, L4, R2, R5, R5, R4, L2, L4, R3, R1, L2, R5, L5, R1, R1, L1, L5, L5, L2, L1, R5, R2, L4, L1, R4, R3, L3, R1, R5, L1, L4, R2, L3, R5, R3, R1, L3,";
int direction = 0;

int convert(int, int&);

void rotate(bool);

int main(){

	int xcoord = 0;
	int ycoord = 0;

	int i = 0;

	bool ended = 0;

	unordered_map<string,bool> locations;

	while (i < inputstr.length() && !ended){

		rotate(inputstr[i] == 'R');

		int * pointer = &xcoord;
		int multint = 1;

		if (direction % 2){
			pointer = &ycoord;
		}
		if (direction >= 2){
			multint = -1;
		}
		i++;

		int steps = convert(i, i);

		for (int j = 0; j < steps; j++){
			*pointer += multint;

			stringstream ssnew;
			string newstr;
			ssnew << xcoord << ' ' << ycoord;
			newstr = ssnew.str();

			cout << newstr << "\n";

			if (locations.count(newstr)){
				cout << "result: " << abs(xcoord) + abs(ycoord) << "\n";
				ended = 1;
				break;
			}
			locations[newstr] = 1;
		}

	}

	cout << "result: " << abs(xcoord) + abs(ycoord) << "\n";


}

int convert(int start, int& i){ //takes start and from string and puts it in an int
	int place = inputstr.length();
	string tempstr;
	while (i < place){
		//cout << i << "\n";
		if (inputstr[i] == ','){
			tempstr = inputstr.substr(start, i - start);
			//cout << inputstr.substr(start, i - start) << "\n";
			cout << tempstr << "\n";
			break;
		}
		i++;
	}
	i+= 2;

	return stoi(tempstr);
}

void rotate(bool clockwise){ //true is right, false is left
	if (clockwise){
		direction += 1;
	}
	else{
		direction -= 1;
	}
	if (direction == -1){
		direction = 3;
	}
	else if (direction == 4){
		direction = 0;
	}
}


//cases
/*
Best way to do this?
Matrixes

*/	
