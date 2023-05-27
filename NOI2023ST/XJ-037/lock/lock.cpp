#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+5;
int T, k, n,l[5][N],ans=10;

int b();
void DFS(int f){
    if(f>n) ans=min(b(), ans);
    DFS(f+1);
    int a[5],i;
    for(i=1;i<k;i++){
        for(int j=1;j<=k;j++)
            a[j]=l[f][j];
        for(int j=1;j<=k;j++)
            l[f][j%k+i]=a[j];

        DFS(f+1);
        
		for(int j=1;j<=k;j++)
			a[j]=l[f][j];
		int j;
		for(j=1;j<=k;j++){
			if(j-i <= 0)
				l[f][j+k-i]=a[j];
			else l[f][j-i]=a[j];
		}		
    }
        for(int j=1;j<=k;j++)
            a[j]=l[f][j];
		int j;
        for(j=1;j<=k;j++){
			if(j-i <= 0)
				l[f][j+k-i]=a[j];
			else l[f][j-i]=a[j];
		}
}

int b(){
    int c1[N];
    for(int i=1;i<=k;i++){
        int maxv=-1,minv=6;
        for(int o=1;o<=n;o++){
            maxv=max(maxv, l[i][o]);
            minv=min(minv, l[i][o]);
        }
        c1[i]=maxv-minv;
    }
    int c=6;
    for(int i=1;i<=k;i++){
        c=min(c, c1[i]);
    }
   return c;
}

int main(){
    cin >> T >> k;
    while(T--){
        cin >> n;
        for(int i=1;i<=k;i++)
            for(int o=1;o<=n;o++)
                cin >> l[i][o];

        DFS(1);
        cout << ans << '\n';
    }
}
