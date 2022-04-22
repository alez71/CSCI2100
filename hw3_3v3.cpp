#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

vector<vector<int>> ppl(2000, vector<int>());
vector<bool> visited(2000, false);

void search(int &count, int location){
    if(visited[location]){
        return;
    }else{
        visited[location] = true;
        count++;
        for(int x:ppl[location]){
            search(count, x);
        }
    }
}



int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        if(temp != -1){
            ppl[i].push_back(temp-1);
        }
    }

    int result = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visited[j] = false;
        }
        int temp = 0;
        search(temp, i);
        if(temp > result){
            result = temp;
        }
    }

    cout << result;
}
