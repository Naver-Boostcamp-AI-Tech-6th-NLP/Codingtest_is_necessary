def solution(answers):
    result = []
    
    one = [1,2,3,4,5]
    two = [2,1,2,3,2,4,2,5]
    three = [3,3,1,1,2,2,4,4,5,5]
    score = [0,0,0]
    
    for idx, answer in enumerate(answers):
        # 찍는 번호 구하기
        oneIdx=idx%len(one)
        twoIdx=idx%len(two)
        threeIdx=idx%len(three)
        
        # 찍는 번호가 정답이면 score +
        if(answer==one[oneIdx]):
            score[0]+=1
        if(answer==two[twoIdx]):
            score[1]+=1
        if(answer==three[threeIdx]):
            score[2]+=1
    
    # 최고점인 학생 result에 추가 및 정렬
    maxs = max(score)
    for i, s in enumerate(score):
        if s==maxs:
            result.append(i+1)
    result = sorted(result)
    
    return result
