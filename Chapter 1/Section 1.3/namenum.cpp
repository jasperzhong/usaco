/*
TASK: namenum
LANG: C++
*/ 
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
char dict[5001][25];
char pred[25];
char name[25];
int flag = 0;

FILE *fin = fopen("namenum.in", "r");
FILE *fin_name = fopen("dict.txt", "r");
FILE *fout= fopen("namenum.out","w");
	
	
void dfs(int i){
	if(name[i] == '\0'){
		pred[i] == '\0';
		int ok = 0;
		int low = 0, high = 5000;
		
		while(low <= high){
			int mid = (low + high) / 2;
			int res = strcmp(pred, dict[mid]);
			if(res == 0){
				ok = 1;
				flag = 1;
				break;
			}else if(res < 0){
				high = mid - 1;
			}else{
				low = mid + 1;
			}
		}
		
		if(ok){
			fprintf(fout, "%s\n", pred);
		}
		return;
	}
	switch(name[i] - '0'){
		case 2:{
			pred[i] = 'A';
			dfs(i+1);
			pred[i] = 'B';
			dfs(i+1);
			pred[i] = 'C';
			dfs(i+1);
			break;
		}
		case 3:{
			pred[i] = 'D';
			dfs(i+1);
			pred[i] = 'E';
			dfs(i+1);
			pred[i] = 'F';
			dfs(i+1);
			break;
		}
		case 4:{
			pred[i] = 'G';
			dfs(i+1);
			pred[i] = 'H';
			dfs(i+1);
			pred[i] = 'I';
			dfs(i+1);
			break;
		}
		case 5:{
			pred[i] = 'J';
			dfs(i+1);
			pred[i] = 'K';
			dfs(i+1);
			pred[i] = 'L';
			dfs(i+1);
			break;
		}
		case 6:{
			pred[i] = 'M';
			dfs(i+1);
			pred[i] = 'N';
			dfs(i+1);
			pred[i] = 'O';
			dfs(i+1);
			break;
		}
		case 7:{
			pred[i] = 'P';
			dfs(i+1);
			pred[i] = 'R';
			dfs(i+1);
			pred[i] = 'S';
			dfs(i+1);
			break;
		}
		case 8:{
			pred[i] = 'T';
			dfs(i+1);
			pred[i] = 'U';
			dfs(i+1);
			pred[i] = 'V';
			dfs(i+1);
			break;
		}
		case 9:{
			pred[i] = 'W';
			dfs(i+1);
			pred[i] = 'X';
			dfs(i+1);
			pred[i] = 'Y';
			dfs(i+1);
			break;
		}
	}
}


int main()
{
	int i = 0;
	while(fscanf(fin_name, "%s", name) != EOF){
		strcpy(dict[i++], name);
	}
	
	fscanf(fin, "%s", &name);
	dfs(0);
	if(!flag){
		fprintf(fout, "NONE\n");
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
