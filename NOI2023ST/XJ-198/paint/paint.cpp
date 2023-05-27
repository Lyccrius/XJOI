#include<bits/stdc++.h>
using namespace std;
int a[100005][100005];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    int T,n, m, q,out,x,c;
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        for(int i=0;i<q;i++){
            cin>>out>>x>>c;
            if(out==1){
                for(int j=0;j<n;j++){
                    a[j][x]=c;
                }
            }else{
                for(int j=0;j<m;j++){
                    a[x][j]=c;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
                a[i][j]=0;
            }
            cout<<endl;
        }

    }
    return 0;
}