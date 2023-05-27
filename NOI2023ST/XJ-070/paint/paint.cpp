#define N 1000
// #define NOI_DEBUG

#include<bits/stdc++.h>
using namespace std;
int main()
{
#ifndef NOI_DEBUG
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
#endif
    unsigned short T;
    int n, m, q, opt, x, c;
    unsigned arr[N][N];
    unsigned short h;
    unsigned i, j;
    cin>>T;
    for(h=0;h<T;h++)
    {
        cin>>n>>m>>q;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                arr[i][j]=0;
        for(i=0;i<q;i++)
        {
            cin>>opt>>x>>c;
            if(!opt)
                for(j=0;j<m;j++)
                    arr[x][i]=c;
            else
                for(j=0;j<n;j++)
                    arr[i][x]=c;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cout<<arr[i][j];
                if(m-j>1)
                    cout<<' ';
            }
            cout<<endl;
        }
    }
#ifndef NOI_DEBUG
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}

/*const unsigned short inSmp[43]={
    2,
    5,5,9,
    1,5,1,
    0,4,0,
    1,4,1,
    0,3,0,
    1,3,1,
    0,2,0,
    1,2,1,
    0,1,0,
    1,1,1,
    3,3,3,
    0,1,2,
    0,3,1,
    1,1,3};*/