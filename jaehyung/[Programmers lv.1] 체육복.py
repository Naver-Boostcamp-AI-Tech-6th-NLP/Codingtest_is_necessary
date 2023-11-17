'''
총 수업을 들을 수 있는 학생 수 구하는 것

** reserve에서 lost 얼마나 채울 수 있나?가 이 문제의 핵심 **

바로 앞뒤 학생들에게만 체육복을 빌릴 수 있음
lost와 reserve에 같은 값 있을 시, reserve 불가능... (문제를 제대로 안읽어서 이 부분 빠뜨림, 고치느라 시간 걸림...)

리스트 만들어서 lost는 -1, reserve는 +1
for문 돌려서 앞뒤로 +1 없는 -1 체크해서 빼주기

'''

def solution(n, lost, reserve):
    # 앞뒤로 dummy 1씩 넣어줌
    # index 사용하기 때문에 별도의 정렬 필요 없음
    cloth=[0 for i in range(n+2)]
    count=0
    for i in lost:
        cloth[i]-=1
    for i in reserve:
        cloth[i]+=1
    for i in range(1,n+1):
        if cloth[i]==-1:
            if cloth[i-1]==1:
                # 지나간 순서는 count 필요 없음
                cloth[i]=0
            elif cloth[i+1]==1:
                cloth[i]=0
                cloth[i+1]-=1
            else:
                count+=1
    return n-count
