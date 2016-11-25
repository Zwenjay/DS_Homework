bool TopSort( LGraph Graph, Vertex TopOrder[] ){  
    int begin=0,end=0;  
    int i,k=0,c=0;  
    int q[MaxVertexNum];  
    int indegree[MaxVertexNum];  
    for(i=0;i<MaxVertexNum;i++)
        indegree[i]=0;  
    PtrToAdjVNode a;  
  
    for(i=0;i<Graph->Nv;i++) {
        a=Graph->G[i].FirstEdge;  
        while(a!=NULL){   
            indegree[a->AdjV]++;  
            a=a->Next;  
        }     
    }  
  
    for(i=0;i<Graph->Nv;i++)
        if(indegree[i]==0)  
            q[end++]=i;  

    while(begin!=end){ 
        TopOrder[k++]=q[begin++];   
        a=Graph->G[q[begin-1]].FirstEdge;  
        while(a!=NULL){  
            indegree[a->AdjV]--;  
            if(indegree[a->AdjV]==0)  
                q[end++]=a->AdjV;  
            a=a->Next;  
        }  
    }  
    if(Graph->Nv!=k)
        return false;  
    return true;  
}  
