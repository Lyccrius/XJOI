#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
long long T,m,n,opt,x,c,p;
long long a[N][N];
int main(){
	freopen("paint.in","r",stdin);
	freopen("paint.out","w",stdout);

	cin >> T;
	while(T--){
        for(int i=1;i<=n;i++)
			for(int o=1;o<=m;o++)
				a[i][o]=0;
				
        cin >> n >> m >> p;            
        while(p--){
            cin >> opt >> x >> c;
            if(opt==1)
                for(int i=1;i<=n;i++)
                    a[i][x]=c;
            if(opt==0)
                for(int o=1;o<=m;o++)
                    a[x][o]=c;
        }

        for(int i=1;i<=n;i++){
            for(int o=1;o<=m;o++)
                cout << a[i][o] << ' ';
            cout << '\n';
        }
	}

	fclose(stdin);fclose(stdout);

	return 0;
}
