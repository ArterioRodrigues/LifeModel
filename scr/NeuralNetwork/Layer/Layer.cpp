#include "Layer.hpp"
#include <iostream>

Layer::Layer(lt::Type type, int num){
        neuron_layer = new Neuron[num];
}