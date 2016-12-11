#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define LINE_WIDTH 8
#define ALPHABET_LEN 26
#define MAX_NUM_LINE 1000

using namespace std;

int main(){

	//set up vectors
	vector<int> miniblankvec;
	vector< vector<int> > lettervec;
	vector<char> charmax;
	vector<int> intmax;

	for (int i = 0; i < LINE_WIDTH; i++){
		miniblankvec.push_back(0);
		intmax.push_back(MAX_NUM_LINE);
		charmax.push_back('A');
	}

	for (int i = 0; i < ALPHABET_LEN; i++){
		lettervec.push_back(miniblankvec);
	}

	//vector<int> intmax = miniblankvec;
	
	string line;
	ifstream myfile ("d6.cpp");

	if (myfile.is_open()){
   		
   		while ( getline (myfile,line) ){

   			for (int i = 0; i < LINE_WIDTH; i++){

   				lettervec[line[i] - 'a'][i]++;

   				/*if (intmax[i] <  lettervec[line[i] - 'a'][i]){

   					charmax[i] = line[i];
   					intmax[i] = lettervec[line[i] - 'a'][i];

   				}*/
   			}
   		}
   	}

   	//now find the least frequent
   	for (int i = 0; i < ALPHABET_LEN; i++){
   		for (int j = 0; j < LINE_WIDTH; j++){
   			if (lettervec[i][j] < intmax[j]){
   				intmax[j] = lettervec[i][j];
   				charmax[j] = i + 'a';
   			}
   		}
   	}


   	for (int i = 0; i < LINE_WIDTH; i++){
   		cout << charmax[i];
   	}

   	cout << "\n";

	return 0;
}