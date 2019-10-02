#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"
long *Load_File(char *Filename, int *Size){
    FILE *file_ptr = fopen(Filename, "r");
    fscanf(file_ptr,"%d", Size);
    long *file_array = malloc(sizeof(long) *  (*Size) );
    int i;
    //Reading File
    for (i = 0;i<*Size;i++){
        fscanf(file_ptr,"%ld\n", file_array + i);
    }

    fclose(file_ptr);

    return file_array;
}


int Save_File(char *Filename, long *Array, int Size){
    FILE *file_ptr = fopen(Filename, "w");
    int num_written = fprintf(file_ptr,"%d\n",Size);
    //Write to Array
    int i;
    num_written = 0;
    for (i = 0;i<Size;i++){
        fprintf(file_ptr,"%ld\n", Array[i]);
        num_written++;
    }

    fclose(file_ptr);

    return num_written;
}








void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move){
    int seq_size;
    long *sequence = malloc((sizeof(long)) * Size);

    sequence[0] = 1;
    int p2 = 0;
    int p3 = 0;

    int i = 1;
    long u2 = 0;
    long u3 = 0;
    while (sequence[i-1]<Size){
        if (sequence[p2]*2 == sequence[i-1]){
            ++p2;
        }
        if (sequence[p3]*3 == sequence[i-1]){
            ++p3;
        }
        u2 = sequence[p2] *2;
        u3 = sequence[p3] *3;
        if(u2<u3){
            ++p2;
            sequence[i]=u2;
        }
        else{
            ++p3;
            sequence[i]=u3;
        }
        i++;
    }

    seq_size=i-1;



    long temp_r = 0;
    int current_k = 0;
    int k;
    int j;
    for (k = (seq_size - 1); k >= 0; --k) //for each k (in descending order)
    {
        current_k = sequence[k];
        for (j = current_k; j <= (Size - 1); ++j) //for j ← k to n-1
        {
        temp_r = Array[j];
        i = j;
        ++(*N_Move);
        ++(*N_Comp);
        while((i>=current_k) && (Array[i - current_k] > temp_r))
        {
            Array[i] = Array[i - current_k];
            i = i - current_k;
            ++(*N_Comp);
            ++(*N_Move);
        }
        Array[i] = temp_r;
        ++(*N_Move);
        }
    }
    free(sequence);
    return;

}


void Improved_Bubble_Sort(long *Array, int Size, double *N_Comp, double *N_Move){
    int seq_size;
    long * sequence = malloc(sizeof(long)*Size);
    int temp = Size;
    int i = 0;
    while (temp>1){
        temp/=1.3;
        if(temp == 9 || temp == 10){
          temp = 11;}
          sequence[i]=temp;
        i++;
    }
    seq_size=i;

    long temp_r = 0;
    long current_k = 0;
    int k;
    int j;

    for (k = 0; k < seq_size; k++) //for each k (in descending order)
    {
        current_k = sequence[k];
        for (j = current_k; j <= (Size - 1); ++j) //for j ← k to n-1
        {
        i = j;
        ++(*N_Comp);
            while((i>=current_k)&&(Array[i] < Array[i - current_k]))
            {
                    temp_r = Array[i];
                    Array[i] = Array[i - current_k];
                    Array[i - current_k] = temp_r;
                    *N_Move+=3;
                    i = i - current_k;
                ++(*N_Comp);
            }
        }
    }

    free(sequence);
    return;
}








void Save_Seq1 (char *Filename, int N){
    FILE *file_ptr = fopen(Filename, "w");
    int seq_size = 1;
    long *sequence = malloc((sizeof(long)) * N);

    sequence[0] = 1;
    int p2 = 0;
    int p3 = 0;

    int i = 1;
    long u2 = 0;
    long u3 = 0;
    while (sequence[i-1]<N){
        if (sequence[p2]*2 == sequence[i-1]){
            ++p2;
        }
        if (sequence[p3]*3 == sequence[i-1]){
            ++p3;
        }
        u2 = sequence[p2] *2;
        u3 = sequence[p3] *3;
        if(u2<u3){
            ++p2;
            sequence[i]=u2;
        }
        else{
            ++p3;
            sequence[i]=u3;
        }
        seq_size++;
        i++;
    }

    fprintf(file_ptr, "%d\n", N);
    for (i = 0;i<seq_size;i++){
        fprintf(file_ptr,"%ld\n", sequence[i]);
    }
    free(sequence);
    fclose(file_ptr);
    return;
}
void Save_Seq2 (char *Filename, int N){
    FILE *file_ptr = fopen(Filename, "w");
    int seq_size;
    long * sequence = malloc(sizeof(long)*N);
    int temp = N;
    int i = 0;
    while (temp>1){
        temp/=1.3;
        if(temp == 9 || temp == 10){
          temp = 11;}
          sequence[i]=temp;
        i++;
    }
    seq_size=i;

    fprintf(file_ptr, "%d\n", N);

    for (i = seq_size-1;i>=0;i--){
        fprintf(file_ptr,"%ld\n", sequence[i]);
    }
    free(sequence);
    fclose(file_ptr);
    return;
}
