#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool abba(string);

int main(){

	string line;
	ifstream myfile ("d7.cpp");

	int ipcount = 0;

	if (myfile.is_open()){
   		
   		while ( getline (myfile,line) ){

   			//cout << line 

   			//split the string into three sections
   			int startplace = 0;

   			string str1;
   			string str2;
   			string str3;

   			for (int i = 0; i < line.length(); i++){
   				if (line[i] == '['){
   					str1 = line.substr(startplace, i - startplace);
   					startplace = i + 1;
   				}
   				if (line[i] == ']'){
   					str2 = line.substr(startplace, i - startplace);
   					str3 = line.substr(i + 1);
   					break;
   				}
   			}

   			//cout << str1 << " " << str2 << " " << str3;

   			bool abba_1_3;
   			bool abba2;

   			abba2 = abba(str2);

   			abba_1_3 = abba(str1) || abba(str3);

   			if ( !abba2 && abba_1_3){
               cout << line << "\n";
   				ipcount++;
   			}

   			//break;

   		}
   	}

   	cout << ipcount << "\n";

	return 0;
}

bool abba(string strpart){
	for (int i = 0; i < strpart.length() - 3; i++ ){
   		if (strpart[i] == strpart[i + 3] && strpart[i + 1] == strpart[i + 2] && strpart[i] != strpart[i+1]){
   			return 1;
   		}
   	}
   	return 0;
}