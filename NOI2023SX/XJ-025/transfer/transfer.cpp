#include<bits/stdc++.h>
using namespace std;
const int N=5100;

int sid;
int n,k,m;
int p[N];
int x[N],v[N];
int id;
int ans1,ans2;

void bi(){
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            if(x[i]==x[j]){
                ans1=max(v[i],v[j]);
            }
        }
    }
}


int main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    
    cin>>sid;
    cin>>n>>k>>m;
    
    for(int i=1;i<n;i++){
        cin>>p[i];
    }
    
    for(int i=0;i<k;i++){
        cin>>x[i]>>v[i];
    }

    for(int i=0;i<m;i++){
        if(sid==1)cin>>x[i]>>v[i];
        else if(sid==2)cin>>id;
    }

    bi();
    for(int i=1;i<=n;i++){
        cout<<ans1<<ans2<<endl;
    }
}