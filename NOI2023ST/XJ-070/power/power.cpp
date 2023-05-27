#define N 1000
#define NOI_DEBUG


#include<bits/stdc++.h>
using namespace std;

typedef unsigned short us;
typedef const unsigned short cus;
typedef unsigned long long ull;
typedef const unsigned long long cull;

ull power(cull a, cus n)
{
    ull ans=1;
    us i;
    for(i=0;i<n;i++)
        ans*=a;
    return ans;
}

int main()
{
#ifndef NOI_DEBUG
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
#endif
    ull n, a, b, sum=0, p, i;
    us k;
    bool ok[N];
    cin>>n>>k;
    memset(ok, 0, n);
    for(a=1;a<=n;a++)
        for(b=k;b<=n;b++)
        {
            p=power(a, b);
            if(!ok[p]&&p<=n)
            {
                ok[p]=1;
                sum++;
            }
        }
    cout<<sum<<endl;
#ifndef NOI_DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}