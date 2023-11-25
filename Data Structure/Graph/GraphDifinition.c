#include<stdio.h>
#define MaxVertexNum 100
#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;
typedef char DataType;

typedef struct ENode *PtrToENode;
struct ENode{
    Vertex v1,v2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;//The number of the Vertexs;
    int Ne;//The number of the Edges;
    WeightType G[MaxVertexNum][MaxVertexNum];
    DataType Data[MaxVertexNum];
};
typedef PtrToGNode MGraph;

MGraph CreatGraph(int VertexNum){
    Vertex V,W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(MGraph));
    Graph->Nv=VertexNum;
    Graph->Ne=0;//initialization 0;

    for(V=0;V<Graph->Nv;V++){
        for(W=0;W<Graph->Nv;W++){
            Graph->G[V][W]=INFINITY;
        }
    }
    return Graph;
}

void InsertEdge(MGraph Graph,Edge E){
    Graph->G[E->v1][E->v2] = E->Weight;
    //For the directed Graph
    //Graph->G[E->v2][E->v1] = E->Weight;
    //For the undirected Graph  
}

MGraph BuildGraph(){
    MGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;
    scanf("%d",&Nv);
    Graph = CreatGraph(Nv);

    scanf("%d",&(Graph->Ne));
    if(Graph->Ne!=0){
        E=(Edge)malloc(sizeof(Edge));
        for(int i=0;i<Graph->Ne;i++){
            scanf("%d %d %d",&E->v1,&E->v2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }

    for(V=0;V<Graph->Nv;V++)
        scanf(" %c",&Graph->Data[V]);

    return Graph;
}