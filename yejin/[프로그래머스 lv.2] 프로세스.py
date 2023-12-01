# 뭐 쉬운 큐 문제 아닌가! 기본 아닌가! 일단 시작!
​
# 우선순위 큐? 백준에서 풀어본적 있기는 한데...
# 우선순위 큐 라이브러리가 있기는 하지만 외부 라이브러리가 사용 안되는 경우가 많으니 pass 
# 그럼 기존 우선순위 큐 코드대로 가보되, 한번 생각해보면...
​
# 예제 2를 보면 편하다. 생각보다 구현은 편할거같은데? 그냥 우선순위대로 가고...큐니까 원형인데 그걸 잘라서 하는느낌이잖아?
​
'''
def solution(priorities, location):
    answer = 1 # 카운트용, 1번째부터니까 1부터 시작해라
    n = len(priorities)
    maxi = priorities.index(max(priorities)) # 최댓값 인덱스
   
    # 그냥 잘라붙이면 안됨? 슬라이싱해서 배열을 아예 새로 만드는거야
    temp = priorities[maxi:] # 최댓값부터 끝까지 넣고
    temp.append(priorities[:maxi]) # maxi 전까지 찾아;
    
    temp =[]
    # 아!! 근데 이러면 원래 location 의 위치를 찾을수 없네요 특히 숫자가 같으면요 헤헤 근데 접근방식은 좋았다
    # 그럼 그냥 인덱스를 배열로 만들어서 하면되는거아님? 나천재인가
    for i in range(maxi,n) :
        temp.append(i)
    for j in range(0,maxi):
        temp.append(j)
        
    answer += temp.index(location)
    print(temp)
    return answer
# ㅎㅎ 20점이네 ; 왜지
'''
​
# 와 씨 질문하기에서 개 간단하게 푸는거 찾음 ; max 써서 결국 중간에 잘라서 거기서 부터 시작하고 끝으로 가면 되는거니까 
# 로케이션 기준으로 하고 t 는 0으로 두면서 while 문을 돌려서 위키가 location 이 나올때 까지 t 카운트를 올리는거야
# 현재 위치랑 로케이션이랑 같다? 그럼 순차적으로 i 인데 몇번쨰 인지니까 거기에 +1 하는거임
​
def solution(priorities, location):
    n=len(priorities)
    t=0
    for i in range(n):
        while priorities[t%n]==0 or priorities[t%n]<max(priorities):
            t+=1
        if t%n==location:
            print(i+1)
            return i+1
        priorities[t%n]=0
