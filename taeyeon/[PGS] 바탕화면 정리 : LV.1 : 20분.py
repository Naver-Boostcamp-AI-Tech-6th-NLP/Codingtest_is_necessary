'''<문제>
- 파일들은 격자칸에 위치, 격자점들은 (0,0) -> (세로, 가로)
- 빈칸은 ., 파일이 있으면 # 
- 드래그하면 파일 선택, 선택된 파일 삭제 가능
- 드래그ㅡ는 S를 왼쪽 버튼으로 클릭한 다음, 격자점 E (rdx, rdy)로 이동한 뒤 마우스 왼쪽 버튼을 뗌는 것
- 드래그한 거리 = |rdx - lux | + |rdy - luy|
- 파일들을 한번에 삭제하기 위해 최소한의 이동거리를 갖는 드래그의 시작점과 끝점을 담은 정수 배열을 return하는 solution
- 
<풀이>
- #이 처음으로 나오는 좌표 담고 가장 마지막으로 # 나오는 좌표 +1 
''' 

def solution(wallpaper):
    answer = [50,50,0,0] # 최대, 최소로 초기화
    
    for i in range(len(wallpaper)): 
        for j in range(len(wallpaper[0])):
            if wallpaper[i][j] == "#":
                answer[0] = min(answer[0], i)
                answer[1] = min(answer[1], j)
                answer[2] = max(answer[2], i+1)
                answer[3] = max(answer[3], j+1)
    
    return answer
