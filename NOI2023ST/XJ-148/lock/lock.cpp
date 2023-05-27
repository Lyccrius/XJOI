#include<bits/stdc++.h>
using namespace std;
const int M=3010;
int t,k,n,a[M][M],lie[M];
int c[M],ans1,ans2=M,ans3;
int cnt,d[M],e[M];
int max1(int a,int b){
	if(a>b) return a;
	return b;
} 
int min1(int a,int b){
	if(a<b) return a;
	return b;
} 
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>t>>k;
    for(int l=1;l<=t;l++){
		ans1=ans3=0;
		ans2=M;
		memset(c,0,sizeof(c));
        memset(e,0,sizeof(e));
        for(int i=1;i<=M;i++){
            d[i]=M;
        }
        cin>>n;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                d[i]=min1(a[j][i],d[i]);
                cout<<d[i]<<" "<<e[i]<<endl;
            }
        }
        sort(d+1,d+n+1);
        ans3=d[n]-d[1];
        cout<<ans3<<endl;
    }
    return 0;
}
