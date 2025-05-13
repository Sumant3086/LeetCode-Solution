// 3335. Total Characters in String After Transformations I
// Solved
// Medium
// Topics
// Companies
// Hint
// You are given a string s and an integer t, representing the number of transformations to perform. In one transformation, every character in s is replaced according to the following rules:

// If the character is 'z', replace it with the string "ab".
// Otherwise, replace it with the next character in the alphabet. For example, 'a' is replaced with 'b', 'b' is replaced with 'c', and so on.
// Return the length of the resulting string after exactly t transformations.

// Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: s = "abcyy", t = 2

// Output: 7

// Explanation:

// First Transformation (t = 1):
// 'a' becomes 'b'
// 'b' becomes 'c'
// 'c' becomes 'd'
// 'y' becomes 'z'
// 'y' becomes 'z'
// String after the first transformation: "bcdzz"
// Second Transformation (t = 2):
// 'b' becomes 'c'
// 'c' becomes 'd'
// 'd' becomes 'e'
// 'z' becomes "ab"
// 'z' becomes "ab"
// String after the second transformation: "cdeabab"
// Final Length of the string: The string is "cdeabab", which has 7 characters.
// Example 2:

// Input: s = "azbk", t = 1

// Output: 5

// Explanation:

// First Transformation (t = 1):
// 'a' becomes 'b'
// 'z' becomes "ab"
// 'b' becomes 'c'
// 'k' becomes 'l'
// String after the first transformation: "babcl"
// Final Length of the string: The string is "babcl", which has 5 characters.
 

// Constraints:

// 1 <= s.length <= 105
// s consists only of lowercase English letters.
// 1 <= t <= 105

// Seen this question in a real interview before?
// 1/5
// Yes
// No
// Accepted
// 34.2K
// Submissions
// 95.5K
// Acceptance Rate
// 35.8%
// Topics
// Companies
// Hint 1
// Discussion (63)

// Choose a type



// Copyright ©️ 2025 LeetCode All rights reserved


using namespace std;

class Solution {
public:
    static constexpr int MOD = 1000000007;

    int lengthAfterTransformations(const string& s, int t) {
        vector<int> arr(26, 0);
        for (char c : s) {
            arr[c - 'a']++;
        }

        while (t-- > 0) {
            vector<int> temp(26, 0);
            for (int j = 0; j < 25; ++j) {
                temp[j + 1] = arr[j];
            }
            temp[0] = (temp[0] + arr[25]) % MOD;
            temp[1] = (temp[1] + arr[25]) % MOD;
            arr = move(temp);
        }

        int res = 0;
        for (int num : arr) {
            res = (res + num) % MOD;
        }

        return res;
    }
};