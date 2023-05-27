#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    double a[1004][2],h = 0;
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
		cin >> a[i][1] >> a[i][2];
		if(h < a[i][2]){
				h = a[i][2];
		}
	}
	return 0;
}
