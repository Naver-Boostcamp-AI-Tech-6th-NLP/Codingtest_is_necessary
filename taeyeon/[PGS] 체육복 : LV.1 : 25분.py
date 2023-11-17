def solution(n, lost, reserve):
    set_reserve = set(reserve) - set(lost)
    set_lost = set(lost) - set(reserve)
    for i in set_reserve:
        if i-1 in set_lost:
            set_lost.remove(i-1)
        elif i+1 in set_lost:
            set_lost.remove(i+1)
            
    answer = n - len(set_lost)
        
    return answer


'''
<문제>
- 여벌 체육복 있는 학생들이 체육복 빌려줌
- 학생들 번호는 체격 순으로 매겨짐 -> 바로 앞번호나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있음
- 최대한 많은 학생들한테 체육복 빌려줄 수 있도록
- 여벌의 체육복이 있는 학생도 도난 당할 수 있음...!!! ⭐️

<풀이>
여벌의 체육복이 있는 학생도 도난 당할 수 있으므로 set함수 이용해서 reserve lost 중복 빼주기⭐️⭐️
그런 다음에 for문 이용해서 왼쪽부터 오른쪽에 도난 당한 사람 있으면 빌려주기
''' 
