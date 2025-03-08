#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector<int> p;
    vector<int> size;
    DSU(int n) { 
        p = vector<int>(n);
        for (int i = 0 ; i < n; i++) {
            p[i] = i;
        }
        size = vector<int>(n);
        for (int i = 0; i < n; i++) {
            size[i] = 1;
        }
    }
 
    int get(int x) {
        if (p[x] == x) {
            return p[x];
        }
        p[x] = get(p[x]);
        return p[x];
    }
 
    bool unite(int a, int b) {
        int pa = get(a), pb = get(b);
        if (pa == pb) return false;
        if (size[pa] < size[pb]) swap(pa,pb);
        p[pb] = pa;
        size[pa] = max(size[pa], size[pb]+1);
        return true;
    }
};

class dsuClass {
    public:
 
    int n;
    vector<int> parent;
    vector<int> size;
    
    int sccCount;
    
    void init(int n) {
        this->n = n;
        parent.resize(n);
        size.resize(n);
        reset();
    }
    
    void reset() {
        sccCount = n;
        FOR (i, 0, n) parent[i] = i;
        FOR (i, 0, n) size[i] = 1;
    }
    
    int update(int a) {
        if (parent[a] == a) return a;
        return parent[a] = update(parent[a]);
    }
    
    void join(int a, int b) {
        a = update(a);
        b = update(b);
        if (size[b] > size[a]) swap(a, b);
        if (a == b) return;
        
        size[a] += size[b];
 
        parent[b] = a;
        sccCount--;
    }
    
    bool isMaster(int v) {
        return parent[v] == v;
    }
 
    void updateAll() {
        FOR (i, 0, n) update(i);
    }
};

int main() {
    set<int> s;
    map<int,set<int>::iterator> pos;

    auto it = s.insert(5);

    pos[5] = it.first;

    auto it1 = s.insert(4);
    // pos[] = it1.first;

    cout << *(pos[5]) << endl;

}