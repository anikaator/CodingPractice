import json
import sys
class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        code = ["abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
        orig_list = []
        for btn in digits:
            if (ord(btn) < ord('2') and ord(btn) > ord('9')):
                continue
            if len(orig_list) == 0:
                orig_list = list(code[ord(btn) - ord('2')])
                continue
            new_list = []            
            for ch in (code[ord(btn) - ord('2')]):
                for elem in orig_list:
                    new_list.append(elem + ch)
            orig_list = new_list        
        return orig_list


def main():
            ret = Solution().letterCombinations(sys.argv[1])
            print json.dumps(ret)

if __name__ == '__main__':
    main()
