
#ifndef EDGE_H
#define EDGE_H

class Neuron;

/*
An Edge knows its next neuron (_n), the neuron its coming from (_nb), it has a weight (_w), 
it can memorize how much its weight was shift (_last_shift) last time it was, 
and it has a backpropagation memory so that it can retain a part of the chain rule
*/

class Edge {

    public:
        Edge();
        int weight;
        int weight_before;

        Neuron* next_neuron;
        Neuron* prev_neuron;
};

#endif