def Swap(arr, i, j):
    tmp = arr[i]
    arr[i] = arr[j]
    arr[j] = tmp

def Permutation(arr, k, selectedCnt):
    if k == selectedCnt:
        print(arr[:selectedCnt])
    
    for i in range(selectedCnt, len(arr)):
        Swap(arr, i, selectedCnt)
        Permutation(arr, k, selectedCnt + 1)
        Swap(arr, i, selectedCnt)

def Combination(arr, k, start, selectedArr):
    if k == 0:
        print(selectedArr)
        return

    for i in range(start, len(arr) - k + 1):
        newSelectedArr = selectedArr.copy()
        newSelectedArr.append(arr[i])
        Combination(arr, k - 1, i + 1, newSelectedArr)

if __name__ == "__main__":
    arr = [1, 3, 5, 7]
    # Permutation(arr, 3, 0)
    selectedArr = list()
    # print(selectedArr)
    Combination(arr, 2, 0, selectedArr)