#include <iostream>
#include <time.h>
#include <chrono>

int size[8]={4,8,10,40,80,100,400};

int main(){ 
    for (int l =0; l < 7; l++){
        int tmp_size = size[l];
        double **A = new double *[tmp_size]; 
        double **B = new double *[tmp_size]; 
        double **C = new double *[tmp_size];

        for(int i=0; i<tmp_size; i++){
            A[i] = new double[tmp_size];
            B[i] = new double[tmp_size];
            C[i] = new double[tmp_size];
        }

        double timeTotal = 0; 
        for(int ii=0; ii<10; ii++){
            //Initialize A and x, assign y=0
            for(int i=0; i<tmp_size;i++){
                for(int j=0; j<tmp_size; j++){
                    A[i][j]=rand()%100; B[i][j]=rand()%100; C[i][j]=0;  
                }
            }

            int blocksize= tmp_size/2;
            //obtiene el tiempo de ejecución del loop
            auto start = std::chrono::high_resolution_clock::now();
            //blocksize of 2
            for (int i=0; i<tmp_size;i+=blocksize){
                for (int j=0; j<tmp_size;j+=blocksize){
                    for (int k=0; k<tmp_size;k+=blocksize){
                      for (int jj=i; jj<i+blocksize; jj++){
                        for(int kk =j; kk<j+blocksize;kk++){
                          for(int ll=k; ll<k+blocksize; ll++){
                            C[jj][kk]+=A[jj][ll] * B[ll][kk];
                          }
                        }
                      }  
                    }
                }
            }

            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            timeTotal += duration.count();
        }

        std::cout<<timeTotal/10<<" microsegundos \n";

        for(int i=0; i<tmp_size; i++){
            delete [] A[i];
            delete [] B[i];
            delete [] C[i];
        } 
        delete []A;
        delete []B;
        delete []C;

    }

    return 0;
}