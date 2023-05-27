#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int a[N][N];
int main()
{
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
    int j,i,T,n,m,p,opt,x,c,b,d;
    cin>>T;
    for(i=0;i<T;i++)
    {
        cin>>n>>m>>p;
        for(j=1;j<=n;j++)
        {
            for(d=1;d<=m;d++)
            {
                a[j][d]=0;
                //cout<<a[j][d]<<" ";
		    }
            //cout<<endl;
        }
        //cout<<endl;
        for(j=0;j<p;j++)
        {
            cin>>opt>>x>>c;
            int num=c;
            if(opt==0)
            {
                for(b=1;b<=m;++b)
                a[x][b]=num;
                continue;
            }
            else if(opt==1)
            {
                for(b=1;b<=n;++b)
                a[b][x]=num;
                //cout<<num<<endl;
                continue;
            }
        }
        for(j=1;j<=n;j++)
        {
            for(d=1;d<=m;d++)
            {
                cout<<a[j][d]<<" ";
		    }
            cout<<endl;
        }
        cout<<endl;
    }
    //system("pause");
    return 0;
}
