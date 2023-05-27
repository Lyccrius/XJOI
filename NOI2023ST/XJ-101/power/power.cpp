//85tps code by MisakaE
#include<bits/stdc++.h>
#define ll long long
#define pll __int128
using namespace std;
const int N = 1e7+10;
const int M =1e7+5;
bool f[N];
ll n;
int cnt,k;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    scanf("%lld%d",&n,&k);
    ll mx=sqrt(n);
    ++cnt;
    for(int i=2;i<=min(mx+10,1ll*M);++i)
    {
        if(f[i])continue;
        pll s=1,h=n;
        for(int j=1;s*i<=h;++j){
            s*=i;
            if(j>=k)++cnt;
            if(s<M)f[s]=1;
        }
    }
    printf("%d",cnt);
    fclose(stdin);
    fclose(stdout);
    return 0;
}