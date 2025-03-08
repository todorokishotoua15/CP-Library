#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
 
#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define nl "\n"
#define el endl
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
 
const ll N = 2e5 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e17 + 2;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;
 
 
typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update
>
ordered_set;

string turn_clock(string s) {
    // 8 possible ways to reach next state;

    // {top - 1,2,3,4,} shift clockwise
    string s1 = "";
    for (int i = 1; i < 5; i++) {
        s1 += s[i%4];
    }

    // front 1,2 will become right 1,2
    s1 += s[16];
    s1 += s[17];
    s1 += s[6];
    s1 += s[7];

    // bottom will remain same
    s1 += s[8] + s[9] + s[10] + s[11];

    // back 1,2 will become left 1,2
    s1 += s[20] + s[21];
    s1 += s[14] + s[15];

    // left 1,2 will become front 1,2
    s1 += s[12] + s[13];
    s1 += s[18] + s[19];

    //  right 1,2 will become back 1,2
    s1 += s[4] + s[5];
    s1 += s[22] + s[23];

    // 

}
 
int main()
{
    // 0-3-top
    // 4-7-right
    // 8-11-bottom
    // 12-15-left
    // 16-19-front
    // 20-23-back

    // Numbering:
    //  _ _
    // |0|1| 
    // |2|3|

    string s;  // current state of cube, looked from top, then right, then bottom, then left, then front, then back

    cin >> s;





}