def solution(brown, yellow):
    answer = []
    summ = brown + yellow
    temp = []
    if yellow == 1:
        return [3,3]
    for i in range(1, 1+yellow):
        if yellow % i == 0:
            temp.append(i)
    
    for i in range(len(temp)):
        a, b = temp[1*i], temp[-1*(i+1)]
        if (a+2) * (b+2) == summ:
            return [b+2,a+2]
