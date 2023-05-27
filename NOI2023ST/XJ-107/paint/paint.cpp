
#include <bits/stdc++.h>
using namespace std;
long long z[1000000],s[1000000],z1[1000000],s1[1000000];
long long m,n,q;	
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int timee;
	cin >>timee;
	for(int i=0;i<timee;i++)
	{	
	memset(z,0,sizeof(z));
	memset(z1,0,sizeof(z));
	memset(s,0,sizeof(z));
	memset(s1,0,sizeof(z));
    cin >>n>>m>>q;
    for(int i=1; i<=q; i++)
    {
        int opt,x,c;
        cin >>opt>>x>>c;
        if(opt==0)
        {
            z[x]=c;
            z1[x]=i;
        }
        if(opt==1)
        {
            s[x]=c;
            s1[x]=i;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(z1[i]>s1[j])
                cout <<z[i] << " ";
            else if(s1[j]>z1[i])
            cout <<s[j] << " ";
			else cout << "0" << " ";
        }
        cout <<endl;
    }
	}
	fclose(stdin);
    return 0;
}
