#include <iostream>
using namespace std;
int a[10000][10000];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int T;
	cin>>T;
	int n,m,q,opt,x,c;
	for(int t=1;t<=T;t++){
		cin>>n>>m>>q;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<=q;i++){
			cin>>opt>>x>>c;
			if(opt==0){
				for(int j=0;j<m;j++){
					a[x-1][j]=c;
				}
			}else{
				for(int j=0;j<n;j++){
					a[j][x-1]=c;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<a[i][j];
			}
			cout<<endl;
		}
		
	}
	return 0;
}
