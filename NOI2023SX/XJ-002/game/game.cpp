#include<bits/stdc++.h>
using namespace std;
const int nm=3e5+5;
queue<int>S[nm];
queue<int>T[nm];
int t,n,m,s,ss;
int cnts=0,cntt=0;
int s1[nm],t1[nm],t2[nm],s2[nm];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>t;
    while(t--)
    {
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        memset(t1,0,sizeof(t1));
        memset(t2,0,sizeof(t2));
        cnts=cntt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=1;j<=s;j++)
            {
                cin>>ss;
                S[i].push(ss);
                s1[ss]++;
            }
        }
        for(int i=1;i<=n;i++)
        {
            cin>>s;
            for(int j=1;j<=s;j++)
            {
                cin>>ss;
                T[i].push(ss);
                t1[ss]++;
            }
        }
        
    }
}
/*
 🤡🤡🤡🤡    🤡🤡🤡🤡  🤡🤡🤡🤡🤡
🤡          🤡          🤡
🤡          🤡          🤡
🤡          🤡          🤡🤡🤡🤡
🤡          🤡          🤡
 🤡🤡🤡🤡    🤡🤡🤡🤡   🤡

🔞        🔞    🔞🔞🔞     🔞🔞🔞  
🔞🔞      🔞  🔞      🔞     🔞
🔞  🔞    🔞  🔞      🔞     🔞 
🔞    🔞  🔞  🔞      🔞     🔞
🔞      🔞🔞  🔞      🔞     🔞
🔞        🔞    🔞🔞🔞     🔞🔞🔞
*/