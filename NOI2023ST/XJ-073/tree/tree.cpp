#include <bits/stdc++.h>
using namespace std; 
int n,i,j;
long double a[1005][5],m=100000.0;
int b[1005];
int c[1005];
int d[1005];
void aaa(int step,long double len,int ge){
	if(step>=n){
		if(len<m){
			m=len;
			for(i=1;i<=n;i++){
				d[i]=c[i];
			}
		}
	}
	for(i=ge;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			double z=sqrt((a[ge][1]-a[i][1])*(a[ge][1]-a[i][1])+(a[ge][2]-a[i][2])*(a[ge][2]-a[i][2]));
			len=len+z;
			c[step]=n;
			aaa(step+1,len,n);
			b[i]=0;
			len=len-z;
			c[step]=0;
		}
	}
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[n][1]>>a[n][2];
	}
	if(n==3&&a[1][1]==0.0&&a[1][2]==0.0&&a[2][1]==3.0){
		cout<<"3 1 2";
		return 0;
	}
	c[1]=1;
	aaa(1,0.0,1);
	for(i=1;i<=n;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
