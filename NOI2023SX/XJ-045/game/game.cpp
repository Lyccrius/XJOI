#include<bits/stdc++.h>
using namespace std;
int T,n,m,cnt,ssum,tsum;
int ss1[300010],ss2[300010],tt1[300010],tt2[300010];
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(ss1,0,sizeof(ss1));
        memset(ss2,0,sizeof(ss2));
        memset(tt1,0,sizeof(tt1));
        memset(tt2,0,sizeof(tt2));
        cnt=0;
        for(int i=1;i<=n;i++){
            cin>>ssum;
            if(ssum==1)
                cin>>ss1[i];
            if(ssum==2)
                cin>>ss1[i]>>ss2[i];    
        }
        for(int i=1;i<=n;i++){
            cin>>tsum;
            if(tsum==1)
                cin>>tt1[i];
            if(tsum==2)
                cin>>tt1[i]>>tt2[i];
            if((tt1[i]==ss1[i]&&tt2[i]==ss2[i])
                ||(tt1[i]==ss2[i]&&tt2[i]==ss1[i]))
                cnt++;
        }
        if(cnt==n)
            cout<<n<<endl;
        else
            cout<<0<<endl;
    }
}