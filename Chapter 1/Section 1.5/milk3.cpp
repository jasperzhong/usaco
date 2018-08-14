/*
TASK: milk3
LANG: C++
*/ 
#include<iostream>
#include<fstream>
#include<algorithm> 
using namespace std;
const int MAX = 20;

int vis[MAX+1][MAX+1][MAX+1];
int record[MAX+1];
int A, B, C;

void dfs(int a, int b, int c){
	if(vis[a][b][c])
		return;
	vis[a][b][c] = 1;
	if(a == 0 && !record[c])
		record[c] = 1;
	
	// c -> a
	if(c >= A - a) 
		dfs(A, b, c-A+a);
	else
		dfs(a+c, b, 0);
	
	// c -> b
	if(c >= B - b)
		dfs(a, B, c-B+b);
	else
		dfs(a, b+c, 0);
	
	// b -> a
	if(b >= A - a)
		dfs(A, b-A+a, c);
	else
		dfs(a+b, 0, c);
	
	// b -> c
	if(b >= C - c)
		dfs(a, b-C+c, C);
	else
		dfs(a, 0, c+b);
	
	// a -> b
	if(a >= B - b)
		dfs(a-B+b, B, c);
	else
		dfs(0, b+a, c);
	
	if(a >= C - c)
		dfs(a-C+c, b, C);
	else
		dfs(0, b, c+a); 
}

int main(){
	ifstream fin("milk3.in");
	fin >> A >> B >> C;
	fin.close();
	
	ofstream fout("milk3.out");
	dfs(0, 0, C);
	int count = 0;
	for(int i = 0; i <= 20; ++i){
		if(record[i]){
			count++;
			if(count == 1)
				fout << i;
			else{
				fout << " " << i;
			}
		}
	} 
	fout << endl;
	fout.close();
	return 0;
} 
