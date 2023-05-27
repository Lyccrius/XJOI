#include<iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int u=1;u<=T;u++){
		int n,m,q;
		int opt,x,c;
		cin>>n>>m>>q;
		int arr[n][m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				arr[i][j]=0;
			}
		}
		for(int i=0;i<q;i++){
			cin>>opt>>x>>c;
			if(opt==0){
				for(int j=0;j<m;j++){
					arr[x][j]=c;
				}
			}
			if(opt==1){
				for(int j=0;j<n;j++){
					arr[j][x]=c;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cout<<arr[i][j]<<' ';
			}
			cout<<endl;
		}
	}
	return 0;
}
