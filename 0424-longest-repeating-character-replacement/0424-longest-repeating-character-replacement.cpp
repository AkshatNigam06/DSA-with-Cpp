class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int low = 0;
        int maxFreq = 0;
        int ans = 0;

        for (int high = 0; high < s.size(); high++) {

            freq[s[high] - 'A']++;

            maxFreq = max(maxFreq, freq[s[high] - 'A']);

            // characters that need replacement
            int changes = (high - low + 1) - maxFreq;

            while (changes > k) {
                freq[s[low] - 'A']--;
                low++;

                changes = (high - low + 1) - maxFreq;
            }

            ans = max(ans, high - low + 1);
        }

        return ans;
    }
};