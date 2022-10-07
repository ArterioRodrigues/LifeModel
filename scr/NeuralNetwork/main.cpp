#include <iostream>
#include "Edge.hpp"
#include "Neuron.hpp"


int main(){

    Edge edge1;
    Edge edge2;
    Neuron neuron1;

    edge1.weight = 1;    
    edge2.weight = 2;

    neuron1.previous_edge = &edge1;
    neuron1.next_edge = &edge2;

    std::cout << neuron1.previous_edge->weight;
    std::cout << neuron1.next_edge->weight;

    return 0;
}