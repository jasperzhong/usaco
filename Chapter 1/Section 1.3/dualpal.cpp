/*
TASK: dualpal
LANG: C++
*/ 
#include<cstdio>
#include<iostream>
using namespace std;


int my_itoa(int n, char* str, int base){
	int j = 0;
	while(n){
		str[j++] = n % base + '0';
		n = n / base;
	}
	str[j] = '\0';
	return j;
}


int main()
{
	FILE *fin = fopen("dualpal.in", "r");
	FILE *fout= fopen("dualpal.out","w");
	
	int n, s;
	fscanf(fin, "%d %d", &n, &s);
	char str[50];
	int i = s + 1;
	int size;
	int cnt = 0;
	int ok;
	while(n){
		cnt = 0;
		ok = 0;
		for(int base = 2; base <= 10; ++base){
			size = my_itoa(i, str, base);
			if(size == 1)
				++cnt;
			int flag = 1;
			for(int j = 0;j < size / 2; ++j){
				if(str[j] != str[size - j - 1]){
					flag = 0;
					break;
				}
			}
			if(flag) 
				++cnt;
			if(cnt >= 2){
				ok = 1;
				break;
			}
		} 
		if(ok){
			fprintf(fout, "%d\n", i);
			--n;
		}
		++i;
	} 
	
	fclose(fout);
	return 0;
}


