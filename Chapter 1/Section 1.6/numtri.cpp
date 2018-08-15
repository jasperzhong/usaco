 /*
TASK: numtri
LANG: C++
*/ 
#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm> 
using namespace std;
const int MAX = 1000;
int r;
int arr[MAX+1][MAX+1];
int dp[MAX+1][MAX+1];



int main()
{
	ifstream fin("numtri.in");
	fin >> r;
	for(int i = 1; i <= r; ++i){
		for(int j = 1; j <= i; ++j){
			fin >> arr[i][j];
		}
	}
	fin.close();
	
	//dp[i][j] = arr[i][j] + max(dp[i+1][j], dp[i+1][j+1])
	
	for(int i = r; i >= 1; --i){
		for(int j = 1; j <= i; ++j){
			dp[i][j] = arr[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
		}
	}
	
	//cout << dp[1][1] << endl;
	 
	ofstream fout("numtri.out");
	fout << dp[1][1] << endl;
	fout.close();
}
