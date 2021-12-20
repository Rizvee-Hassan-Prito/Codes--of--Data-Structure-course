#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -999999
#define INFINITY 999999
#define WHITE 1
#define GREY 2
#define BLACK 3


//****************Dynamic ArrayList class based************************
class ArrayList
{
	int * list;
	int length ;
	int listMaxSize ;
	int listInitSize ;
public:
	ArrayList() ;
	~ArrayList() ;
	int searchItem(int item) ;
    void insertItem(int item) ;
	void removeItem(int item) ;
	void removeItemAt(int item);
	int getItem(int position) ;
	int getLength();
	bool empty();
	void printList();
} ;


ArrayList::ArrayList()
{
	listInitSize = 2 ;
	listMaxSize = listInitSize ;
	list = new int[listMaxSize] ;
	length = 0 ;
}

void ArrayList::insertItem(int newitem)
{
	int * tempList ;
	if (length == listMaxSize)
	{
		//allocate new memory space for tempList
		listMaxSize = 2 * listMaxSize ;
		tempList = new int[listMaxSize] ;
		int i;
        for( i = 0; i < length ; i++ )
        {
            tempList[i] = list[i] ; //copy all items from list to tempList
        }
        delete[] list ; //free the memory allocated before
        list = tempList ; //make list to point to new memory
	};
	list[length] = newitem ; //store new item
	length++ ;
}

int ArrayList::searchItem(int item)
{
	int i = 0;
	for (i = 0; i < length; i++)
	{
		if( list[i] == item ) return i;
	}
	return NULL_VALUE;
}

void ArrayList::removeItemAt(int position) //do not preserve order of items
{
	if ( position < 0 || position >= length ) return ; //nothing to remove
	list[position] = list[length-1] ;
	length-- ;
}


void ArrayList::removeItem(int item)
{
	int position;
	position = searchItem(item) ;
	if ( position == NULL_VALUE ) return ; //nothing to remove
	removeItemAt(position) ;
}


int ArrayList::getItem(int position)
{
	if(position < 0 || position >= length) return NULL_VALUE ;
	return list[position] ;
}

int ArrayList::getLength()
{
	return length ;
}

bool ArrayList::empty()
{
    if(length==0)return true;
    else return false;
}

void ArrayList::printList()
{
    int i;
    for(i=0;i<length;i++)
        printf("%d ", list[i]);
    printf("Current size: %d, current length: %d\n", listMaxSize, length);
}

ArrayList::~ArrayList()
{
    if(list) delete [] list;
    list = 0 ;
}

//******************ArrayList class ends here*************************
class Queue
{
    int queueInitSize ;
    int queueMaxSize;
    int * data;
    int length;
    int front;
    int rear;
public:
    Queue();
    ~Queue();
    void enqueue(int item); //insert item in the queue
    int dequeue(); //returns the item according to FIFO
    bool empty(); //return true if Queue is empty
};

Queue::Queue()
{
    queueInitSize = 2 ;
    queueMaxSize = queueInitSize;
    data = new int[queueMaxSize] ; //allocate initial memory
    length = 0 ;
    front = 0;
    rear = 0;
}


void Queue::enqueue(int item)
{
	if (length == queueMaxSize)
	{
		int * tempData ;
		//allocate new memory space for tempList
		queueMaxSize = 2 * queueMaxSize ;
		tempData = new int[queueMaxSize] ;
		int i, j;
		j = 0;
		for( i = rear; i < length ; i++ )
		{
			tempData[j++] = data[i] ; //copy items from rear
		}
		for( i = 0; i < rear ; i++ )
		{
			tempData[j++] = data[i] ; //copy items before rear
		}
		rear = 0 ;
		front = length ;
		delete[] data ; //free the memory allocated before
		data = tempData ; //make list to point to new memory
	}

	data[front] = item ; //store new item
	front = (front + 1) % queueMaxSize ;
	length++ ;
}


bool Queue::empty()
{
	if(length == 0) return true ;
	else return false ;
}


int Queue::dequeue()
{
	if(length == 0) return NULL_VALUE ;
	int item = data[rear] ;
	rear = (rear + 1) % queueMaxSize ;
	length-- ;
	return item ;
}


Queue::~Queue()
{
    if(data) delete[] data; //deallocate memory
    data = 0; //set to NULL
}
//******************Graph class starts here**************************
class Graph
{
	int nVertices, nEdges ;
	bool directed ;
	ArrayList  * adjList ;
	int *color;
	int *parent;
	int *dist;
	int *hasVisited;
	Queue qe;
	//define other variables required for bfs such as color, parent, and dist
	//you must use pointers and dynamic allocation

public:
	Graph(bool dir = false);
	~Graph();
	void setnVertices(int n);
	void addEdge(int u, int v);
	void removeEdge(int u, int v);
	bool isEdge(int u, int v);
    int getDegree(int u);
    void printAdjVertices(int u);
    bool hasCommonAdjacent(int u, int v);
    void bfs(int source);
    int getDist(int u,int v);
    int findComponents();
    void dfsVisit(int u);
    void dfs(int source);
    void printGraph();
};


Graph::Graph(bool dir)
{
	nVertices = 0 ;
	nEdges = 0 ;
	adjList = 0 ;
	directed = dir ; //set direction of the graph
	//define other variables to be initialized
}

void Graph::setnVertices(int n)
{
	this->nVertices = n ;
	if(adjList!=0) delete[] adjList ; //delete previous list
	adjList = new ArrayList[nVertices] ;
    color = new int[nVertices];
    dist = new int[nVertices];
    parent = new int[nVertices];
}

