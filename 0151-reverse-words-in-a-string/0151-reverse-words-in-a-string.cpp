class Solution {
public:
    string reverseWords(string s) {

        stringstream ss(s);      // Split string into words
        string word;
        vector<string> words;

        // Store all words in a vector
        while (ss >> word) {
            words.push_back(word);
        }

        // Reverse the order of words
        reverse(words.begin(), words.end());

        string ans = "";

        // Join the reversed words with a single space
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];

            // Don't add a space after the last word
            if (i != words.size() - 1) {
                ans += " ";
            }
        }

        return ans;
    }
};