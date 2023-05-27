#include<bits/stdc++.h>

using namespace std;

int T;
int x,y,t;
long long a[10010][10010];
int n,m,p;

int main(){

    freopen("print.in","r",stdin);
    freopen("print.out","w",stdout);
    cin>>T;

    while(T--){
		memset(a,0,sizeof(a));
        cin>>x>>y>>t;
        for (int i=0;i<t;i++){
            cin>>m>>n>>p;
            if(m == 1){
                for (int i=1;i<=x;i++){
                    a[i][n] = p;
                }
            }
            else{
                for (int i=1;i<=y;i++){
                    a[n][i] = p;
                }
            }
        }
        for (int i=1;i<=x;i++){
            for (int j=1;j<=y;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}
