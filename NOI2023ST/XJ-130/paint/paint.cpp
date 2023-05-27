#include<cstdio>
#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int maxn=100005;
int T,n,m,q;
vector<int> a[maxn];
struct node{
    int fr,nxt;
}h[2][maxn];
bool f[2][maxn];
int opi[maxn],xi[maxn],yi[maxn];
int main(){
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>T;
    int op=0,x=0,y=0,z=0,k=0;
    for(int t=1;t<=T;t++){
        cin>>n>>m>>q;
        for(int i=0;i<maxn;i++){
            while(a[i].size()) a[i].pop_back();
            h[0][i].fr=i-1, h[0][i].nxt=i+1;
            h[1][i].fr=i-1, h[1][i].nxt=i+1;
            f[0][i]=f[1][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=(m+1);j++){
                a[i].push_back(0);
            }
        }
        for(int i=1;i<=q;i++){
            cin>>opi[i]>>xi[i]>>yi[i];
        }
        for(int i=q;i>=1;i--){
            op=opi[i],x=xi[i],y=yi[i];
            if(f[op][x]) continue;
            z=h[op^1][0].nxt;
            if(op==0) k=m;
            else k=n;
            while(z<=k){
                if(op==0) a[x][z]=y;
                else a[z][x]=y;
                z=h[op^1][z].nxt;
            }
            h[op][h[op][x].fr].nxt=h[op][x].nxt;
            h[op][h[op][x].nxt].fr=h[op][x].fr;
            h[op][x].fr=h[op][x].nxt=0;
            f[op][x]=1;         
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<a[i].size();j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}