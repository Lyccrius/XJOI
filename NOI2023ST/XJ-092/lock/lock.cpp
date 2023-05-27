#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e+5;
long long t,k,b[maxn],n;
int main(){
	freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>t>>k;
    for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>b[j];
		}
		sort(b,b+n);
		cout<<b[n-1]-b[0]<<endl;
		memset(b,0,sizeof(b));
	}
	return 0;
	fclose(stdin);
    fclose(stdout);
}
