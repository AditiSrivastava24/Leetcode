// Last updated: 7/30/2026, 9:13:12 PM
class Solution {
public:
    // Returns C(n, r), capped at limit + 1.
    long long combination(int n, int r, long long limit) {
        r = min(r, n - r);
        long long result = 1;

        for (int i = 1; i <= r; i++) {
            __int128 next = (__int128)result * (n - r + i) / i;

            if (next > limit)
                return limit + 1;

            result = (long long)next;
        }

        return result;
    }

    // Number of distinct permutations of the given multiset,
    // capped at limit + 1.
    long long countPermutations(const vector<int>& freq, long long limit) {
        long long ways = 1;
        int used = 0;

        for (int count : freq) {
            if (count == 0)
                continue;

            long long choose = combination(used + count, count, limit);

            __int128 next = (__int128)ways * choose;

            if (next > limit)
                return limit + 1;

            ways = (long long)next;
            used += count;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> freq(26, 0);

        for (char ch : s)
            freq[ch - 'a']++;

        // Required variable mentioned in the problem.
        auto prelunthak = make_pair(s, k);

        char middle = '\0';

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1)
                middle = char('a' + i);

            freq[i] /= 2;
        }

        int halfLength = s.size() / 2;

        // Check whether the k-th permutation exists.
        if (countPermutations(freq, k) < k)
            return "";

        string leftHalf;

        for (int position = 0; position < halfLength; position++) {
            for (int ch = 0; ch < 26; ch++) {
                if (freq[ch] == 0)
                    continue;

                // Try placing this character at the current position.
                freq[ch]--;

                long long permutations = countPermutations(freq, k);

                if (k > permutations) {
                    // Skip all permutations beginning with this character.
                    k -= permutations;
                    freq[ch]++;
                } else {
                    leftHalf.push_back(char('a' + ch));
                    break;
                }
            }
        }

        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());

        if (middle != '\0')
            return leftHalf + middle + rightHalf;

        return leftHalf + rightHalf;
    }
};