'''
<문제>
answers -> 1번 문제부터 마지막 문제까지 정답 순서대로 든 배열
가장 많은 문제를 맞힌 사람이 누구인지 return

1번-> 1,2,3,4,5
2번 -> 2,1,2,3,2,4,2,5,2,1,2,3,2,4,2,5 -> 홀수번째는 2, 짝수번째는 1,3,4,5 반복
3번 -> 3,3,1,1,2,2,4,4,5,5,3,3,1,1,2,2, -> 3,1,2,4,5를 각각 2번씩 반복

<풀이> 
1번, 2번, 3번 반복구간 담은 리스트 만들어준 다음에 탐색해주기

''' 


def solution(answers):
    answer = []
    score = [0,0,0]
    
    a1 = [1,2,3,4,5]
    a2 = [2,1,2,3,2,4,2,5]
    a3 = [3,3,1,1,2,2,4,4,5,5]
    
    for i, s in enumerate(answers):
        if s == a1[i%5]:
            score[0] += 1
        
        if s == a2[i%8] :
            score[1] += 1
        
        if s == a3[i%10] :
            score[2] += 1
            
    for k in range(len(score)):
        if score[k] == max(score):
            answer.append(k+1)    
    
    return answer