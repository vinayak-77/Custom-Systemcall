#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<syscall.h>
#define kernel_2d_memcpy 451

int main(){
    float sourceMatrix[4][3] = {{1.0,2.0,3.0},{4.0,5.0,6.0},{7.0,8.0,9.0},{10.0,11.0,12.0}};
    float destinationMatrix[4][3] = {{1.0,1.0,2.0},{9.0,9.0,6.0},{8.0,8.0,9.0},{10.0,21.0,12.0}};

    printf("The source matrix is :- \n");
    for(int i = 0;i<4;i++){
        for(int j = 0;j<3;j++){
            printf("%f ",sourceMatrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("The original destination matrix is :- \n");
    for(int i = 0;i<4;i++){
        for(int j = 0;j<3;j++){
            printf("%f ",destinationMatrix[i][j]);
        }
        printf("\n");
    }


    syscall(kernel_2d_memcpy,sourceMatrix,destinationMatrix,4,3);
    printf("\n");
    printf("The final destination matrix is :- \n");

    for(int i = 0;i<4;i++){
        for(int j = 0;j<3;j++){
            printf("%f ",destinationMatrix[i][j]);
        }
        printf("\n");
    }

}