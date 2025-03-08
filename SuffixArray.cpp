template<typename T>
class SuffixArray {
public:
    T s;
    int n;
    vector<int> p,c;
    SuffixArray(T s_) {
        s = s_;
        n = s.size();
        p = vector<int>(n,0);
        c = vector<int>(n,0);
    }
    void count_sort() {
        vector<int> cnt(11);
        for (auto x : c) {
            cnt[x]++;
        }
        vector<int> p_new(n);
        vector<int> pos(n);
        pos[0] = 0;
        for (int i = 1; i < n; i++) {
            pos[i] = pos[i-1]+cnt[i-1];
        }
        for (auto x : p) {
            int i = c[x];
            p_new[pos[i]] = x;
            pos[i]++;
        }
        p = p_new;
    }
    vector<int> getSuffixArray() {
        vector<pair<char,int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {s[i],i};
        }
        sort(a.begin(),a.end());
        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
            if (i > 0) {
                if (a[i].first == a[i-1].first) {
                    c[p[i]] = c[p[i-1]];
                }
                else {
                    c[p[i]] = c[p[i-1]]+1;
                }
            }
            else {
                c[p[i]] = 0;
            }
        }

        int k = 0;
        while ((1<<k) < n) {
            for (int i = 0; i < n; i++) {
                p[i] = (p[i]-(1<<k)+n)%n;
            }
            count_sort();
            vector<int> c_new(n);
            c_new[p[0]] = 0;
            for (int i = 1; i < n; i++) {
                pair<int,int> prev = {c[p[i-1]],c[(p[i-1]+(1<<k))%n]};
                pair<int,int> curr = {c[p[i]],c[(p[i]+(1<<k))%n]};
                if (curr == prev) {
                    c_new[p[i]] = c_new[p[i-1]];
                }
                else {
                    c_new[p[i]] = c_new[p[i-1]]+1;
                }
            }
            k++;
            c = c_new;
        }
        return p;
    };

    vector<int> getLcp() {
        int k = 0;
        vector<int> lcp(n);
        for (int i = 0; i < n-1; i++) {
            int pi = c[i];
            int j = p[pi-1];
            // lcp[i] = lcp(s[i..], s[j..])
            while (s[i+k] == s[j+k]) k++;
            lcp[pi] = k;
            k = max(k-1,int(0));
        }
        return lcp;
    };

};