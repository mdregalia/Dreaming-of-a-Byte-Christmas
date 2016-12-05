#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

	string line;
	ifstream myfile ("d3.txt");

	int arrayofthree[3];

	int correctcount = 0;

	if (myfile.is_open()){
   		
   		while ( getline (myfile,line) ){
   			
   			//get all three numbers
   			int place = 0;

   			for (int i = 0; i < line.size(); i++){

   				if (line[i] <= '9' && line[i] >= '0'){
   					int start = i;

   					while(line[i] <= '9' && line[i] >= '0'){
   						i++;
   					}

   					string tempstr = line.substr(start, i - start);

   					cout << "x" <<tempstr << "x\n";
   					cout << i << " " << start << "\n";

   					arrayofthree[place] = stoi(tempstr);

   					place++;

   				}
   			}

   			//find the max number
   			int max = 0;
   			int maxplace = 0;
   			for (int i = 0; i < 3; i++){
   				if (arrayofthree[i] > max){
   					max = arrayofthree[i];
   					maxplace = i;
   				}
   			}
   			int sum = 0;
   			for (int i = 0; i < 3; i++){
   				if (i == maxplace){
   					continue;
   				}
   				sum += arrayofthree[i];
   			}

   			if (sum > max){
   				correctcount++;
   			}
   		}
   	}

   	cout << correctcount << "\n";

	return 0;
}