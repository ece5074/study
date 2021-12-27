# stdlib 재현해보기
### 컴파일
    make clean;make all

## 동적할당 관련 함수
    malloc: 메모리에 공간 할당
    free: 메모리에 공간 사용 해제
    realloc: 메모리에 공간을 재할당
    calloc: 메모리 공간 할당 및 초기화
    [참조: https://arjunsreedharan.org/post/148675821737/write-a-simple-memory-allocator]
    
## 문자열 변환 함수
    atof: char to double
    atoi: char to int
    atol: char to long
    strtod: char to double
    strtol: char to long
    stroul: char to unsigned long

## 난수 생성 함수
    rand: 난수 생성
    srand: 난수 생성을 위한 초기값 생성

## 실행 관련
    abort: 현재 프로세스를 종료한다.
    atexit: 특정 함수 종료 시 실행
    exit: 호출한 프로세스를 종료
    getenv: 환경 문자열을 얻는다.
    system: 시스템 명령어를 수행.

## 검색 및 정렬 함수
    bsearch: 배열에서 이진 탐색
    qsort: 배열의 원소들을 정렬한다.

## 정수 관련 연산
    abs: 절대값을 구한다.
    div: 정수 나눗셈을 수행한다.
    labs: 절대값을 구한다.(long)
    ldiv: 정수 나눗셈을 수행한다.(long)