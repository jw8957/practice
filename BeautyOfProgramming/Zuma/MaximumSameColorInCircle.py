def Prev(circle, i):
    if circle is None or len(circle) == 0:
        return -1
    
    if i > 0:
        return i - 1
    else:
        return len(circle) - 1

def Next(circle, i):
    if circle is None or len(circle) == 0:
        return -1
    
    if i == (len(circle) - 1):
        return 0
    else:
        return i + 1

def MaximumCircleLength(circle):
    start = 0
    end = len(circle) - 1

    maximumLength = 1
    while start != end:
        if circle[start] != circle[Prev(circle, start)]:
            break
        else:
            start = Next(circle, start)
    
    if start == end:
        maximumLength = len(circle)
        return maximumLength

    print("Find start:" + str(start))

    lastColor = circle[start]
    sameColorLength = 1

    i = Next(circle, start)
    while i != start:
        if circle[i] == circle[Prev(circle, i)]:
            sameColorLength = sameColorLength + 1
            if maximumLength < sameColorLength:
                maximumLength = sameColorLength
        else:
            lastColor = circle[i]
            sameColorLength = 1
        
        i = Next(circle, i)
        print("Next i:" + str(i))

    return maximumLength


if __name__ == "__main__":
    circle = ['b', 'b', 'p', 'b', 'b', 'b', 'p', 'g', 'p', 'y', 'p', 'y', 'g', 'g', 'g']
    circle = ['g', 'b', 'p', 'b', 'b', 'b', 'p', 'g', 'p', 'y', 'p', 'y', 'g', 'g', 'g']
    circle = ['b', 'b', 'b', 'b', 'b']

    res = MaximumCircleLength(circle)
    print(res)
