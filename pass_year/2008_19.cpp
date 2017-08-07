#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subset{
	int num;
	long long element[32];
}subsets[4096], nowset;


long long a[32];
int n, subset_n;

int cp(const void *a, const void *b){
	const long long *c = (const long long*)a;
	const long long *d = (const long long*)b;

	if(*c > *d)
		return 1;
	else if(*c < *d)
		return -1;
	else
		return 0;
}

int cp2(const void *a, const void *b){
	const subset *c = (const subset*)a;
	const subset *d = (const subset*)b;

	if(c->num > d->num)
		return 1;
	else if(c->num < d->num)
		return -1;
	else
		for(int i=0; i<c->num; i++){
			if(c->element[i] > d->element[i])
				return 1;
			else if(c->element[i] < d->element[i])
				return -1;
		}
	return 0;
}

void recur(int a_idx, int set_idx, long long remain){
	if(remain == 0){
		memcpy(&subsets[subset_n], &nowset, sizeof(subset));
		subsets[subset_n].num = set_idx;
		subset_n++;
	}else if(a_idx <= n - 1){
		if(a[a_idx] <= remain){
			nowset.element[set_idx] = a[a_idx];
			recur(a_idx+1, set_idx+1, remain - a[a_idx]);
		}
		recur(a_idx+1, set_idx, remain);
	}
}

int main(){
	char buf[1024], *tok;
	int i, j;
	long long sum, half;
	bool flag = false;

	while(fgets(buf, 1024, stdin)){
		if(buf[0] == '.')
			return 0;

		if(flag)
			printf("\n");
		else
			flag = true;

		n = 0;
		sum = 0;
		tok = strtok(buf, "{} \n\t\r");
		while(tok){
			sscanf(tok, "%lld", &a[n]);
			sum += a[n];
			n++;

			tok = strtok(NULL, "{} \n\t\r");
		}

		qsort(a, n, sizeof(long long), cp);


		if(sum % 2 == 0){
			half = sum / 2;
			subset_n = 0;
			recur(0, 0, half);
			if(subset_n > 0){
				qsort(subsets, subset_n, sizeof(subset), cp2);
				printf("%d subsets.\n", subset_n);
				for(i=0; i<subset_n; i++){
					printf("{%lld", subsets[i].element[0]);
					for(j=1; j<subsets[i].num; j++)
						printf(" %lld", subsets[i].element[j]);
					printf("}\n");
				}
			}else{
				printf("No such subset\n");
			}
		}else{
			printf("No such subset\n");
		}
	}

	return 0;
}
