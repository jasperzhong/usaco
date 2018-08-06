/*
TASK: barn1
LANG: C++
*/ 
#include<cstdio>
#include<queue>
#include<algorithm> 
using namespace std;

int cows[205];

int main()
{
	FILE* fin = fopen("barn1.in", "r");
	FILE*fout = fopen("barn1.out", "w");
	
	int m, s, c;
	fscanf(fin, "%d %d %d", &m, &s, &c);
	
	for(int i = 0;i < c; ++i){
		fscanf(fin, "%d", &cows[i]);
	}
	
	sort(cows, cows+c);
	
	priority_queue<int> pq;
	for(int i = 0;i < c - 1; ++i){
		pq.push(cows[i+1] - cows[i]);
	}
	
	int sum = cows[c-1] - cows[0] + 1;
	m -= 1;
	while(m-- && !pq.empty()){
		sum -= pq.top() - 1;
		pq.pop();
	}
	fprintf(fout, "%d\n", sum);
	
	
	fclose(fin);
	fclose(fout);
	return 0;
}

