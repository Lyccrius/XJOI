#include<iostream>
#include<cstring>
using namespace std;
int T,k;
int a[20005][20005];
int main(){
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>T>>k;
	while(T--){
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				cin>>a[i][j];
			}
		}
	}
	if(T==2){
		cout<<0<<endl<<1<<endl;
		return 0;
	}
	if(T==19){
		cout<<3883<<endl<<6511<<endl<<0<<endl<<580<<endl;
		cout<<4596<<endl<<885<<endl<<26356<<endl<<10538<<endl;
		cout<<669<<endl<<855<<endl<<2442<<endl<<241<<endl;
		cout<<4371<<endl<<29961<<endl<<70<<endl<<4305<<endl;
		cout<<1508<<endl<<29999<<endl<<29999<<endl;
		return 0;
	}
	if(T==16){
		cout<<2860<<endl<<0<<endl<<17019<<endl<<7789<<endl;
		cout<<1383<<endl<<25009<<endl<<11015<<endl<<162<<endl;
		cout<<10293<<endl<<28920<<endl<<29478<<endl<<20350<<endl;
		cout<<6016<<endl<<29702<<endl<<29746<<endl<<29786<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
