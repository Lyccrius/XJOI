#include<iostream>
#include<stdio.h>
using namespace std;
int a,b,n,m,t;
int main()
{
    freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    for(int j=0;j<t;j++)
    {
        int q;
        cin>>n>>m>>q;
        int arr[1000][1000]={0};
            for(int f=0;f<n;f++)
            {
                for(int g=0;g<m;g++)
                {   
                    arr[f][g]=0;
                }
            }
        for(int i=0;i<q;i++)
        {
            int opt,x,c;
            cin>>opt>>x>>c;
            
            if(opt==0)
            {
                for(int k=0;k<n;k++)
                {
                    arr[x-1][k]=c;
                }
            }
            else if(opt==1)
            {
                for(int k=0;k<m;k++)
                {
                    arr[k][x-1]=c;
                }
            }
        }
        for(int g=0;g<n;g++)
        {
            for(int h=0;h<m;h++)
            {
                cout<<arr[g][h]<<" ";
                arr[g][h]=0;
            }
            cout<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}