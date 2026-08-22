class Solution {
public:
    int minSubArrayLen(int target, vector<int>& a) {

        int n = a.size();
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += a[right];

            while (sum >= target) {
                minLen = min(minLen, right - left + 1);
                sum -= a[left];
                left++;
            }
        }

        if (minLen == INT_MAX)
            return 0;

        return minLen;
    };
};
