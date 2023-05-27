#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    //cout<<"...?";
    int n;
    cin>>n;
    int c[2*n+1],l=0,d[2*n+1],e[2*n+1];
    for(int i=1;i<=n;i++)
    {
        double a,b;
        cin>>a>>b;
        c[l]=a;
        c[l+1]=b;
        e[l]=a+b;
        l+=3;
    }
    for(int i=0;i<=l;i++)
    {
        if(c[i]!=0)
        {
            d[c[i]]++;
        }
    }
    for(int i=l;i<=0;i++)
    {
        if(d[c[i]]!=0)
        {
            cout<<i;
            d[c[i]]=0;
        }
    }
    for(int i=0;i<=l;i++)
    {
        if(e[i]!=0)
        {
            d[c[i]]++;
        }
    }
    for(int i=l;i<=0;i++)
    {
        if(e[c[i]]!=0)
        {
            cout<<i;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
