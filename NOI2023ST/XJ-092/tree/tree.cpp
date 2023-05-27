#include<bits/stdc++.h>
using namespace std;
const long long maxn=1e+5;
long long t,k,b[maxn],n;
bool flag=true;
double x[maxn]={},y[maxn]={},z=0,l[maxn]={};
int main(){
	freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		l[i]=i;
	}
	while(n--){
		long long sc=rand()%100000;
		sc%=100;
		cout<<sc%10<<" ";
	}
	fclose(stdin);
    fclose(stdout);
	return 0;
}
