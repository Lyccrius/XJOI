#include <iostream>
#include <cstring>
#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
struct node{
	int x,v;
};
node o[100000];
int p[100000];
int main(){
	freopen("transfer.in","r",stdin);
	freopen("transfer.out","w",stdout);
	int n,k,m,id,sid;
	cin>>sid>>n>>k>>m;
	for(int i=1;i<n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=k;i++){
		cin>>o[i].x>>o[i].v;
	}
	
	for(int i=k+1;i<=m+k;i++){
		int f;
		cin>>f;
		if(f==1)
		{
			cin>>o[i].x>>o[i].v;
		}
		if(f==2)
		{
			cin>>id;
		}
	}
	int ans;
	for(int i=1;i<=m+k;i++){
		ans+=o[i].v;
		}
		cout<<ans;
	return 0;
}
