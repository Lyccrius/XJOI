


#include<iostream>
using namespace std;
int main(){
	int opt[100],x[100],c[100];
    int u[100][100];
	int m,n,q;
    cin>>m>>n>>q;
    for(int i=0;i<=q;i++){
        cin>>opt[i]>>x[i]>>c[i];
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(opt==0){
                for(int l=0;l<=n;l++){
                        int u[l][j]=c[i];
                }
            }
            if(opt==1){
                for(int l=0;l<=n;l++){
                        int u[i][l]=c[i];
                }
            }
        }
    }
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
			cout<<u[i][j];
        }
    }
    return 0;
}


