#include<bits/stdc++.h>
using namespace std;
int n[10001],m[10001],q;
int opt,x,c;
int T;
int ans1[10001][10001];
int ans[11][10000001];
int ind=1;
int out_k1=1,out_k2=1;
void paint(int k[10001][10001],int n,int m,int q){
    for(int i=1;i<=q;i++){
        cin>>opt>>x>>c;
        if(opt==0){
            for(int x1=1;x1<=m;x1++){
                k[x][x1]=c;
            }
        }else{
            for(int x1=1;x1<=n;x1++){
                k[x1][x]=c;
            }
        }
    }
}
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.ans","w",stdout);
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>n[i]>>m[i]>>q;
        paint(ans1,n[i],m[i],q);
        for(int x1=1;x1<=n[i];x1++){
            for(int x2=1;x2=m[i];x2++){
                cout<<ans1[x1][x2];
            }
        }
        for(int x2=1;x2<=n[i];x2++){
            for(int x3=1;x3<=m[i];x3++){
                ans[i][ind++]=ans1[x2][x3];
            }
        }
        for(int x1=1;x1<=n[i];x1++){
            for(int x2=1;x2<=m[i];x2++){
                ans1[x1][x2]=0;
            }
        }
    }
    for(int i=1;i<=T;i++){
        for(int j=1;j<=ind-1;j++){
            if(out_k1<=m[i]&&out_k2<=n[i]){
                cout<<ans[i][j]<<" ";
                out_k1++;
            }else if(out_k2<=n[i]){
                cout<<endl;
                out_k1=1;
                out_k2++;
            }else{
                out_k2=1;
                out_k1=1;
                break;
            }
        }   
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
