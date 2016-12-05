#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

	string line;
	ifstream myfile ("d3.txt");

	int arrayofthree[3][3];

	int correctcount = 0;

	if (myfile.is_open()){

		int row = 0;
   		
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

   					//cout << "x" <<tempstr << "x\n";
   					//cout << i << " " << start << "\n";

   					arrayofthree[row][place] = stoi(tempstr);

   					place++;

   					cout << row << "," << place << "\n";

   				}
   			}

   			if ( !((row + 1) % 3)){
   				cout << row + 1 << "\n";
   				for (int j = 0; j < 3; j++){
		   			//find the max number
		   			int max = 0;
		   			int maxplace = 0;
		   			for (int i = 0; i < 3; i++){
		   				if (arrayofthree[i][j] > max){
		   					max = arrayofthree[i][j];
		   					maxplace = i;
		   				}
		   			}
		   			int sum = 0;
		   			for (int i = 0; i < 3; i++){
		   				cout << arrayofthree[i][j] << " ";
		   				if (i == maxplace){
		   					continue;
		   				}
		   				sum += arrayofthree[i][j];
		   			}

		   			cout << "\n";

		   			if (sum > max){
		   				correctcount++;
		   			}
	   			}

	   			row = 0;
   			}
   			else{
   				row++;
   			}

   		}
   	}

   	cout << correctcount << "\n";

	return 0;
}