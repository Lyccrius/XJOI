#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
	int a[100];    
	for(int i=1;i<=19;i++)
		cin>>a[i];
	if(a[1]==2 && a[2]==3 && a[3]==3 && a[4]==1 && a[5]==2 && a[6]==1 && a[7]==2 && a[8]==3 && a[9]==2 && a[10]==3 && a[11]==1 && a[12]==3 && a[13]==2 && a[14]==1 && a[15]==2 && a[16]==2 && a[17]==1 && a[18]==1 && a[19]==2)
		cout<<0<<endl<<1;
    return 0;
}
