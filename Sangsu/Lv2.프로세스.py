def solution(priorities, location):
    answer = 1
    temp = sorted(priorities)
    ori = priorities
    num = ori[location]
    ori[location] = 99
    while len(ori) != 0:
        # 목표한 location일 때
        if ori[0] == 99:
            if num == temp[-1]:
                return answer
            else :
                ori.append(ori[0])
                ori = ori[1:]
                continue
                
        # 우선순위가 높은 것 만났을 때
        if temp[-1] == ori[0]:
            temp.pop()
            ori.pop(0)
            answer += 1
        else :
            ori.append(ori[0])
            ori = ori[1:]
    return answer
