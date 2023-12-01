def solution(priorities, location):
    answer = 0
    finish = list()
    
    a = [[key,value] for key,value in enumerate(priorities)]   
    
    while True:
        if max(item[1] for item in a) > a[0][1] :
            a.append(a.pop(0))

        elif max(item[1] for item in a) == a[0][1]:
            finish.append(a[0][0])
            a.pop(0)
            
        if len(priorities) == len(finish):
            break
            
    answer = finish.index(location) + 1
            
    
    return answer