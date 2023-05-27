#include<bits/stdc++.h>
using namespace std;
long long int n,k,t,x=1,bi,c,xi,ans=0;
long long int a[16383][16383];
int main(){
	freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>t>>k;
    for(long long int w=1;w<=t;w++){
		cin>>n;
        for(long long int i=0;i<k;i++){
		    for(long long int j=0;j<n;j++){
		        cin>>a[i][j];
		    }
	    }
	    for(long long int i=0;i<k;i++){
			x=1;
	        bi=a[i][0];
	        while(x<n){
			    if(bi<a[i][x]){
			        bi=a[i][x];
		        }
		        x++;
	        }
	    }
	    for(long long int i=0;i<n;i++){
		    while(bi!=a[0][i]){
			    c=a[k-1][i];
			    for(long long int g=k-2;g>=0;g--){
				    a[g+1][i]=a[g][i];
			    }
			    a[0][i]=c;
		    }
	    }
	    for(long long int i=0;i<k;i++){
			x=1;
		    bi=a[i][0];
		    xi=a[i][0];
		    while(x<n){
			    if(bi<a[i][x]){
			       bi=a[i][x];
		        }
		        if(xi>a[i][x]){
			        xi=a[i][x];
		        }
		        x++;
		    }
		    if(ans<bi-xi){
			    ans=bi-xi;
		    }
		}
	    cout<<ans<<endl;
    }
    return 0;
}
