


void build(vector<int>a, int node, int st, int en, vector<int> &segtree)
{
    if (st == en) {
        segtree[node] = a[st];
        return;
    }

    int mid = (st + en)/2;
    build(a,2*node, st,mid,segtree);
    build(a,2*node+1, mid+1, en,segtree);

    segtree[node] = segtree[2*node] + segtree[2*node + 1];

}

int sumquery(int node, int st, int en, int l, int r, vector<int> segtree)
{
    if (l > r) {
        return 0;
    }

    if (st == l && en == r) {
        return segtree[node];
    }

    int mid = (st + en)/2;

    return sumquery(2*node,st,mid,l,min(r,mid),segtree) + sumquery(2*node + 1, mid+1,en,  max(l,mid+1), r,segtree);
}

void update(int node, int st, int en, int pos, int new_val, vector<int> &segtree)
{
    if (st == en) {
        segtree[node] = new_val;
    }

    else {
        int mid = (st + en)/2;
        if (pos <= mid) {
            update(2*node, st,mid, pos, new_val, segtree);
        }

        else {
            update(2*node+1, mid + 1, en, pos, new_val, segtree);
        }
        segtree[node] = segtree[2*node] + segtree[2*node+1];
    }
}

