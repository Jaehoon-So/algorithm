#include <iostream>
#define MAX 
using namespace std;
bool areFriends[10][10];
bool taken[10]; // taken[i] -> i번째 학생이 짝을 찾았으면 true 아니면 false.
int n, m;

void initialize(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            areFriends[i][j] = 0;
            taken[i] = false;
        }
    }
}
int countPairing(bool taken[10]){
    int firstFree = -1;
    for(int i = 0; i < n; i++){
        if(!taken[i]){
            firstFree = i;
            break;
        }
    }
    // 기저사례 더이상 짝을 맺을 수 없다는 것은 모든학생이 짝을
    // 맺었다는 것이므로 종료한다.
    if(firstFree == -1) return true;
    int ret = 0;
    for(int pairWith = firstFree + 1; pairWith < n; pairWith++){
        // 만약 pairWith 번째 학생이 짝을 찾지 않고 firstFree 번째와
        // PairWith 번째 친구가 서로 친구라면 함수를 재귀호출해준다.
        if(!taken[pairWith] && areFriends[firstFree][pairWith]){
            taken[pairWith] = taken[firstFree] = true;
            ret += countPairing(taken);
            taken[pairWith] = taken[firstFree] = false;
        }
    }
    return ret;
}
void printMat(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << areFriends[i][j] << " ";
        }
        cout << endl;
    }
}
int main(){
    int c;
    cin >> c;
    while(c--){
        cin >> n >> m;
        initialize();
        for(int i = 0; i < m; i++){
            int start, end;
            cin >> start >> end;
            areFriends[start][end] = areFriends[end][start] = true;  
        }
        //printMat();
        cout << countPairing(taken) << endl;
    }
    return 0;
}