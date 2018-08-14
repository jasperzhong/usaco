/*
TASK: ariprog
LANG: C++
*/ 
#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm> 
using namespace std;

int N;
int M;

int arr[125000 + 4];
FILE* fout = fopen("ariprog.out", "w");
int res_a[10005];
int res_b[10005];
int sum = 0;

void find_all_bisquares(){
	for(int i = 0; i <= M; ++i){
		for(int j = 0;j <= M; ++j){
			arr[i*i + j*j] = 1;
		} 
	}
}

bool is_ok(int a, int b){
	for(int i = 0;i < N; ++i){
		if(!arr[a + i * b])
			return false;
	}
	return true;
} 

int solve(){
	int limit = 2 * M * M;
	for(int b = 1; b <= limit/(N-1); ++b){
		for(int a = 0; a + (N-1)*b <= limit; ++a){
			if(is_ok(a, b)){
				res_a[sum] = a;
				res_b[sum] = b;
				sum++;
			} 
		}
	}
}

int main()
{
	FILE* fin = fopen("ariprog.in", "r");
	fscanf(fin, "%d %d", &N, &M);
	fclose(fin);
	
	find_all_bisquares();
	solve();
	if(!sum)
		fprintf(fout, "NONE\n");
	for(int i = 0;i < sum; ++i){
		fprintf(fout, "%d %d\n", res_a[i], res_b[i]);
	}
	fclose(fout);
	return 0;
}
