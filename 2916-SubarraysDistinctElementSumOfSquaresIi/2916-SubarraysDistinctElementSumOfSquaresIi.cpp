// Last updated: 10/19/2026, 12:51:30 PM
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int n;
    long long MOD = 1e9 + 7;
    vector<long long> treeSum;
    vector<long long> treeSqSum;
    vector<long long> lazy;

    void propagate(int node, int start, int end) {
        if (lazy[node] == 0) return;
        
        long long val = lazy[node];
        lazy[node] = 0; // Clear early to avoid re-propagation issues
        
        int mid = start + (end - start) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        // Propagate to left child
        long long lenL = mid - start + 1;
        treeSqSum[leftChild] = (treeSqSum[leftChild] + 2 * val % MOD * treeSum[leftChild] % MOD + val * val % MOD * lenL) % MOD;
        treeSum[leftChild] = (treeSum[leftChild] + val * lenL) % MOD;
        lazy[leftChild] = (lazy[leftChild] + val) % MOD;

        // Propagate to right child
        long long lenR = end - mid;
        treeSqSum[rightChild] = (treeSqSum[rightChild] + 2 * val % MOD * treeSum[rightChild] % MOD + val * val % MOD * lenR) % MOD;
        treeSum[rightChild] = (treeSum[rightChild] + val * lenR) % MOD;
        lazy[rightChild] = (lazy[rightChild] + val) % MOD;
    }

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        
        if (l <= start && end <= r) {
            long long len = end - start + 1;
            treeSqSum[node] = (treeSqSum[node] + 2 * val % MOD * treeSum[node] % MOD + val * val % MOD * len) % MOD;
            treeSum[node] = (treeSum[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }

        propagate(node, start, end);
        int mid = start + (end - start) / 2;
        updateRange(2 * node + 1, start, mid, l, r, val);
        updateRange(2 * node + 2, mid + 1, end, l, r, val);

        treeSum[node] = (treeSum[2 * node + 1] + treeSum[2 * node + 2]) % MOD;
        treeSqSum[node] = (treeSqSum[2 * node + 1] + treeSqSum[2 * node + 2]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        treeSum.assign(4 * n, 0);
        treeSqSum.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        
        unordered_map<int, int> lastSeen;
        long long totalSumOfSquares = 0;

        for (int r = 0; r < n; ++r) {
            // Pick starting index bound. If element was seen before, update range [lastSeen + 1, r]
            int l = lastSeen.count(nums[r]) ? lastSeen[nums[r]] + 1 : 0;
            
            // Add 1 to distinct element tracking for all valid subsegment points
            updateRange(0, 0, n - 1, l, r, 1);
            
            // Cumulative aggregate count from the root of the tree
            totalSumOfSquares = (totalSumOfSquares + treeSqSum[0]) % MOD;
            
            lastSeen[nums[r]] = r;
        }

        return totalSumOfSquares;
    }
};
