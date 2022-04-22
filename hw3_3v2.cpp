#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
#include "iterator"

using namespace std;

void insertintotree(vector<vector<int>> &treeofsuper, int currentsuper, int i, queue<vector<int>> &storeprevious){
    if(currentsuper == -1){
        treeofsuper.push_back(vector<int>(1,i));
    }else{
        for(int j=0;j<treeofsuper.size();j++){
            vector<int>::iterator it = find(treeofsuper[j].begin(), treeofsuper[j].end(), currentsuper); 
            if(it == treeofsuper[j].end()){
                //move to next iteration if elements is not here
                continue;
            }else{
                //if found at last element
                if(next(it) == treeofsuper[j].end()){
                    treeofsuper[j].push_back(i);
                    return;
                }else{
                    //if found in middle
                    //create new tree, copy content of previous node
                    vector<int> ntree(treeofsuper[j].begin(), it+1);
                    ntree.push_back(i);
                    treeofsuper.push_back(ntree);
                    return;
                }
            }
        }
        storeprevious.emplace(vector<int>{i, currentsuper});
    }
}


int main(){
    int numperson;
    cin >> numperson;

    vector<vector<int>> treeofsuper;
    queue<vector<int>> storeprevious;
    for(int i=0;i<numperson;i++){
        int currentsuper;
        cin >> currentsuper;
        if(currentsuper != -1){
            currentsuper--;
        }
        if(currentsuper < i){
            insertintotree(treeofsuper, currentsuper, i, storeprevious);
        }else{
            //queues vector of int, stores previous positon and previous super
            storeprevious.emplace(vector<int>{i, currentsuper});
        };
    }
    
        while(!empty(storeprevious)){
            insertintotree(treeofsuper, storeprevious.front()[1], storeprevious.front()[0], storeprevious);
            storeprevious.pop();
        }


    int result = 0;
    for(int i=0;i<treeofsuper.size();i++){
        if(treeofsuper[i].size() > result){
            result = treeofsuper[i].size();
        }
    }

    cout << result;
}