#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <random>



int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    for(size_t i = 0; i < 10; i++){
        std::cout << arr[i] << ',';
    }
    std::cout << std::endl;


    std::shuffle(arr, arr+10, std::default_random_engine(time(0)));

    for(size_t i = 0; i < 10; i++){
        std::cout << arr[i] << ',';
    }
    std::cout << std::endl;



    return 0;
}