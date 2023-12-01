'''
<문제>
초 단위로 기록된 주식가격, 가격이 떨어지지 않은 기간이 몇 초인지를 return
[1,2,3,2,3] -> 

<풀이>
for loop 두개 돌려서, 현재 위치에서 그 다음 위치들과 주식 가격 비교하기
'''

def solution(prices):
    answer = [0] * len(prices)
    for i in range(len(prices)-1):
        for j in range(i,len(prices)-1):
            if prices[i] <= prices[j]:
                answer[i] += 1
            else:
                break
    
    return answer