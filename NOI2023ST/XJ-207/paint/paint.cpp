#include<bits/stdc++.h>
using namespace std;
long long int a[16383][16383];
int t,n,m,q;
int o,x,c;
int main(){
	freopen("paint.in","r",stdin);
    freopen("paint.out","w",stdout);
    cin>>t;
    for(int i=1;i<=t;i++){
		cin>>n>>m>>q;
		for(int j=1;j<=q;j++){
			cin>>o>>x>>c;
			if(o==0){
				for(int h=0;h<m;h++){
					a[x-1][h]=c;
				}
			}
			else{
				for(int g=0;g<n;g++){
					a[g][x-1]=c;
				}
			}
		}
		for(int h=0;h<n;h++){
		    for(int g=0;g<m;g++){
			    cout<<a[h][g]<<' ';
			    a[h][g]=0;
		    }
		    cout<<endl;
	    }
	}
    return 0;
}
