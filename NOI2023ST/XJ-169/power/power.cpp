#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    freopen ("power4.in","r",stdin);
    freopen ("power4.out","w",stdout);
    long long n;
    cin>>n;
    int k;
    cin>>k;
    int res=0;
    int a[n+1];
    for(int i=0;i<=n;i++)
    {
        a[i]=0;
    }
    a[1]=1;
    for(int down=2;pow(down,2)<=n;down++)
    {
        for(int up=k;pow(down,up)<=n;up++)
        {
            a[int (pow(down,up))]=1;
        }
    }
    for(int i=0;i<=n;i++)
    {
        res+=a[i];
    }
    cout<<res;
    fclose(stdin);
    fclose(stdout);
    return 0;
}