/** A data structure that can answer point update & range minimum queries. */
template <class T> class MinSegmentTree {
  private:
    const T DEFAULT = std::numeric_limits<T>().max();

    vector<T> segtree;
    int len;

  public:
    MinSegmentTree(int len) : len(len), segtree(len * 2, DEFAULT) {}

    /** Sets the value at ind to val. */
    void set(int ind, T val) {
        ind += len;
        segtree[ind] = val;
        for (; ind > 1; ind /= 2) {
            segtree[ind / 2] = std::min(segtree[ind], segtree[ind ^ 1]);
        }
    }

    /** @return the minimum element in the range [start, end) */
    T range_min(int start, int end) {
        T min = DEFAULT;
        for (start += len, end += len; start < end; start /= 2, end /= 2) {
            if (start % 2 == 1) { min = std::min(min, segtree[start++]); }
            if (end % 2 == 1) { min = std::min(min, segtree[--end]); }
        }
        return min;
    }
};

struct dat {
    long long sm = 0; 
    long long mn = LLONG_MAX;
    long long mx = LLONG_MIN;
    long long lazysm = 0;
    dat() {};
};
struct seg_tree {
    vector<dat> st;
    int n;
    void init(int sz) {
        st.resize(4*sz);
        n = sz;
    }
    void merge (dat &d1, dat &d2) {
        d1.mn = min(d1.mn,d2.mn);
        d1.mx = max(d1.mx,d2.mx);
        d1.sm += d2.sm;
        d1.lazysm += d2.lazysm;
    }

    void push (int node, int l, int r) {
        if (st[node].lazysm != 0) {
            int mid = (l+r)/2;
            long long lenr = (r-(mid+1)+1);
            long long lenl = (mid-l+1);
            // int change = st[2*node].sm - st[node].lazysm;
            if (st[2*node].mn == LLONG_MAX) st[2*node].mn = st[node].lazysm;
            else st[2*node].mn += st[node].lazysm;;

            if (st[2*node].mx == LLONG_MIN) st[2*node].mx = st[node].lazysm;
            else st[2*node].mx += st[node].lazysm;;

            st[2*node].sm += (st[node].lazysm)*lenl;
            st[2*node].lazysm += st[node].lazysm;

            if (st[2*node+1].mn == LLONG_MAX) st[2*node+1].mn = st[node].lazysm;
            else st[2*node+1].mn += st[node].lazysm;;

            if (st[2*node+1].mx == LLONG_MIN) st[2*node+1].mx = st[node].lazysm;
            else st[2*node+1].mx += st[node].lazysm;;

            st[2*node+1].sm += (st[node].lazysm)*lenr;;
            st[2*node+1].lazysm += st[node].lazysm;

            st[node].lazysm = 0;
        }
    }

    void update(int node, int l, int r, int i, int j, long long val) {
        if (i > j || l > r) return;
        if (l == i && r == j) {
            // debug(l,r);
            long long len = (r-l+1);
            st[node].sm += len*(val);
            st[node].lazysm += (val);
            if (st[node].mn == LLONG_MAX) {
                st[node].mn = val;
            }
            else st[node].mn += val;

            if (st[node].mx == LLONG_MIN) {
                st[node].mx = val;
            }
            else st[node].mx += val;
            // debug(st[node].sm,st[node].mn);
            return;
        }
        // debug(l,r);
        int mid = (l+r)/2;
        
        push(node,l,r);
        update(2*node, l, mid, i, min(mid,j),val);
        update(2*node+1,mid+1,r,max(mid+1,i),j,val);

        st[node].sm = st[2*node].sm+st[2*node+1].sm;
        st[node].mn = min(st[2*node].mn,st[2*node+1].mn);
        st[node].mx = max(st[2*node].mx,st[2*node+1].mx);
    }

    void update_single (int node, int l, int r, int i, int val) {

        if (l == r) {
            // debug(l,r);
            int len = (r-l+1);
            st[node].sm = val;
            st[node].lazysm = 0;
            st[node].mn = val;
            st[node].mx = val;
            // debug(st[node].sm,st[node].mn);
            return;
        }
        // debug(l,r);
        int mid = (l+r)/2;
        
        push(node,l,r);
        if (i <= mid) {
            update_single(2*node, l, mid, i,val);
        }
        else {
            update_single(2*node+1,mid+1,r,i,val);
        }

        st[node].sm = st[2*node].sm+st[2*node+1].sm;
        st[node].mn = min(st[2*node].mn,st[2*node+1].mn);
        st[node].mx = max(st[2*node].mx,st[2*node+1].mx);
    };

    void set (int l, int r, int val) {
        update(1,0,n-1,l,r,val);
    }
    void set (int idx, int val) {
        update(1,0,n-1,idx,idx,val);
    }
    void set_single(int idx, int val) {
        update_single(1,0,n-1,idx,val);
    }

    long long mi = LLONG_MAX, sm = 0, mx = LLONG_MIN;
    void qry(int node, int l, int r, int i, int j) {
        if (i > j || l > r) return;
        // debug(l,r,mi);
        if (l == i && r == j) {
            // debug(l,r,st[node].sm,st[node].mn);
            mi = min(mi,st[node].mn);
            mx = max(mx,st[node].mx);
            // debug(mi);
            sm += st[node].sm;
            return;
        }
        int mid = (l+r)/2;
        push(node,l,r);

        qry(2*node, l, mid, i, min(mid,j));
        qry(2*node+1,mid+1,r,max(mid+1,i),j);
    }

    void query(int l, int r) {
        mi = LLONG_MAX, sm = 0, mx = LLONG_MIN;
        qry(1,0,n-1,l,r);
    }

    int leff = -1;
    void qry2(int node, int l, int r, int ind) {
        //stopping conditions = 1. answer found, 
        // 2. segment lies outside of search range
        // max is < 0
        if (leff != -1) return;
        if (l > ind) return;
        if (st[node].mx < 0) return;
        if (l == r) {
            leff = l;
            return;
        }
        int mid = (l+r)/2;
        push(node,l,r);
        qry2(2*node,l,mid,ind);
        qry2(2*node+1,mid+1,r,ind);
    };

    int get_ans(int ind) {
        leff = -1;
        qry2(1,0,n-1,ind);
        return leff;
    }
};