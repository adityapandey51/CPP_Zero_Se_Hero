// check whether the element is present in the array or not

bool present_or_not(int arr[],int size,int element){
    for (int i=0;i<size;i++){
        if (arr[i]==element){
            return 1;
        }
    }
    return 0;
}
