/*
TASK: milk
LANG: C++
*/ 
#include<cstdio>
#include<algorithm> 
using namespace std;

struct Milk{
	int p;
	int a;
	bool operator<(const Milk& m){
		return p < m.p;
	}
}milk[5005];


int main()
{
	FILE* fin = fopen("milk.in", "r");
	FILE* fout= fopen("milk.out", "w");
	int n, m;
	fscanf(fin, "%d %d", &n, &m);
	
	for(int i = 0;i < m; ++i){
		fscanf(fin, "%d %d", &milk[i].p, &milk[i].a);
	}
	
	sort(milk, milk+m);
	
	int sum = 0;
	int i = 0;
	while(n){
		if(n >= milk[i].a){
			n -= milk[i].a;
			sum += milk[i].a * milk[i].p;
		}
		else{
			sum += n * milk[i].p;
			n = 0;
		}
		++i;
	}
	fprintf(fout, "%d\n", sum);
	
	fclose(fin);
	fclose(fout);
	return 0;
}
