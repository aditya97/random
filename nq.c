#include <stdio.h>

int is_attacked(int x, int y, int b[][50], int n){
    int i, j;
    for(i=0; i<n; i++){
        if(b[x][i]==1)
            return 1;
    }
    for(i=0; i<n; i++){
        if(b[i][y]==1)
            return 1;
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i+j==x+y && b[i][j]==1)
                return 1;
        }
    }
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(i-j==x-y && b[i][j]==1)
                return 1;
        }
    }
    return 0;
}
int nqueen(int b[][50], int n, int size){
    if(n==0){
        return 1;
    }
    int p, q;
    for(p=0; p<size; p++){
        for(q=0; q<size; q++){
            if(is_attacked(p, q, b, size))
                continue;
            b[p][q] = 1;
            if(nqueen(b, n-1, size))
                return 1;
            else
                b[p][q] = 0;
        }
    }
    return 0;
        
}
int main()
{   
    int b[50][50], n, i, j, size;
    scanf("%d", &n);
    size = n;
    for(i=0; i<n; i++){
        for(j=0; j<n; i++){
            b[i][j]= 0;
            printf("%d", b[i][j]);
        }
    }
    nqueen(b, n, size);
    for(i=0; i<n; i++){
        for(j=0; j<n; i++)
            printf("%d ", b[i][j]);
        printf("\n");
    }
    printf("Hello World!\n");
    return 0;
}
