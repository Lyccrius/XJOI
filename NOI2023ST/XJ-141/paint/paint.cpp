#include<iostream>
#include<cstring>
using namespace std;
int T;
int a[10005][10005];//x=n  y=m a[x][y]
void f(int opt,int x,int c,int n,int m){
	if(opt==0){
		for(int i=1;i<=n;i++){
			a[x][i]=c;
		}
	}
	if(opt==1){
		for(int i=1;i<=m;i++){
			a[i][x]=c;
		}
	}
}
void pt(int x,int y){
	for(int i=1;i<=x;i++){//x
		for(int j=1;j<=y;j++){//y
			cout<<a[i][j];
		}
		cout<<endl;
	}
}
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		int n,m,q,opt,x,c;
		cin>>n>>m>>q;
		for(int i=1;i<=q;i++){
			cin>>opt>>x>>c;
			f(opt,x,c,n,m);
		}
		pt(n,m);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
