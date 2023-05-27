#include <iostream>
using namespace std;
int a[1000][1000];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int t,n,m,q,i,j,k,opt,x,c;
	cin>>t;
	for(i=0;i<t;i++){
		cin>>n>>m>>q;
		for(j=0;j<q;j++){
			cin>>opt>>x>>c;
			if(opt==0){
				for(k=0;k<m;k++){
					a[x-1][k]=c;
				}
			}else{
				for(k=0;k<n;k++){
					a[k][x-1]=c;
				}
			}
		}
		for(j=0;j<n;j++){
			for(k=0;k<m;k++){
				cout<<a[j][k]<<' ';
				a[j][k]=0;
			}
			cout<<endl;
		}
	}
	return 0;
}
