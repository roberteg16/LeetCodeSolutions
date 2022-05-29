class Solution {
public:
    struct SlidingWindow {
        int lBorder = 0;
        int rBorder = 0;  
        
        int size() {
            return rBorder - lBorder;
        }
    };
    
    int lengthOfLongestSubstring(string s) {
        
        int lastPosOfChar[256];
        for (size_t i = 0; i < 256; i++) {
            lastPosOfChar[i] = -1;
        }
        
        SlidingWindow win;    
        int solution = 0;
        
        while (win.rBorder < s.size()) {
            const char currentChar = s[win.rBorder]; 
            int idx = lastPosOfChar[currentChar];
            
            if (idx != -1) {
                // Clear all visited chars since we are going
                // to move lBound of windows.
                for (int i = win.lBorder; i <= idx; ++i) {
                    lastPosOfChar[s[i]] = -1;
                }
                 
                // Set left bound of window to one past the next char where
                // we last saw it
                win.lBorder = idx + 1;
            }
            
            // Store last position where we saw this very char
            // and advance
            lastPosOfChar[currentChar] = win.rBorder++;
            
            const int currentSize = win.size();
            // Update solution with current windows size
            solution = solution < currentSize ? currentSize : solution;
        }
        
        return solution;
    }
};
