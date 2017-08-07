#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
int main(){
	unsigned long long S;
	unsigned long long D;
	while( cin >> S){
		cin >> D;
		unsigned long long day = 1;
		while( day <= D ){
			day = day + S;
			S++;
		}
		cout << S-1 << endl;
	}

	return 0;
}
