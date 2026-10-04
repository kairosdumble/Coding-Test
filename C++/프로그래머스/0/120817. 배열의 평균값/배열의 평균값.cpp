#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    float sum = 0.0;
    for(float i : numbers){
        sum += i;
    }
    return sum / (float)numbers.size();
}