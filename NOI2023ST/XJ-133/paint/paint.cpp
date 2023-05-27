#include<iostream>
#include<stdio.h>
freopen("paint","r",stdin);
freopen("paint","w",stdout);
using namespace std;
int opt,x,c;
int m,n,q,t,a[100010][100010];
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)
            for(int j=i;j<=m;j++)
                a[i][j]=0;
        for(int i=q;i>0;i--){
            cin>>opt>>x>>c;
            if(opt==0){
                for(int j=1;j<=n;j++)
                {
                    a[j][m]=c;
                }
            }
            if(opt==1){
                for(int j=1;j<=m;j++)
                {
                    a[n][j]=c;
                }
            }

        }
     for(int i=1;i<=n;i++){
       for(int j=i;j<=m;j++) {
           cout<<a[i][j];
       }   
       printf("\n");
     }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}