def main():
    str = "abcdeafgg"

    for i,ch in enumerate(str[:-1]):
        for ch2 in str[i+1:]:
            if ch == ch2:
                print "I found same char %c" % ch

    sort_str = sorted(str)
    #print sort_str

    for i, ch in enumerate(sort_str[:-1]):
        if ch == sort_str[i+1]:
            print "Found same char %c" % ch

    checked = 0
    for i, ch in enumerate(str):
        if (checked & (1 << (ord(ch) - ord('a')))) > 0:
            print "Dup found : ", ch
        checked |= (1 << (ord(ch) - ord('a')))

if __name__ == "__main__":
    main()
