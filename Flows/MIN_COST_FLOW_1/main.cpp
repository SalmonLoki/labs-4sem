#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;
 long long L =  LONG_LONG_MAX;

struct Edge {
    int destination ;
    int capacity ;
     long long residualFlow;
    int cost ;
    Edge* counterEdge;
};
struct Graph {
    int  numVertices;
    vector<Edge*> *adj;
};

Graph g;
Graph resGraph;

Edge*  newEdge(int destination, int capacity,  long long residualFlow, int cost) {
    Edge* e1 = new Edge;
    e1->destination = destination;
    e1->capacity = capacity;
    e1->residualFlow = residualFlow;
    e1->cost = cost;
    return e1;
}

bool BF(Graph resGraph, int source, int sink, int* parentVertex, Edge* * parentEdge) {
    int numVertices = resGraph.numVertices;
    vector<Edge*> *adj = resGraph.adj;
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
        for (int e = 0; e < adj[v].size(); e++) {
            if (adj[v][e]->residualFlow > 0) {
                int t = adj[v][e]->destination;
                int w = adj[v][e]->cost;

                //Если T принадлежит M2, то T переносим во множество M1 в конец очереди. DT полагаем равным DV + w.
                if (M2[t]) {
                    M2[t] = false;
                    M1[t] = true;
                    q.push_back(t);

                    distance[t] = distance[v] + w;
                    parentVertex[t] = v;
                    parentEdge[t] = adj[v][e];
                } else {
                    //Если T принадлежит M1, то пытаемся улучшить значение DT: DT = min (DT, DV + w).
                    // Сама вершина T никак не передвигается в очереди.
                    if (M1[t]) {
                        if (distance[v] == L) {}
                        else if (distance[t] > distance[v] + w) {
                            distance[t] = distance[v] + w;
                            parentVertex[t] = v;
                            parentEdge[t] = adj[v][e];
                        }
                    }
                    //Если T принадлежит M0, и если DT можно улучшить (DT > DV + w), то улучшаем DT,
                    // а вершину T возвращаем в множество M1, помещая её в начало очереди.
                    if (M0[t]) {
                        if (distance[v] == L) {}
                        else if (distance[t] > distance[v] + w) {
                            distance[t] = distance[v] + w;
                            parentVertex[t] = v;
                            parentEdge[t] = adj[v][e];

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

    Edge *te1, *te2;
    int parent[g.numVertices];
    Edge*  parentEdge[g.numVertices];
    while (BF(resGraph, s, t, parent, parentEdge)) {
         long long path_flow = L;
        for (v = t; v != s; v = parent[v]) {
            te1 = parentEdge[v];
            path_flow = min(path_flow, te1->residualFlow);
        }

        for (v = t; v != s; v = parent[v]) {
            te1 = parentEdge[v];
            te2 = te1->counterEdge;
            te1->residualFlow -= path_flow;
            te2->residualFlow += path_flow;
            runningCost += path_flow * (te1->cost);
        }
    }
    return runningCost;
}


int main() {
    int numVertices = 0, numEdges = 0;
    int tu = 0, tv = 0, tcap = 0, tcost = 0;

    ifstream fin;  fin.open("mincost.in");

    fin >> numVertices >> numEdges;
    g.numVertices = numVertices;
    g.adj = new vector<Edge *>[numVertices];
    resGraph.numVertices = numVertices;
    resGraph.adj = new vector<Edge*>[numVertices];

    for (int i = 0; i < numEdges; i++) {
        fin >> tu >> tv >> tcap >> tcost;
        tu--;
        tv--;

        Edge*  tmpEdge1 = newEdge(tv, tcap, tcap, tcost);
        Edge*  tmpEdge2 = newEdge(tu, tcap, 0, -1 * tcost);
        tmpEdge1->counterEdge = tmpEdge2;
        tmpEdge2->counterEdge = tmpEdge1;
        g.adj[tu].push_back(tmpEdge1);
        resGraph.adj[tu].push_back(tmpEdge1);
        resGraph.adj[tv].push_back(tmpEdge2);
    }

     long long mincost = calcMinCostFlow(0, numVertices - 1);
    ofstream fout; fout.open("mincost.out");
    fout << mincost << "\n";
    fin.close();
    fout.close();
    return 0;
}