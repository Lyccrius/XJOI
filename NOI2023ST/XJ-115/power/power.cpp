#include<bits/stdc++.h>
using namespace std;
long long int n,k,y=1,f=0;
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    long long int a,flag=0,j,i;
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        for(j=i;j>=1;j--)
        {
            if(i==1)
            {
                a=1;
                f++;
                break;
               
            }
            if(i%j!=0)continue;
            for(a=1;a<=i/2;a++)
            {
                if(pow(j,a)==i&&a>=k)
                {
                    flag=1;
                    break;
                }
            }
            y=1;
            if(flag==1)
            {
                f++;
                flag=0;
                break;
            }
            
        }
    } 
    cout<<f;
    fclose(stdin);
    fclose(stdout);
    return 0;
}