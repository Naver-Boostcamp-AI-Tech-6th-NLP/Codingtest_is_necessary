def solution(numbers):
    from itertools import permutations
    answer = []
    total = 0
    for i in range(1, len(numbers)+1):
        temp = permutations(numbers, i)
        for j in temp:
            answer.append(int(''.join(j)))
    result = list(set(answer))
    for i in result:
        cnt = 1
        if i == 0 or i == 1:
            continue
        for j in range(2, i):
            if i%j == 0 :
                cnt = 0
                break
        if cnt == 1:
            total += 1
    return total
