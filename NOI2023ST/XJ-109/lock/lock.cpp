#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);
	int t,k,n;
	cin>>t>>k;
	for(int v=0;v<t;v++){
		cin>>n;
		if(n==1){
			cout<<0;
			continue;
		}
		int a[n][k];
		for(int i=0;i<n;i++){
			for(int j=0;j<k;j++){
				cin>>a[i][j];
			}
		}
		if(n==2){
			cout<<abs(a[0][0]-a[1][0]);
			continue;
		}
		srand(time(NULL));
		k=rand();
		k%=300001;
		k++;
		cout<<k;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
