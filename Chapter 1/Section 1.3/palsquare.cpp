/*
TASK: palsquare
LANG: C++
*/ 
#include<cstdio>
#include<iostream>
using namespace std;

int my_itoa(int n, char* str, int base){
	int j = 0;
	int tmp;
	while(n){
		tmp = n % base;
		if(base > 10 && tmp >= 10){
			str[j++] = tmp + 'A' - 10;
		}else{
			str[j++] = tmp + '0';
		}
		n = n / base;
	}
	str[j] = '\0';
	for(int i = 0;i < j/2; ++i){
		tmp = str[i];
		str[i] = str[j - i - 1];
		str[j - i - 1] = tmp;
	}
	
	return j;
}

int main()
{
	FILE* in = fopen("palsquare.in", "r");
	int base;
	fscanf(in, "%d", &base);
	fclose(in);
	char tmp[12];
	char str[50];
	
	FILE* out = fopen("palsquare.out", "w");
	int size;
	for(int i = 1;i <= 300; ++i){
		my_itoa(i, tmp, base);
		size = my_itoa(i*i, str, base);
		
		int ok = 1;
		for(int j = 0;j < size / 2; ++j){
			if(str[j] != str[size - j - 1]){
				ok = 0;
				break;
			}
		}
		if(ok){
			fprintf(out, "%s %s\n", tmp, str);
		}
	} 
	fclose(out);
	
	return 0;
}
