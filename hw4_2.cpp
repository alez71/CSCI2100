#include "vector"
#include "iostream"
using namespace std;

int main(){
    int n;
    int m;
    cin >> n;
    cin >> m;
    vector<bool> cantbuild(n+1);
    for(int i;i<m;i++){
        int x,y;
        cin >> x;
        cin >> y;
        cantbuild[x] = cantbuild[y] = true;
    }
    
    int i = 1;
    while(cantbuild[i]){
        i++;
    }

    cout << n-1 << "\n";
    for(int j=1;j<n+1;j++){
        if(i != j){
            cout << i << ' ' << j << "\n";
        }
    }

}