
long *Load_File(char *Filename, int *Size){

}








int Save_File(char *Filename, long *Array, int Size){

}








void Shell_Insertion_Sort(long *Array, int Size, double *N_Comp, double *N_Move){

}


void Improved_Bubble_Sort(long *Array, int Size, double *N_Comp, double *N_Move){

}




long * Gen_Seq1 (int N){
    long * seq1 = malloc(sizeof(long) * N);
    seq1[0] = 1;
    int p2 = 0;
    int p3 = 0;
    int i;
    long u2 = 0;
    long u3 = 0;
    for (i=1;i<N;i++){
        if (seq1[p2]*2 == seq1[i-1]){
            p2++;
        }
        if (seq1[p3]*3 == seq1[i-1]){
            p3++;
        }
        u2 = seq1[p2] *2;
        u3 = seq1[p3] *3;
        if(u2<u3){
            p2++;
            seq1[i]=u2;
        }
        else{
            p3++;
            seq1[i]=u3;
        }
    }
    return seq1;
}



long * Gen_Seq2 (int N){
    long * seq2 = malloc(sizeof(long)*N);
    int temp = N;
    int i = 0;
    while (temp!=1){
        temp/=1.3;
        seq2[i]=temp;
        i++;
    }
    return seq2;
}

void Save_Seq1 (char *Filename, int N){

}
void Save_Seq2 (char *Filename, int N){

}