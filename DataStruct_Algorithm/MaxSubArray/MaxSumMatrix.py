def MaxSubArray(nums):
    if nums is None or len(nums) < 1:
        raise Exception("Input array is none or empty")

    maxSum = nums[0]
    maxSumEnd = nums[0]

    for i in range(1, len(nums)):
        maxSumEnd = max(nums[i], maxSumEnd + nums[i])
        maxSum = max(maxSumEnd, maxSum)
    
    return maxSum

def MaxSubMatrix(matrix):
    if matrix is None or len(matrix) < 1:
        raise Exception("Input matrix is none or empty")

    maxSum = MaxSubArray(matrix[0])
    for rowNo_i in range(0, len(matrix)):
        maxSumNow = MaxSubArray(matrix[rowNo_i])
        for rowNo_j in range(rowNo_i + 1, len(matrix)):
            for k in range(0, len(matrix[0])):
                matrix[rowNo_i][k] += matrix[rowNo_j][k]      

            maxSumNow = max(maxSumNow, MaxSubArray(matrix[rowNo_i]))

        maxSum = max(maxSum, maxSumNow)
    
    return maxSum

if __name__ == '__main__':
    array = [1, 3, -3, 5]
    print(MaxSubArray(array))

    matrix = [[0, -1, -1], [-5, 2, 9]]
    print(MaxSubMatrix(matrix))
