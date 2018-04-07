/*
TASK: friday
LANG: C++
*/
#include<stdio.h>
int arr[7];
const int month1[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
const int month2[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

int is_leap_year(int year){
	if(year % 400 == 0)
		return 1;
	else if(year % 100 == 0)
		return 0;
	else if(year % 4 == 0)
		return 1;
	else
		return 0;
}

void solve(int n){
	int year = 1900;
	int end = year + n;
	int week = 6;  
	for(int i = 0; i < 7;++i)
		arr[i] = 0;
	++arr[week-1];
	while(year < end){
		if(is_leap_year(year)){
			for(int i = 0;i < 12; ++i){
				week = (week + month2[i]-1)%7+1;
				++arr[week-1];
			}
		}
		else{
			for(int i = 0;i < 12; ++i){
				week = (week + month1[i]-1)%7+1;
				++arr[week-1];
			}
		}
		++year;
	}
	--arr[week-1];
}

int main()
{
	FILE* fin = fopen("friday.in","r");
	FILE*fout = fopen("friday.out","w");
	int n;
	fscanf(fin, "%d", &n);
	solve(n);
	
	for(int i = 5;i < 7; ++i){
		fprintf(fout,"%d ",arr[i]);
	}
	for(int i = 0;i < 4; ++i){
		fprintf(fout,"%d ",arr[i]);
	}
	fprintf(fout,"%d",arr[4]);
	fprintf(fout,"\n");
	fclose(fin);
	fclose(fout);
	return 0;
}
