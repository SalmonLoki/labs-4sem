#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <climits>
#include <set>

using namespace std;
long long L =  LONG_LONG_MAX;

struct Edge {
    int destination ;
    int capacity ;
    long long residualFlow;
    int cost ;
    //Edge* counterEdge;
    int counterInt;

    Edge() {}
    Edge(int destination1, int capacity1,  long long residualFlow1, int cost1, int counterInt1) {
        destination = destination1;
        capacity = capacity1;
        residualFlow = residualFlow1;
        cost = cost1;
        counterInt = counterInt1;
    }
};


struct Graph {
    int  numVertices;
    vector<vector<Edge>> adj;
};

Graph g;
Graph resGraph;


typedef pair<long long, int> pairs;
/*bool BFD(Graph resGraph, int source, int sink, int* parentVertex, Edge* * parentEdge) {
    int numVertices = resGraph.numVertices;
    vector<Edge*> *adj = resGraph.adj;

    long long distance[numVertices];
    bool used [numVertices];
    for (int i = 0; i < numVertices; i++) {
        parentVertex[i] = -1;
        distance[i] = L;
        used[i] = false;
    }
    distance[source] = 0l;
    int index = 0, u = 0;
    for (int i = 0; i < numVertices; i++) {
        long long min = LONG_MAX;
        for (int j = 0; j < numVertices; j++) {
            if (!used[j] && ( distance[j] < min) ) {
                min = distance[j];
                index = j;
            }
        }
        u = index;
        used[u] = true;
        for(int j = 0;j < adj[u].size(); j++)
        {
            if (adj[u][j]->residualFlow > 0) {

                int to = adj[u][j]->destination;
                long len = adj[u][j]->cost;

                if (!used[to] && distance[u] != LONG_MAX && (distance[u] + len < distance[to])) {
                    distance[to] = distance[u] + len;
                    parentVertex[to] = u;
                    parentEdge[to] = adj[u][j];
                }
            }
        }
    }

    return parentVertex[sink] != -1;
}*/

/*
bool BFDSet(Graph resGraph, int source, int sink, int* parentVertex, int* parentEdge) {
    int numVertices = resGraph.numVertices;
    vector<vector<Edge>> adj = resGraph.adj;

    long long distance[numVertices];
    for (int i = 0; i < numVertices; i++) {
        parentVertex[i] = -1;
        distance[i] = L;
    }
    distance[source] = 0l;

    set <pairs> q;
    q.insert(* new pairs(distance[source], source));

    while (!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());

        for (int  j = 0; j < adj[v].size(); j++) {
            int to = adj[v][j].destination;
            long len = adj[v][j].cost;

            if (adj[v][j].residualFlow > 0) {
                if (distance[v] == LONG_MAX) { }
                else if (distance[to] > distance[v] + len) {
                    q.erase(* new pairs(distance[to], to));
                    distance[to] = distance[v] + len;
                    q.insert(* new pairs(distance[to], to));

                    parentVertex[to] = v;
                    parentEdge[to] = j;
                    //parentEdge[to] = adj[v][j];
                }
            }
        }
    }
    return parentVertex[sink] != -1;

}
*/

int *parentVertex;
int *parentEdge;
bool BF(int source, int sink) {
    int numVertices = resGraph.numVertices;
    //vector<vector<Edge>> adj = resGraph.adj;
    long long distance[numVertices];

    for (int i = 0; i < numVertices; i++) {
        parentVertex[i] = -1;
        distance[i] = L;
    }
    distance[source] = 0l;

    //M0 - вершины, расстояние до которых уже вычислено (но, возможно, не окончательно);
    //M1 - вершины, расстояние до которых вычисляется;
    //M2 - вершины, расстояние до которых ещё не вычислено
    bool M0[numVertices];
    bool M1[numVertices];
    deque<int> q;
    bool M2[numVertices];
    for (int i = 0; i < numVertices; i++) {
        M0[i] = false;
        M1[i] = false;
        M2[i] = true;
    }

    M2[0] = false;
    M1[0] = true;
    q.push_back(0);

    while (q.size() > 0) {
        //берём вершину из множества M1 (достаём верхний элемент из очереди). from q
        // Пусть V - это выбранная вершина. Переводим эту вершину во множество M0.
        int v = q.front();
        q.pop_front();
        M1[v] = false;
        M0[v] = true;

        // просматриваем все рёбра, выходящие из этой вершины.
        // Пусть T - это второй конец текущего ребра (т.е. не равный V), а w - это длина текущего ребра.
        for (int e = 0; e < resGraph.adj[v].size(); e++) {
            if (resGraph.adj[v][e].residualFlow > 0) {
                int t = resGraph.adj[v][e].destination;
                int w = resGraph.adj[v][e].cost;

                //Если T принадлежит M2, то T переносим во множество M1 в конец очереди. DT полагаем равным DV + w.
                if (M2[t]) {
                    M2[t] = false;
                    M1[t] = true;
                    q.push_back(t);

                    distance[t] = distance[v] + w;
                    parentVertex[t] = v;
                    parentEdge[t] = e;
                    //parentEdge[t] = adj[v][e];
                } else {
                    //Если T принадлежит M1, то пытаемся улучшить значение DT: DT = min (DT, DV + w).
                    // Сама вершина T никак не передвигается в очереди.
                    if (M1[t]) {
                        if (distance[v] == L) {}
                        else if (distance[t] > distance[v] + w) {
                            distance[t] = distance[v] + w;
                            parentVertex[t] = v;
                            //parentEdge[t] = adj[v][e];
                            parentEdge[t] = e;
                        }
                    }
                    //Если T принадлежит M0, и если DT можно улучшить (DT > DV + w), то улучшаем DT,
                    // а вершину T возвращаем в множество M1, помещая её в начало очереди.
                    if (M0[t]) {
                        if (distance[v] == L) {}
                        else if (distance[t] > distance[v] + w) {
                            distance[t] = distance[v] + w;
                            parentVertex[t] = v;
                            //parentEdge[t] = adj[v][e];
                            parentEdge[t] = e;

                            M0[t] = false;
                            M1[t] = true;
                            q.push_front(t);
                        }
                    }
                }
            }
        }
    }
    return parentVertex[sink] != -1;
}


