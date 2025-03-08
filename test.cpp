#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// #include "testlib.h"
#include "graph.h"
#define int long long
#define nl "\n"
// Function to generate random graph 

// std::string balanced_bracket_sequence_v1(int n) {
//     auto res = std::string(n, '(') + std::string(n + 1, ')');
//     shuffle(res.begin(), res.end());
//     std::vector<int> pref(2 * n + 2, 0);
//     for (int x = 0; x < 2 * n + 1; x++)
//         pref[x + 1] = pref[x] + (res[x] == '(' ? 1 : -1);
//     int idx =
//         int(std::min_element(pref.begin(), pref.end()) - pref.begin());
//     std::rotate(res.begin(), res.begin() + idx, res.end());
//     return res.substr(0, 2 * n);
// }

// std::string balanced_bracket_sequence_v2(int n) {
//     auto a = std::string(n, '(') + std::string(n, ')');
//     shuffle(a.begin(), a.end());
//     auto output = a;
//     for (int l_in = 0, l_out = 0, r_in = 2 * n; l_in < r_in;) {
//         int pos = l_in;
//         int balance = 0;
//         for (; pos != r_in; ++pos)
//             if ((balance += (a[pos] == '(' ? +1 : -1)) == 0) break;
//         if (a[l_in] == '(') {
//             for (; l_in <= pos; ++l_in, ++l_out) output[l_out] = a[l_in];
//         } else {
//             const int sz_u = r_in - pos - 1, r_out = l_out + sz_u + 1;
//             output[l_out] = '(', output[r_out] = ')';
//             for (int i = l_in + 1, j = r_out + 1; i != pos; ++i, ++j)
//                 output[j] = (a[i] == '(' ? ')' : '(');
//             l_in = pos + 1;
//             l_out++;
//         }
//     }
//     return output;
// }

// std::string balanced_bracket_sequence_v3(int n) {
//     long long a = 0, b = 0;
//     std::string res;
//     for (int x = 0; x < 2 * n; x++) {
//         if (rnd.next((2 * n - a - b) * (a - b + 1)) <
//             (n - a) * (a - b + 2)) {
//             res += '(';
//             a++;
//         } else {
//             res += ')';
//             b++;
//         }
//     }
//     return res;
// }

// struct tree {
//     int node;
//     tree *l, *r;
//     tree(int node_, tree* l_, tree* r_) : node{node_}, l{l_}, r{r_} {}
// };

// int get_value(tree* t) {
//     if (t) return t->node;
//     return -1;
// }

// using representation_t = std::vector<std::tuple<int, int, char>>;

// auto representation(tree* t) {
//     representation_t repr;
//     auto dfs = [&repr](auto self, tree* a) -> void {
//         if (!a) return;
//         repr.emplace_back(a->node, get_value(a->l), 'L');
//         repr.emplace_back(a->node, get_value(a->r), 'R');
//         self(self, a->l);
//         self(self, a->r);
//     };
//     dfs(dfs, t);
//     return repr;
// }

// auto shuffled_representation(int n, representation_t r) {
//     std::vector<int> p(n);
//     std::iota(p.begin(), p.end(), 0);
//     shuffle(p.begin(), p.end());  // shuffle vertex labels
//     for (auto& [n1, n2, dir] : r) {
//         if (n1 != -1) n1 = p[n1];
//         if (n2 != -1) n2 = p[n2];
//     }
//     shuffle(r.begin(), r.end());  // shuffle edge order
//     return r;
// }

// tree* binary_tree_from_balanced_bracket_sequence(const std::string& s) {
//     int n = int(s.size()) / 2;
//     std::vector<int> nxt(2 * n, -1);
//     std::vector<int> stk;
//     for (int x = 0; x < 2 * n; x++) {
//         if (s[x] == '(') {
//             stk.push_back(x);
//         } else {
//             nxt[stk.back()] = x;
//             stk.pop_back();
//         }
//     }
//     int node = 0;
//     std::vector<tree*> roots(2 * n, nullptr);
//     for (int x = 2 * n - 1; x >= 0; x--) {
//         if (s[x] == '(') {
//             tree *left = nullptr, *right = nullptr;
//             if (s[x + 1] == '(') left = roots[x + 1];        // left child
//             if (nxt[x] + 1 < 2 * n && s[nxt[x] + 1] == '(')  // right child
//                 right = roots[nxt[x] + 1];
//             roots[x] = new tree(node++, left, right);
//         }
//     }
//     return roots[0];
// }
// int getNum(vector<int>& v)
// {
 
//     // Size of the vector
//     int n = v.size();
 
//     // Generate a random number
 
//     // Make sure the number is within
//     // the index range
//     int index = rnd.next(1,1000000000) % n;
 
//     // Get random number from the vector
//     int num = v[index];
 
//     // Remove the number from the vector
//     swap(v[index], v[n - 1]);
//     v.pop_back();
 
//     // Return the removed number
//     return num;
// }
 
// // Function to generate n non-repeating random numbers
// void generateRandom(int n)
// {
//     vector<int> v(n);
 
//     // Fill the vector with the values
//     // 1, 2, 3, ..., n
//     for (int i = 0; i < n; i++)
//         v[i] = i + 1;
 
//     // While vector has elements
//     // get a random number from the vector and print it
//     while (v.size()) {
//         cout << getNum(v) << " ";
//     }
// }
mt19937 mt(time(nullptr));  
int getval(int a, int b) {
    return mt()%(b-a+1)+a;
}

string gen(int len) {
    string s = "";
    for (int i = 0; i < len; i++) {
        s += (getval(0,1) == 0 ? '0' : '1');
    }
    return s;
}

int runcases(int qq)
{   

    int n,k;
    cin >> n >> k;
    vector<vector<int>> v;
    v.push_back({k});
    for (int i = 1; i < n; i++) {
        vector<int> temp = {k};
        for (int j = 1; j < i; j++) {

            temp.push_back(v.back()[j-1]%v.back()[j]);
        }
        temp.push_back(k);
    }
    for (int i = 0; i < n; i++) {
        cout << v[n-1][i] << " ";
    }
    cout << nl;
    return 0;
}
 
signed main()
{
    
    //..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    //..........................//


 
    // registerGen(argc, argv, 1);
    int t ;
 
    cin >> t;

    // cout << t << endl;

    
    // sieve();
    
 
    // cout << t << nl;
    for (int32_t i = 1; i <= t; i ++) {
        runcases(i);
    }
    
    return 0;
 
}