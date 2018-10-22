class Solution {
public:
    void reverseWords(string &s) {
        int len = s.length();
        if (len == 0)
            return;
        int b =0, e = 0;
        stack<string> stk;
        while(b < len) {
            if ((s[b]==' ')) {
                b++; continue;
            }
            e = b;
            while (e < len && !(s[e] == ' ')) {
                e++;
            }
            stk.push(s.substr(b, e-b));
            b = e;
        }
        if(stk.empty()) {
            s = "";
            return;
        }
        string final_str;
        final_str.append(stk.top());
        stk.pop();
        while(!stk.empty()) {
            final_str = final_str + " " + stk.top();
            stk.pop();
        }
        
        s = final_str;
    }
};
