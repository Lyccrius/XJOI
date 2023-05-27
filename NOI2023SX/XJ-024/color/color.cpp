#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("color.in","r",stdin);
    freopen("color.out","w",stdout);
    srand(time(NULL));
    int c,n,m,t;
    cin>>c;
    while(c--){
        int t1,t2;
        cin>>n>>m>>t;
        for(int i=1;i<=t;i++) cin>>t1;
        while(1){
            t1=rand();
            t2=rand();
            if(t1<998244353&&t2<998244353){
                cout<<t1<<" "<<t2<<endl;
                break;
            }
        }
    }
}