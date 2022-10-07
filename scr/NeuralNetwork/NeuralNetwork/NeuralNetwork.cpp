#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(int size_input, int size_hidden, int size_output, int num_hidden){

    this->input  = new Layer(lt::INPUT, size_input);
    this->output = new Layer(lt::OUTPUT, size_output);
    this->hidden = new Layer(lt::HIDDEN, size_hidden);

    this->input->setEdges(0, size_hidden);
    this->output->setEdges(size_hidden, 0);
    this->hidden->setEdges(size_input, 1);
}

void NeuralNetwork::setUpConnection(){
    int n = this->input->layer_size;
    int k = this->hidden->layer_size;
    int l = this->output->layer_size;

    Neuron* neuron;

    for(int i = 0; i < n; i++){
        neuron = &(this->input->neuron_layer[i]);
        for(int j = 0; j < k; j++)
            neuron->next_edges[j].next_neuron = &(this->hidden->neuron_layer[j]);
    }


}


void NeuralNetwork::displayNetwork(){
    int n = this->input->layer_size;

    std::cout << "INPUT LAYER:  " << std::endl;
    for(int i = 0; i < n; i++)
        std::cout << "[" << this->input->neuron_layer[i].accumulated_output << "]" << std::endl;

    n = this->output->layer_size;

    std::cout << "OUTPUT LAYER:  " << std::endl;
    for(int i = 0; i < n; i++)
        std::cout << "[" << this->output->neuron_layer[i].accumulated_output << "]" << std::endl;

    
    n = this->hidden->layer_size;

    std::cout << "HIDDEN LAYER:  " << std::endl;
    for(int i = 0; i < n; i++)
        std::cout << "[" << this->hidden->neuron_layer[i].accumulated_output << "]" << std::endl;


    
};
