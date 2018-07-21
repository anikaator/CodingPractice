
def main():
    arr = [2,2,3,4,5,5,5,6,6,6,7,7,8,9,9,9]
    ptr = 0
    second = False
    for idx, num in enumerate(arr):
        if idx == 0:
            marker = arr[idx]
            ptr += 1
            marker = num
            second = False

        if marker == num:
            if second == False:
                arr[ptr] = num
                ptr += 1
                second = True
        else:
            marker = num
            arr[ptr] = num
            ptr += 1
            second = False

    for num in arr[:ptr]:
        print num,

if __name__ == '__main__':
    main()
