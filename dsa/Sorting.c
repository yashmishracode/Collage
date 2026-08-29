#include <stdio.h>
int  main(){
    int arr[100],n,i,j;
    printf("Enter no. of element ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("Enter Element %d of arr: ",i+1 );
        scanf("%d",&arr[i]);
    }

    // Sorting
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[i]){
                arr[i]=arr[i]+arr[j];
                arr[j]=arr[i]-arr[j];
                arr[i]=arr[i]-arr[j];;
            }
        }
    }
    printf("Sorted arr: ");
    for(i=0;i<n;i++){
        printf("\n%d",arr[i]);
    }
    return 0;
}