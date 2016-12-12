#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool abba(string);

int main(){

	string line;
	ifstream myfile ("d7.cpp");

	int ipcount = 0;

	if (myfile.is_open()){
   		
   		while ( getline (myfile,line) ){
            //line = "hello[how]are[you]doing";

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
                  cout << str1 << "\n";
   				}
   				if (line[i] == ']'){
   					string str1 = line.substr(startplace, i - startplace);
                  strinside.push_back(str1);
   					startplace = i + 1;
                  cout << str1 << "\n";
   				}
               if (i == line.length() - 1){
                  string str1 = line.substr(startplace, i + 1 - startplace);
                  stroutside.push_back(str1);
                  cout << str1 << "\n";
               }
   			}

   			//cout << str1 << " " << str2 << " " << str3;

   			bool abba_outside = 0;
   			bool abba_inside = 0;;

   			for (int i = 0; i < stroutside.size(); i++){
               abba_outside = abba_outside || abba(stroutside[i]);
            }

            for (int i = 0; i < strinside.size(); i++){
               abba_inside = abba_inside || abba(strinside[i]);
            }

   			if ( !abba_inside && abba_outside){
               cout << line << "\n";
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

bool aba(string strpart){
   for (int i = 0; i < strpart.length() - 3; i++ ){
         if (strpart[i] == strpart[i + 3] && strpart[i + 1] == strpart[i + 2] && strpart[i] != strpart[i+1]){
            return 1;
         }
      }
      return 0;
}

bool bab(string strpart){
   for (int i = 0; i < strpart.length() - 3; i++ ){
         if (strpart[i] == strpart[i + 3] && strpart[i + 1] == strpart[i + 2] && strpart[i] != strpart[i+1]){
            return 1;
         }
      }
      return 0;
}