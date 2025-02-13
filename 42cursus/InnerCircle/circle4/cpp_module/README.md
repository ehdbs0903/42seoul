# 42 School - C++ (CPP) Modules

이 저장소는 42 School 커리큘럼의 일부로 완료한 C++ 모듈들을 포함하고 있습니다. 각 모듈은 C++ 프로그래밍 개념에 대한 지식을 강화하고 확장하기 위해 설계된 일련의 연습 문제들로 구성되어 있습니다.

## 모듈 목록

<details>
<summary>Module 00 - Namespace, 클래스, 멤버 함수, stdio 스트림, 초기화 리스트, static</summary>

- [ex00 - 문자열 조작 및 커맨드라인 인자 처리](./cpp00/ex00/)
- [ex01 - 클래스, 객체 생성, 기본 I/O, 문자열 조작](./cpp00/ex01/)
- [ex02 - 파일 재생성, C++ 프로그래밍, 객체 지향 설계](./cpp00/ex02/)

**참고 자료:**
- **C++의 OOP:** [GeeksforGeeks](https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/)
- **std::cin.getline() vs. std::cin:** [Stack Overflow](https://stackoverflow.com/questions/4745858/stdcin-getline-vs-stdcin)
- **cpp 문자열에서의 atoi() 사용법:** [Stack Overflow](https://stackoverflow.com/questions/27640333/how-do-i-use-atoi-function-with-strings-in-c)
- **string.length() vs. string.size():** [Stack Overflow](https://stackoverflow.com/questions/31628940/which-is-faster-c-string-length-or-size)
- **C++의 생성자:** [GeeksforGeeks](https://www.geeksforgeeks.org/constructors-c/)
- **C++의 소멸자:** [GeeksforGeeks](https://www.geeksforgeeks.org/destructors-c/)
- **C++: cin.getline - 함수 오버로드 인스턴스가 없음:** [Stack Overflow](https://stackoverflow.com/questions/36459267/c-cin-getline-no-instance-of-overload-function)
- **C++ iomanip 라이브러리:** [YouTube](https://www.youtube.com/watch?v=JAEKyNfqm0A)

</details>

<details>
<summary>Module 01 - 메모리 할당, 참조, 멤버 함수 포인터, 파일 스트림</summary>

- [ex00 - 클래스, 멤버 함수, 포인터, 메모리 할당 (스택 vs. 힙), 소멸자](./cpp01/ex00/)
- [ex01 - 객체 배열, 메모리 할당 (객체 배열), 객체 초기화](./cpp01/ex01/)
- [ex02 - 포인터, 참조, 메모리 주소](./cpp01/ex02/)
- [ex03 - 컴포지션, 집약, 객체 관계, 생성자, 세터](./cpp01/ex03/)
- [ex04 - 파일 I/O, 새 파일로 내용 복사, 에러 처리](./cpp01/ex04/)
- [ex05 - 멤버 함수, 멤버 함수 포인터, 열거형, 로깅](./cpp01/ex05/)
- [ex06 - 스위치 문, 필터링, 로깅](./cpp01/ex06/)
  
  ### 참고 자료
- **C++의 참조:** [GeeksforGeeks](https://www.geeksforgeeks.org/references-in-c/)
- **멤버 함수 포인터:** [CodeGuru](https://www.codeguru.com/cplusplus/c-tutorial-pointer-to-member-function/)
- **C++ 포인터 - GeeksforGeeks:** [GeeksforGeeks](https://www.geeksforgeeks.org/cpp-pointers/)
- **C++에서 파일을 한 줄씩 읽는 방법:** [Medium](https://medium.com/@teamcode20233/how-to-read-file-line-by-line-in-c-a1d829f697c0)
- **C++ 파일 핸들링: 파일 열기, 쓰기, 읽기, 닫기:** [Guru99](https://www.guru99.com/cpp-file-read-write-open.html)
</details>
  
<details>
<summary>Module 02 - 애드혹 다형성, 연산자 오버로드, 캐노니컬 클래스</summary>

- [ex00 - 고정 소수점 숫자, 정통 캐노니컬 폼](./cpp02/ex00/)
- [ex01 - 생성자 (int와 float), 멤버 함수 (toFloat, toInt), 연산자 오버로드](./cpp02/ex01/)
- [ex02 - 연산자 오버로드 (비교, 산술, 증가/감소), 정적 멤버 함수 (min, max)](./cpp02/ex02/)
- [ex03 - 이진 공간 분할(BSP), 고정 소수점 산술, 삼각형 내부 점 포함 테스트](./cpp02/ex03/)

  ### 참고 자료
- **고정 소수점 숫자 표현 소개:** [CS61c Spring 2006](https://inst.eecs.berkeley.edu//~cs61c/sp06/handout/fixedpt.html)
- **Back To Basics! C++에서의 고정 소수점 숫자:** [YouTube](https://www.youtube.com/watch?v=ZMsrZvBmQnU)
- **부동 소수점 숫자의 이해 및 사용:** [Cprogramming](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html)
- **부동 소수점 숫자 출력하기 - Cprogramming.com:** [Cprogramming.com](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html)
- **C++의 복사 생성자:** [GeeksforGeeks](https://www.geeksforgeeks.org/copy-constructor-in-cpp/)
- **대입 연산자 오버로드:** [LearnCpp.com](https://www.learncpp.com/cpp-tutorial/overloading-the-assignment-operator/?utm_content=cmp-true)
- **C++에서의 부동 소수점 및 고정 소수점 표현:** [Medium](https://medium.com/@oumaimafisaoui/floating-and-fixed-point-representation-in-c-what-is-going-on-b71af54718a5)
- **고정 소수점 표기법 기초:** [YouTube](https://www.youtube.com/watch?v=CONpWLc-tHA)
- **10진수를 부동 소수점으로 변환:** [YouTube](https://www.youtube.com/watch?v=ZrlQpzc61Vc)
- **부동 소수점 이진 산술에 대한 IEEE 754 표준:** [YouTube](https://www.youtube.com/watch?v=RuKkePyo9zk)
- **C++의 연산자 및 연산자 오버로드:** [YouTube](https://www.youtube.com/watch?v=mS9755gF66w)
- **후위형 증가 및 감소 연산자 오버로드:** [YouTube](https://www.youtube.com/watch?v=XJbA1AjW1zw)
- **전위 및 후위 증가 연산자 오버로드:** [Stack Overflow](https://stackoverflow.com/questions/15244094/overloading-for-both-pre-and-post-increment)
- **삼각형 내부의 점 포함 여부 확인:** [YouTube](https://www.youtube.com/watch?v=qObJQesvZUU)
</details>

<details>
<summary>Module 03 - 상속</summary>

- [ex00 - 클래스 구현](./cpp03ex00/)
- [ex01 - 상속, 생성자/소멸자 체이닝, 멤버 함수 오버라이딩](./cpp03/ex01/)
- [ex02 - 상속, 생성자/소멸자 체이닝, 멤버 함수 오버라이딩](./cpp03ex02/)
- [ex03 - 다이아몬드 문제, 다중 상속, 생성자/소멸자 체이닝, 부모 클래스의 속성 및 멤버 함수 접근](./cpp03ex03/)

### 참고 자료
- **상속과 다형성:** [YouTube](https://www.youtube.com/watch?v=wrkkAOMp3Sw)
- **C++에서 클래스 상속이란?:** [YouTube](https://www.youtube.com/watch?v=ptwZfAhI-kk)
- **C++ 다중 상속:** [GeeksforGeeks](https://www.geeksforgeeks.org/multiple-inheritance-in-c/)
- **다중 상속 – 여러 부모로부터 상속받기:** [YouTube](https://www.youtube.com/watch?v=JSBtx_f3WqM)
- **다중 상속 심층 분석:** [YouTube](https://www.youtube.com/watch?v=sswTE0u0r7g)
- **혼합 상속과 다이아몬드 문제:** [YouTube](https://www.youtube.com/watch?v=DiUXoiOLZY0)
</details>

<details>
<summary>Module 04 - 서브타입 다형성, 추상 클래스, 인터페이스</summary>

- [ex00 - 다형성, 상속, 가상 함수](./cpp04/ex00/)
- [ex01 - 메모리 관리, 깊은 복사](./cpp04/ex01/)
- [ex02 - 추상 클래스](./cpp04/ex02/)
- [ex03 - 인터페이스 / 순수 추상 클래스](./cpp04/ex03/)

### 참고 자료
- **C++의 다형성 | 컴파일 타임 vs. 런타임 다형성:** [YouTube](https://www.youtube.com/watch?v=uc_Hr10cBBE)
- **C++ 서브타입 다형성과 가상 함수:** [YouTube](https://www.youtube.com/watch?v=avq_ITaqD-k)
- **C++의 가상 함수 & 추상 클래스:** [YouTube](https://www.youtube.com/watch?v=JU8DbwBvOWE)
- **추상 클래스와 순수 가상 함수:** [YouTube](https://www.youtube.com/watch?v=wE0_F4LpGVc)
- **C++에서 추상 클래스 선언하기:** [Stack Overflow](https://stackoverflow.com/questions/43502488/declare-abstract-class-in-c)
- **C++ 프로그래밍/클래스/추상 클래스/순수 추상 클래스:** [Wikibooks](https://en.wikibooks.org/wiki/C++_Programming/Classes/Abstract_Classes/Pure_Abstract_Classes)
- **추상 클래스 vs. 순수 추상 클래스의 차이점은?:** [Stack Overflow](https://stackoverflow.com/questions/15253642/what-is-the-difference-between-abstract-class-and-pure-abstract-class-in-c)
- **C++ 인터페이스 (순수 가상 함수):** [YouTube](https://www.youtube.com/watch?v=UWAdd13EfM8)
- **C++ 인터페이스 (순수 가상 함수):** [YouTube](https://www.youtube.com/watch?v=8USgOF7x0hM)
- **C++ 프로그래밍: 추상 및 인터페이스 클래스:** [YouTube](https://www.youtube.com/watch?v=GumbgtSUMMo)
- **추상 클래스 vs. 순수 추상 클래스 | 인터페이스 | OOP C++:** [YouTube](https://www.youtube.com/watch?v=BkrISFxSn-4)
- **C++ 전방 선언이란?:** [GeeksforGeeks](https://www.geeksforgeeks.org/what-are-forward-declarations-in-c/)
- **C++ 전방 선언이란?:** [Stack Overflow](https://stackoverflow.com/questions/4757565/what-are-forward-declarations-in-c)
- **C++: STL 리스트 또는 서브 리스트 복사/클론하기:** [thispointer](https://thispointer.com/c-how-to-copy-clone-a-stl-list-or-sub-list/)
</details>

<details>
<summary>Module 05 - Try/Catch와 예외 처리</summary>

- [ex00 - 예외 처리, 클래스 설계](../../circle5/cpp_module/cpp05/ex00/)
- [ex01 - 예외 처리, 클래스 설계, 멤버 함수](../../circle5/cpp_module/cpp05/ex01/)
- [ex02 - 추상 클래스, 상속, 다형성, 실행 로직](../../circle5/cpp_module/cpp05/ex02/)
- [ex03 - 팩토리 메소드, 클래스 설계, 문자열 조작](../../circle5/cpp_module/cpp05/ex03/)

### 참고 자료
- **예외 처리 - C++ 초보자 튜토리얼:** [NeuralNine](https://www.youtube.com/watch?v=5MI2N8yLdMI)
- **C++에서 예외 던지기:** [RollBar](https://rollbar.com/blog/error-exceptions-in-c/#)
- **C++ 예외 처리 (프로그램 내 오류 처리 방법):** [CodeBeauty](https://www.youtube.com/watch?v=kjEhqgmEiWY)
- **C++ 중첩 try-catch 구문 | 예외 재던지기:** [LearningLad](https://www.youtube.com/watch?v=UcT_sXaJF94)
- **C++에서 커스텀 예외 구현하기:** [Rollbar Editorial Team](https://rollbar.com/blog/cpp-custom-exceptions/#)
- **std::exception:** [cppreference](https://en.cppreference.com/w/cpp/error/exception)
- **중급-고급 C++ 3: 커스텀 예외 처리:** [Cave of Programming](https://www.youtube.com/watch?v=64HmWAH9Jvg)
- **C++에서 난수 생성기 만들기:** [digitalocean](https://www.digitalocean.com/community/tutorials/random-number-generator-c-plus-plus)
- **C++ 파일:** [w3schools](https://www.w3schools.com/cpp/cpp_files.asp)
- **정말 50/50 확률인가요?:** [cplusplus](https://cplusplus.com/forum/beginner/48833/)
- **클래스 내부 함수 배열 선언:** [Stack Overflow](https://stackoverflow.com/questions/68666087/declaring-an-array-of-functions-inside-a-class)
- **C++ 팩토리 메소드 올바른 구현법:** [medium](https://medium.com/@antwang/factory-method-in-c-the-right-way-e8c5f015fe39)
</details>

<details>
<summary>Module 06 - C++ 캐스트</summary>

- [ex00 - 형 변환, static_cast](../../circle5/cpp_module/cpp06/ex00/)
- [ex01 - reinterpret_cast](../../circle5/cpp_module/cpp06/ex01/)
- [ex02 - dynamic_cast](../../circle5/cpp_module/cpp06/ex02/)

### 참고 자료
- **C++의 형 변환:** [scaler](https://www.scaler.com/topics/cpp/type-conversion-in-cpp/)
- **C++ 형 변환:** [Neso Academy](https://www.youtube.com/watch?v=uI10H1jzw00&ab_channel=NesoAcademy)
- **C++ 타입 퍼닝:** [The Cherno](https://www.youtube.com/watch?v=8egZ_5GA9Bc&ab_channel=TheCherno)
- **C++ 캐스팅:** [The Cherno](https://www.youtube.com/watch?v=pWZS1MtxI-A&ab_channel=TheCherno)
- **std::string::find_first_not_of:** [cppreference](https://en.cppreference.com/w/cpp/types/numeric_limits)
- **strtof, strtod, strtold:** [cppreference](https://en.cppreference.com/w/c/string/byte/strtof)
- **C++ 캐스팅 - Part 3: static_cast와 dynamic_cast (메가 레슨) | Modern Cpp Series:** [Mike Shah](https://www.youtube.com/watch?v=rJO7azMDOjU)
- **C++ 캐스팅 - Part 4: static_cast vs dynamic_cast (인터뷰 질문):** [Mike Shah](https://www.youtube.com/watch?v=pHktGhvXVR0)
- **C++ 캐스팅 - Part 5: reinterpret_cast | Modern Cpp Series:** [Mike Shah](https://www.youtube.com/watch?v=jQR2doi51Bo)
- **uintptr_t 데이터 타입이란?:** [Stack Overflow](https://stackoverflow.com/questions/1845482/what-is-the-uintptr-t-data-type)
- **dynamic_cast 변환:** [cppreference](https://en.cppreference.com/w/cpp/language/dynamic_cast)
</details>

<details>
<summary>Module 07 - C++ 템플릿</summary>

- [ex00 - 템플릿 함수, swap, min, max](../../circle5/cpp_module/cpp07/ex00/)
- [ex01 - 템플릿을 사용한 반복](../../circle5/cpp_module/cpp07/ex01/)
- [ex02 - 템플릿 클래스](../../circle5/cpp_module/cpp07/ex02/)

### 참고 자료
- **C++ 함수 템플릿:** [programiz](https://www.programiz.com/cpp-programming/function-template)
- **C++ 클래스 템플릿:** [programiz](https://www.programiz.com/cpp-programming/class-templates)
- **C++에서 서브스크립트(배열 인덱스) 연산자 [] 오버로드:** [GeeksforGeeks](https://www.geeksforgeeks.org/overloading-subscript-or-array-index-operator-in-c/)
- **헤더에 정의된 템플릿 함수/클래스 구현 시 "tpp" 파일을 사용하는 이유:** [Stack Overflow](https://stackoverflow.com/questions/44774036/why-use-a-tpp-file-when-implementing-templated-functions-and-classes-defined-i)
- **후보 템플릿 무시됨: 추론된 매개변수 타입 충돌 (<const T &> vs <T &>):** [Stack Overflow](https://stackoverflow.com/questions/29367467/candidate-template-ignored-deduced-conflicting-types-for-parameter-const-t)
</details>

<details>
<summary>Module 08 - 템플릿 컨테이너, 반복자, 알고리즘</summary>

- [ex00 - 함수 템플릿, 컨테이너 조작, 예외 처리](../../circle5/cpp_module/cpp08/ex00/)
- [ex01 - std::max, std::min, std::sort 예외 처리, 반복자](../../circle5/cpp_module/cpp08/ex01/)
- [ex02 - 반복자, 템플릿 특수화](../../circle5/cpp_module/cpp08/ex02/)

### 참고 자료
- **Back To Basics: C++ 컨테이너:** [javidx9](https://www.youtube.com/watch?v=6OoSgY6NVVk&ab_channel=javidx9)
- **Back to Basics: Classic STL - Bob Steagall - CppCon 2021:** [CppCon](https://www.youtube.com/watch?v=tXUXl_RzkAk)
- **C++ 표준 템플릿 라이브러리 (STL):** [GeeksforGeeks](https://www.geeksforgeeks.org/the-c-standard-template-library-stl/)
- **컨테이너:** [cplusplus](https://cplusplus.com/reference/stl/)
- **C++ 벡터:** [programiz](https://www.programiz.com/cpp-programming/vectors)
- **std::max:** [cppreference](https://en.cppreference.com/w/cpp/algorithm/max)
- **std::sort:** [cppreference](https://en.cppreference.com/w/cpp/algorithm/sort)
- **벡터에서 최대 요소 찾기 (C++):** [Stack Overflow](https://stackoverflow.com/questions/32159151/how-do-i-find-the-max-element-in-a-vector-c)
- **std::stack:** [cppreference](https://cplusplus.com/reference/stack/stack/)
</details>

<details>
<summary>Module 09 - STL</summary>

- [ex00 - 파일 조작, std::map, 시간 파싱](../../circle5/cpp_module/cpp09/ex00/)
- [ex01 - 후위 표기법, std::stack, 입력 파싱](../../circle5/cpp_module/cpp09/ex01/)
- [ex02 - 병합 정렬 알고리즘, std::vector, std::deque, 입력 파싱](../../circle5/cpp_module/cpp09/ex02/)

### 참고 자료
- **C++에서 부분 문자열 다루기:** [GeeksforGeeks](https://www.geeksforgeeks.org/substring-in-cpp/)
- **마이크로초를 포함한 C++ 날짜/시간 파싱:** [Stack Overflow](https://stackoverflow.com/questions/44398598/c-parse-date-time-with-microseconds)
- **std::ifstream::ifstream:** [cplusplus](https://cplusplus.com/reference/fstream/ifstream/ifstream/)
- **std::map – 하나의 키에 두 개의 값:** [Stack Overflow](https://stackoverflow.com/questions/5560573/stdmap-one-key-two-values)
- **클래스 내부 정적 템플릿 함수:** [Stack Overflow](https://stackoverflow.com/questions/9346076/static-template-functions-in-a-class)
- **후위 표기법과 스택:** [Computerphile](https://www.youtube.com/watch?v=7ha78yWRDlE&ab_channel=Computerphile)
- **후위 표기법(포스트픽스 표기법)이란? 왜 중요한가?:** [Gary Explains](https://www.youtube.com/watch?v=QM_RsQ9Yeio&t=425s&ab_channel=GaryExplains)
- **C++에서 실행 시간 계산하기:** [Stack Overflow](https://stackoverflow.com/questions/876901/calculating-execution-time-in-c)
</details>


## 실행 방법

1. 이 저장소를 클론합니다:

    ```bash
    git clone github.com/snowhp/CPP-Modules
    ```

2. 원하는 모듈/연습 문제 디렉토리로 이동합니다:

    ```bash
    cd CPP00/ex00
    ```

3. 프로그램을 컴파일하고 실행합니다:

    ```bash
    make
    ./PROGRAM_EXECUTABLE_NAME  # (연습 문제에 따라 다름: 대부분 기본 [a.out] 또는 연습 문제 번호 [ex00])
    ```
