#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long l[1000005];
int ans=0;
int get(int x,int y,int z){
    if(x==1) return x;
    if(y==1) return x*z;
    if(y==0) return 1;
    if(y%2==0) return get(x*x,y/2,z);
    else{
        y--;
        z=z*x;
        return get(x*x,y/2,z);
    }
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
    cin>>n>>k;
    memset(l,0,sizeof l);
    for(int i=1;i<=n/k+1;i++){
		if(i==1){
			l[1]=1;
			continue;	
		}
        int b=get(i,k,1);
        if(l[b]!=0) continue;
        while(b<=n){
			l[b]++;
			b*=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(l[i]!=0) ans++;
	}	
	cout<<ans;
    return 0;
}
