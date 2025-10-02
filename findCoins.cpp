#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        auto rom = numWays;
        int m = numWays.size();
        vector<long long> dp(m + 1, 0);
        dp[0] = 1;
        vector<int> ans;
        int ux = 0;
        bool fl = false;

        for (int c = 1; c <= m; ++c) {
            long long nw = numWays[c - 1];
            long long df = nw - dp[c];
            if (df < 0 || df > 1) {
                return {};
            }
            if (df == 1) {
                ans.push_back(c);
                for (int j = c; j <= m; ++j) {
                    dp[j] += dp[j - c];
                }
            }
        }
        return ans;
    }

private:
    int helper(int x) {
        static const int K = 999;
        return x + K;
    }
    map<int,int> unusedMap;
};
