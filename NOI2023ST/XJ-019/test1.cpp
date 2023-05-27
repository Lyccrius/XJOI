#include<bits/stdc++.h>
using namespace std;
int main()
{
    fstream infs,outfs;
    infs.open("paint.in",ios::in);
    outfs.open("paint.out",ios::out);

    long long int n,m,q,x,c;
    int t,opt;
    char a;
    while(infs.get(a)){
        a>>t;
        for(int a=1;a<=t;a++){
            a>>n>>m>>q;
            long long int list[n][m];
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)list[i][j]=0;
            }
            for(int k=0;k<q;k++)
            {
                a>>opt>>x>>c;
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
                for(int j=0;j<m;j++){outfs.put(list[i][j]);outfs.put(' ');}
                outfs.put('\n');
            }
        }
    }
    return 0;
}