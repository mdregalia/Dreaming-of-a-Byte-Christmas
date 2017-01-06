#include <iostream>
#include <unordered_map>
#include <string>

#include "building.h"

using namespace std;

unordered_map <string, bool> seenRoutes;

unordered_map <unsigned long int, string> steps;

unsigned long int uniqueid = 0;

void vecappend(vector<string>&, vector<string>&, vector<double>&);

void trace(vector<string> resultsvec);

int main(){

	bool found = false;

	vector<string> currentLevel;
	vector<string> nextLevel;
	vector<string> empty;
	vector<double> currentid;
	vector<double> nextid;

	int currentlevelint = 0;

	string puzzleinput = "[0]1111101011000001010000000000000000000000";
	//string puzzleinput = "[1]0000000000000001000000000000001111101111";
	currentLevel.push_back(puzzleinput);
	currentid.push_back(0);

	while(!found){
	//for (int k = 0; k < 3; k++){

		for(int i = 0; i < currentLevel.size(); i++){

			//cout << currentid[i];

			//cout << currentLevel[i] << "\n";

			building tempbuild(currentLevel[i],4,5,currentid[i],0);

			vector<string> returnedvec;

			//cout << "NOW" << "\n";

			returnedvec = tempbuild.nextLevelOptions(found);

			if (found){
				//cout << currentlevelint + 1 << "\n";
				trace(returnedvec);
				break;
			}

			//cout << "before vecappend\n";
			//exit(0);

			vecappend(nextLevel, returnedvec, nextid);

		}

		cout << "\nLevel: " << currentlevelint << "\n";
		cout << nextLevel.size() << "\n\n";
		//cout << nextLevel[0] << "\n";

		//cout << seenRoutes.count("[3]0000000000000000000000000000001111111111") << "\n";

		if (currentlevelint > 50){
			break;
		}

		currentLevel = nextLevel;
		currentid = nextid;
		nextLevel = empty;
		currentlevelint++;

	}

	cout << "Result: " << currentlevelint << "\n";

	return 0;
}

void vecappend(vector<string>& v1, vector<string>& v2, vector<double>& vid){
	for (int i = 0; i < v2.size(); i++){
		string hashed = v2[i].substr(0,43);
		if (!seenRoutes.count(hashed)){
			v1.push_back(v2[i]);
			vid.push_back(uniqueid);
			seenRoutes[hashed] = true;
			steps[uniqueid] = v2[i];
			uniqueid++;
			if (uniqueid == 0){
				cout << uniqueid << "\n";
			}
		}
		//else{
		//	cout << "Seen\n";
		//}
		//add to the array if not already in it, and then add to the the thing
	}
}

void trace(vector<string> resultsvec){
	int place = 0;

	cout << "Tracing:\n";

	for (int i = 0; i < resultsvec.size(); i++){
		bool found = 1;
		for (int j = 0; j < resultsvec[i].length(); j++ ){
			if (resultsvec[i][j] != '1'){
				found = 0;
			}
		}
		if (found){
			place = i;
			break;
		}
	}
	cout << resultsvec[place] << "\n";
	string buildnow = resultsvec[place];
	while (true){
		string getid = buildnow.substr(44,buildnow.length() - 1 - 44);
		cout << getid << "\n";
		double id = stod(getid);
		if (id == 0){
			break;
		}
		buildnow = steps[id];
		cout << buildnow << "\n";
	}
}



