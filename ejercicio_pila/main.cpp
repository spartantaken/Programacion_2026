#include "custom_stack.h"
#include <iostream>

int main(){
    CustomStack MiPila;
    MiPila.push(1);
    MiPila.push(2);
    MiPila.push(3);
    MiPila.pop();
    MiPila.top();
    MiPila.size(); 

    return 0;

}