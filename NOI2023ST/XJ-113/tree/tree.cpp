#include<bits/stdc++.h>

using namespace std;

int a[100000];

int main(){
	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
    double x,y;
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>x>>y;
        a[i] = max(x,y) - min(x,y);
    }
    for (int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}
