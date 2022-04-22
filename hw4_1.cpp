#include "iostream"
#include "vector"
using namespace std;

typedef struct{
    int nextnode;
    bool visited;
}node;

int main(){
    int n;
    int t;
    cin >> n;
    cin >> t;
    vector<node> graph(n+1);

    for(int i=1;i<n;i++){
        int next;
        cin >> next;
        node temp = {.nextnode = i+next, .visited = false};
        graph[i] = temp;
    }
    int curnode = 1;
    while(curnode != 0){
        graph[curnode].visited = true;
        curnode = graph[curnode].nextnode;
    }

    if(graph[t].visited){
        cout << "YES";
    }else{
        cout << "NO";
    }

}