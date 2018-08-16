/*
TASK: frac1
LANG: C++
*/ 
#include<cstdio>
#include<iostream>
#include<fstream>
#include<set>
#include<algorithm> 
#include<functional>
using namespace std;
const int MAX = 160;
int n;
/*
class SafeDouble{
public:
    explicit SafeDouble(double v)  //forbit implicit transfer
        :value_(v){};

    SafeDouble(){}

    double AsDouble()const{return value_;}

    bool operator<(const SafeDouble& rhs)const{
        return static_cast<int>(value_/precision_) < static_cast<int>(rhs.AsDouble()/precision_);
    }

    bool operator==(const SafeDouble& rhs)const{
        return static_cast<int>(value_/precision_) == static_cast<int>(rhs.AsDouble()/precision_);
    }

private:
    double value_;
    static double precision_;
};*/


struct Node{
	int x, y;
	Node(int xx, int yy)
		: x(xx), y(yy) {
		}
		
	Node(){
	}
	bool operator<(const Node& n) const{
		return (double(x)/y) < (double(n.x) / n.y);
	}
};

int main(){
	ifstream fin("frac1.in");
	fin >> n;
	fin.close();
	
	set<Node> v;
	
	ofstream fout("frac1.out");
	
	fout << "0/1" << endl;

	for(int i = 1; i <= n-1; ++i){
		for(int j = i+1; j <= n; ++j){
			if(i > 1 && j % i == 0) continue;
			v.insert(Node(i, j));
		}
	}
	
	
	for(auto &e:v){
		fout << e.x << "/" << e.y << endl; 
	}
	fout << "1/1" << endl;
	fout.close();
	return 0;
}
