#include<stdio.h>
#include<stdlib.h>

int n;

// ++++++++++++++++++++++++++++
// queue for bfs
int queue[1000];
int front = -1, rear = -1;

void push(int num){
    if(front == -1 && rear == -1)
        front = 0;
    queue[++rear] = num;
}

int pop(){
    if(rear == -1 && front == -1)
        return;
    return queue[front++];
}

int isEmpty(){
    if(rear == -1 && front == -1)
        return 1;
   if(rear == front-1)
       return 1;
    return 0;
}
// ++++++++++++++++++++++++++++
void dfs(int mat[n][n], int visited[], int s){
    printf("%d ", s+1);
    visited[s] = 1;
    for(int i=0;i<n;i++){
        if(i != s && mat[s][i] == 1 && visited[i] == 0){
            dfs(mat, visited, i);
        }
    }
}


void bfs(int mat[n][n], int visited[], int s){
    push(s);
    // printf("pushed: %d \n", s+1);
    visited[s] = 1;
    int x;
    while(isEmpty() == 0){
        x = pop();
        // printf("popped: %d \n", x+1);
        printf("%d ", x+1);
        for(int i=0;i<n;i++){
            if(mat[x][i] == 1 && visited[i] == 0 && i!=x){
                visited[i] = 1;
                push(i);
                // printf("pushed: %d \n", i+1);
            }
        }
    }
}


int main(){
    int source;
    scanf("%d %d", &n, &source);
    source--;
    int mat[n][n];
    int visited[n];
    for(int i=0;i<n;i++){
        visited[i] = 0;
        for(int j=0;j<n;j++)
            scanf("%d", &mat[i][j]);
    }
    // dfs(mat, visited, source);
    bfs(mat, visited, source);
    return 0;
}

/*

input: 
4 2
1 0 1 1
0 1 0 1
1 0 1 0
1 1 0 1 

op: 
2 4 1 3

*/