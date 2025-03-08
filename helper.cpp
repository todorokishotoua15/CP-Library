#include<bits/stdc++.h>
using namespace std;

// custom hash
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x = (x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// ordered set
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
>
ordered_set;

// number to binary string
void bin(long long x, string &s) {
    if (x > 1) bin(x/2,s);
    int y = x%2;
    //cout << y;
    s += (y+'0');
    //cout << s << nl;
}
// extend the binary string to n bit
void extbin(string &s, int n) {

	reverse(s.begin(), s.end());
	while (s.size() < n) s += '0';
	reverse(s.begin(), s.end());

}
bool isPrime(int n)
{
      // Since 0 and 1 is not 
      // prime return false.
      if(n == 1 || n == 0) return false;
   
      // Run a loop from 2 to n-1
      for(int i = 2; i < n; i++)
      {
        // if the number is divisible by i, 
        // then n is not a prime number.
        if(n % i == 0) return false;
      }
      // Otherwise n is a prime number.
      return true;
}
 
// prime factors of a given number
void factor(int n, vector<int> &fac) {
    
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            fac.push_back(i);
            n /= i;
        }
    }
    if (n > 1) fac.push_back(n);
    
}

//..........Fast I/O.........//
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
// ..........................//





// Euler Totient function for all x smaller than aur equal to n
ll phi[MAXN];

void phi_1_to_n(int n) {
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}

long long int_sqrt (long long x) {
  long long ans = 0;
  for (ll k = 1LL << 30; k != 0; k /= 2) {
    if ((ans + k) * (ans + k) <= x) {
      ans += k;
    }
  }
  return ans;
}

template<typename T>
vector<T> extended_gcd(T a, T b) {
    vector<T> ans;

    T r0 = a, r1 = b;
    T s0 = 1, s1 = 0;
    T t0 = 0, t1 = 1;

    while (r1 != 0) {
        T r2 = r0%r1;
        T q = r0/r1;
        T s_temp = s0 - s1*q;
        T t_temp = t0 - t1*q;
        s0 = s1;
        s1 = s_temp;
        t0 = t1;
        t1 = t_temp;
        r0 = r1;
        r1 = r2;
    }

    ans = {r0, s0, t0};

    return ans;
}

// diameter
pair<int,int> lgst = {0,-1}; 
function<void(int,int,int)> lg = [&] (int node, int p, int lv) {
    if (lv > lgst.second) {
        lgst = {node,lv};
    }
    for (auto x : adj[node]) {
        if (x != p) {
            lg(x,node,lv+1);
        }
    }
};

auto diam = [&] () -> pair<int,int>{
    lg(1,-1,0);
    pair<int,int> ans = {lgst.first,0};
    lgst = {0,-1};
    lg(ans.first, -1, 0);
    ans.second = lgst.first;
    return ans;
};
