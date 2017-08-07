#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<cstring>
using namespace std;

int main(){
    int numberOfWord, numberOfJob, valueOfWords[10000], sumOfValue;
	char Words[10000][30];
  	while(cin >> numberOfWord){ // 1.×xData
		cin >> numberOfJob;
		for(int i = 0; i < numberOfWord; i++){
			cin >> Words[i] >> valueOfWords[i];
		}
		char input[30];
		for(int i = 0; i < numberOfJob; i++){
			sumOfValue = 0;
			while(1){
				cin >> input;
				if(!strcmp(input, ".\0")){
					break;
				}
				for(int j = 0; j < numberOfWord; j++){
					if(!strcmp(input, Words[j])){
						sumOfValue += valueOfWords[j];
					}
				}
			}
			cout << sumOfValue << endl;
		}
 	}
    return 0;
}
