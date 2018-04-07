/*
TASK: gift1
LANG: C++
*/
#include<stdio.h>
#include<string.h>
struct Person{
	char name[20];
	int money;
	Person(){
		money = 0;
	}
}p[20];
int n;

int find(char name[20]){
	for(int i = 0;i < n; ++i){
		if(strcmp(name,p[i].name) == 0)
			return i;
	}
}

using namespace std;
int main()
{
	FILE* fin = fopen("gift1.in","r");
	FILE*fout = fopen("gift1.out","w");
	
	fscanf(fin, "%d",&n);
	char name[20];
	for(int i = 0;i < n; ++i){
		fscanf(fin, "%s", p[i].name);
	}
	
	int sum, num;
	while(fscanf(fin, "%s%d%d",name,&sum,&num) != EOF){
		if(num == 0) continue;
		int give = sum / num;
		int save = sum % num;
		p[find(name)].money -= sum - save;
		for(int i = 0; i < num; ++i){
			fscanf(fin, "%s", name);
			p[find(name)].money += give;
		}
	}
	
	for(int i = 0;i < n; ++i){
		fprintf(fout, "%s %d\n", p[i].name, p[i].money);
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
