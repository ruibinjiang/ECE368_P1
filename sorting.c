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
    int seq_size = 1;
    long *sequence = malloc((sizeof(long)) * Size);

    sequence[0] = 1;
    int p2 = 0;
    int p3 = 0;
    
    int i;
    long u2 = 0;
    long u3 = 0;
    for (i=1;i<=Size;i++){
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
    }





    long temp_r = 0;
    long current_k = 0;
    long i = 0;

    for (int k = (seq_size - 1); k >= 0; --k) //for each k (in descending order)
    {
        current_k = sequence[k];
        for (int j = current_k; j <= (Size - 1); ++j) //for j ← k to n-1
        {
        temp_r = Array[j];
        i = j;
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
    int seq_size = 1;
    long *sequence = Gen_Seq1(Size, &seq_size);

    long temp_r = 0;
    long current_k = 0;
    long i = 0;

    for (int k = (seq_size - 1); k >= 0; --k) //for each k (in descending order)
    {
        current_k = sequence[k];
        for (int j = current_k; j <= (Size - 1); ++j) //for j ← k to n-1
        {
        i = j;
        ++(*N_Comp);
            while(i>=current_k)
            {
                if(Array[i] < Array[i - current_k]){
                    temp_r = Array[i];
                    Array[i] = Array[i - current_k];
                    Array[i - current_k] = temp_r;
                    *N_Move+=3;
                }
                i = i - current_k;
                ++(*N_Comp);
            }
        }
    }

    free(sequence);
    return;
}








long * Gen_Seq2 (int N, int *seq_size){
    long * seq2 = malloc(sizeof(long)*N);
    int temp = N;
    int i = 0;
    while (temp!=1){
        temp/=1.3;
        seq2[i]=temp;
        i++;
        (*seq_size)=(*seq_size)+1;
    }
    return seq2;
}

void Save_Seq1 (char *Filename, int N){
    FILE *file_ptr = fopen(Filename, "w");
    int seq_size = 1;
    long *sequence = malloc((sizeof(long)) * N);

    sequence[0] = 1;
    int p2 = 0;
    int p3 = 0;
    
    int i;
    long u2 = 0;
    long u3 = 0;
    for (i=1;i<=N;i++){
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
    }

    int i;
    for (i = 0;i<seq_size;i++){
        fprintf(file_ptr,"%ld\n", sequence[i]);
    }
    free(sequence);
    fclose(file_ptr);
    return;
}
void Save_Seq2 (char *Filename, int N){
    FILE *file_ptr = fopen(Filename, "w");
    int seq_size = 0;
    long *sequence = Gen_Seq2(N, &seq_size);

    int i;
    for (i = 0;i<seq_size;i++){
        fprintf(file_ptr,"%ld\n", sequence[i]);
    }

    fclose(file_ptr);
    return;
}