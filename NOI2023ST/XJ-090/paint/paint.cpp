#include<bits/stdc++.h>
using namespace std;
int a[10000][10000];
int T;
int main(){
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    cin >> T;
    while(T --){
		int n, m, q;
        cin >> n >> m >> q;
        for(int i = 1; i <= m; i ++)
            for(int j = 1; j <= n; j ++)
                a[i][j] = 0;
        while(q --){
            int op, x, c;
            cin >> op >> x >> c;
            if(op)
                for(int i = 1; i <= n; i ++)
                    a[i][x] = c;
            else
                for(int i = 1; i <= m; i ++)
                    a[x][i] = c;
        }
        for(int i = 1; i <= m; i ++){
            for(int j = 1; j <= n; j ++)
                cout << a[i][j] <<" ";
			cout << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
