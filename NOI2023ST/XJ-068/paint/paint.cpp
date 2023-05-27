#include<iostream>
using namespace std;
int main(){ 
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    int t;
    int n,m,q;
    int opt,x,c; 
    int b[1005][1005];
    cin>>t;
	for(int p=0;p<t;p++){
		cin>>n>>m>>q;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				b[i][j]=0;
			}
		}				
		for(int i=0;i<q;i++){ 
			cin>>opt>>x>>c;
			if(opt==1){
				for(int j=0;j<n;j++){
					b[j][x-1]=c;
				}
			}
				else{
					for(int k=0;k<m;k++){
						b[x-1][k]=c;
					}
				}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<b[i][j]<<" ";
			}
			cout<<endl;
		}
	}	
    return 0;
}
