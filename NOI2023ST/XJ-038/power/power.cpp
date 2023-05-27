#include<bits/stdc++.h>
using namespace std;

long long n,k;

int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(k==1)
    {
        cout<<n;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(n==1)
    {
        cout<<n;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(k>n/2)
    {
        cout<<"1";
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    int cnt=1;
    for(int i=2;i<=n;i++)
    {
        bool f=0;
        for(int j=k;j<=100;j++)
        {
            for(int l=1;l<=sqrt(i);l++)
            {
                if(pow(l,j)==i)
                {
                    cnt++;
                    f=1;
                    break;
                }
            }
            if(f)
                break;
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}