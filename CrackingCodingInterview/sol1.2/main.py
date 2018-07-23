import sys

def using_sort(str1, str2):
    if len(str1) != len(str2):
        print "Size mismatch. Two string are not permutation of each other"
    str1 = sorted(str1)
    str2 = sorted(str2)

    # or for idx in range(len(str1)):
    for idx, _ in enumerate(str1):
        if str1[idx] != str2[idx]:
            print "Two string are not permutation of each other"
            return
    print "Two string are permutation of each other"

def using_hash(str1, str2):
    hash_map = {}
    for ch in str1:
        if hash_map.has_key(ch) == True:
            hash_map[ch] += 1
        else:
            hash_map[ch] = 1

    for ch in str2:
        if hash_map.has_key(ch) == False:
            print "Two string are not permutation of each other"
            return
        hash_map[ch] -= 1
        if hash_map[ch] == 0:
            del hash_map[ch]

    if len(hash_map) != 0:
        print "Two string are not permutation of each other"
    else:
        print "Two string are permutation of each other"

def main():
    if len(sys.argv) != 3:
        print "Invalid arguments!"
    str1 = sys.argv[1]
    str2 = sys.argv[2]
    print ''.join(str1) + " : " + ''.join(str2)
    using_hash(str1, str2)
    using_sort(str1, str2)

if __name__ == "__main__":
    main()
