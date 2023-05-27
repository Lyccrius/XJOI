#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int t,k,n;
	cin>>t>>k;
	if(k==1)
        {
            while(t--)
            {
                int a[50005]={0},s,t;
                cin>>n;
                for(int i=1;i<=n;i++)
                    cin>>a[i];
                s=a[1];t=a[1];
                for(int i=2;i<=n;i++)
                    {
                        if(a[i]>s)
                            s=a[i];
                        if(a[i]<t)
                            t=a[i];
                    }
                cout<<s-t<<endl;
            }
        }
	return 0;
}

