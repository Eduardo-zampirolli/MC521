#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
 
//funções do cp-algorithms (https://cp-algorithms.com/data_structures/segment_tree.html)
struct Node {
    int mx1, cnt1, mx2, cnt2;
    Node(int v = -1) : mx1(v), cnt1(1), mx2(-1), cnt2(0) {}
    Node(int mx1, int cnt1, int mx2, int cnt2)
        : mx1(mx1), cnt1(cnt1), mx2(mx2), cnt2(cnt2) {}
};

Node combine(Node a, Node b) {
    if (a.mx1 == b.mx1) {
        int mx2 = max(a.mx2, b.mx2);
        int cnt2 = 0;
        if (a.mx2 == mx2) cnt2 += a.cnt2;
        if (b.mx2 == mx2) cnt2 += b.cnt2;
        return Node(a.mx1, a.cnt1 + b.cnt1, mx2, cnt2);
    }
    Node hi = a.mx1 > b.mx1 ? a : b;
    Node lo = a.mx1 > b.mx1 ? b : a;
    int mx2 = max(lo.mx1, hi.mx2);
    int cnt2 = 0;
    if (lo.mx1 == mx2) cnt2 += lo.cnt1;
    if (hi.mx2 == mx2) cnt2 += hi.cnt2;
    return Node(hi.mx1, hi.cnt1, mx2, cnt2);
}

const int MAXN = 200005;
Node t[4 * MAXN];
int a[MAXN], n;

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = Node(a[tl]);
    } else {
        int tm = (tl + tr) / 2;
        build(v*2, tl, tm);
        build(v*2+1, tm+1, tr);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
        t[v] = Node(new_val);
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

Node query(int v, int tl, int tr, int l, int r) {
    if (l > r) return Node(-1);
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return combine(
        query(v*2, tl, tm, l, min(r, tm)),
        query(v*2+1, tm+1, tr, max(l, tm+1), r)
    );
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int q; cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];
    build(1, 0, n-1);

    while (q--) {
        int type; cin >> type;
        if (type == 1) {
            int p, x; cin >> p >> x;
            a[--p] = x;
            update(1, 0, n-1, p, x);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            Node res = query(1, 0, n-1, l, r);
            cout << (res.mx2 == -1 ? 0 : res.cnt2) << endl;
        }
    }
    return 0;
}
