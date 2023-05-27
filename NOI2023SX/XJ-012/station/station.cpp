#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5+5;

struct rail {
    int l, r, dis;
    friend bool operator< (const rail x, const rail y) {
        return x.dis < y.dis;
    }
};
rail raill[maxn], railr[maxn];
int cntl = 0, cntr = 0;

set<int> ans;

int main() {
    freopen("station.in", "r", stdin);
    freopen("station.out", "w", stdout);
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    int l = x, r = x;
    for(int i = 1; i <= m; i ++) {
        int li, ri;
        scanf("%d%d", &li, &ri);
        if(li <= x && x <= ri) {
            if(li != x) ans.insert(li);
            if(ri != x) ans.insert(ri);
            l = min(l, li);
            r = max(r, ri);
        }
        else if(ri < x) {
            raill[++cntl].l = li;
            raill[cntl].r = ri;
            raill[cntl].dis = x-ri;
        }
        else {
            railr[++cntr].l = li;
            railr[cntr].r = ri;
            railr[cntr].dis = li-x;
        }
    }
    sort(raill + 1, raill + cntl + 1);
    sort(railr + 1, railr + cntr + 1);
    for(int i = 1; i <= cntl; i ++) {
        if(raill[i].r < l) break;
        l = min(l, raill[i].l);
        ans.insert(raill[i].l);
    }
    for(int i = 1; i <= cntr; i ++) {
        if(railr[i].l > r) break;
        r = max(r, railr[i].r);
        ans.insert(railr[i].r);
    }
    for(auto i = ans.begin(); i != ans.end(); i ++) {
        printf("%d ", *i);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}