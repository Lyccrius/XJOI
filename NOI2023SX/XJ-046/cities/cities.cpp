#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
struct node {
	int u,v;
}a[100005];
int main(){
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v;
	}
	if(k==0){
		cout<<m;
		return 0;
	}
	return 0;
}
