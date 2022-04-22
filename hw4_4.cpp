#include "iostream"
#include "vector"
#include "algorithm"
#include "iterator"

const int TOFRONT = 0;
const int TOBACK = -1;

using namespace std;

void appendtoresult(vector<int> &result, int location, int numofnode){
    if(location == TOFRONT){
        result.push_back(numofnode+1);
    }
    for(int i=1;i<numofnode+1;i++){
        result.push_back(i);
        if(i == location){
            result.push_back(numofnode+1);
        }
    }
    if(location == TOBACK){
        result.push_back(numofnode+1);
    }
}

int main(){

    int t;
    cin >> t;
    vector<vector<int>> result(t);
    for(int curtest=0;curtest<t;curtest++){
        int n;
        cin >> n;
        vector<int> nodein;
        vector<int> nodeout;
        nodein.clear();
        nodeout.clear();
        bool frontorback = false;
        for(int i=1;i<n+1;i++){
            int direction;
            cin >> direction;
            if(direction == 1 && i == 1){
                appendtoresult(result[curtest], TOFRONT, n);
                frontorback = true;
            }else if(direction == 0 && i == n && !frontorback){
                appendtoresult(result[curtest], TOBACK, n);
                frontorback = true;
            }

            if(direction == 0){
                nodein.push_back(i);
            }else{
                nodeout.push_back(i);
            }
        }

        if(!frontorback){
            int maxofout = *max_element(nodeout.begin(), nodeout.end());
            int minofin = *min_element(nodein.begin(), nodein.end());

            if(maxofout < minofin){
                cout << "-1\n";
                continue;
            }
        }

        pair<int,int> match = {0,0};
        for(int x:nodein){
            vector<int>::iterator it = find(nodeout.begin(), nodeout.end(), x+1);
            if(it != nodeout.end()){
                match = {x, *it};
                break;
            }
        }
        if(!frontorback){
            if(match != pair<int,int>{0,0}){
                appendtoresult(result[curtest], match.first, n);
            }else{
                cout << "-1";
            }
        }
    }
    
    for(auto x: result){
        for(auto y : x){
            cout << y << " ";
        }
        cout << "\n";
    }

}