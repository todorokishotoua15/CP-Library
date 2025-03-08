void __print32_t(int32_t x) {cerr << x;}
void __print32_t(long x) {cerr << x;}
void __print32_t(long long x) {cerr << x;}
void __print32_t(unsigned x) {cerr << x;}
void __print32_t(unsigned long x) {cerr << x;}
void __print32_t(unsigned long long x) {cerr << x;}
void __print32_t(float x) {cerr << x;}
void __print32_t(double x) {cerr << x;}
void __print32_t(long double x) {cerr << x;}
void __print32_t(char x) {cerr << '\'' << x << '\'';}
void __print32_t(const char *x) {cerr << '\"' << x << '\"';}
void __print32_t(const string &x) {cerr << '\"' << x << '\"';}
void __print32_t(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print32_t(const pair<T, V> &x) {cerr << '{'; __print32_t(x.first); cerr << ','; __print32_t(x.second); cerr << '}';}
template<typename T>
void __print32_t(const T &x) {int32_t f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print32_t(i); cerr << "}";}
void _print32_t() {cerr << "]\n";}
template <typename T, typename... V>
void _print32_t(T t, V... v) {__print32_t(t); if (sizeof...(v)) cerr << ", "; _print32_t(v...);}

#define debug(x...) cerr << "[" << #x << "] = ["; _print32_t(x)