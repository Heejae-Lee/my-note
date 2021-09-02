#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int memo[500][500];
    int lastIndex = triangle.size() - 1;

    // memoization을 위한 공간 init
    for (int i = 0; i <= lastIndex; i++)
        for (int j = 0; j <= lastIndex; j++)
            memo[i][j] = 0;

    // 첫 라인 init
    memo[0][0] = triangle[0][0];
    for (int i = 0; i < lastIndex; i++) {
        for (int j = 0; j <= i; j++) {
            // 좌
            int tmp = memo[i][j] + triangle[i + 1][j];
            memo[i + 1][j] = tmp > memo[i + 1][j] ? tmp : memo[i + 1][j];

            // 우
            tmp = memo[i][j] + triangle[i + 1][j + 1];
            memo[i + 1][j + 1] = tmp > memo[i + 1][j + 1] ? tmp : memo[i + 1][j + 1];
        }
    }

    // 마지막 라인에서 가장 큰 수를 찾아냄
    for (int i = 0; i <= lastIndex; i++) {
        answer = memo[lastIndex][i] > answer ? memo[lastIndex][i] : answer;
    }
    return answer;
}