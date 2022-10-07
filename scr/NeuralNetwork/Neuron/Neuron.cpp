#include "Neuron.hpp"

Neuron::Neuron(){
    this->accumulated_output = 0;
    prev_edges = nullptr;
    next_edges = nullptr;
}