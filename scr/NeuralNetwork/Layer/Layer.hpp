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
        HIDDEN,
        OUTPUT,
    };
}

class Layer {
    public:
        Layer( lt::Type type, int num);

        void setEdges(int prev, int next);
       

        Neuron* neuron_layer;
        int layer_size;
};

#endif