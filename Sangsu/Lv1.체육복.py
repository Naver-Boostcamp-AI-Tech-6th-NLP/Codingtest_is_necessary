def solution(n, lost, reserve):
    answer = 0
    for i in sorted(lost):
        if i in lost and i in reserve:
            reserve.remove(i)
            continue
        if (i-1) in reserve:
            reserve.remove(i-1)
            continue
        elif (i+1) in reserve and (i+1) not in lost:
            reserve.remove(i+1)
            continue
        else:
            answer += 1
    return n - answer
