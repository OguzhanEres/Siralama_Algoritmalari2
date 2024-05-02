#include <stdio.h>
#include <stdlib.h>

void heapify(int arr[],int n,int index){
    int left= 2*index+1;
    int right=2*index+2;
    int largest=index;
    if(left<n&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=index){
        int temp=arr[index];
        arr[index]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}

void build_heap(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}

void heap_sort(int arr[],int n){
    build_heap(arr,n);
    for(int i=n-1;i>0;i--){
        int temp=arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
        heapify(arr,i,0);
    }
}


void selection(int arr[],int n){
    int min;
    for(int i=0;i<n-1;i++){
        min=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}



void bubble_sort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if (arr[j]<arr[j-1]){
                int temp=arr[j];
                arr[j]=arr[j-1];
                arr[j-1]=temp;
            }
        }
    }
}

void merge(int arr[],int left,int middle,int right){
    int newsize1=middle-left+1;
    int newsize2=right-middle;
    int newarray1[newsize1];
    int newarray2[newsize2];

    for(int i=0;i<newsize1;i++){
        newarray1[i]=arr[left+i];
    }
    for(int i=0;i<newsize2;i++){
        newarray2[i]=arr[middle+i+1];
    }
    //sıralamak için kullanılan döngüler
    int i=0;
    int j=0;
    int main_i=left;
    while(i<newsize1&&j<newsize2){
        if(newarray1[i]<newarray2[j]){
            arr[main_i]=newarray1[i];
            i++;
        }
        else
        {
            arr[main_i]=newarray2[j];
            j++;
        }
        main_i++;
    }
    //bu döngüler sonunda dizi sıralandı ve birleştirilmesi lazım

    //birleşitirme kısmı
    while (i<newsize1){
        arr[main_i]=newarray1[i];
        i++;
        main_i++;
    }
    while (j<newsize2){
        arr[main_i]=newarray2[j];
        j++;
        main_i++;
    }
}

void merge_sort(int arr[],int left,int right){
    if(left<right){
        int middle=left+(right-left)/2;
        merge_sort(arr,left,middle);
        merge_sort(arr,middle+1,right);
        merge(arr,left,middle,right);
    }
}

void merge2(int arr[],int left,int middle,int right){
    int newsize1=middle-left+1;
    int newsize2=right-middle;
    int arr1[newsize1];
    int arr2[newsize2];

    for(int i=0;i<newsize1;i++){
        arr1[i]=arr[left+i];
    }

    for(int i=0;i<newsize2;i++){
        arr2[i]=arr[middle+i+1];
    }

    int i=0;
    int j=0;
    int main_i=left;

    while(i<newsize1&&j<newsize2){
        if(arr1[i]<=arr2[j]){
            arr[main_i]=arr1[i];
            i++;
        }
        else{
            arr[main_i]=arr2[j];
            j++;
        }
        main_i++;
    }

    //birleştirme
    while (i<newsize1){
        arr[main_i]=arr1[i];
        i++;
        main_i++;
    }
    while (j<newsize2){
        arr[main_i]=arr2[j];
        j++;
        main_i++;
    }
}
void merge_sort2(int arr[],int left,int right){
    if(left<right){
        int middle=left+(right-left)/2;
        merge_sort2(arr,left,middle);
        merge_sort2(arr,middle+1,right);
        merge2(arr,left,middle,right);
    }
}
void printer(int arr[],int size){
    printf("The sorted array is: \n");
    for(int i=0;i<size;i++){
        printf("%d  ",arr[i]);
    }
}



int main(){
    int arr[]={1,54,64,12,98,31,95,781,135};
    int size=sizeof(arr)/sizeof (arr[0]);
    /*heap_sort(arr,size);
    selection(arr,size);
    bubble_sort(arr,size);
    merge_sort(arr,0,8);*/
    merge_sort2(arr,0,8);
    printer(arr,size);
    return 0;
}