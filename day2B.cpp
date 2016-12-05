#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){

	string line;
	ifstream myfile ("d2A.txt");

	//starts at 5

	char codearray[7][7] = {
		{'x', 'x', 'x', 'x', 'x', 'x', 'x'},
		{'x', 'x', 'x', '1', 'x', 'x', 'x'},
		{'x', 'x', '2', '3', '4', 'x', 'x'},
		{'x', '5', '6', '7', '8', '9', 'x'},
		{'x', 'x', 'A', 'B', 'C', 'x', 'x'},
		{'x', 'x', 'x', 'D', 'x', 'x', 'x'},
		{'x', 'x', 'x', 'x', 'x', 'x', 'x'}
						};

	int placex = 2;
	int placey = 3;

	if (myfile.is_open()){
   		
   		while ( getline (myfile,line) ){
			
   			for (int i = 0; i < line.length(); i++){
   				if (line[i] == 'L'){
   					if (codearray[placey][placex - 1] != 'x'){
   						placex--;
   					}
   				}
   				else if (line[i] == 'R'){
   					if (codearray[placey][placex + 1] != 'x'){
   						placex++;
   					}
   				}
   				else if (line[i] == 'U'){
   					if (codearray[placey - 1][placex] != 'x'){
   						placey--;
   					}
   				}
   				else{ // if (line[i] == 'D'){
   					if (codearray[placey + 1][placex] != 'x'){
   						placey++;
   					}
   				}
   				//cout << placex << "," << placey << "\n";
   			}

   			cout << codearray[placey][placex]<< "\n";

    	}

    	myfile.close();
 	}

}