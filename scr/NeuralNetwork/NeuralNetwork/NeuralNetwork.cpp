#include "NeuralNetwork.hpp"

NeuralNetwork::NeuralNetwork(int size_input, int size_hidden, int size_output, int num_hidden){

    this->input  = new Layer(lt::INPUT, size_input);
    this->output = new Layer(lt::OUTPUT, size_output);
    this->hidden = new Layer(lt::HIDDEN, size_hidden);

    setUpConnection();
}

void NeuralNetwork::setUpConnection(){
    int input_size = this->input->layer_size;
    int hidden_size = this->hidden->layer_size;
    int output_size = this->output->layer_size;

    Neuron* neuron;
    Edge* edge;
    //Sets up the nodes edges and there connects to the other nodes in the network
    //Sets up the edges for the nodes
    for(int i = 0; i < input_size; i++){
        neuron = &(input->neuron_layer[i]);
        neuron->next_edges = new Edge[hidden_size];

        //Set up the edge here 
        for(int j = 0; j < hidden_size; j++){
            edge = &(neuron->next_edges[j]);
            edge->prev_neuron = neuron;
        }
    }
    //Setting up the middle layer
    for(int i = 0; i < hidden_size; i++){
        
        neuron = &(hidden->neuron_layer[i]);
        neuron->next_edges = new Edge[output_size];

         //Set up the edge here 
        for(int j = 0; j < output_size; j++){
            edge = &(neuron->next_edges[j]);
            edge->prev_neuron = neuron;
        }


        neuron->prev_edges = new Edge[input_size];

        for(int j = 0; j < input_size; j++){
            neuron->prev_edges[j] = ((input->neuron_layer[j]).next_edges[i]);
            edge = &(input->neuron_layer[j].next_edges[i]);

            edge->next_neuron = neuron;
        }
    }

    for(int i = 0; i < output_size; i++){
        neuron = &(output->neuron_layer[i]);
        neuron->prev_edges = new Edge[hidden_size];

         for(int j = 0; j < hidden_size; j++){
            neuron->prev_edges[j] = ((hidden->neuron_layer[j]).next_edges[i]);
            edge = &(neuron->prev_edges[j]);

            edge->next_neuron = neuron;
        }
    }
}

void NeuralNetwork::displayNetwork(){

    int m = this->input->layer_size;
    // std::cout << "  ";
    // for(int i = 0; i < n; i++)
    //     std::cout << " [" << this->input->neuron_layer[i].accumulated_output << "] ";
    // std::cout << std::endl << std::endl;

    int n = this->hidden->layer_size;
    Neuron* neuron;

    for(int i = 0; i < n; i++){
        neuron = &(this->hidden->neuron_layer[i]);
        for(int j = 0; j < m; j++){
            std::cout << neuron->prev_edges[j].weight;
        }
        std::cout << std::endl;
    }



    // n = this->output->layer_size;
    //  std::cout << "  ";
    // for(int i = 0; i < n; i++)
    //     std::cout << " [" << this->output->neuron_layer[i].accumulated_output << "] ";
    // std::cout << std::endl ;
    
    
};
