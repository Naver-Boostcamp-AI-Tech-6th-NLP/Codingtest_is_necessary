#드가자~~~~ 문제가 디게 짧네
# 우선 제한사항 흠... 뭐 1만에 10만 정도면 크게 신경쓸 정도는 아닌거같은대
# 어...어..? 뭔소리야 문제 이해가 조금 어려운데..? 
# 아 뭐야 이해했쓰 i got it~~~
# 흠... 그냥 배열 이용해서 하면될거같은데... 근데 스택 큐 문제라고 적혀있잖아..?
​
# 마지막은 무조건 0이 나올 수 밖에 없고. 스택을 이용한다면... 
# pop 을 이용하면 뒤에서 부터 나오니까 pop 해서 나오는 순서대로 숫자를 넣고 reverse 해주면 될거같은데?
​
# 뭐야 뭐가문젠데 이럭게 하면안도;ㄴ데
# 그럼... deque 를 써서 popleft 를 써도 되는거같고 힌트도 그런게 있는거같긴한데... 그냥 공식으로 푸는걸로
​
def solution(prices):
    answer = [] # 정답
    n = len(prices)
    for i in range(n-1): # -1 해줘야함 마지막은 어차피 끝이니까
        # 떡락 안함
        time = n - i -1
        # 중간에 떨어지는 경우
        for j in range(i+1,n):
            if prices[j] < prices[i]:
                time = j - i
                break
        answer.append(time)
    answer.append(0) # 마지막은 무조건 0 
    
    return answer
