#include "vector"
#include "iostream"
using namespace std;

int main(){
    int lenght;
    cin >> lenght;

    //array of nodes, which is stored as array of int
    //each nodes stores its parent, and then its children if any
    vector<vector<int>> node(lenght);
    //parent bit
    node[0].push_back(-1);
    //sticky bit, determines if it is once a parent
    node[0].push_back(0);
    for(int i=1;i<lenght;i++){
        int temp;
        cin >> temp;
        //add parent int and sticky bit
        node[i].push_back(temp-1);
        node[i].push_back(0);
        //add children to parent node
        node[temp-1].push_back(i);
        node[temp-1][1] = 1; // change sticky bit
        //once a children gets a children, it is not a leaf
        //thus need to remove from its parent
        int parentofparent = node[temp-1][0];
        if(parentofparent != -1){
            node[temp-1][0] = -1;
            node[parentofparent].pop_back();
        }
    }

    for(int i=lenght-1;i>=0;i--){
        //non leaf
        if(node[i][1] != 0){
            int size = node[i].size();
            //only 2 or less child
            if(node[i].size() < 5){
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";
    return 0;
}