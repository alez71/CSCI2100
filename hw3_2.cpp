#include "iostream"
#include "vector"
#include "iterator"
#include "algorithm"
using namespace std;


int main(){
    int size;
    cin >> size;
    int numquery;
    cin >> numquery;
    vector<int> cards;
    vector<int> position;
    vector<int> result;

    for(int i=0;i<size;i++){
        int temp;
        cin >> temp;
        if(find(cards.begin(), cards.end(), temp) == cards.end()){
            cards.push_back(temp);
            position.push_back(i+1);
        }
    }


    for(int i=0;i<numquery;i++){
        int query;
        cin >> query;

        vector<int>::iterator posptr = find(cards.begin(), cards.end(), query);
        int pos = distance(cards.begin(), posptr);

        result.push_back(position[pos]);
        for(int j=0;j<position.size();j++){
            if(position[j] < position[pos]){
                position[j]++;
            }
        }
        position[pos] = 1;
    }

    for(int i:result){
        cout << i << ' ';
    }

}