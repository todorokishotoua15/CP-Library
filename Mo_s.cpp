int B;

struct Query {
    int l, r, idx;
    Query(int l_, int r_, int idx_) : l(l_),r(r_),idx(idx_){};
    Query(){}
    bool operator <(Query other) const {
        return (make_pair(l/B,r) < make_pair(other.l/B, other.r));
    }
};

struct RMQ_Mo {
    vector<int> v;
    vector<int> freq;
    int ans = 0;

    void init(vector<int> array) {
        v = array;
        for (int i = 0; i < N; i++) {
            freq.push_back(0);
        }
        ans = 0;
    }

    void remove(int idx) {
        ans -= freq[v[idx]]*freq[v[idx]]*v[idx];
        freq[v[idx]]--;
        ans += freq[v[idx]]*freq[v[idx]]*v[idx];
    }

    void add(int idx) {
        ans -= freq[v[idx]]*freq[v[idx]]*v[idx];
        freq[v[idx]]++;
        ans += freq[v[idx]]*freq[v[idx]]*v[idx];
    }

    int get_answer() {
        return ans;
    }

    vector<int> Mo_s_algorithm(vector<Query> queries) {
        vector<int> answers((int)queries.size(),0);
        sort(queries.begin(), queries.end());

        int l = 0;
        int r = -1;

        for (auto q : queries) {
            while (l > q.l) {
                l--;
                add(l);
            }
            while (r < q.r) {
                r++;
                add(r);
            }
            while (r > q.r) {
                remove(r);
                r--;
            }
            while (l < q.l) {
                remove(l);
                l++;
            }
            answers[q.idx] = get_answer();
        }
        return answers;
    }
};
