class Solution {
public:
    unsigned getBitSetFromWord(std::string &str) {
        unsigned bitset = 0;
        for (size_t j = 0; j < str.size(); j++) {
            bitset |= 1 << (str[j] - 'a');
        }
        return bitset;
    }
    
    int maxProduct(vector<string>& words) {
        
        // Sort in ascending order
        auto ascOrder = [](std::string &lhs, std::string &rhs) {
            return lhs.size() > rhs.size();
        };
        std::sort(words.begin(), words.end(), ascOrder);        
        
        std::vector<unsigned> lettersSetOfEachString;
        std::vector<bool> alreadyCalculated(words.size(), false);
        lettersSetOfEachString.reserve(words.size());
        
        size_t maxMultiple = 0;
        for (size_t i = 0; i < words.size(); i++) {
            for (size_t j = i+1; j < words.size(); j++) {
                const size_t tmpMul = words[i].size() * words[j].size();
                if (tmpMul < maxMultiple) continue;
                
                if (!alreadyCalculated[i]) {
                    lettersSetOfEachString[i] = getBitSetFromWord(words[i]);
                    alreadyCalculated[i] = true;
                }
                if (!alreadyCalculated[j]) {
                    lettersSetOfEachString[j] = getBitSetFromWord(words[j]);
                    alreadyCalculated[j] = true;
                }
                
                if (! (lettersSetOfEachString[i] & lettersSetOfEachString[j])) {
                    maxMultiple = tmpMul;
                }
            }    
        }
        
        
        return maxMultiple;
    }
};
