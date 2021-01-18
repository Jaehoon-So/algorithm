#include <iostream>
#define MAX 999
using namespace std;
// #은 검은칸 .은 흰칸을 의미한다.
char board[MAX][MAX];
int white, black;
int h, w;
bool used[MAX][MAX];
void initialize(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            board[i][j] = '0';
            used[i][j] = false;
        }
    }
}
void printfMat(int h, int w){
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}
int boardCover(int i, int j){
    int ret = 0;
    if(i == h || j == w) return true;
    if(!used[i][j]){
        if(i+1 < h && j+1 < w && used[i+1][j] != true && used[i][j+1] != true){
            used[i+1][j] = true; used[i][j+1] = true;
            if(j == w-1 && i < h-1)
                ret += boardCover(i+1, 0);
            else ret +=boardCover(i, j+1);
        }
    }
    return ret;
}
int main(){
    int c;
    cin >> c;
    while(c--){
        white = 0; black = 0;
        cin >> h >> w;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                char color = getchar();
                if(color == '\n') {j--; continue;}
                board[i][j] = color;
                if(board[i][j] == '#') {black++; used[i][j] = true;}
                else white++;
            }
            if(white%3 != 0) cout << 0 << endl;
            else cout << boardCover(0, 0) << endl;
        }
        printfMat(h, w);
    }


    return 0;
}