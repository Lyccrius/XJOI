#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int main(){
	//freopen("paint.in","r",stdin);
	//freopen("paint.out","w",stdout);
	int t;
	cin>>t;
	int a[N][N];
	int n,m,q,o,x,c;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			a[i][j]=0;
		}
	}
	for(int i=0;i<t;i++){
		cin>>n>>m>>q;
		for(int j=0;j<q;j++){
			cin>>o>>x>>c;
			if(o==1){
				for(int s=0;s<n;s++){
					a[s][0]=c;
				}
			}
			else if(o==0){
				for(int d=0;d<m;d++){
					a[0][d]=c;
				}
			}
		}
		for(int k=0;k<n;k++){
			for(int h=0;h<m;h++){
				cout<<a[k][h]<<" ";
			}
			cout<<endl;
		}	
	}
	return 0;
}	

