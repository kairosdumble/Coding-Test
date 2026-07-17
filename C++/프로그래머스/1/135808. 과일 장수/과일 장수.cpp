#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int result = 0; 
    
    sort(score.begin(), score.end(), greater<int>()); // 올림차순으로 정렬
    
    for(int i =0;i<score.size()/m;i++){ // 사과 m개가 든 상자별로 확인
        int min = k;                    // 현재의 최솟값 = 가능한 최댓값
        for(int j = 0 ; j < m ;j ++){   // 상자안에 존재하는 사과들 모두 조회
            if(min > score[i * m + j]) min = score[i*m +j];
        }
        result += min * m;              // 상자 1개 내부에서 최저값 * 사과 갯수
    }
    return result;
}