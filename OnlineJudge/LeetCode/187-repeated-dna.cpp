/**
 * Problem: 187. Repeated DNA sequences
 * Date: 2024.06.09
 * Author: Nulla
 */

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> dna;
        vector<string> result;
        for (int i = 0; i < s.length(); i++) {
            string sub_sequence = s.substr(i, 10);
            if (dna.find(sub_sequence) != dna.end()) {
                dna[sub_sequence] += 1;
            } else {
                dna[sub_sequence] = 1;
            }
        }

        for (auto it = dna.begin(); it != dna.end(); it++) {
            if (it->second > 1) {
                result.push_back(it->first);
            }
        }
        return result;
    }
};