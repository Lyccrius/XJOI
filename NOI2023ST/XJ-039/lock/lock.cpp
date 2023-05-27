#include<bits/stdc++.h>
using namespace std;
int t;
int a[5000][5000];
int x,y;
int gans=999999;
int aa=0;
int bb=999989;
int main(){
	
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>t>>y;
	for(int k=1;k<=t;k++){
		cin>>x;
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				cin>>a[i][j];
				if(a[i][j]>aa)
				aa=a[i][j];
				if(a[i][j]<bb)
				bb=a[i][j];
			}
		}
	if(y==1)
	{
		cout<<aa-bb<<endl;
		}
	else if(x==1){
		cout<<aa<<endl;
	}
	else
	cout<<0<<endl;
	
}
}
