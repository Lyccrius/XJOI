#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath> 
using namespace std;
long long a[1005][100005];
/*int lowbit(int x){
	x=x&-x;
	return x;
	}
int ask(int x){
	int ans=0;
	for(;x;x-=lowbit(x))ans+=chafen[x];
	return ans;
	}
void add(int x,int y){
	for(;x<=n;x+=lowbit(x))chafen[x]+=y;
	}*/
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int n,m,q;
	int T;
	while(cin >> T){ 
		int t=T;
		while(t!=0){
			t-=1;
			cin >> n >> m >> q;
			while(q!=0){//paint
				q-=1;
				int opt=0,x=0,c=0;
				cin >> opt >> x >> c;
				if(opt==0){//paint
					for(int i=1;i<=m;i++){
						a[x][i]=c;
						//cout << a[x][i] << " ";
					}
				}else if(opt==1){
					for(int i=1;i<=n;i++){
						a[i][x]=c;
						//cout << a[i][x] << " ";
					}
				}//paint
			}//paint
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			memset(a,0,sizeof(a));
		}
	}
	return 0;
}
