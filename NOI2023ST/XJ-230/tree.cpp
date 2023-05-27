#include<iostream>
using namespace std;
int p[100];
int main(){
	int n;
	double x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		p[i]=x*y;
	}
	for(int i=0;i<n;i++){
		cout<<p[i]<<' ';
	}
	return 0;
}
