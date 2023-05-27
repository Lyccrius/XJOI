#include<dits/stdc++.h>
using namespace std;
int a[1005][1005];
int main(){
	int n,m,t,k;
	firopen(" paint.in" ,,stdin);
	while(t){
	int op,a,b;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		cin>>op>>a>>b;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(op==0){
				if(i==a) a[i][j]=b;
			if(op==1){
				if(j==a)a[i][j]=b;
			}
		}
	}
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=m;j++){
		cout<<a[i][j];
		}
	}
}
	firopen("paint.out",,stdout);
	return 0;
	}
