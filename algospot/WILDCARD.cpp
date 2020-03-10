//
// Created by Jongwoo on 2020-03-11.
//
#include <iostream>
#include <string>
#include <vector>
/**
 * 1. 문제를 읽고 이해한다.
2. 문제를 익숙한 용어로 재정의한다.
3. 어떻게 해결할지 계획을 세운다.
 wildcard가 있고 string이 주어지면
 그 string이 wildcard에 부합 여부 판단 함수!
    wildcard를 기준으로 하느냐?
        i == wildcard.size() 도달했을 때,
            if string[j]도 끝이면 true
            아니면 false
        wildcard[i]와 string[j]를 비교하면서
            w[i]가 문자면 string[j]와 같으면 compare(i+1, j+1);
            w[i]가 와일드카드면
                w[i] 가 ? 일때
                    string[j]는 무엇이든 상관없음 따라서 return compare(i+1, j+1)
                w[i] 가 * 일때//이게 어렵쥬
                    string[j]는 무엇이든 상관없고 또한 어느 길이던 상관없음.
                    고로 return compare(i+1, j+1) || compare(i, j+1)
    string을 기준으로 하느냐?
4. 계획을 검증한다.
5. 프로그램으로 구현한다.
6. 어떻게 풀었는지 돌아보고, 개선할 방법이 있는지 찾아본다.
 */
using namespace std;
string wild;
string str;

// i는 wildcard 의 색인
// j는 string 의 색인
bool myCompare(int i, int j) {
    if (i > wild.size() || j > str.size())
        return false;
    if (i == wild.size()) {
        return j == str.size();
    }
    if (j == str.size()) {
        return myCompare(i + 1, j);
    }
    // 위 세개를 그냥 i == wild.size() && j == str.size() 이렇게 해도 될까
    if (wild[i] == '*' || wild[i] == '?') {
        return wild[i] == '?' ? myCompare(i + 1, j + 1) : myCompare(i + 1, j + 1) || myCompare(i, j + 1);
    } else if (wild[i] == str[j]) {
        return myCompare(i + 1, j + 1);
    }
    return false;
}

int main() {
    int tc;
    cin >> tc;
    while (tc-- > 0) {
        cin >> wild;
        int strN;
        cin >> strN;
        for (int i = 0; i < strN; i++) {
            cin >> str;
            if (myCompare(0, 0))
                cout << str << endl;
        }
    }
}