void Graph::addEdge(int u, int v)
{
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    this->nEdges++ ;
	adjList[u].insertItem(v) ;
	if(!directed) adjList[v].insertItem(u) ;
}

void Graph::removeEdge(int u, int v)
{
    //removed the edge between u and v if such edge exists
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return; //vertex out of range
    if(adjList[u].searchItem(v)!=NULL_VALUE)
    {
    if(!directed)
      {
            adjList[u].removeItem(v);
            adjList[v].removeItem(u);
      }
      else{ adjList[u].removeItem(v);}
    }
    else{printf("\nItem is not in the list.\n");}
	this->nEdges-- ;
}

bool Graph::isEdge(int u, int v)
{
    //returns true if (u,v) is an edge, otherwise should return false
    if(u<0 || v<0 || u>=nVertices || v>=nVertices) return 0; //vertex out of range
    if(!directed)
    {
        if(adjList[u].searchItem(v)!=NULL_VALUE && adjList[v].searchItem(u)!=NULL_VALUE )
     {
            return 1;
     }
      else{return 0;}
    }
    else
    {
     if(adjList[u].searchItem(v)!=NULL_VALUE)
     {
            return 1;
     }
      else{return 0;}
    }
}

int Graph::getDegree(int u)
{
    //returns the degree of vertex u
    return adjList[u].getLength();
}

void Graph::printAdjVertices(int u)
{
     adjList[u].printList();
    //prints all adjacent vertices of a vertex u
}

bool Graph::hasCommonAdjacent(int u, int v)
{
    //returns true if vertices u and v have common adjacent vertices
    for(int i=0;i<nVertices;i++)
    {
    for(int j=0;j<nVertices;j++)
    {
     if(adjList[u].getItem(i)==adjList[v].getItem(j))
      {
         return 1;
      }
    }
    }
    return 0;

}


void Graph::printGraph()
{
    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
    for(int i=0;i<nVertices;i++)
    {
        printf("%d:", i);
        for(int j=0; j<adjList[i].getLength();j++)
        {
            printf(" %d", adjList[i].getItem(j));
        }
        printf("\n");
    }
}


Graph::~Graph()
{
    delete[] adjList;
    delete[] color;
    delete[] dist;
    delete[] parent;
    //write your destructor here
}

void Graph::bfs(int source)
{
    int i;
    for(i=0;i<nVertices;i++)
    {
        color[i]=WHITE;
        parent[i]=NULL_VALUE;
        dist[i]=INFINITY;
    }

    color[source]=GREY;
    dist[source]=0;
    parent[source]=NULL_VALUE;
    qe.enqueue(source);

    while(!qe.empty())
        {
        int u=qe.dequeue();
        for(i=0;i<adjList[u].getLength();i++)
            {
            int v=adjList[u].getItem(i);
            if(color[v]==WHITE)
            {
                color[v]=GREY;
                dist[v]=dist[u]+1;
                parent[v]=u;
                qe.enqueue(v);
            }
        }
        color[u]=BLACK;
    }
}

int Graph::getDist(int u,int v)
{
    bfs(u);
    return dist[v];
}

int Graph::findComponents()
{
    int i;
  for(i=0;i<nVertices;i++)
    {
        color[i]=WHITE;
    }
    int count=0;
    for(i=0;i<nVertices;i++){
        while(color[i]!=BLACK){
            bfs(i);
            count++;
        }
    }
    return count;
}

void Graph::dfsVisit(int u){
    color[u]=GREY;
    for(int i=0;i<adjList[u].getLength();i++)
    {
        int v=adjList[u].getItem(i);
        if(color[v]==WHITE)
        {
            dfsVisit(v);
        }
    }
    color[u]=BLACK;
}

void Graph::dfs(int source){
    for(int i=0;i<nVertices;i++)
    {
        color[i]=WHITE;
    }
    for(int i=0;i<nVertices;i++)
    {
        if(color[i]==WHITE)
        {
            dfsVisit(i);
        }
    }
}

//**********************Graph class ends here******************************


//******main function to test your code*************************
int main(void)
{
    int n;
    Graph g;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    g.setnVertices(n);

    while(1)
    {
        printf("1. Add edge. 2. Remove Edge 3.Check Edge\n");
        printf("4.Get Degree 5.Print Adjacent Vertices 6.Check Common Adjacent\n");
        printf("7. Print Graph 8. Exit. 9. Find components 10.Get distance\n");

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.addEdge(u, v);
        }
        else if(ch==2)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g.removeEdge(u,v);
        }
        else if(ch==3)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(g.isEdge(u,v)) printf("It's an Edge\n");
            else printf("Not an edge\n");
        }
        else if(ch==4)
        {
            int u;
            scanf("%d",&u);
            int degree = g.getDegree(u);
            printf("%d\n",degree);
        }
        else if(ch==5)
        {
            int u;
            scanf("%d",&u);
            g.printAdjVertices(u);
        }
        else if(ch==6)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            if(g.hasCommonAdjacent(u,v)) printf("They have common adjacent\n");
            else printf("They don't have common adjacent\n");
        }
        else if(ch==7)
        {
            g.printGraph();
        }
        else if(ch==8)
        {
            break;
        }
        else if(ch==9)
        {
            printf("%d\n",g.findComponents());
        }
        else
        {
            int u, v;
            scanf("%d%d", &u, &v);
            printf("%d\n",g.getDist(u,v));
        }
    }

}
