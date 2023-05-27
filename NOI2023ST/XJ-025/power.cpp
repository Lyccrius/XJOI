#include<bits/stdc++.h>
using namespace std;
bool p(int i,int x,int k,int j)
{
    if(x%i!=0)
    {
        if(j>=k)
            {return true;}
        else
            {return false;}
    }
    else
        {return p(i,x,k,j+1);}
}
int main()
{
    int n,k,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(p(j,i,k,0)==true)
                {ans++;}
        }   
    }
    cout<<ans;
    return 0;
}
