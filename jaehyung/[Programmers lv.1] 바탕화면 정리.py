"""
x의 최대최소값, y의 최대최소값을 구하면 됨
그래서 최소x,최소y,최대x,최대y 반환

wallpaper 리스트를 loop 돌리면서 가장 먼저 등장하는 #의 위치가 y의 최소값이라는 것만 확정할 수 있음
(나머지는 loop를 계속 돌면서 갱신될 수 있음)

모든 위치 좌표를 저장할 필요는 없음 -> min, max 변수 지정해서
# 만날 때 마다 min, max 함수써서 갱신하는게 가장 최선인 듯

시작 지점과 끝 지점 인덱스 값 잘 생각하기 (# 최대값에 하나 더 추가해야 함)


??: min, max를 매번 count하는게 최선일까?

"""

def solution(wallpaper):
    m,n=len(wallpaper[0]),len(wallpaper)
    # min을 가장 큰 지점, max를 가장 작은 지점 찍어야 # 만나면 갱신됨
    min_x,max_x,min_y,max_y=m,0,n,0
    
    for y in range(n):
        for x in range(m):
            if wallpaper[y][x]=='#':
                min_x,min_y=min(min_x,x),min(min_y,y)
                max_x,max_y=max(max_x,x),max(max_y,y)
                
    return [min_y,min_x,max_y+1,max_x+1]
