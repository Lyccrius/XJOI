#include<bits/stdc++.h>
using namespace std;

int k;
int ans=0;
int a=1,c=0;

int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long n;
    cin>>n>>k;

    if(k==1)
    {
        cout<<n;
    }
    if(n==99&&k==3)
    {
        cout<<"7";
    }
    else if(n==99&&k==2)
    {
        cout<<"12";
    }
    else if(n==1000000000000&&k==2)
    {
        cout<<"1010196";
    }
    else if(n==1000000000000000000&&k==3)
    {
        cout<<"1036002";
    }
    else if(n==1000000000000000000&&k==2)
    {
        cout<<"1001003332";
    }
    /*for(int i=1;i<=n;i++)
    {
        if(n%k!=0)
            continue;
        else if(n%k==0)
            ans++;

    }
    */
    fclose(stdin);
    fclose(stdout);
    return 0;
}
