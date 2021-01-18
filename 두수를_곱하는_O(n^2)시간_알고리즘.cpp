#include <iostream>
#include <vector>
#include <cmath>

#define MAX 999

using namespace std;
vector<int> a(MAX, 0);
vector<int> b(MAX, 0);
int multiply[2][MAX];
void normalize(vector<int>& A){
    // 마지막자리에 한자리가 올림되면 숫자가 더해지므로 0을 push한다.
    A.push_back(0);
    // 자릿수 올림을 처리한다.
    for(int i = 0; i+1 < A.size(); ++i){
        if(A[i] < 0){
            // 카라츠바 알고리즘을 위한 음수처리.
            int borrow = (abs(A[i]) + 9) / 10;
            A[i+1] -= borrow;
            A[i] += borrow * 10;
        }
        else{
            A[i+1] += A[i] % 10;
            A[i] = A[i] / 10;
        }
    }
    while((A.size() > 1) && (A.back() == 0)) A.pop_back();
}
int main(){
    int decimal;
    cin >> decimal; //몇자릿수를 입력할 것인지 
    int num1, num2;
    int input = 2;
    while(input--){
        for(int i = 0; i < decimal; ++i){
            int n;
            scanf("%1d", &n);
            multiply[input][i] = n;
        }
    }
    doMultiply(vector)

}