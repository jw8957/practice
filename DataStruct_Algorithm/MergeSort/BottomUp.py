
def MergeSort(numList):
    n = len(numList)
    width = 1
    # for width = 1; width < n; width = width * 2:
    while width < n:
        print("== Width[{0}] =======================================".format(width))
        # for i = 0; (i + width) < n; i = i + width:
        i = 0
        while i + width < n:
            start = i
            mid = i + width - 1
            end = min(i + width * 2 -1, n - 1)
            print ("Merge [{0}, {1}] and [{2}, {3}]".format(start, mid, mid + 1, end))
            i = i + width * 2

        width = width * 2

if __name__ == '__main__':
    numList = [2, 5, 1, 3, 4, 9]
    MergeSort(numList)