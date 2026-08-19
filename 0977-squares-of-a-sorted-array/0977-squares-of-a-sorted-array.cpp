class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> neg;
        vector<int> pos;
        
        int n = nums.size();

        // Separate negative and positive numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                neg.push_back(nums[i]);
            else
                pos.push_back(nums[i]);
        }

        // Only positive numbers
        if (neg.size() == 0) {
            for (int i = 0; i < pos.size(); i++) {
                pos[i] = pos[i] * pos[i];
            }
            return pos;
        }

        // Only negative numbers
        if (pos.size() == 0) {
            for (int i = 0; i < neg.size(); i++) {
                neg[i] = neg[i] * neg[i];
            }

            reverse(neg.begin(), neg.end());
            return neg;
        }

        // Square negative numbers
        for (int i = 0; i < neg.size(); i++) {
            neg[i] = neg[i] * neg[i];
        }

        // Reverse negative squares
        reverse(neg.begin(), neg.end());

        // Square positive numbers
        for (int i = 0; i < pos.size(); i++) {
            pos[i] = pos[i] * pos[i];
        }

        // Merge two sorted arrays
        vector<int> ans;
        
        int i = 0;
        int j = 0;

        while (i < neg.size() && j < pos.size()) {
            if (neg[i] < pos[j]) {
                ans.push_back(neg[i]);
                i++;
            }
            else {
                ans.push_back(pos[j]);
                j++;
            }
        }

        while (i < neg.size()) {
            ans.push_back(neg[i]);
            i++;
        }

        while (j < pos.size()) {
            ans.push_back(pos[j]);
            j++;
        }

        return ans;
    }
};