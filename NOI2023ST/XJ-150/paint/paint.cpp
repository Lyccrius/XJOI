#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
int T;
int a[10005][10005];
using namespace std;
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    long long n,m,q;
    cin>>T;
    while(T--){
        memset(a,-1,sizeof(a));
        cin>>n>>m>>q;
        for(int i=1;i<=q;i++){
            long long op,x,c;
            cin>>op>>x>>c;
            if(op==0){
                for(int j=1;j<=m;j++){
                    a[x][j]=c;
                }
            }
            else if(op==1){
                for(int j=1;j<=m;j++){
                    a[j][x]=c;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
				if(a[i][j]<0) cout<<"0"<<" ";
                else cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
