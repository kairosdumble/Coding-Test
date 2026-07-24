#include <string>
#include <vector>
#include <iostream>

using namespace std;
int cnt;

int dfs(int limit,int curr,const vector<int> &num, const vector<vector<int>> & links){
    int left = links[curr][0];
    int right = links[curr][1];
    
    int left_val = (left != -1) ? dfs(limit, left, num, links) : 0;
    int right_val = (right != -1) ? dfs(limit, right, num, links) : 0;
    
    if(num[curr] + left_val+ right_val <= limit){ // 안끊음
        return num[curr] + left_val + right_val;
    }
    else if(num[curr] + min(left_val,right_val) <=limit){ // 하나만 끊음
        cnt ++;
        return num[curr] + min(left_val, right_val);
    }
    else{ // 둘다 끊음
        cnt +=2;
        return num[curr];
    }
}
bool canSplit(int k, int limit, int curr, const vector<int> & num, const vector<vector<int>> & links){
    cnt = 0;
    dfs(limit, curr, num,links);
    
    return cnt <= k - 1;
}
int solution(int k, vector<int> num, vector<vector<int>> links) {
    int answer = 0;
    int SIZE = num.size();
    
    // 한 그룹당 최대값/최솟값 설정
    int low = 0;
    int high = 0;
    
    for(int i =0;i<SIZE ; i ++){
        low = max(low, num[i]);
        high +=num[i];    
    }
    
    // 노드들의 부모 기억
    vector<int> parents (SIZE,-1);
    for ( int i = 0 ; i < links.size() ; i ++){
        if(links[i][0] != -1) parents[links[i][0]] = i;
        if(links[i][1] != -1) parents[links[i][1]] = i;
    }
    
    // 최상단 노드 번호 구하기
    int head;
    for(int i = 0 ; i <SIZE ; i ++){
        if(parents[i] == -1){
        head = i;
        break;
        }
    }
    
    
    // 이진 분할로 탐색
    while(low <=high){
        int mid = (high + low)/2;
        // 이진 분할로 그룹의 최대값의 제한이 mid값을 설정했을 때, k개 만큼 쪼개질 수 있으면  
        if(canSplit(k, mid, head,num,links)){
            answer = mid;
            high = mid -1;
        }else{
            low = mid +1;
        }
    }
    
    return answer;
}