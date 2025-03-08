class xor_basis {
public:

    // Implementation idea : neal_wu

    int size;
    int curr = 0;
    int basis[BITS];


    bool add(int x) {
        if (curr == 20) {
            return false;
        }
        for (int i = 0; i < curr; i++) {
            int b = basis[i];
            x = min(x,b^x);
        }
        if (x == 0) {
            return false;
        }

        // We are using insertion sort to maintain a list
        // of values sorted in decreasing order, where each
        // value has a unique highest bit.
        basis[curr++] = x;
        int k = curr-1;
        while (k > 0 && basis[k] > basis[k-1]) {
            swap(basis[k],basis[k-1]);
            k--;
        }

        return true;
    }

    void merge(const xor_basis &other) {
        for (int i = 0; i < other.curr; i++) {
            add(other.basis[i]);
        }
    }

    void merge(const xor_basis &a,const xor_basis &b) {
        if (a.curr > b.curr) {
            *this = a;
            merge(b);
        }
        else {
            *this = b;
            merge(a);
        }
    }

    void debug_() {
        for (int i = 0; i < curr; i++) {
            cerr << basis[i] << " ";
        }
        cerr << nl;
    }
    


};