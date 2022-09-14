#include <iostream>
#include <time.h>
#include <chrono>

int size[5]={10,50,100,500,1000};

int main(){

    for (int k=0; k<5; k++){
        int tmp_size = size[k];
        double A[tmp_size][tmp_size], x[tmp_size], y[tmp_size];
        
        //Initialize A and x, assign y=0
        for(int i=0; i<tmp_size;i++){
            for(int j=0; j<tmp_size; j++){
                A[i][j]=rand()%100;
            }
            x[i]=rand()%100, y[i]=0;
        }
        
        //obtiene el tiempo de ejecución del loop
        auto start = std::chrono::high_resolution_clock::now();
    
        for(int j=0; j<tmp_size;j++){
            for(int i=0; i<tmp_size; i++){
                y[i] += A[i][j]*x[j];
            }
        }
    
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        std::cout<<duration.count()<<" microsegundos \n";
    }

    return 0;
}