class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        if (s.length() == 0)
            return 0;
        char last_ch;
        bool has_char = false;
        for (auto &x : s) {
            if (x > 32)
               has_char = true;
            if (last_ch == x)
                continue;
            if (x == ' ' & has_char)
                count++;
            last_ch = x;
        }
        if (has_char == false) {
            return 0;
        }
        if (last_ch == ' ')
            return count;
        return ++count;
    }
};
