#include<bits/stdc++.h>
using namespace std;
int main()
{int n,k,t=0,l[101];
cin>>n>>k;
for(int a=0;a<=n;a++)
{int s=1;
for(int b=0;b<=n;b++)
{s=s*a;
if(s>n)
break;
if(s<n and b>=k)
{l[a]=s;
for(int d=0;d<(a-1);d++)
{
    if(l[d]==s)
    t--;
    
}
t++;
}
}
}
cout<<t;
return 0;}
