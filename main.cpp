class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = 0;
        int arr[256] = {-1};
        
        for (int i = 0; i < 256; ++i) {
            arr[i] = -1;
        }
        int tempStartIndex = 0;
        int tempEndIndex = 0;
        int tempSize = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            int index = s[i];
  
            if (arr[index] != -1 && arr[index] >= tempStartIndex) {
                int previousIndex = arr[index];
                                
                if (tempSize > size) {
                    size = tempSize;
                    valueChanged = true;
                }
                
                tempStartIndex = previousIndex + 1;
                tempEndIndex = i;
                
                tempSize = tempEndIndex - tempStartIndex + 1;
                
                arr[index] = i;
            }
            else {
                arr[index] = i;
                tempEndIndex = i;
                tempSize++;
            }
        }
        
        if (tempSize > size) {
            size = tempSize;
        }
        return size;
    }
};
