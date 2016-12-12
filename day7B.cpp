#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool abba(string);

void aba(string, vector<string>&);

int main(){

	string line;
	ifstream myfile ("d7.cpp");

	int ipcount = 0;

	if (myfile.is_open()){
   		
   		while ( getline (myfile,line) ){
            //line = "bab[aba]are[you]doing";

   			//cout << line 

   			//split the string into three sections
   			int startplace = 0;

   			vector<string> stroutside;
            vector<string> strinside;

   			for (int i = 0; i < line.length(); i++){
   				if (line[i] == '['){
   					string str1 = line.substr(startplace, i - startplace);
                  stroutside.push_back(str1);
   					startplace = i + 1;
                  //cout << str1 << "\n";
   				}
   				if (line[i] == ']'){
   					string str1 = line.substr(startplace, i - startplace);
                  strinside.push_back(str1);
   					startplace = i + 1;
                  //cout << str1 << "\n";
   				}
               if (i == line.length() - 1){
                  string str1 = line.substr(startplace, i + 1 - startplace);
                  stroutside.push_back(str1);
                  //cout << str1 << "\n";
               }
   			}

            vector<string> abastr;
            vector<string> babstr;

   			for (int i = 0; i < stroutside.size(); i++){
               aba(stroutside[i], abastr);
            }

            for (int i = 0; i < strinside.size(); i++){
               aba(strinside[i], babstr);
            }

            bool found = false;
            for (int i = 0; i < abastr.size(); i++){
               //cout << abastr[i] << "\n";
               for (int j = 0; j < babstr.size(); j++){
                  //cout << babstr[i] << "\n";
                  if (abastr[i][0] == babstr[j][1] && abastr[i][1] == babstr[j][0]){
                     found = true;
                  }
               }
            }

            if (found){
               ipcount++;
            }
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

void aba(string strpart, vector<string>& results){
   for (int i = 0; i < strpart.length() - 2; i++ ){
      if (strpart[i] == strpart[i + 2] && strpart[i] != strpart[i + 1]){
         string tempstr = "";
         tempstr += strpart[i];
         tempstr += strpart[i + 1];
         results.push_back(tempstr);
      }
   }
}