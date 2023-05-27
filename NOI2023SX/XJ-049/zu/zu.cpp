#include<bits/stdc++.h>
using namespace std;
int d,t;
int a[50][50];
int main(){
	freopen("zu.in","r",stdin);
	freopen("zu.out","w",stdout);
	cin >> d >> t;
	for(int x=1;x<=t;x++){
		int n,m;
		cin >> n >> m;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			a[i][0]=1;
			a[i][m+1]=1;
		}
		for(int i=1;i<=m;i++){
			a[0][i]=1;
			a[n+1][i]=1;
		}
		for(int i=1;i<=n;i++){
			string s;
			cin >> s;
			for(int j=0;j<m;j++){
				if(s[j]=='#') a[i][j+1]=1;
				if(s[j]=='X') a[i][j+1]=2;
				if(s[j]=='O') a[i][j+1]=3;
			}
		}
		int k=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]==3){
					if((a[i-1][j]==3||a[i-1][j]==1)&&(a[i+1][j]==3||a[i+1][j]==1)&&(a[i][j+1]==3||a[i][j+1]==1)&&(a[i][j-1]==3||a[i][j-1]==1)) k++;
				}
			}
		}
		if(k==2){
			cout << "Black" << " ";
			cout << 0 << endl;
			continue;
		}
		if(d<=4 && d>=1){
			cout << "Tie" << endl;
			continue;
		}
		if(5<=d && d<=6){
			int q,e,w,r;
			for(int i=1;i<=n-2;i++){
				for(int j=1;j<=m;j++){
					if(a[i][j]==2){
						q=i;
						w=j;
					}
					if(a[i][j]==3){
						e=i;
						r=j;
					}
				}
			}
			if(m==1){	
				if(q>e){
					if((q-e)%2==1){
						cout << "Red" << " ";
						cout << q-e << endl;
						continue;
					}else{
						cout << "Black" << " ";
						cout << 2*e+(q-e) << endl;
					}
				}else{
					if(e-q==1){
						cout << "Red" << " ";
						cout << e-q << endl;
					}else{
						cout << "Black" << " ";
						cout << 2*q << endl;
					}
					continue;
				}
			}else{
				if(q>=e){
					if((q-e)+1>=fabs(w-r)){
						cout << "Red" << " ";
						cout << q-e+fabs(w-r) << endl;
					}else{
						cout << "Black" << " ";
						cout << 2*q << endl;
					}
				}else{
					cout << "Black" << " ";
					cout  << 2*q << endl;
				}
				continue;
			}
		}
		cout << "Tie" << endl;
		continue;
	}
	return 0;
}
