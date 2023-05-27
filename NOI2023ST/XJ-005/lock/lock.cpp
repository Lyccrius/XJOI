#include<bits/stdc++.h>
using namespace std;
int a[10000][10000];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int T,k;
	cin>>T>>k;
	int n;
	int x,y;
	while(T--){
		cin>>n;
		cin>>x;
		cin>>y;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				a[i][x]=x;
				
				
			}
		}
	}
}
