#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int f[100][100];
int T;
int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        memset(f,0,sizeof(f));
        int n,m,q;
        cin>>n>>m>>q;
        for(int j=1;j<=q;j++){
            bool opt;
            int x,c;
            cin>>opt;
            cin>>x>>c;
            if(opt==0){
                for(int k=1;k<=m;k++)
                 f[x][k]=c;
            }
            else if(opt==1){
                for(int k=1;k<=n;k++)
                 f[k][n]=c;
            }
        }
        for(int i1=1;i1<=n;i1++){
            for(int j1=1;j1<=m;j1++)
                printf("%d",f[i1][j1]);
            cout<<endl;
        }
    }
    return 0;
}