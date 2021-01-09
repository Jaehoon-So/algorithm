// 1 부터 n까지의 합을 계산하는 반복함수와 재귀함수.

#include <iostream>

using namespace std;

int sum(int n){
    int ret = 0;
    int i = n;
    for(int i = 1; i <= n; ++i){
        ret += i;
    }
    return ret;
}
int recursiveSum(int n){
    if(n == 1)  return 1; // 더이상 쪼개지지 않을 때
    return n + recursiveSum(n-1);

}
int main(void){
    int a, b;
    cin >> a >> b;

    cout << sum(a) << endl;
    cout << recursiveSum(b) << endl;

    return 0;
}