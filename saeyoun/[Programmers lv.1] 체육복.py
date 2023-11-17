def solution(n, lost, reserve):
    lostSet = set(lost)
    reserveSet= set(reserve)
    
    #여벌 체육복을 가져온 학생이 도난당했을 때
    lostSet, reserveSet = lostSet-reserveSet, reserveSet-lostSet
    
    for l in list(lostSet): #도난당한 학생의
        for tar in [l-1, l+1]: #앞뒤 번호가
            if tar in list(reserveSet): #여벌 체육복을 가져온 학생의 번호에 있을 때
                lostSet.remove(l)
                reserveSet.remove(tar)
                break
         
    return n - len(lostSet) #전체 학생수 - 도난당한 학생수
