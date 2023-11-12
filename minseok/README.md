# Codingtest_is_necessary
네이버 부스트캠프 AI Tech 6기 NLP 쉽조 코테 스터디


### 코테에 대한 준비

- 내 생각 : 기본 되었다 싶으면 - BFS/DFS, Greedy, DP - 끝 / 더 가면 다익스트라, 벨만포드 정도
- 시간복잡도와 공간복잡도 생각하기 - 입력 수 n에 따른 일반적인 최대 시간 복잡도
    
    (절대적인 것은 아니고 일반적으로 이걸 따름)
    
    - n≤20 → O(n!), O(2^n)
    - n≤100 → O(n^3)
    - n≤1000 → O(n^2)
    - n≤10000 → O(n), O(nlogn)
    - n≤10^8 → O(logn)

### 내 코딩테스트 문제풀이 방법

- 2시간 이상 고민해서 안 떠오르면 답지 보자(이 이상은 손해) - 남이 푼 걸로 정답 제출 후, 원리 파악 및 코드 리뷰
- 아래의 3단계를 거쳐서 문제해결
    - 문제를 읽고 정의 및 입력범위 확인(주석작성) +  ~알고리즘으로 ~해서 풀면 되겠다! → 50%
    - 근데 시간/메모리 안에 수행 가능? 복잡도가 얼마지? 의사 코드로 확인해보자 → 80%
    - 이 로직에 예외나 반례는 없나? 극한의 인풋값을 넣어도 가능한가? → 100%

### 스터디 방식

- 난이도 기준 : 프로그래머스 레벨 - 최대한 다양한 난이도 분포로 선정함
- 문제 선정 기준 :
    1. 레벨 별로 다양한 주제 뽑았음 / 팀원들이 필요로 하는 부분 추가 선정 예정
    2. 같은 레벨 → 아래로 갈수록 어려워짐
- 문제 정하기 : 팀원들의 관심사와 학습 필요성을 고려해서 선정
- 리뷰 및 피드백 : 작성한 코드를 보여주며 설명 - 서로의 코드를 보며 배울 점 생각해보기

- SQL 필요하신 분 있으신가용? 있으시면 이것도 준비할게요!

## Programmers 코딩테스트 문제 목록

### Lv.1

- 단순구현 - [바탕화면 정리 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/161990)
- 해시 - [폰켓몬 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/1845)
- 완전탐색 - [모의고사 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42840)
- Greedy - [체육복 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42862)
- 단순구현 - [공원 산책 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/172928)
- map/dictionary - [달리기 경주 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/178871)

- 구현 - [대충 만든 자판 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/160586)
- 완전탐색 - [최소직사각형 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/86491)

### Lv.2

- 완전탐색 - [카펫 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42842)
- 문자열 파싱, 구현 - [호텔 대실 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/155651)
- BFS/DFS - [타겟 넘버 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/43165)
- 구현 - [두 원 사이의 정수 쌍 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/181187)
- 재귀함수로 탐색 - [광물 캐기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/172927)
- Stack [- 과제 진행하기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/176962)
- Stack/Queue - [프로세스 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42587)
- 구현(아이디어 필요) - [요격 시스템 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/181188)
- Greedy - [조이스틱 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42860)

- Heap - [더 맵게 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42626)
- 정렬 - [H-Index | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42747)
- 완전탐색 - [소수 찾기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42839)
- Greedy - [큰 수 만들기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42883)
- BFS/DFS - [게임 맵 최단거리 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/1844)

### Lv.3

- Greedy - [섬 연결하기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42861)
- 구현(아이디어 필요) - [2차원 동전 뒤집기 | 프로그래머스 스쿨](https://school.programmers.co.kr/learn/courses/30/lessons/131703)
- BFS/DFS - [네트워크 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/43162)
- BFS/DFS - [부대복귀 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/132266)
- 카카오 코테 - [미로 탈출 명령어 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/150365)
- 카카오 코테(DP) - [코딩 테스트 공부 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/118668)
- 카카오 코테(다익스트라) - [등산코스 정하기 | 프로그래머스 스쿨](https://school.programmers.co.kr/learn/courses/30/lessons/118669)
- DP 매운맛 - [아방가르드 타일링 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/181186)

- Greedy -[단속카메라 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42884)
- DP - [N으로 표현 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/42895)
- BFS/DFS - [단어 변환 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/43163)
- BFS/DFS [- 여행경로 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/43164)
- 이분탐색 - [입국심사 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/43238)
- 그래프 - [순위 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/49191)

### SQL

- SUM, MAX, MIN(lv.1) [- 가장 비싼 상품 구하기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/131697)
- SELECT(lv.1) - [과일로 만든 아이스크림 고르기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/133025)
- JOIN(lv.2) [- 조건에 맞는 도서와 저자 리스트 출력하기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/144854)
- GROUP BY(lv.2) - [성분으로 구분한 아이스크림 총 주문량 | 프로그래머스 스쿨](https://school.programmers.co.kr/learn/courses/30/lessons/133026)
- IS NULL(lv.2) - [NULL 처리하기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/59410)
- String, Date(lv.2) - [이름에 el이 들어가는 동물 찾기 | 프로그래머스 스쿨 (programmers.co.kr)](https://school.programmers.co.kr/learn/courses/30/lessons/59047)
