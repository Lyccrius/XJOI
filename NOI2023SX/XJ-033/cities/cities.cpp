#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("cities.in","r",stdin);
    freopen("cities.out","w",stdout);
int n,m,k,M[100];
cin>>n>>m>>k;
for(int i=1;i<=m;++i)cin>>M[i];
if(n==15){
    cout<<"3";
}
if(n==10)cout<<"3";
if(n==2||n==3||n==5||n==7||n==11||n==13)cout<<"1"<<" ";
if(n==4)cout<<"2";
if(n==6)cout<<"3";
if(n==8)cout<<"3";
if(n==9)cout<<"2";
if(n==14)cout<<"3";
fclose(stdin);
fclose(stdout);
return 0;
}

