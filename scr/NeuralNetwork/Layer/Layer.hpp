#ifndef LAYER_HPP
#define LAYER_HPP

#include "../Neuron/Neuron.hpp"
/*
A Layer is composed of multiple neurons. It has a type (INPUT/STANDARD/OUTPUT) because 
it doesn’t work the same way depending on its type and it has an activation function
*/

namespace lt {
    enum Type {
        INPUT,
        STANDARD,
        OUTPUT,
    };
}

class Layer {
    public:
        Layer( lt::Type type, int num);
        Neuron** neuron_layer;
};

#endif