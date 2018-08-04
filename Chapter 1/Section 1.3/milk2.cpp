/*
TASK: milk2
LANG: C++
*/ 
#include<stdio.h>
#include<algorithm>
using namespace std;

struct Farmer{
	int start;
	int end;
	
	bool operator<(const Farmer& f){
		return this->start < f.start;
	}
};


int main()
{
	FILE * fin = fopen("milk2.in", "r");
	FILE * fout= fopen("milk2.out", "w");
	int n;
	fscanf(fin, "%d", &n);
	Farmer * farmer = new Farmer[n];
	
	for(int i = 0;i < n; ++i){
		fscanf(fin, "%d %d", &farmer[i].start, &farmer[i].end);
	}
	
	sort(farmer, farmer+n);
	
	int max_continuous = farmer[0].end - farmer[0].start, max_interval = 0;
	int start = farmer[0].start;
	int end = farmer[0].end;
	
	for(int i = 0;i < n; ++i){
		if(farmer[i].start <= end){
			max_continuous = max(max_continuous, farmer[i].end - start);
			end = max(end, farmer[i].end);
		}
		else{
			start = farmer[i].start;
			max_interval = max(max_interval, farmer[i].start - end);
			end = max(end, farmer[i].end);
		}
	}
	
	
	fprintf(fout, "%d %d\n", max_continuous, max_interval);
	fclose(fin);
	fclose(fout);
	return 0;
}
