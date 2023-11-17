#단순구현

def solution(wallpaper):
    minX, minY, maxX, maxY = 21e8,21e8,0,0 #(개선사항) 길이의 최댓값 확인 -> 50

    for x in range(len(wallpaper)):
        for y in range(len(wallpaper[0])):
            if wallpaper[x][y]=='#': #(개선사항) 리스트로 만들어 max, min값 찾기
                if x<minX:
                    minX=x
                if y<minY:
                    minY=y
                if x>maxX:
                    maxX=x
                if y>maxY:
                    maxY=y
                
    return [minX, minY, maxX+1, maxY+1] 
		#maxX가 아닌 maxX+1 인 이유
		#특정 칸의 좌측상단 점을 좌표로 지정 -> 모두 드래그하려면, 마지막 칸의 우측하단 점의 좌표를 나타내야 함
