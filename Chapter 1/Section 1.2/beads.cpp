/*
TASK: beads
LANG: C++
*/
#include<stdio.h>
#include<string.h>
char str[1000];

int solve(int n){
	int max = -1;
	int l,r;
	int ok = 0;
	for(int i = 0;i < 2*n - 1; ++i){
		if(str[i] == 'w') continue;
		if(str[i] == 'r' && str[i+1] == 'b'){
			ok = 1;
			l = i; r = i+1;
			while(l >= 0 && (str[l] == 'r' || str[l] == 'w')) --l;
			while(r < 2*n && (str[r] == 'b' || str[r] == 'w')) ++r;
			if(max < r - l){
				max = r - l - 1;
			}
		}
		else if(str[i] == 'b' && str[i+1] == 'r'){
			ok = 1;
			l = i; r = i+1;
			while(l >= 0 && (str[l] == 'b' || str[l] == 'w')) --l;
			while(r < 2*n && (str[r] == 'r' || str[r] == 'w')) ++r;
			if(max < r - l){
				max = r - l - 1;
			}
		}
		else if(str[i] == 'r' && str[i+1] == 'w'){
			ok = 1;
			l = i; r = i+1;
			char t;
			while(l >= 0 && (str[l] == 'r' || str[l] == 'w')) --l;
			
			while(r < 2*n && str[r] == 'w') ++r;
			t = str[r];
			while(r < 2*n && (str[r] == t || str[r] == 'w')) ++r;
			
			if(max < r - l){
				max = r - l - 1;
			}
		}
		else if(str[i] == 'b' && str[i+1] == 'w'){
			ok = 1;
			l = i; r = i+1;
			char t;
			while(l >= 0 && (str[l] == 'b' || str[l] == 'w')) --l;
			
			while(r < 2*n && str[r] == 'w') ++r;
			t = str[r];
			while(r < 2*n && (str[r] == t || str[r] == 'w')) ++r;
			
			if(max < r - l){
				max = r - l - 1;
			}
		}
	}
	if(ok)
		return max <= n ? max : n;
	else
		return n; 
}

int main()
{
	FILE* fin = fopen("beads.in","r");
	FILE*fout = fopen("beads.out","w");
	int n;
	fscanf(fin, "%d", &n);
	fscanf(fin, "%s", str);
	memcpy(str+n,str,n*sizeof(char));
	int ans = solve(n);
	fprintf(fout,"%d\n",ans);
	fclose(fin);
	fclose(fout);
	return 0;
}
