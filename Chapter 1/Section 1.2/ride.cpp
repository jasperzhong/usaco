/*
TASK: ride
LANG: C++
*/
#include<stdio.h>

int main(){
	FILE* fin = fopen("ride.in","r");
	FILE*fout = fopen("ride.out","w");
	char name1[7],name2[7];
	fscanf(fin, "%s%s", name1,name2);
	int p1,p2;
	p1 = p2 = 1;
	int i = 0;
	while(name1[i]){
		p1 *= name1[i] - 'A' + 1;
		++i;
	}
	i = 0;
	while(name2[i]){
		p2 *= name2[i] - 'A' + 1;
		++i;
	}
	char *ans;
	if(p1%47 == p2%47){
		ans = "GO\n";
	}
	else{
		ans = "STAY\n";
	}
	fprintf(fout, "%s", ans);
	fclose(fin);
	fclose(fout);
	return 0;
}
