# 스읍...하... 벌써 대가리아픈데
# 그래도..어.. 시도해볼게! 약간 나는 알러지 있는 문제인데...
​
​
​
# 30분간 생각하다가 포기하고 답안을 보았습니다 
# 
​
def convertToMin(time):
    return int(time[:2])*60 + int(time[3:])
​
​
def solution(plans):
    time_table, job_queue, cur_job = {}, [], None
    answer =[]
    for plan in plans:
        # 이름, 숫자
        time_table[convertToMin(plan[1])] = (plan[0],int(plan[2]))
​
    # time_table에는 시작이 걸림
    for time in range(5000*60):
        # 진행 작업 처리
        if cur_job:
            cur_job = (cur_job[0], cur_job[1] - 1)
            if cur_job[1] == 0:
                answer.append(cur_job[0])
                cur_job = None
​
        if time in time_table:
​
            # 현재 진행 중인 작업이 있으면
            if cur_job:
                job_queue.append(cur_job)
                cur_job = time_table[time]
            # 현재 진행 중인 작업이 없으면
            else:
                cur_job = time_table[time]
        else:
            # 트리거할 작업이 없고, 진행 중인 작업이 없다면
            if not cur_job and job_queue:
                cur_job = job_queue.pop()
    return answer
