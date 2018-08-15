 /*
TASK: pprime
LANG: C++
*/ 
#include<cstdio>
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm> 
#include<cmath>
using namespace std;
const int MAX = 100000000;
int a, b;
char str[12];
vector<int> v;

void generate_1(){
	for(int i = 5; i <= 9; i+=2)
		v.push_back(i);
} 

void generate_2(){
	for(int i = 1; i <= 9; i+=2)
		v.push_back(i * 10 + i);
} 

void generate_3(){
	for(int i = 1; i <= 9; i+=2){
		for(int j = 0;j <= 9; ++j){
			v.push_back(i*100 + j*10 + i);
		}
	}
} 

void generate_4(){
	for(int i = 1; i <= 9; i+=2){
		for(int j = 0;j <= 9; ++j){
			v.push_back(i * 1000 + j * 100 + j * 10 + i);
		}
	}
}

void generate_5(){
	for(int i = 1; i <= 9; i +=2){
		for(int j = 0 ;j <= 9; ++j){
			for(int k = 0;k <= 9; ++k){
				v.push_back(i * 10000 + j * 1000 + k * 100 + j * 10 + i);
			}
		}
	}
}

void generate_6(){
	for(int i = 1; i <= 9; i +=2){
		for(int j = 0 ;j <= 9; ++j){
			for(int k = 0;k <= 9; ++k){
				v.push_back(i * 100000 + j * 10000 + k * 1000 + k * 100 + j * 10 + i);
			}
		}
	}
}

void generate_7(){
	for(int i = 1; i <= 9; i +=2){
		for(int j = 0 ;j <= 9; ++j){
			for(int k = 0;k <= 9; ++k){
				for(int l = 0; l <= 9; ++l){
					v.push_back(i * 1000000 + j * 100000 + k * 10000 + l * 1000 +  k * 100 + j * 10 + i);
				}
			}
		}
	}
}

void generate_8(){
	for(int i = 1; i <= 9; i +=2){
		for(int j = 0 ;j <= 9; ++j){
			for(int k = 0;k <= 9; ++k){
				for(int l = 0; l <= 9; ++l){
					v.push_back(i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + l * 1000 +  k * 100 + j * 10 + i);
				}
			}
		}
	}
}

void generate(){
	generate_1();
	generate_2();
	generate_3();
	generate_4();
	generate_5();
	generate_6();
	generate_7();
	generate_8();
}

bool is_prime(int x){
	if(x == 2){
		return true;
	}
	if(x % 2 == 0){
		return false;
	}
	
	for(int i = 3; i <= sqrt(x); i+=2){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}



int main()
{
	ifstream fin("pprime.in");
	fin >> a >> b;
	fin.close();
	
	ofstream fout("pprime.out");
	
	generate();
	
	for(auto &e:v){
		if(e < a) continue;
		if(e > b) break;
		if(is_prime(e)){
			fout << e << endl;
		}
	}
	fout.close();
	return 0;
}
