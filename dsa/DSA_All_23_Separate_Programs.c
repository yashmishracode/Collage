/*
DATA STRUCTURES AND ALGORITHMS - PRACTICAL RECORD
Contains all 23 experiments from the supplied index.

IMPORTANT:
- Each numbered section is a SEPARATE C PROGRAM.
- Each section has its own main() function.
- Before compiling, copy only the required section into a separate .c file.
- Do not compile this entire combined file as one program because it contains
  multiple main() functions.
- Graph programs use vertices numbered from 0.
*/

/* 1. SUM OF ARRAY ELEMENTS */
#include <stdio.h>
int main(void) {
    int a[100], n, i, sum = 0;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) { scanf("%d", &a[i]); sum += a[i]; }
    printf("Sum = %d\n", sum);
    return 0;
}

/* 2. INSERTING ELEMENT IN ARRAY */
#include <stdio.h>
int main(void) {
    int a[100], n, i, pos, value;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter position and value: "); scanf("%d%d", &pos, &value);
    if (pos < 1 || pos > n + 1 || n >= 100) { printf("Invalid position/size\n"); return 0; }
    for (i = n; i >= pos; i--) a[i] = a[i - 1];
    a[pos - 1] = value; n++;
    printf("Array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

/* 3. DELETION OF ELEMENT IN ARRAY */
#include <stdio.h>
int main(void) {
    int a[100], n, i, pos;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter position to delete: "); scanf("%d", &pos);
    if (pos < 1 || pos > n) { printf("Invalid position\n"); return 0; }
    for (i = pos - 1; i < n - 1; i++) a[i] = a[i + 1];
    n--;
    printf("Array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

/* 4. SEARCHING IN ARRAY (LINEAR SEARCH) */
#include <stdio.h>
int main(void) {
    int a[100], n, i, key, found = 0;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    printf("Enter element to search: "); scanf("%d", &key);
    for (i = 0; i < n; i++)
        if (a[i] == key) { printf("Found at position %d\n", i + 1); found = 1; }
    if (!found) printf("Element not found\n");
    return 0;
}

/* 5. SORTING IN ARRAY (BUBBLE SORT) */
#include <stdio.h>
int main(void) {
    int a[100], n, i, j, t;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (i = 0; i < n; i++) scanf("%d", &a[i]);
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) { t = a[j]; a[j] = a[j + 1]; a[j + 1] = t; }
    printf("Sorted array: ");
    for (i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}

/* 6. ADDITION, SUBTRACTION AND MULTIPLICATION OF MATRICES */
#include <stdio.h>
int main(void) {
    int a[10][10], b[10][10], c[10][10], r1, c1, r2, c2, i, j, k, ch;
    printf("Enter rows and columns of A: "); scanf("%d%d", &r1, &c1);
    printf("Enter rows and columns of B: "); scanf("%d%d", &r2, &c2);
    printf("Enter matrix A:\n");
    for (i=0;i<r1;i++) for(j=0;j<c1;j++) scanf("%d",&a[i][j]);
    printf("Enter matrix B:\n");
    for (i=0;i<r2;i++) for(j=0;j<c2;j++) scanf("%d",&b[i][j]);
    printf("1.Add 2.Subtract 3.Multiply: "); scanf("%d",&ch);
    if ((ch==1 || ch==2) && (r1!=r2 || c1!=c2)) { printf("Dimensions must match\n"); return 0; }
    if (ch==3 && c1!=r2) { printf("A columns must equal B rows\n"); return 0; }
    if (ch==1 || ch==2) {
        for(i=0;i<r1;i++) for(j=0;j<c1;j++) c[i][j]=(ch==1)?a[i][j]+b[i][j]:a[i][j]-b[i][j];
        for(i=0;i<r1;i++){ for(j=0;j<c1;j++) printf("%d ",c[i][j]); printf("\n"); }
    } else if(ch==3) {
        for(i=0;i<r1;i++) for(j=0;j<c2;j++){ c[i][j]=0; for(k=0;k<c1;k++) c[i][j]+=a[i][k]*b[k][j]; }
        for(i=0;i<r1;i++){ for(j=0;j<c2;j++) printf("%d ",c[i][j]); printf("\n"); }
    } else printf("Invalid choice\n");
    return 0;
}

/* 7. POINTERS IN ARRAY */
#include <stdio.h>
int main(void) {
    int a[100], n, i, *p;
    printf("Enter number of elements: "); scanf("%d", &n);
    printf("Enter elements: ");
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    p=a;
    printf("Elements using pointer: ");
    for (i=0;i<n;i++) printf("%d ",*(p+i));
    return 0;
}

/* 8. STRUCTURE AND DISPLAY STUDENT INFORMATION */
#include <stdio.h>
struct Student { int roll; char name[50]; float marks; };
int main(void) {
    struct Student s;
    printf("Enter roll number: "); scanf("%d",&s.roll);
    printf("Enter name: "); scanf(" %49[^\n]",s.name);
    printf("Enter marks: "); scanf("%f",&s.marks);
    printf("\nStudent Details\nRoll: %d\nName: %s\nMarks: %.2f\n",s.roll,s.name,s.marks);
    return 0;
}

/* 9. STACK USING ARRAY */
#include <stdio.h>
#define MAX 5
int main(void) {
    int s[MAX], top=-1, ch, x, i;
    do {
        printf("\n1.Push 2.Pop 3.Display 0.Exit: "); scanf("%d",&ch);
        if(ch==1) { if(top==MAX-1) printf("Stack Overflow\n"); else { printf("Value: "); scanf("%d",&x); s[++top]=x; } }
        else if(ch==2) { if(top==-1) printf("Stack Underflow\n"); else printf("Popped: %d\n",s[top--]); }
        else if(ch==3) { if(top==-1) printf("Stack is empty\n"); else { for(i=top;i>=0;i--) printf("%d ",s[i]); printf("\n"); } }
    } while(ch!=0);
    return 0;
}

/* 10. QUEUE USING ARRAY */
#include <stdio.h>
#define MAX 5
int main(void) {
    int q[MAX], front=0, rear=-1, ch, x, i;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit: "); scanf("%d",&ch);
        if(ch==1) { if(rear==MAX-1) printf("Queue is full\n"); else { printf("Value: "); scanf("%d",&x); q[++rear]=x; } }
        else if(ch==2) { if(front>rear) printf("Queue is empty\n"); else { printf("Deleted: %d\n",q[front++]); if(front>rear){front=0;rear=-1;} } }
        else if(ch==3) { if(front>rear) printf("Queue is empty\n"); else { for(i=front;i<=rear;i++) printf("%d ",q[i]); printf("\n"); } }
    } while(ch!=0);
    return 0;
}

/* 11. INFIX TO POSTFIX CONVERSION (SINGLE-CHARACTER OPERANDS) */
#include <stdio.h>
#include <ctype.h>
char st[100]; int top=-1;
int prec(char c){ if(c=='^')return 3; if(c=='*'||c=='/'||c=='%')return 2; if(c=='+'||c=='-')return 1; return 0; }
int main(void) {
    char in[100], out[100], c; int i,k=0;
    printf("Enter infix expression: "); scanf("%99s",in);
    for(i=0;in[i];i++){
        c=in[i];
        if(isalnum((unsigned char)c)) out[k++]=c;
        else if(c=='(') st[++top]=c;
        else if(c==')'){ while(top>=0&&st[top]!='(') out[k++]=st[top--]; if(top>=0)top--; }
        else {
            while(top>=0&&st[top]!='('&&(prec(st[top])>prec(c)||(prec(st[top])==prec(c)&&c!='^'))) out[k++]=st[top--];
            st[++top]=c;
        }
    }
    while(top>=0) out[k++]=st[top--];
    out[k]='\0'; printf("Postfix: %s\n",out);
    return 0;
}

/* 12. CIRCULAR QUEUE */
#include <stdio.h>
#define MAX 5
int main(void) {
    int q[MAX], front=-1, rear=-1, ch, x, i;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 0.Exit: "); scanf("%d",&ch);
        if(ch==1) {
            if((rear+1)%MAX==front) printf("Circular queue is full\n");
            else { printf("Value: "); scanf("%d",&x); if(front==-1)front=0; rear=(rear+1)%MAX; q[rear]=x; }
        } else if(ch==2) {
            if(front==-1) printf("Queue is empty\n");
            else { printf("Deleted: %d\n",q[front]); if(front==rear)front=rear=-1; else front=(front+1)%MAX; }
        } else if(ch==3) {
            if(front==-1) printf("Queue is empty\n");
            else { i=front; while(1){printf("%d ",q[i]); if(i==rear)break; i=(i+1)%MAX;} printf("\n"); }
        }
    } while(ch!=0);
    return 0;
}

/* 13. SINGLY LINKED LIST */
#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *next; };
int main(void) {
    struct Node *head=NULL,*p,*n,*prev; int ch,x;
    do {
        printf("\n1.Insert at end 2.Delete value 3.Display 0.Exit: "); scanf("%d",&ch);
        if(ch==1) {
            n=(struct Node*)malloc(sizeof(struct Node)); if(!n){printf("Memory error\n");continue;}
            printf("Value: "); scanf("%d",&n->data); n->next=NULL;
            if(!head)head=n; else {p=head;while(p->next)p=p->next;p->next=n;}
        } else if(ch==2) {
            printf("Value to delete: "); scanf("%d",&x); p=head;prev=NULL;
            while(p&&p->data!=x){prev=p;p=p->next;}
            if(!p)printf("Not found\n"); else {if(prev)prev->next=p->next;else head=p->next;free(p);printf("Deleted\n");}
        } else if(ch==3) {
            p=head;while(p){printf("%d -> ",p->data);p=p->next;}printf("NULL\n");
        }
    } while(ch!=0);
    while(head){p=head;head=head->next;free(p);}
    return 0;
}

/* 14. BINARY SEARCH (ARRAY MUST BE SORTED) */
#include <stdio.h>
int main(void) {
    int a[100],n,i,key,low,high,mid;
    printf("Enter number of elements: "); scanf("%d",&n);
    printf("Enter sorted elements: "); for(i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Enter key: "); scanf("%d",&key);
    low=0;high=n-1;
    while(low<=high){mid=(low+high)/2;if(a[mid]==key)break;else if(a[mid]<key)low=mid+1;else high=mid-1;}
    if(low<=high)printf("Found at position %d\n",mid+1);else printf("Not found\n");
    return 0;
}

/* 15. BREADTH FIRST SEARCH (BFS) */
#include <stdio.h>
int main(void) {
    int a[20][20], visited[20]={0}, q[20], n, start, i, j, front=0, rear=0, v;
    printf("Enter number of vertices: "); scanf("%d",&n);
    printf("Enter adjacency matrix:\n");
    for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    printf("Enter starting vertex (0 to %d): ",n-1); scanf("%d",&start);
    if(start<0||start>=n)return 0;
    visited[start]=1;q[rear++]=start;
    printf("BFS: ");
    while(front<rear){v=q[front++];printf("%d ",v);for(i=0;i<n;i++)if(a[v][i]&&!visited[i]){visited[i]=1;q[rear++]=i;}}
    printf("\n"); return 0;
}

/* 16. DOUBLY LINKED LIST */
#include <stdio.h>
#include <stdlib.h>
struct Node { int data; struct Node *prev,*next; };
int main(void) {
    struct Node *head=NULL,*tail=NULL,*p,*n; int ch,x;
    do {
        printf("\n1.Insert end 2.Delete value 3.Display forward 0.Exit: "); scanf("%d",&ch);
        if(ch==1){n=(struct Node*)malloc(sizeof(struct Node));if(!n)continue;printf("Value: ");scanf("%d",&x);n->data=x;n->next=NULL;n->prev=tail;if(tail)tail->next=n;else head=n;tail=n;}
        else if(ch==2){printf("Value to delete: ");scanf("%d",&x);p=head;while(p&&p->data!=x)p=p->next;if(!p)printf("Not found\n");else{if(p->prev)p->prev->next=p->next;else head=p->next;if(p->next)p->next->prev=p->prev;else tail=p->prev;free(p);printf("Deleted\n");}}
        else if(ch==3){p=head;while(p){printf("%d <-> ",p->data);p=p->next;}printf("NULL\n");}
    }while(ch!=0);
    while(head){p=head;head=head->next;free(p);}
    return 0;
}

/* 17. DEPTH FIRST SEARCH (DFS) */
#include <stdio.h>
void dfs(int v,int n,int a[20][20],int visited[20]){
    int i; visited[v]=1; printf("%d ",v);
    for(i=0;i<n;i++) if(a[v][i]&&!visited[i]) dfs(i,n,a,visited);
}
int main(void) {
    int a[20][20],visited[20]={0},n,i,j,start;
    printf("Enter number of vertices: ");scanf("%d",&n);
    printf("Enter adjacency matrix:\n");for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    printf("Enter starting vertex: ");scanf("%d",&start);
    if(start>=0&&start<n){printf("DFS: ");dfs(start,n,a,visited);printf("\n");}
    return 0;
}

/* 18. SELECTION SORT AND BUBBLE SORT */
#include <stdio.h>
int main(void) {
    int a[100],b[100],n,i,j,min,t,ch;
    printf("Enter number of elements: ");scanf("%d",&n);
    printf("Enter elements: ");for(i=0;i<n;i++){scanf("%d",&a[i]);b[i]=a[i];}
    printf("1.Selection sort 2.Bubble sort: ");scanf("%d",&ch);
    if(ch==1){
        for(i=0;i<n-1;i++){min=i;for(j=i+1;j<n;j++)if(a[j]<a[min])min=j;t=a[i];a[i]=a[min];a[min]=t;}
    } else if(ch==2){
        for(i=0;i<n-1;i++)for(j=0;j<n-i-1;j++)if(b[j]>b[j+1]){t=b[j];b[j]=b[j+1];b[j+1]=t;}
    } else {printf("Invalid choice\n");return 0;}
    printf("Sorted array: ");for(i=0;i<n;i++)printf("%d ",ch==1?a[i]:b[i]);
    return 0;
}

/* 19. STRING MATCHING (NAIVE PATTERN MATCHING) */
#include <stdio.h>
#include <string.h>
int main(void) {
    char text[200],pat[100]; int i,j,n,m,found=0;
    printf("Enter text: ");scanf(" %199[^\n]",text);
    printf("Enter pattern: ");scanf(" %99[^\n]",pat);
    n=strlen(text);m=strlen(pat);
    for(i=0;i<=n-m;i++){for(j=0;j<m&&text[i+j]==pat[j];j++);if(j==m){printf("Pattern found at position %d\n",i+1);found=1;}}
    if(!found)printf("Pattern not found\n");
    return 0;
}

/* 20. MERGE SORT */
#include <stdio.h>
void merge(int a[],int l,int m,int r){
    int t[100],i=l,j=m+1,k=0,x;
    while(i<=m&&j<=r)t[k++]=(a[i]<=a[j])?a[i++]:a[j++];
    while(i<=m)t[k++]=a[i++];
    while(j<=r)t[k++]=a[j++];
    for(x=0;x<k;x++)a[l+x]=t[x];
}
void mergeSort(int a[],int l,int r){int m;if(l<r){m=(l+r)/2;mergeSort(a,l,m);mergeSort(a,m+1,r);merge(a,l,m,r);}}
int main(void){
    int a[100],n,i;printf("Enter number of elements: ");scanf("%d",&n);
    printf("Enter elements: ");for(i=0;i<n;i++)scanf("%d",&a[i]);
    mergeSort(a,0,n-1);printf("Sorted array: ");for(i=0;i<n;i++)printf("%d ",a[i]);return 0;
}

/* 21. PRIM'S ALGORITHM (MINIMUM SPANNING TREE) */
#include <stdio.h>
#define INF 99999
int main(void) {
    int a[20][20],vis[20]={0},n,i,j,k,u=-1,v=-1,min,cost=0;
    printf("Enter number of vertices: ");scanf("%d",&n);
    printf("Enter adjacency matrix (0 means no edge):\n");
    for(i=0;i<n;i++)for(j=0;j<n;j++){scanf("%d",&a[i][j]);if(i!=j&&a[i][j]==0)a[i][j]=INF;}
    vis[0]=1;printf("MST edges:\n");
    for(k=0;k<n-1;k++){min=INF;u=-1;
        for(i=0;i<n;i++)if(vis[i])for(j=0;j<n;j++)if(!vis[j]&&a[i][j]<min){min=a[i][j];u=i;v=j;}
        if(u==-1){printf("Graph is disconnected\n");return 0;}
        printf("%d - %d : %d\n",u,v,min);vis[v]=1;cost+=min;
    }
    printf("Total cost = %d\n",cost);return 0;
}

/* 22. KRUSKAL'S ALGORITHM (MINIMUM SPANNING TREE) */
#include <stdio.h>
struct Edge { int u,v,w; };
int parent[20];
int find(int x){while(parent[x]!=x){parent[x]=parent[parent[x]];x=parent[x];}return x;}
int main(void) {
    struct Edge e[100],t;int n,m,i,j,a,b,cost=0,count=0;
    printf("Enter vertices and edges: ");scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){printf("Enter edge (u v weight): ");scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);}
    for(i=0;i<n;i++)parent[i]=i;
    for(i=0;i<m-1;i++)for(j=0;j<m-i-1;j++)if(e[j].w>e[j+1].w){t=e[j];e[j]=e[j+1];e[j+1]=t;}
    printf("MST edges:\n");
    for(i=0;i<m&&count<n-1;i++){a=find(e[i].u);b=find(e[i].v);if(a!=b){printf("%d - %d : %d\n",e[i].u,e[i].v,e[i].w);parent[a]=b;cost+=e[i].w;count++;}}
    if(count!=n-1)printf("Graph is disconnected\n");else printf("Total cost = %d\n",cost);
    return 0;
}

/* 23. DIJKSTRA'S ALGORITHM (NON-NEGATIVE EDGE WEIGHTS) */
#include <stdio.h>
#define INF 99999
int main(void) {
    int a[20][20],d[20],vis[20]={0},n,src,i,j,u,min;
    printf("Enter number of vertices: ");scanf("%d",&n);
    printf("Enter adjacency matrix (0 means no edge):\n");
    for(i=0;i<n;i++)for(j=0;j<n;j++){scanf("%d",&a[i][j]);if(i!=j&&a[i][j]==0)a[i][j]=INF;}
    printf("Enter source vertex: ");scanf("%d",&src);
    for(i=0;i<n;i++)d[i]=INF;d[src]=0;
    for(i=0;i<n;i++){
        min=INF;u=-1;
        for(j=0;j<n;j++)if(!vis[j]&&d[j]<min){min=d[j];u=j;}
        if(u==-1)break;vis[u]=1;
        for(j=0;j<n;j++)if(!vis[j]&&a[u][j]!=INF&&d[u]+a[u][j]<d[j])d[j]=d[u]+a[u][j];
    }
    printf("Shortest distances from %d:\n",src);
    for(i=0;i<n;i++)if(d[i]==INF)printf("%d : Not reachable\n",i);else printf("%d : %d\n",i,d[i]);
    return 0;
}
