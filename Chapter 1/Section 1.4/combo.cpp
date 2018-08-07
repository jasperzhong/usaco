/*
TASK: combo
LANG: C++
*/ 
#include<cstdio>
#include<set> 
#include<algorithm> 
using namespace std;

int n;
int a[3];
int b[3];
	
struct Lock{
	int x, y, z;
	Lock(int a, int b, int c){
		x = a; y = b; z = c;
	} 
};

struct LockCmp{
	bool operator()(const Lock& l1, const Lock& l2){
		if(l1.x != l2.x){
			return l1.x < l2.x;
		}else{
			if(l1.y != l2.y){
				return l1.y < l2.y;
			}else{
				return l1.z < l2.z;
			}
		}
	}
};

set<Lock, LockCmp> s;

int main()
{
	FILE* fin = fopen("combo.in", "r");
	FILE* fout= fopen("combo.out", "w");
	
	fscanf(fin, "%d", &n);
	for(int i = 0;i < 3; ++i){
		fscanf(fin, "%d", &a[i]);
		//printf("%d ", a[i]);
	}
	//printf("\n");
	
	for(int i = 0;i < 3; ++i){
		fscanf(fin, "%d", &b[i]);
		//printf("%d ", b[i]);
	}
	//printf("\n");
	
	for(int i = -2;i <= 2; ++i){
		for(int j = -2;j <= 2; ++j){
			for(int k = -2;k <= 2; ++k){
				int x = a[0] + i, y = a[1] + j, z = a[2] + k;
				if( x <= 0)
					x = n + x;
				if( y <= 0)
					y = n + y;
				if( z <= 0)
					z = n + z;
				//printf("%d %d %d\n",x ,y ,z);
				s.insert(Lock{x % n, y % n, z % n});
			}
		}
	}
	
	for(int i = -2;i <= 2; ++i){
		for(int j = -2;j <= 2; ++j){
			for(int k = -2;k <= 2; ++k){
				int x = b[0] + i, y = b[1] + j, z = b[2] + k;
				if( x <= 0)
					x = n + x;
				if( y <= 0)
					y = n + y;
				if( z <= 0)
					z = n + z;
				//printf("%d %d %d\n",x ,y ,z);
				s.insert(Lock{x % n, y % n, z % n});
			}
		}
	}
	
	fprintf(fout, "%d\n", s.size());
	fclose(fin);
	fclose(fout);
	return 0;
}
