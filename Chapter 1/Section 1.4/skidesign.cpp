/*
TASK: skidesign
LANG: C++
*/ 
#include<iostream>
#include<fstream>
#include<algorithm> 
using namespace std;

const int MAX = 1000; 
int n;
int hill[MAX + 1];

int solve(){
	sort(hill+1, hill+n+1);
	
	int total;
	int min_total = 0x3f3f3f3f;
	for(int i = 0; i <= 83; ++i){
		total = 0;
		for(int j = 1; j <= n; ++j){
			if(hill[j] < i){
				total += (i - hill[j]) * (i - hill[j]);
			}else if(hill[j] > i + 17){
				total += (hill[j] - i - 17) * (hill[j] - i - 17);
			}
		}
		cout << i << ":" << total << endl;
		if(total < min_total)
			min_total = total;
	}
	return min_total;
}

int main()
{
	ifstream fin("skidesign.in");
	fin >> n;
	for(int i = 1; i <= n; ++i){
		fin >> hill[i];
	}
	
	fin.close();

	ofstream fout("skidesign.out");
	
	fout << solve() << endl;
	fout.close();
	return 0;
}
