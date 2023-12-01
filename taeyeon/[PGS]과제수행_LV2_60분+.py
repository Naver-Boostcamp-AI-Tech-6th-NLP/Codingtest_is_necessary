'''
<문제> 
- 과제 시작하기로 한 시간 되면 시작
- 새로운 과제 시작할 시간 되었는데, 기존 과제 시간과 겹치면, 기존과제 멈추고 새로운 과제 시작
- 새로운 과제 시작할 시간까지 남은 시간 있으면 남아있던 기존 과제 풀든가 


< 풀이 >
- 시간을 분 단위로 바꿔주기




'''

def solution(plans):
    answer = []
    
    length = len(plans)
    
    for i in range(len(plans)):
        plans[i][1] = int(plans[i][1][:2]) * 60 + int(plans[i][1][3:])
        plans[i][2] = int(plans[i][2])
        
    plans = sorted(plans, key=lambda x: x[1])
    count = 0
    wait = []
    now = 0
    
    while True:
        if len(plans) >= 2 and plans[0][1] + plans[0][2] > plans[1][1]:
            now = plans[1][1]
            plans[0][2] = plans[0][1] + plans[0][2] - plans[1][1]
            wait.append(plans.pop(0))

        else:
            rest_time = plans[0][1] - now
            now = plans[0][1] + plans[0][2]
            answer.append(plans.pop(0)[0])
            
            if rest_time > 0 :
                
            
            if len(plans) > 1:
                while rest_time > 0 and wait:
                    if rest_time >= wait[0][2]:
                        rest_time -= wait[-1][2]
                        answer.append(wait.pop()[0])
            
            else:
                while wait:
                    answer.append(wait.pop()[0])

        if len(answer) == length:
            break
        
    return answer