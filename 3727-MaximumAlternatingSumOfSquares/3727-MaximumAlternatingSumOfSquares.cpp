// Last updated: 10/19/2026, 12:51:00 PM
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        
        // Convert all elements to their squares
        for (int i = 0; i < n; ++i) {
            nums[i] = (long long)nums[i] * nums[i]; 
        }
        
        // Sort the squares in ascending order
        sort(nums.begin(), nums.end());
        
        long long max_score = 0;
        int minus_slots = n / 2;
        
        // Subtract the smaller half of the squares
        for (int i = 0; i < minus_slots; ++i) {
            max_score -= nums[i];
        }
        
        // Add the larger half of the squares
        for (int i = minus_slots; i < n; ++i) {
            max_score += nums[i];
        }
        
        return max_score;
    }
};
