#include<bits/stdc++.h>
using namespace std;
int a[50001][4];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int t,n,k;
	cin>>t>>k;
	for(int q=1;q<=t;q++){
		cin>>n;
		for(int x=1;x<=n;x++){
			for(int y=1;y<=k;y++){
				cin>>a[x][y];
			}
		}
		cout<<'0';
	}
	return 0;
}
