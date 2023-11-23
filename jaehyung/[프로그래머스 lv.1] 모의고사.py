'''
20분!

1,2,3번 수포자가 찍는 방식을 n까지 loop 돌려야 함
나눗셈의 나머지 활용하면 index만으로 정확히 mapping 할 수 있음

1,2,3 list 만들어 준 후, len(answer)만큼 loop 돌면서 array에 하나씩 더하기

여럿인 경우 동시에 return? -> 어떻게 깔끔한 logic으로 만들까??

tmp dict 만들어서 가장 마지막 값 return
'''

def solution(answers):
    supo1,supo2,supo3=[1,2,3,4,5],[2,1,2,3,2,4,2,5],[3,3,1,1,2,2,4,4,5,5]
    array=[0,0,0]
    n,n1,n2,n3=len(answers),len(supo1),len(supo2),len(supo3)
    for i in range(n):
        if answers[i]==supo1[i%n1]:
            array[0]+=1
        if answers[i]==supo2[i%n2]:
            array[1]+=1
        if answers[i]==supo3[i%n3]:
            array[2]+=1
    tmp={}
    for idx,val in enumerate(array):
        if val not in tmp:
            tmp[val]=[]
        tmp[val].append(idx+1)
    answer=sorted(tmp.items())[-1][-1]
    return answer
