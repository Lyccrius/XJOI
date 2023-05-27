#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        int n,m,q;
        scanf("%d %d %d",&n,&m,&q);
        const int nn=n+50,mm=m+50;
        int dt[nn][mm];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dt[i][j]=0;
            }
        }
        for(int j=0;j<q;j++){
            int opt,x,c;
            scanf("%d %d %d",&opt,&x,&c);
            if(opt==1){
                for(int k=0;k<n;k++){
                    dt[k][x-1]=c;
                }
            }
            else{
                for(int k=0;k<m;k++){
                    dt[x-1][k]=c;
                }
            }
        }
        for(int ii=0;ii<n;ii++){
            for(int j=0;j<m;j++){
                cout<<dt[ii][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
