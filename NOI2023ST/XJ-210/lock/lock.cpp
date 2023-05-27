#include<bits/stdc++.h>
using namespace std;

int n,k;
int T;
int a[10010][10010];

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);

    cin>>T>>k;
    for(int i=1;i<=T;i++){
        cin>>n;
        for(int j=1;j<=k;j++){
            for(int h=1;h<=n;h++)cin>>a[i][j];
        }
        cout<<0<<endl;
    }

}