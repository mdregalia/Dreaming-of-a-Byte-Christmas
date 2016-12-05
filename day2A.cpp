#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

	string line;
	ifstream myfile ("d2A.txt");

	//starts at 5

	int placex = 1;
	int placey = 1;

	if (myfile.is_open()){
   		
   		while ( getline (myfile,line) ){
			
   			for (int i = 0; i < line.length(); i++){
   				if (line[i] == 'L'){
   					if (placex > 0){
   						placex--;
   					}
   				}
   				else if (line[i] == 'R'){
   					if (placex < 2){
   						placex++;
   					}
   				}
   				else if (line[i] == 'U'){
   					if (placey > 0){
   						placey--;
   					}
   				}
   				else if (line[i] == 'D'){
   					if (placey < 2){
   						placey++;
   					}
   				}
   				//cout << placex << "," << placey << "\n";
   			}

   			cout << placey * 3 + placex + 1 << "\n";

    	}

    	myfile.close();
 	}

}