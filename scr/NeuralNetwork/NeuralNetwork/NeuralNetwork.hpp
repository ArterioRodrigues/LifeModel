#ifndef NEURALNETWORK_HPP
#define NEURALNETWORK_HPP

#include "../Edge/Edge.hpp"
#include "../Neuron/Neuron.hpp"
#include "../Layer/Layer.hpp"
#include <iostream>

/*
the main class containing a model. A NeuralNetwork is composed of multiple layers
*/

class NeuralNetwork {
    public:
        NeuralNetwork(int size_input, int size_hidden, int size_output, int num_hidden);
        void displayNetwork();
         void setUpConnection();
        Layer* input;
        Layer* hidden;
        Layer* output;        

};


#endif