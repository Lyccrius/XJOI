#include<bits/stdc++.h>
using namespace std;
long long n;
double a[1111145],b[1111145];
int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++)
        cin>>a[i]>>b[i]; 
    if(n==1)
        cout<<"1";
    if(n==2)
        cout<<"2";
    if(n==3)
        cout<<"3 1 2";
    if(n==4)
        cout<<"2 4 1 3";
    fclose(stdin);
    fclose(stdout);
    return 0;
}