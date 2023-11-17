def solution(wallpaper):
    answer = []
    n = len(wallpaper)
    m = len(wallpaper[0])
    # print(n, m)
    result = []
    for i, w in enumerate(wallpaper):
        for j, ww in enumerate(w):
            # print(i, j, w, ww)
            if '#' == ww:
                result.append((i,j))
    # print(result)
    l_x = 9999
    m_x = 0
    l_y = 9999
    m_y = 0
    for a,b in result:
        if l_x > a :
            l_x = a
        if m_x < a :
            m_x = a
        if l_y > b :
            l_y = b
        if m_y < b :
            m_y = b
    # print()
    return [l_x, l_y, m_x+1, m_y+1]
