#include <bits/stdc++.h>
using namespace std;
int n;
double x[1005],y[1005],maxy=-9999999999,k;
double dis(int a,int b){
	return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(y[i]>maxy){
			maxy=y[i];
			k=i;
		}
	}
	x[0]=x[n];
	y[0]=y[n];
	x[n+1]=x[1];
	y[n+1]=y[1];
	int l=k-1,r=k+1,m=k;
	for(int i=1;i<=n;i++){
		cout<<m<<" ";
		if(l==0) l=n;
		if(r==n+1) r=1;
		if(dis(m,l)<dis(m,r)){
			m=l;
			l--;
		}else{
			m=r;
			r++;
		}
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
