#include <cstdio>
#include <iostream>
#include <queue>
int T;
int m,n,q;
struct node{
	int sx;
	int ys;
};
const int N=100010,M=100010;
node hang[N],lie[M];
using namespace std;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	cin>>T;
	for(int u=1;u<=T;u++){
		cin>>n>>m>>q;
		for(int i=1;i<=n;i++) hang[i].ys=0,hang[i].sx=0;
		for(int i=1;i<=m;i++) lie[i].ys=0,lie[i].sx=0;
		
		for(int i=1;i<=q;i++){
			int opt,x,c;
			cin>>opt>>x>>c;
			if(opt==0){
				hang[x].ys=c;
				hang[x].sx=i;
			}
			else{
				lie[x].ys=c;
				lie[x].sx=i;
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(hang[i].sx>lie[j].sx) cout<<hang[i].ys<<" ";
				else cout<<lie[j].ys<<" ";
			}
			cout<<endl;
		}
		
		
		
	
		
		
	}
	
	return 0;
}
