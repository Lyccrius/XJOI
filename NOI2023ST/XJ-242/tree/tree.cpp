#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int n,i;
	cin>>n;
	float a[3][n];
	for(i=1;i<=n;i++)
	    cin>>a[1][i]>>a[2][i];
	cout<<n<<" "<<int(a[1][n])<<" "<<int(a[1][n-1]-a[1][n]);
}
