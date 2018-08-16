/*
TASK: castle
LANG: C++
*/ 
#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm> 
using namespace std;
const int MAX = 50;
const int d[4] = {1, 2, 4, 8}; // 西, 北，东，南 
int m, n;
int map[MAX+1][MAX+1];
int room_area[MAX * MAX + 10];
int vis[MAX+1][MAX+1];

int cnt = 0; //room numbers
int tt = 0; // area
int tt_max = 0; //max area


void flood_fill(int x, int y){
	tt++;  //访问,面积+1
	vis[x][y] = cnt;  //vis
	if((15 - map[x][y]) > 0) map[x][y] = 15 - map[x][y];
	else return;
	
	for(int k = 3; k >= 0; --k){
		if((map[x][y] - d[k]) >= 0)
			map[x][y] -= d[k];
		else
			continue;
		switch (k) {
			case 0: if(!vis[x][y-1]) flood_fill(x, y-1); break;
			case 1: if(!vis[x-1][y]) flood_fill(x-1, y); break;
			case 2: if(!vis[x][y+1]) flood_fill(x, y+1); break;
			case 3: if(!vis[x+1][y]) flood_fill(x+1, y); break;
		}
		if(!map[x][y])
			return;
	}
}

int main()
{
	ifstream fin("castle.in");
	fin >> m >> n;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			fin >> map[i][j];
		}
	}
	
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(map[i][j]){
				tt = 0;
				cnt++;
				flood_fill(i, j);
				room_area[cnt] = tt;  //第cnt个房间大小是tt
				if(tt > tt_max) tt_max = tt; 
			}
		}
	}
	fin.close();
	
	ofstream fout("castle.out");
	
	fout << cnt << endl << tt_max << endl;
	int x=0, y=0;
	char dir;
	for(int j = 1; j <= m; ++j){
		for(int i = n; i >= 1; --i){
			if((i-1>0) && vis[i-1][j] != vis[i][j] && (room_area[vis[i-1][j]] + room_area[vis[i][j]]) > tt_max){
				x = i;
				y = j;
				dir = 'N';
				tt_max = room_area[vis[i-1][j]] + room_area[vis[i][j]];
			}
			if((j < m) && vis[i][j] != vis[i][j+1] && (room_area[vis[i][j]] + room_area[vis[i][j+1]]) > tt_max){
				x = i;
				y = j;
				dir = 'E';
				tt_max = room_area[vis[i][j]] + room_area[vis[i][j+1]];
			}
		}
	}
	fout << tt_max << endl << x << " " << y << " " << dir << endl;
		return 0;
	
}
