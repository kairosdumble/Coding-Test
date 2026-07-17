#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int k, int m, vector<int> score) {
    int result = 0; 
    
    sort(score.begin(), score.end(), greater<int>()); // 올림차순으로 정렬
    
    for(int i =1 ; i<=score.size()/m ; i++){ // 사과 m개가 든 상자별로 확인
        result += score[i*m-1]* m;              // 상자 1개 내부에서 최저값 * 사과 갯수
    }
    return result;
}