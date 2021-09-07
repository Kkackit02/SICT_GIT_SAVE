/*

앞서 소개한 예제 RefSwap.cpp의 SwapByRef2 함수를 다음의 형태로 호출하면 컴파일 에러가 발생한다.
SWapByRef2(23, 45);
컴파일 에러가 발생하는 이유가 무엇인지 설명해보자.

void SwapByRef2(int & ref1, int &ref2)
{
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

-> 참조하는 매개변수에 23과 45라는 상수가 들어왔기 때문에 참조가 불가능해 컴파일 에러가 발생했다.

*/