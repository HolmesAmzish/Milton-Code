/**
 * @problem: Length of last word
 * @date: 2024-08-27
 * @author: cacciatore
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.length() - 1;
        int wordLength = 0;
        while (s[index] == ' ') index--;
        while (s[index] != ' ' && index >= 0) {
            wordLength++;
            index--;
        }
        return wordLength;
    }
};