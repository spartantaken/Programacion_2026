#include "Custom_stack.h"
#include <iostream>

CustomStack::CustomStack(){
    
}

CustomStack::~CustomStack(){
    
}

bool CustomStack::empty(){
    return datos.empty();
}

int CustomStack::size(){
    return datos.size();
}

int CustomStack::top(){
    if(empty()){
        std::cout << "la pila esta vacia";
        return -1; 
    }
    return datos.back();
}

void CustomStack::push(int valor){
    datos.push_back(valor);
}

void CustomStack::pop(){
    if(empty()){
        std::cout << "la pila esta vacia";
    }
    datos.pop_back();
}

