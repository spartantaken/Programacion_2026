#ifndef CUSTOM_STACK_H   
#define CUSTOM_STACK_H

#include <vector>

class CustomStack {
    private:
        std::vector<int> datos; //costructor de la pila utilizando un vector para almacenar los elementos
    public:
        CustomStack();//Constructor de la clase CustomStack
        ~CustomStack();//Destructor de la clase CustomStack
        
        //Indica la pila no contiene elementos  
        bool empty();

        //Indica el número de elementos en la pila
        int size();

        //Devuelve el elemento en la parte superior de la pila sin eliminarlo
        int top();

        //Agrega un nuevo elemento a la parte superior de la pila
        void push(int valor);

        //Elimina el elemento en la parte superior de la pila
        void pop();
};

#endif
