def solution(answers):
    answer = {1:0, 2:0, 3:0}
    result = []
    one = [1,2,3,4,5]
    two = [2,1,2,3,2,4,2,5]
    three = [3,3,1,1,2,2,4,4,5,5]
    for i in range(len(answers)):
        if one[i%len(one)] == answers[i]:
            answer[1] += 1
        if two[i%len(two)] == answers[i]:
            answer[2] += 1
        if three[i%len(three)] == answers[i]:
            answer[3] += 1
    m = max(answer.values())
    for i in range(3):
        if m == list(answer.values())[i]:
            result.append(i+1)
    return result
