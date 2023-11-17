def solution(name):
    udmove = 0
    lrmove = len(name) - 1
    
    for i in range(len(name)):
        #상/하 커서 계산
        udmove += min(ord(name[i])-ord('A'), ord('Z')-ord(name[i])+1) 
                      
        #최대 연속 A의 길이
        next = i + 1
        while next < len(name) and name[next] == 'A':
            next += 1
        
        #좌/우 커서 계산
        lrmove = min([lrmove,2*i + len(name)-next, i + 2*(len(name)-next)])
        
    # 합
    answer = udmove + lrmove
    return answer

# 테케 12 오류 찾아보기
# def solution(name):
#     answer = 0
#     aLen = 0
#     aLenMax = 0
#     aLenMaxi = 0
    
#     for i in range(len(name)):
#         #상/하 커서 계산
#         answer += min(ord(name[i])-ord('A'), ord('Z')-ord(name[i])+1) 
                      
#         #최대 연속 A의 길이, 위치
#         if name[i]=='A':
#             if i>=1 and name[i-1]!='A':
#                 aLen = 1
#             else:
#                 aLen += 1
#             if aLenMax<aLen:
#                 aLenMax = aLen
#                 aLenMaxi = i
#             if aLenMax==len(name): 
#                 return 0
    
#     #최대 연속 A의 앞, 뒤 길이
#     front = aLenMaxi-aLenMax
#     back = len(name)-aLenMaxi-1
#     if front==-1 : front=0
    
#     # 좌/우 커서 계산
#     answer +=  min((len(name)-1),front*2+back, front+back*2)
    
#     return answer
