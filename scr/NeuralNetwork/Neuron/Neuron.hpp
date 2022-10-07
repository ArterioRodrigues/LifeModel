
#ifndef NEURON_HPP
#define NEURON_HPP

#include "../Edge/Edge.hpp"
/*
 A Neuron has a parent layer. A neuron accumulates the output of the edges connected to it (_accumulated),
it outputs that input to its edges after processing it with its _activation_function 
(which you can change on a per-neuron basis). A neuron knows its _next and _previous edges.
*/

class Neuron{
    public:
      
        Neuron();

        int accumulated_output;
        
        Edge* prev_edges;
        Edge* next_edges;

};

#endif