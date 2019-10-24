def Swap(arr, i, j):
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def Permutation(arr, start, resultList):
    if start == len(arr) - 1:
        resultList.append(arr.copy())
        return

    firstPos = set()
    for k in range(start, len(arr)):
        if arr[k] not in firstPos:
            Swap(arr, start, k)
            Permutation(arr, start + 1, resultList)
            Swap(arr, start, k)
            firstPos.add(arr[k])
        else:
            print("Skip")

if __name__ == '__main__':
    arr = [1, 2, 2, 3, 3]
    resultList = []
    Permutation(arr, 0, resultList)

    for res in resultList:
        print(res)