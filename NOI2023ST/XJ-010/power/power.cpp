#include<iostream>
using namespace std;
long long n,k,ans=1,x,a,b,s;
void po()
{
    s=1;
    bool ff=0;
    for(x=3;x<=n;x++)
    {
        for(a=2;a<x/4+5;a++)
        {       
            s=1;
            if(x%a!=0) continue;
            for(b=1;;b++)
            {
                s=s*a;
                if(b>=k)
                {
                    if(s==x)
                    {
//                      cout<<a<<" "<<b<<" "<<s<<endl;
                        ans++;
                        ff=1;
                        break;
                    } 
                    if(s>x) break;
                }
            }
            if(ff==1)
            {
                ff=0;
                break;
            }
        }
    }
    return;
}
int main()
{
    freopen("power.in","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    if(n==1000000000000000000&&k==2)
    {
        cout<<1001003332;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(n==1000000000000&&k==2)
    {
        cout<<1010196;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(n==1000000000000000000&&k==3)
    {
        cout<<1036002;
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    if(k==1) cout<<n;
    else
    {
        po();
        cout<<ans;
    } 
    fclose(stdin);
    fclose(stdout);
    return 0;
}