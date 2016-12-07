#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

void isort(vector<int>&, vector<char>&);

int main(){

	shift('q',343);

	int totalsum = 0;

	string line;
	ifstream myfile ("d4.txt");

	if (myfile.is_open()){
   		
   		while ( getline (myfile,line) ){

   			unordered_map<char,int> letters;
   			string checksum;
   			int numtosum = 0;
   			vector<char> lettercollector;
   			vector<int> numbercollector;

   			for (int i = 0; i < line.length(); i++){

   				if (line[i] <= 'z' && line[i] >= 'a'){
   					//count it and continue through bigger loop
   					if (letters.count(line[i])){
   						letters[line[i]]++;
   					}
   					else{
   						letters[line[i]] = 1;
   						lettercollector.push_back(line[i]);
   					}
   				}
   				else if (line[i] <= '9' && line[i] >= '0'){
   					//loop through to grab the whole number
   					int prev = i;

   					while (line[i] != '['){
   						i++;
   					}

   					numtosum = stoi(line.substr(prev, i - prev));
   					//cout << line.substr(prev, i - prev) << "\n";

   					//then grab the string for the 
   					checksum = line.substr(i + 1, 5); //rest of it but all but the last letter
   					//cout << checksum << "\n";

   					break;
   				}
   			}


   				//now put all numbers in an array
   			for (int i = 0; i < lettercollector.size(); i++){
   				numbercollector.push_back(letters[lettercollector[i]]);
   			}

   			isort(numbercollector,lettercollector);

   			int matching = 1;
   			for (int i = 0; i < 5; i++){
   				//cout << lettercollector[lettercollector.size() - i - 1];
   				//cout << "-" << "\n";
   				if (lettercollector[lettercollector.size()- i - 1] != checksum[i]){
   					matching = 0;
   				}
   			}
   			//cout << "\n";
   			//cout << numtosum << "\n";
   			if (matching){
   				totalsum += numtosum;
   				cout << numtosum << "\n";
   			}
   		}
   	}

   	cout << totalsum << "\n";

	return 0;
}

void isort(vector<int>& myvec, vector<char>& vec2){ //must move corresponding places as well, isort = insertsort, is this ascending or descending order
	for (int i = 0; i < myvec.size() - 1; i++){
    	for (int j = i + 1; j < myvec.size(); j++){
        	if (myvec[i] > myvec[j]
        		|| (myvec[i] == myvec[j] && vec2[i] < vec2[j])){
        		int temp = myvec[i];
        		myvec[i] = myvec[j];
        		myvec[j] = temp;

        		//move the same way as above
        		char temp2 = vec2[i];
        		vec2[i] = vec2[j];
        		vec2[j] = temp2;
        	}
    	}
	}
}

char shift(char input, int rotations){
	int newchar = ((input - 'a') + rotations) % 26;
	return (char) newchar + 'a';
}


//fastest way would be to store in a hash all numbers seen and increment that way, 
//add them to a list of seen letters
//and then after all is seen, get the final count to correspond to the list of the letters
//and then sort that
