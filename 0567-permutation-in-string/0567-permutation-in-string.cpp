class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if (s1.length() > s2.length())
            return false;

        vector<int> count1(26, 0);
        vector<int> count2(26, 0);

        // Frequency of s1
        for (char ch : s1)
            count1[ch - 'a']++;

        int k = s1.length();

        // First window
        for (int i = 0; i < k; i++)
            count2[s2[i] - 'a']++;

        if (count1 == count2)
            return true;

        // Sliding window
        for (int i = k; i < s2.length(); i++) {

            count2[s2[i] - 'a']++;          // Add new character
            count2[s2[i - k] - 'a']--;      // Remove old character

            if (count1 == count2)
                return true;
        }

        return false;
    }
};