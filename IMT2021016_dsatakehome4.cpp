// Q25 - Minimum Size Subarray Sum

#include<bits/stdc++.h>
using namespace std;
#define nl "\n"

int main()
{
	int n, target;
	cin >> n >> target;

	vector<int> nums(n);

	for (auto &s : nums) cin >> s;
	int i = 0;  // pointer 1
    int j = 0;  // pointer 2

    int ans = 1e9; // initializing answer to infinity

    int sum = target;  // copying target to modify it

    int curr = 1; // size of window

    int currsum = nums[j]; // current sum
    while (j < nums.size()) {
        // valid condition to update answer
        if (currsum >= sum) {
            ans = min(ans,curr);
        }

        // moving j forward till we achieve desired target
        while (currsum < sum) {
            j++;
            if (j >= nums.size()) {
                cout << (ans == 1e9 ? 0 : ans);
                return 0;
            }
            curr++;
            currsum += nums[j];
            //cout << currsum << " " << i << " " << j << endl;
            if (currsum >= sum) {
                ans = min(ans,curr);
                break;
            }
        }

        // moving i forward till sum gets lesser than desired target
        while (currsum > sum) {
            i++;
            
            curr--;
            currsum -= nums[i-1];
            //cout << currsum << " " << i << " " << j << endl;
            if (currsum >= sum) {
                ans = min(ans,curr);
            }
            if (i == j) break;
        }
    j++;
    if (j >= nums.size()) {
        cout << (ans == 1e9? 0 : ans);
        return 0;
    }
    currsum += nums[j];
    curr++;
        
            
    }
    cout <<  (ans == 1e9 ? 0 : ans);
    return 0;		

}