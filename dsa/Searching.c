#include<stdio.h>
int main(){
    int arr[100],search,i,n;
    printf("Enter the no of elemnet ");
    scanf("%d",&n);
    printf("Enter %d integer",n);
    for(i=0;i<n;i++){
        printf("\nEnter %d no. of arr",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter a no. to search");
    scanf("%d",&search);

    for(i=0;i<n;i++){
        if(arr[i]==search){
            printf("%d is present at %d position",search,i+1);
            break;
        }
    }
    if(i==n){
        printf("%d is not peresent in the array you entered",search);
    }
    
    return 0;
}