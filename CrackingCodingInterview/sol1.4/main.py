import sys

class Solution(object):
    def check_permutation_palindrome(self, strr):
        single_ctr = 0
        arr = [False] * 256
        for ch in strr:
            if arr[ord(ch)] == False:
                single_ctr += 1
                arr[ord(ch)] = True;
            else:
                single_ctr -= 1
                arr[ord(ch)] = False
        if single_ctr == 0 or single_ctr == 1:
            return True
        else:
            return False

def main():
    ret = Solution().check_permutation_palindrome(sys.argv[1]);
    if ret == True:
        print "It is permutation palindrome"
    else:
        print "Its not a permutation palindrome"

if __name__ == "__main__":
    main()
