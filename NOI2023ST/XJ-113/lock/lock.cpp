#include<bits/stdc++.h>

using namespace std;

int o,p,q,r;
int n,m,x,ans;
int a[4][100010];

int main(){
	
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n>>m;
	while(n--){
		memset(a,0,sizeof(a));
		cin>>x;
		for (int i=0;i<m;i++){
			for (int j=0;j<x;j++){
				cin>>a[m][x];
			}
		}
		for (int i=0;i<x;i++){
			cout<<min(n,i);
		}
	}

    return 0;
}
