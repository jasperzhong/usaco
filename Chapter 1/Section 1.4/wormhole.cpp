/*
TASK: wormhole
LANG: C++
*/ 
#include<iostream>
#include<fstream>
#include<algorithm> 
using namespace std;
const int MAX = 12;

int n;
struct Node{
	int x, y;
};

Node farm[MAX+1];
int partner[MAX+1];
int next_on_right[MAX+1];

bool cycle_exists(){
	/*
	for(int i = 1; i <= n; ++i){
		cout << i << "," << partner[i] << " ";
	}
	cout << endl;
	*/
	
	for(int start = 1; start <= n; ++start){
		int pos = start;
		for(int count = 0; count < n; ++count){
			pos = next_on_right[partner[pos]]; 
		}
		if(pos != 0)
			return true;
	}
	return false;
}

int solve(){	
	int i, total = 0;
	for(i = 1; i <= n; ++i){
		if(partner[i] == 0) {
			break;
		}
	}
	
	if(i == n + 1){
		if(cycle_exists()) return 1;
		else return 0;
	}
	
	for(int j = i + 1; j <= n; ++j){
		if(partner[j] == 0){
			partner[i] = j;
			partner[j] = i;
			total += solve();
			partner[i] = partner[j] = 0;
		}
	}
	
	return total;
}

int main()
{
	ifstream fin("wormhole.in");
	
	fin >> n;
	
	for(int i = 1; i <= n; ++i){
		fin >> farm[i].x >> farm[i].y;
	}
	fin.close();
	
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			if(farm[j].x > farm[i].x && farm[j].y == farm[i].y)
				if(next_on_right[i] == 0 || farm[j].x - farm[i].x < farm[next_on_right[i]].x - farm[i].x)
					next_on_right[i] = j;
	
	ofstream fout("wormhole.out");
	fout << solve() << endl;
	fout.close();
	return 0; 
}
