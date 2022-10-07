#include "Layer.hpp"
#include <iostream>


Layer::Layer(lt::Type type, int num){
        this->layer_size = num;
        this->neuron_layer = new Neuron[this->layer_size];
}


void Layer::setEdges(int prev, int next){
    for(int i = 0; i < this->layer_size; i++){
        if(prev != 0){
            neuron_layer[i].prev_edges = new Edge[prev];
            for(int k = 0; k < prev; k++)
                neuron_layer[i].prev_edges[k].next_neuron = &(this->neuron_layer[i]);
        }
        else
            neuron_layer[i].prev_edges = nullptr;
        
        if(next != 0){
            neuron_layer[i].next_edges = new Edge[next];
            for(int k = 0; k < next; k++)
                    neuron_layer[i].next_edges[k].prev_neuron = &(this->neuron_layer[i]);
        }
        else
            neuron_layer[i].next_edges = nullptr;
    }
}


