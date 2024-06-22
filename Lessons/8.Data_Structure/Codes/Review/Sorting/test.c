void BubbleSort(int* arr, int size){
    for (int i=0;i<size;i++){
        int flag=0;
        for (int j=0;j<size-i;j++){
            if (arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag++;
            }
        }
        if(flag==0)
            break;
    }
}
