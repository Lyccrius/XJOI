#include<bits/stdc++.h>
using namespace std;
int m;
double x[10],y[10],s[10][10];
main()
{
    freopen(tree,"w",stdin);
    freopen(tree,"r",stdout);
    cin>>m;
    for(int i=1;i<=m;i++)
    cin>>x[i]>>y[i];
    if(m==1)
    {cout<<1;return 0;}
    if(m==2)
    {cout<<2<<" "<<2;return 0;}

    for(inti =1;i<=m-1;i++)
    for(int j=i+1;j<=m;j++)
{s[i][j]=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
s[j][i]=s[i][j];}
if(m==3)
if(s[2][3]>s[1][3])
{cout<<3<<" "<<1<<" "<<2;return 0;}
else
{cout<<3" "<<2<<" "<<1;return 0;}
if(m==4)
if(s[1][2]+s[2][3]+s[3][4]<s[1][2]+s[3][4]+s[2][4]&&s[1][2]+s[3][4]+s[2][3]<s[1][2]+s[3][4]+s[1][3]&&s[1][2]+s[3][4]+s[2][3]<s[1][2]+s[3][4]+s[1][4])
{cout<<4<<" "<<3<<" "<<2<<" "<<1;return 0;}
else
if(s[1][2]+s[1][3]+s[3][4]<s[1][2]+s[3][4]+s[2][4]&&s[1][2]+s[3][4]+s[1][3]<s[1][2]+s[3][4]+s[2][3]&&s[1][2]+s[3][4]+s[1][3]<s[1][2]+s[3][4]+s[1][4])
{cout<<4<<" "<<3<<" "<<1<<" "<<2;return 0;}
else
if(s[1][2]+s[1][4]+s[3][4]<s[1][2]+s[3][4]+s[2][4]&&s[1][2]+s[3][4]+s[1][4]<s[1][2]+s[3][4]+s[1][3]&&s[1][2]+s[3][4]+s[1][4]<s[1][2]+s[3][4]+s[2][3])
{cout<<3<<" "<<4<<" "<<1<<" "<<2;return 0;}
else
cout<<3<<" "<<4<<" "<<2<<" "<<1;
    return 0;
    }
