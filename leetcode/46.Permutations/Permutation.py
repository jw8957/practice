def Swap(arr, i, j):
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def Permutation(arr, start, resultList):
    if start == len(arr) - 1:
        resultList.append(arr.copy())
        return

    for k in range(start, len(arr)):
        Swap(arr, start, k)
        Permutation(arr, start + 1, resultList)
        Swap(arr, start, k)

if __name__ == '__main__':
    arr = [1, 2, 3]
    resultList = []
    Permutation(arr, 0, resultList)

    print(resultList)