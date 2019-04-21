from random import *

def AvailableNum(matrix, rowNo, colNo):
    availableDict = {}
    for i in range(9):
        availableDict[i + 1] = 1

    # print(availableDict)

    for i in range(9):
        if matrix[rowNo][i] != 0 and availableDict[matrix[rowNo][i]] == 1:
            availableDict[matrix[rowNo][i]] = 0

    for i in range(9):
        if matrix[i][colNo] != 0 and availableDict[matrix[i][colNo]] == 1:
            availableDict[matrix[i][rowNo]] = 0
    
    subMatrix_x = int(rowNo / 3) * 3
    subMatrix_y = int(colNo / 3) * 3

    for i in range(3):
        for j in range(3):
            if matrix[subMatrix_x + i][subMatrix_y + j] != 0 and availableDict[matrix[subMatrix_x + i][subMatrix_y + j]] == 1:
                availableDict[matrix[subMatrix_x + i][subMatrix_y + j]] = 0

    availableNum = []
    for num, status in availableDict.items():
        if status == 1:
            availableNum.append(num)

    print(availableNum)
    return availableNum

def PrintSudoku(matrix):
    for i in range(9):
        print(matrix[i])
        
        # print('\n')

if __name__ == '__main__':
    sudokuMatrics = []
    for i in range(9):
        sudokuMatrics.append([])
        for j in range(9):
            sudokuMatrics[i].append(0)
    
    for i in range(9):
        for j in range(9):
            avaibaleNum = AvailableNum(sudokuMatrics, i, j)
            sudokuMatrics[i][j] = avaibaleNum[randint(0, len(avaibaleNum) - 1)]
            PrintSudoku(sudokuMatrics)

