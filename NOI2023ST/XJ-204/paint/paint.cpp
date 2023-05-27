#include <iostream>
#include <cstdio>
using namespace std;
int a[10010][10010]={0};
void pa(int pd,int y,int z,int s,int v){
	if(pd==0){
		for(int i=1;i<=v;i++){
			a[y][i]=z;
		}
	}
	else if(pd==1){
		for(int i=1;i<=s;i++){
			a[i][y]=z;
		}
	}
}
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int t,m,n,opt,x,c,q;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>m>>q;
		for(int j=1;j<=q;j++){
			cin>>opt>>x>>c;
			pa(opt,x,c,n,m);
		}
		for(int f=1;f<=n;f++){
			for(int d=1;d<=m;d++){
				cout<<a[f][d]<<" ";
			}
			cout<<endl;
		}
		for(int f=1;f<=n;f++){
			for(int d=1;d<=m;d++){
				a[f][d]=0;
			}
		}
	}
	return 0;
}
