#include<bits/stdc++.h>
using namespace std;
const int N = 1e8+5;
long long n,k,ans,vis[N];

void p(long long a){
	if(vis[a]==1) return ;
    int c=0,b=1;
    while(1){
		b*=a;
		if(b > n){
			break;
		}
        c++;
        if(c >= k && vis[b]!=1) ans++;
        vis[b]=1;
    }
    return ;
}

int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	
    cin >> n >> k;
    for(long long i=2;i<=n;i++){
            p(i);
    }
    cout << ans+1;
    
    fclose(stdin);fclose(stdout);
    
    return 0;
}
