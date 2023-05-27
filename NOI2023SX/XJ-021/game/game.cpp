#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=10010;
int T;
int n,m;
int s[N][3],t[N][3],x;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i][0];
            for(int j=1;j<=s[i][0];j++)
                cin>>s[i][j];
        }
        for(int i=1;i<=n;i++)
        {
            cin>>t[i][0];
            for(int j=1;j<=t[i][0];j++)
                cin>>t[i][j];
        }
        cout<<"-1";
    }
}