#include "iostream"
#include "vector"
#include "queue"
#include "algorithm"
using namespace std;

vector<vector<pair<long long, long long>>> adjlist(100005);
vector<long long> cost(100005);
vector<long long> previous(100005);

void dijkstra(long long src, long long n){
    cost.clear();
    cost.resize(100005, LONG_LONG_MAX);
    cost[src] = 0;
    previous[src] = src;
    priority_queue<pair<long long, long long>> squeue;
    squeue.push({-cost[src], src});
    while(!squeue.empty()){
        long curnode = squeue.top().second;
        squeue.pop();

        for(auto x:adjlist[curnode]){
            if(cost[curnode] + x.first < cost[x.second]){
                cost[x.second] = cost[curnode] + x.first;
                previous[x.second] = curnode;
                squeue.push({-cost[x.second], x.second});
            }
        }
    }
}



int main(){
    long long n,m;
    cin >> n;
    cin >> m;

    for(long long i=0;i<m;i++){
        long long src;
        long long dest;
        long long weight;
        cin >> src;
        cin >> dest;
        cin >> weight;
        adjlist[src].push_back({weight, dest});
        adjlist[dest].push_back({weight, src});
    }

    dijkstra(1, n);

    if(previous[n] == 0){
        cout << "-1";
        adjlist.clear();
        previous.clear();
    }else{
        vector<long long> answer;
        long long curnode = n;
        while(curnode != 1){
            answer.push_back(curnode);
            curnode = previous[curnode];
        }
        answer.push_back(1);
        reverse(answer.begin(), answer.end());
        for(long long x:answer){
            cout << x << " ";
        }
    }
}