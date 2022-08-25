#include "../common.h"

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int letters[26] = {0};
        for (char c : ransomNote) {
            letters[c-'a']++;
        }
        for (char c : magazine) {
            letters[c-'a']--;
        }
        
        for (auto letter : letters) {
            if (letter > 0) {
                return false;
            }
        }
        
        return true;
    }
};
