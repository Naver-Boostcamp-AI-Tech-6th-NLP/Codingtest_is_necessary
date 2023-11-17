def solution(name):
    answer = 0
    lr = len(name) - 1
    for i, s in enumerate(name):
        answer += min(ord(s) - ord("A"), ord("Z")-ord(s)+1)

        next = i + 1
        while next < len(name) and name[next] == 'A':
            next += 1
        
        lr = min([lr, 2 * i + len(name) - next, i + 2 * (len(name) - next)])
    answer += lr
    
    return answer

'''
ABCDEFGHIJKLMNOPQRSTUVWXYZ
- 맨처음엔 A로만 이루어짐
- 위: 다음 알파벳 / 아래: 이전 알파벳(A -> Z) / 왼: 커서를 왼쪽으로 / 오: 커서를 오른쪽으로
- 조이스틱 조작 횟수의 최댓값
- 처음엔 첫글자로 이동해야 함! -> 
- 알파벳 전체 26자, 아스키코드 A 65 Z 90
- 현재 위치에서 해당 위치로 가는 것보다 A에서 Z로 이동하는게 빠른지 
- 좌 우 이동 -> A가 연속적으로 있으면, A의 시작점과 A의 끝점+1을 표시해두고, A 시작점 왼쪽 과 끝점 오른쪽에 A가 아닌 알파벳이 몇개가 있는지 계산
'''