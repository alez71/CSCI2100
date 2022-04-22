#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int main(){
    vector<int> person;
    vector<vector<int>> groups;
    int numperson;
    cin >> numperson;
    bool found = false;
    for(int i=0;i<numperson;i++){
        vector<int> supervisors(0);
        int temp;
        cin >> temp;
        if(temp != -1){
            temp--;
        }
        person.push_back(temp);
        int currsuper = person[i];
        supervisors.push_back(currsuper);
        while(currsuper != -1){
            currsuper = person[currsuper];
            supervisors.push_back(currsuper);
        }
        for(int j=0;j<groups.size();j++){

        }
        if(!found){
            groups.push_back(vector<int>(1, i));
        }

    }
    cout << groups.size();
}