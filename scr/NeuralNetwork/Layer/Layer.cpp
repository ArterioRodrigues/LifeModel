#include "Layer.hpp"
#include <iostream>


Layer::Layer(lt::Type type, int num){
        this->layer_size = num;
        this->neuron_layer = new Neuron[this->layer_size];
        this->type = type;
}

