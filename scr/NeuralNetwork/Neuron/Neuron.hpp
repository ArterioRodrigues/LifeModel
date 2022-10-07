#ifndef NEURON_HPP
#define NEURON_HPP

/*
 A Neuron has a parent layer. A neuron accumulates the output of the edges connected to it (_accumulated),
it outputs that input to its edges after processing it with its _activation_function 
(which you can change on a per-neuron basis). A neuron knows its _next and _previous edges.
*/

class Neuron{
    public:
        int accumulated_output;

};

#endif