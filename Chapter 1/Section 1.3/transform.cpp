/*
TASK: transform
LANG: C++
*/ 
#include<stdio.h>
const int MAX = 11;
int n;
char a[MAX][MAX];
char b[MAX][MAX];

int solve(){
	int flag = 1;
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < n; ++j){
			if(a[i][j] != b[j][n - i - 1]){
				flag = 0;
				break;
			}
		}
	}
	if(flag)
		return 1;
	
	
	flag = 1;
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < n; ++j){
			if(a[i][j] != b[n - i - 1][n - j - 1]){
				flag = 0;
				break;
			}
		}
	}
	if(flag)
		return 2;
	
	
	flag = 1;
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < n; ++j){
			if(a[i][j] != b[n - j - 1][i]){
				flag = 0;
				break;
			}
		}
	}
	if(flag)
		return 3;
	
	
	flag = 1;
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < n; ++j){
			if(a[i][j] != b[i][n - j -1]){
				flag = 0;
				break;
			}
		}
	}
	if(flag)
		return 4;
	
	
	flag = 1;
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < n; ++j){
			if(a[i][j] != b[j][i]){
				flag = 0;
				break;
			}
		}
	}
	if(flag)
		return 5;
	flag = 1;
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < n; ++j){
			if(a[i][j] != b[n - i - 1][j]){
				flag = 0;
				break;
			}
		}
	}
	if(flag)
		return 5;
	flag = 1;
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < n; ++j){
			if(a[i][j] != b[n - j - 1][n - i - 1]){
				flag = 0;
				break;
			}
		}
	}
	if(flag)
		return 5;
		
	flag = 1;
	for(int i = 0;i < n; ++i){
		for(int j = 0;j < n; ++j){
			if(a[i][j] != b[i][j]){
				flag = 0;
				break;
			}
		}
	}
	if(flag)
		return 6;
	
	return 7;
	
}

int main()
{
	FILE *fin = fopen("transform.in", "r");
	FILE *fout= fopen("transform.out","w");
		
	fscanf(fin, "%d", &n);
	for(int i = 0;i < n; ++i){
		fscanf(fin, "%s", a[i]);
	}
	
	for(int i = 0;i < n; ++i){
		fscanf(fin, "%s", b[i]);
	}
	
	for(int i = 0;i < n; ++i){
		printf("%s\n", a[i]);
	}
	for(int i = 0;i < n; ++i){
		printf("%s\n", b[i]);
	}
	
	
	fprintf(fout, "%d\n", solve());
	fclose(fin);
	fclose(fout);
	return 0;
}

 
