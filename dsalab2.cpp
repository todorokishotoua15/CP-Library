#include<bits/stdc++.h>
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#define rep(i,a,b) for(int i = a; i < b; i ++)
#define ill long long int
#define ll long long
#define nl "\n"
#define el endl
#define pb push_back
using namespace std;
const ll N = 1e3 + 2;
const ll neg_inf = -2e7 + 2;
const ll inf = 1e17 + 2;
const int mod = 1e9 + 7;
const int MOD = 1e9 + 7;


    

int runcases(int i)
{
  
  
  string s; // taking input as string
  cin >> s;
  
  int ans = 0; // initializing answer variable

  // Approach : Use two stacks and loop through the string
  // if '{' found, put it in first stack and if '}' found
  // and first stack is not empty then pop first stack. 
  // If '}' found and stack 1 is empty then invert it to '{' 
  // (adding 1 to number of operation) and add it to stack 1
  // Time complexity : O(n)
  // Space complexity : O(n) (since we are putting all elements either in first or second stack)


  stack<char> s1;
  stack<char> s2;

  for (auto ch : s) {
    if (ch=='{') {
        if (!s2.empty()) {
            s2.pop();
        }
        else {
          s1.push(ch);
        }
      }
    else {
      if (!s1.empty()) {
        s1.pop();
      }
      else {
        s1.push('{');
        ans++;
      }
    }
  }
  
  // Now whatever remains after iteration and popping, increment
  // ans by that size divided by two. i.e, if {{{{ remains, ans
  // will be ans = ans + 4/2
  
  if (!s1.empty()) ans += (s1.size())/2;
  if (!s2.empty()) ans += (s2.size())/2;

  
  else cout  <<  ans<< nl;
  
  
  
  return 0;

}
 
int main()
{
  //..........Fast I/O.........//
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);
  // ..........................//
  
  int t = 1;
  
  
  
  for (int i = 1; i <= t; i ++) {
    runcases(i);
  }
 
  return 0;
 
}