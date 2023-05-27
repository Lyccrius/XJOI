#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m,q,x,c;
    int t,opt;
    cin>>t;
    for(int a=1;a<=t;a++){
        cin>>n>>m>>q;
        long long int list[n][m];
        for(int k=0;k<q;k++)
        {
            cin>>opt>>x>>c;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)list[i][j]=0;
            }
            if(opt==0)
            {
                for(int i=0;i<m;i++){list[x-1][i]=c;}
            }
            if(opt==1)
            {
                for(int i=0;i<n;i++){list[i][x-1]=c;}
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;i<m;j++){cout<<list[i][j]<<" ";}
            cout<<endl;
        }
    }
    return 0;
}
