/*
TASK: crypt1
LANG: C++
*/ 
#include<cstdio>
#include<algorithm> 
using namespace std;

int n;
int a[12];

int res[5];  

int cnt = 0;
void dfs(int cur){
	if(cur == 5){
		int x = res[0]*100 + res[3]*10 + res[4];
		int y = res[1]*10 + res[2];
		int z = x * y;
		
		int s = res[2] * x;
		int t = res[1] * x;
		if(s / 1000 >= 1) return;
		if(t / 1000 >= 1) return;
		
		int s3 = s / 100,
			s2 = (s / 10) % 10,
			s1 = s % 10;
		
		int t3 = t / 100,
			t2 = (t / 10) % 10,
			t1 = t % 10;
		//printf("%d %d %d %d %d %d\n", s3, s2, s1, t3, t2, t1);
		int o1 = 0,o2 = 0,o3 = 0,o4 = 0,o5 = 0,o6 = 0;
		for(int i = 0;i < n; ++i){
			if(a[i] == s1){
				o1 = 1;
			}
			if(a[i] == s2){
				o2 = 1;
			}
			if(a[i] == s3){
				o3 = 1;
			}
			if(a[i] == t1){
				o4 = 1;
			}
			if(a[i] == t2){
				o5 = 1;
			}
			if(a[i] == t3){
				o6 = 1;
			}
		}
		
		if(o1 && o2 && o3 && o4 && o5 && o6){
			if(z / 10000 >= 1) return;
			int z4 = z / 1000,
				z3 = (z % 1000) / 100,
				z2 = (z %100) / 10,
				z1 = z % 10;
			
			int ok4 = 0, ok3 = 0, ok2 = 0, ok1 = 0;
			for(int i = 0;i < n; ++i){
				if(z1 == a[i]){
					ok1 = 1;
				}
				if(z2 == a[i]){
					ok2 = 1;
				}
				if(z3 == a[i]){
					ok3 = 1;
				}
				if(z4 == a[i]){
					ok4 = 1;
				}
			}
			if(ok1 && ok2 && ok3 && ok4){
				/*
				for(int i = 0;i < cur; ++i){
					printf("%d ", res[i]);
				}
				printf("\n");*/
				cnt++;
			}
		}
		return;
	}
	
	//¿ÉÒÔ¼ôÖ¦ÁË 
	if(cur == 4){
		if (res[0] * res[1] + res[3] * res[1] / 10  >= 10 ||
		res[0] * res[2] + res[3] * res[2] / 10 >= 10){
			return;
		}
	}
	
	for(int i = 0;i < n; ++i){
		res[cur] = a[i];
		dfs(cur + 1);
	}
}


int main()
{
	FILE* fin = fopen("crypt1.in", "r");
	FILE* fout= fopen("crypt1.out", "w");
	
	
	fscanf(fin, "%d", &n);
	
	for(int i = 0;i < n; ++i){
		fscanf(fin, "%d", &a[i]);
	}
	
	dfs(0);
	
	fprintf(fout, "%d\n", cnt);
	fclose(fin);
	fclose(fout);
	return 0;
} 
