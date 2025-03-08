class psegtree {
public:
    struct node {
        node *l, *r;
        int64_t sum;

        node(int val) : l(nullptr), r(nullptr), sum(val) {};
        node(node *ll1, node *rr1) : l(ll1), r(rr1), sum(0) {
            if (l) sum += l->sum;
            if (r) sum += r->sum;
        }
        node(node *cp) : sum(cp->sum), l(cp->l), r(cp->r) {};
    };

    int n;
    vector<node*> roots;
    vector<int> v;
    int cnt = 0;
    void init(int sz) {
        roots = vector<node*>(sz);
        n = sz;
        cnt = 0;
    }
    void init(int sz, vector<int> arr) {
        roots = vector<node*>(sz);
        v = arr;
        n = sz;
        cnt = 0;
    }

    node* build (int l, int r) {
        if (l == r) {
            return new node(v[l]);
        }
        int mid = (l+r)/2;
        return new node(build(l,mid), build(mid+1,r));
    }

    node* update(node* nod, int val, int pos, int l, int r) {
        if (l == r) return new node(val);
        int mid = (l+r)/2;
        if (pos > mid) {
            return new node(nod->l, update(nod->r,val,pos,mid+1,r));
        }
        else return new node(update(nod->l,val,pos,l,mid),nod->r);
    }

    int64_t query(node *nod, int a, int b, int l, int r) {
        if (l > b || r < a) return 0;
        if (l >= a && r <= b) return nod->sum;
        int mid = (l+r)/2;
        return query(nod->l, a, b, l, mid) + query(nod->r, a, b, mid + 1, r);
    }

    void set_time_fixed(int pos, int val, int time) {
        roots[time] = update(roots[time], val, pos, 0, n-1);
    }

    void copy_time(int time) {
        int c = 0;
        roots[cnt++] = new node(roots[time]);
    }

    int64_t get (int a, int b, int time) {
        return query(roots[time], a, b, 0, n-1);
    }

};