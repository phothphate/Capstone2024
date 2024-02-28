#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// 맵의 크기 상수 정의
const int WIDTH = 10;
const int HEIGHT = 10;

// 팩맨 맵 클래스 정의
class PacmanMap {
private:
    vector<vector<char>> map; // 맵을 저장하는 2차원 벡터
    int pacmanX, pacmanY; // 팩맨의 좌표
    int fruitX, fruitY; // 과일(보너스)의 좌표

public:
    PacmanMap() {
        // 맵을 공백으로 초기화
        map.assign(HEIGHT, vector<char>(WIDTH, ' '));
    }

    void generateWalls() {
        // 외곽 벽 생성
        for (int i = 0; i < WIDTH; ++i) {
            map[0][i] = '#';
            map[HEIGHT - 1][i] = '#';
        }
        for (int i = 0; i < HEIGHT; ++i) {
            map[i][0] = '#';
            map[i][WIDTH - 1] = '#';
        }

        // 내부 벽 생성
        for (int i = 0; i < WIDTH * HEIGHT / 4; ++i) {
            int x = rand() % (WIDTH - 2) + 1;
            int y = rand() % (HEIGHT - 2) + 1;
            map[y][x] = '#';
        }
    }

    void placeEntities() {
        // 팩맨 위치 설정
        pacmanX = rand() % (WIDTH - 2) + 1;
        pacmanY = rand() % (HEIGHT - 2) + 1;
        map[pacmanY][pacmanX] = 'P';

        // 과일(보너스) 위치 설정
        fruitX = rand() % (WIDTH - 2) + 1;
        fruitY = rand() % (HEIGHT - 2) + 1;
        map[fruitY][fruitX] = 'F';
    }

    void printMap() {
        // 맵 출력
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                cout << map[i][j];
            }
            cout << endl;
        }
    }
};

int main() {
    srand(time(nullptr)); // 난수 생성기 초기화

    PacmanMap pacmanMap;
    pacmanMap.generateWalls();
    pacmanMap.placeEntities();
    pacmanMap.printMap();

   
}
