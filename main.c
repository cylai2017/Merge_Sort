
#include <stdio.h>
#include <mm_malloc.h>

int* Merge(int* Left_Array, int* Right_Array){
    int Left_Array_length = (sizeof(Left_Array)/sizeof(*Left_Array));
    int Right_Array_length = (sizeof(Right_Array)/sizeof(*Right_Array));
    int* Sorted_Array=(int *)malloc(sizeof(int)*(Left_Array_length+Right_Array_length));
    int Left_Index = 0, Right_Index = 0;
    
    for(int i = 0; i < Left_Array_length + Right_Array_length; i++){
        
        // Fill the Right_Array's data if Sorted_Array include all the data of Left_Array
        if(Left_Index == Left_Array_length)
            Sorted_Array[i] = Right_Array[Right_Index++];
        
        // Fill the Left_Array's data if Sorted_Array include all the data of Right_Array
        else if(Right_Index == Right_Array_length)
            Sorted_Array[i] = Left_Array[Left_Index++];
        
        // Fill the Left_Array's data if leftData < rightData
        else if(Left_Array[Left_Index] < Right_Array[Right_Index])
            Sorted_Array[i] = Left_Array[Left_Index++];
        
        // Fill the Right_Array's data if rightData < leftData
        else
            Sorted_Array[i] = Right_Array[Right_Index++];
    }
    return Sorted_Array;
}

int* Merge_Sort(int* array){
    int array_length = (sizeof(array)/sizeof(*array));
    if(array_length > 1) {    // If the size of array is larger than 1
        int middle = (int)(array_length/2);
        int tmp = 0;
        if(middle == 1){tmp = 1;}
        int* Left_Array=(int *)malloc(sizeof(int)*(middle-1+tmp));
        int* Right_Array=(int *)malloc(sizeof(int)*(array_length-middle));
        
        // Divide the array into Left_Array and Right_Array
        for(int i = 0; i < middle; i++)
            Left_Array[i] = array[i];
        for(int j = middle; j < array_length; j++)
            Right_Array[j-middle] = array[j];
        
        Left_Array = Merge_Sort(Left_Array);
        Right_Array = Merge_Sort(Right_Array);
        return Merge(Left_Array, Right_Array);
    }

    return array;    // If the size of array is only 1, return array directly
}

