#include <string>
#include <iostream>
using namespace std;
int pos[2];
int graph[2][11][10];

int solution(string dirs) {
    int answer = 0;
    for (int i = 0; i < dirs.length(); i++) {
        switch (dirs[i]) {
        case 'U':
            if (pos[1] < 5 && pos[1] >= -5) {
                graph[1][pos[0] + 5][4 - pos[1]]++;
                pos[1]++;
            }
            break;
        case 'D':
            if (pos[1] <= 5 && pos[1] > -5) {
                graph[1][pos[0] + 5][5 - pos[1]]++;
                pos[1]--;
            }
            break;
        case 'R':
            if (pos[0] < 5 && pos[0] >= -5) {
                graph[0][5 - pos[1]][pos[0] + 5]++;
                pos[0]++;
            }
            break;
        case 'L':
            if (pos[0] <= 5 && pos[0] > -5) {
                graph[0][5 - pos[1]][pos[0] + 4]++;
                pos[0]--;
            }
            break;
        }
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 11; j++) {
            for (int k = 0; k < 10; k++) {
                //cout << graph[i][j][k] << " ";
                if (graph[i][j][k] != 0)
                    answer++;
            }
            //cout << endl;
        }
        //cout << endl;
    }
    //cout<<pos[0]<<pos[1];
    return answer;
}