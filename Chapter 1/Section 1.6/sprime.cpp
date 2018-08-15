  /*
TASK: sprime
LANG: C++
*/ 
#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm> 
#include<cmath>
using namespace std;
int n;
ofstream fout("sprime.out");

bool is_prime(int x){
	if(x == 2){
		return true;
	}
	if(x % 2 == 0){
		return false;
	}
	
	for(int i = 3; i <= sqrt(x); i+=2){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

void dfs(int cur, int num){
	if(cur == n+1){
		if(is_prime(num)){
			fout << num << endl;
		}
		return;
	}
	//cout << num << endl;
	if(num && !is_prime(num))
		return;
			
	num *= 10;
	if(cur == 1){
		dfs(cur+1, num+2);
		dfs(cur+1, num+3);
		dfs(cur+1, num+5);
		dfs(cur+1, num+7);
	}
	else {
		dfs(cur+1, num+1);
		dfs(cur+1, num+3);
		dfs(cur+1, num+5);
		dfs(cur+1, num+7);
		dfs(cur+1, num+9);
	}
}

int main()
{

	ifstream fin("sprime.in");
	fin >> n;
	fin.close();
	
	
	
	dfs(1, 0);
	
	
	fout.close();
	return 0;
}
