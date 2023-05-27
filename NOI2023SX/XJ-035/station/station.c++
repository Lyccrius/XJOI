#include <bits/stdc++.h>
using namespace std;
int n,m,x,vis[200050],ans[200005];
int main()
{
	freopen("station.in","r",stdin);
	freopen("station.out","w",stdout);
	cin>>n>>m>>x;
	if(x==1){
		int a,c,b[200005],t=m;
		for(int i=1;i<=m;i++){
			cin>>a>>c;
			if(vis[c]==0){
				b[i]=c;
				vis[c]++;
			}else t--;
		}
		sort(b+1,b+1+t);
		for(int i=1;i<=t;i++){
			cout<<b[i]<<" ";
		}
	}
	int l1,l2;
	int j=0;
	for(int i=1;i<=m;i++){
		cin>>l1>>l2;
		if(vis[l1]!=1){
			if(l1<x){
		    	j++;
		    	ans[j]=l1;
		    }
		}
		if(vis[l2]!=1){
			if(l2>x){
		    	j++;
		    	ans[j]=l2;
		    }
		}
		vis[l1]=1;
		vis[l2]=1;
	}
	
    sort(ans+1,ans+1+j);
    for(int i=1;i<=j;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