long long calcMinCostFlow(int s, int t) {
    int v;
    long long runningCost = 0l;

    Edge *te1; Edge *te2;
    parentVertex = new int[g.numVertices];
    parentEdge = new int[g.numVertices];

    while (BF(s, t)) {
        long long path_flow = L;
        for (v = t; v != s; v = parentVertex[v]) {

            te1 = &resGraph.adj[parentVertex[v]][parentEdge[v]];
            path_flow = min(path_flow, te1->residualFlow);
        }

        for (v = t; v != s; v = parentVertex[v]) {

            te1 = &resGraph.adj[parentVertex[v]][parentEdge[v]];
            te2 = &resGraph.adj[v][te1->counterInt];
            te1->residualFlow -= path_flow;
            te2->residualFlow += path_flow;
            runningCost += path_flow * (te1->cost);
        }
    }
    return runningCost;
}

int n, m;
int from, to, cost;
int start; int finish;
int  arrNum;

//добавление ребра в графы для поиска MIN_COST_FLOW
void addEdge(int from,int destination, int capacity, int cost){
    //Edge*  tmpEdge1 = newEdge(destination, capacity, capacity, cost);
    Edge tmpEdge1 (destination, capacity, capacity, cost, (int) resGraph.adj[destination].size());

    //Edge*  tmpEdge2 = newEdge(from, capacity, 0, -1 * cost);
    Edge  tmpEdge2 (from, capacity, 0, -1 * cost, (int) resGraph.adj[from].size());

    //g.adj[from].push_back(tmpEdge1);

    resGraph.adj[from].push_back(tmpEdge1);
    resGraph.adj[destination].push_back(tmpEdge2);

    //tmpEdge1.counterInt = (int) resGraph.adj[destination].size() - 1;
    //tmpEdge2.counterInt = (int) resGraph.adj[from].size() - 1;
}

//разделение каждого ребра на 3 для циркуляции
void addEdgeCirc(int from, int to,int capacityMin, int cost){

    addEdge(start, to, capacityMin, 0);
    addEdge(from, to, INT_MAX, cost);
    addEdge(from, finish, capacityMin, 0);
}


int main() {
    std::ios::sync_with_stdio(false);
    scanf("%d%d",&n,&m); //n,m — количество городов и количество дорог
    int registrationCost[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &registrationCost[i]);

    arrNum = 2*n + 2;
    start = 0; finish = arrNum - 1;
    //графы для поиска MIN_COST_FLOW
    g.numVertices = arrNum;
    g.adj = vector<vector<Edge>>(g.numVertices, vector<Edge>(0));
    //g.adj = new vector<Edge*>[arrNum];

    resGraph.numVertices = arrNum;
    resGraph.adj = vector<vector<Edge>>(resGraph.numVertices, vector<Edge>(0));
    //resGraph.adj = new vector<Edge*>[arrNum];

    for (int i = 0; i < n; i++){
        //добавляем ребра из одной половины вершины другую: vfrom = i, vto = i + n (аналог посещения города)
        addEdgeCirc(i+1, i+n+1, 1, 0);

        //добавляем ребра из одной половины в другую из vto = i + n в vfrom=i (петли)
        addEdgeCirc(i+n+1, i+1, 0, registrationCost[i]);
    }

    //добавляем ребра-дороги из города u в город v со стоимостью проезда cost
    //u->v  =  u_to->v_from  =  u+n->v
    for (int i = 0; i < m; i++) {

        scanf("%d%d%d",&from,&to,&cost);
        addEdgeCirc(from+n, to, 0, cost);
    }
    //теперь у нас есть граф со стартом и финишем и одной пропускной способностью


    cout << calcMinCostFlow(start, finish) << "\n";
    return 0;
}
