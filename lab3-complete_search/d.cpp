#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define mod(a) (a+MOD)%MOD
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()

//Retirei o código da minha resolução do exercício realizado em 17/10/2025 - problema F
//CP-Algorithms
vector<int> sort_cyclic_shifts(string const& s) {
    int n = s.size();
    const int alphabet = 256;
    //Sorting the ciclic substring
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i]]++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i]]] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n); //store permutations
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p;
}

vector<int> suffix_array_construction(string s) {
    s += "$";
    vector<int> sorted_shifts = sort_cyclic_shifts(s);
    sorted_shifts.erase(sorted_shifts.begin());
    return sorted_shifts;
}

int main() {
    string str;
    cin >> str; 


     //Suffix Array
    vector<int> sa = suffix_array_construction(str);
    int n = sz(str);

    vector<int> suff_ind(n+1);
    for (int i = 0; i < n; i++) {
        suff_ind[sa[i]] = i;
    }
    //Cálculo LCP
    vector<int> lcp(n,0);
    int k = 0;
    
    for (int i = 0; i < n; i++) {
        if (suff_ind[i]== 0) {
            k = 0;
            continue;
        }
        int j = sa[suff_ind[i] - 1];
        //Comparar
        while (i + k < n && j + k < n && str[i + k] == str[j + k]) {
            k++;
        }
        lcp[suff_ind[i]] = k;
        if (k > 0) k--;
    }
    //Pegar o maior LCP
    int max_lcp = 0;
    int max_pos = -1;
    
    for (int i = 0; i < n; i++) {
        if (lcp[i] > max_lcp) {
            max_lcp = lcp[i];
            max_pos = i;
        }
    }
    
    if (max_lcp == 0) {
        cout << "0" << endl; // sem repetição
    } else {
        // começa em sa[max_pos]
        string result = str.substr(sa[max_pos], max_lcp);
        cout << result.size() << endl;
    }
    
    return 0;
}
