#include <iostream>
using namespace std;
char mine[16][16], touch[16][16];
int r;
int vi[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int vj[] = {0, 1, 1, 1, 0, -1, -1, -1};

inline bool isvalid(int ci, int cj)
{
	return ci >= 0 && ci < r && cj >= 0 && cj < r;
}

int count(int ci, int cj)
{
	int sum = 0;
	for (int i = 0; i < 8; i++){
		if (isvalid(ci + vi[i], cj + vj[i])){
			if (mine[ci+vi[i]][cj+vj[i]] == '*'){
                sum++;
			}
		}
	}
	return sum;
}


int main()
{
	int n,i,j;
	cin >> n;
	while (n--){
		cin >> r;
		bool dead = false;
		for (i = 0; i < r; i++){
			for (j = 0; j < r; j++){
                cin >> mine[i][j];
			}
		}
		for (i = 0; i < r; i++){
			for (j = 0; j < r; j++){
                cin >> touch[i][j];
			}
		}
		char ans[r][r];
		for (i = 0; i < r; i++){
			for (j = 0; j < r; j++){
				if (touch[i][j] == 'x'){
                    ans[i][j] = count(i, j) + '0';
				}
				else{
                    ans[i][j] = '.';
				}
				if (mine[i][j] == '*' && touch[i][j] == 'x'){
                    dead = true;
				}
			}
		}
		if (!dead){
			for (i = 0; i < r; i++){
				for (j = 0; j < r; j++){
                    cout << ans[i][j];
				}
				cout << endl;
			}
		}
		else{
			for (i = 0; i < r; i++){
				for (j = 0; j < r; j++){
                    cout << mine[i][j];
				}
				cout << endl;
			}
		}
		if(n){
            cout << endl;
		}
	}
	return 0;
}
