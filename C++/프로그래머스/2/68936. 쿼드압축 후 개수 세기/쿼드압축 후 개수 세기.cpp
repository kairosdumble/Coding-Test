#include <string>
#include <vector>

using namespace std;
int zero_cnt = 0; 
int one_cnt = 0;

void split_square(vector<vector<int>> & arr, int start_r, int end_r, int start_c, int end_c){
    int zero = 0;
    int one = 0;
    
    // 모두 1인지 0인지 판단
    for(int c = start_c ; c<= end_c ; c++){
        for(int r = start_r ; r <= end_r ; r++){
            if(arr[c][r] == 0) zero ++;
            else {one++;}
        }        
    }
    
    //만약 모두 1이거나 0이면 압축
    int check = (end_r - start_r + 1) * (end_r - start_r + 1) ; 
    if(zero == check) {
        zero_cnt ++ ;
        return;
    } else if(one == check){
        one_cnt ++ ;
        return;
    } else{
        int mid_r = (start_r + end_r)/2;
        int mid_c = (start_c + end_c)/2;
        split_square(arr, start_r, mid_r, start_c, mid_c);
        split_square(arr, start_r, mid_r, mid_c + 1, end_c);
        split_square(arr, mid_r + 1, end_r, start_c, mid_c);
        split_square(arr, mid_r + 1, end_r, mid_c + 1, end_c); 
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;  
    split_square(arr, 0, arr.size()-1, 0, arr.size()-1); 
    return {zero_cnt, one_cnt};
}