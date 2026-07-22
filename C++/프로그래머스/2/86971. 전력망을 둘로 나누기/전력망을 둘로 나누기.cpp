#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;
int cnt;
    
void dfs(int start, int except , vector<vector<int>> graph){
    if(graph[start].size() == 1 && graph[start][0] == except) return; // 상위 노드를 제외하고 갈 곳이 없다면 종료
    
    for(int i = 0 ; i < graph[start].size() ; i++){ // 하위노드 순회
        if(graph[start][i] == except) continue; // 상위 노드는 제외
        cnt++;
        dfs(graph[start][i],start,graph);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    // 그래프 생성
    vector<vector<int>> graph(n+1);
    for(int i = 0 ; i < wires.size(); i ++){
        graph[wires[i][0]].push_back(wires[i][1]);
        graph[wires[i][1]].push_back(wires[i][0]);
    }
    
    for(int i = 1 ; i <= n ; i++){    // 모든 노드를 탐색 (i : 선택된 노드)
        for(int k = 0; k < graph[i].size() ; k++){     // 하위 노드 탐색(graph[i] : 선택된 노드의 하위 노드)         
            cnt = 1;
            dfs(graph[i][k], i, graph);      // (시작노드, 예외 노드-상위노드) 
            int res_cnt = n - cnt;
            int gap = abs(cnt - res_cnt); // 두 송전탑의 갯수 차
            if (answer > gap){                 // 최소 갯수차 발견
               answer =  gap;
                cout << "cnt: " << cnt << " 끊긴 사이:"<< graph[i][k] <<"와 "<< i <<'\n';
                cout << "answer: "<<answer<<'\n';
            }
        }
    }
    return answer;
}