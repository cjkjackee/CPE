#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int pali(unsigned int n){
	long long t1 = n, t2 = 0;

	while(t1 > 0){
		t2 *= 10;
		t2 += t1%10;
		t1 /=10;
	}

	if(t2 != (unsigned int)t2)
		return 0;
	return t2;
}

unsigned int add(unsigned int a, unsigned int b){
	long long t1 = a, t2 = b;

	t1 += t2;

	if(t1 != (unsigned int)t1)
		return 0;
	return t1;
}

bool ispali(unsigned int a){
	return a == pali(a);
}

int main(){
	int T;
	unsigned int a, b;

	scanf("%d", &T);

	while(T--){
		scanf("%u", &a);
		printf("%u", a);

		do{
			b = pali(a);
			if(b == 0){
				printf(" overflow");
				break;
			}
			a = add(a, b);
			if(a == 0){
				printf(" overflow");
				break;
			}
			printf(" %u", a);
		}while(!ispali(a));
		printf("\n");
	}

	return 0;
}
