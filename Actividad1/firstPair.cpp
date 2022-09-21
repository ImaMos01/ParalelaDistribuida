#include <iostream>
#include <time.h>
#include <chrono>

int size[8]={10,40,80,100,400,800,1000,4000};

int main(){

    for (int k=0; k<8; k++){
        int tmp_size = size[k];
        double **A = new double *[tmp_size];
        double *x = new double[tmp_size];
        double *y = new double[tmp_size];
        
        for(int i=0; i<tmp_size; i++){
            A[i] = new double[tmp_size];
        }

        float timeTotal = 0;
        for(int l=0; l<10;l++){
            //Initialize A and x, assign y=0
            for(int i=0; i<tmp_size;i++){
                for(int j=0; j<tmp_size; j++){
                    A[i][j]=rand()%100;
                }
                x[i]=rand()%100, y[i]=0;
            }

            //obtiene el tiempo de ejecución del loop
            auto start = std::chrono::high_resolution_clock::now();
        
            for(int i=0; i<tmp_size;i++){
                for(int j=0; j<tmp_size; j++){
                    y[i] += A[i][j]*x[j];
                }
            }
        
            auto end = std::chrono::high_resolution_clock::now();
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

            timeTotal += duration.count();
        }
        std::cout<<timeTotal/10<<" microsegundos \n";

        delete []x;
        delete []y;

        for(int i=0; i<tmp_size; i++) delete [] A[i];
        delete []A;
    }

    return 0;
}