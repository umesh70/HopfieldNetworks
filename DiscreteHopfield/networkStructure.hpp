#ifndef UNIQUE_HEADER_IDENTIFIER_H
#define UNIQUE_HEADER_IDENTIFIER_H

#include<stdio.h>
#include<vector>
#include<iostream>
#include<random>
#include<algorithm>


#endif
/*
When we are calculating the weighted sum to update each state, we are checking which neurons are involved in updating its state. That's why we have used ΣTijVj.
*/

/*
for being analogous to paper    
    V (vector) = networkstate 
    T(2d vector) = weightMatrix
    U(vector) = neuronthreshold
for now lets assume each neuron has its own arbitrary threshold value
*/


namespace HopfieldNetwork{

    class Hopfield{
        private:
            int numNeuron;
            std::vector<bool>networkState;
            std::vector<float>neuronThreshold;
            std::vector<std::vector<float>>weightMat;
            std::vector<int>weightedSumVec;
            double energy;
        public:
            Hopfield(int numNeuron) : 
                networkState(numNeuron, false),numNeuron(numNeuron), 
                neuronThreshold(numNeuron, 0.0f), 
                weightMat(numNeuron, std::vector<float>(numNeuron, 0.0f)),energy(0.0){

            }

            void learn(std::vector<std::vector<float>>&patterns);
            void updateNeuronState(int neuron);
            void updateFunc();
            void weightedSum(std::vector<bool>inputPattern,std::vector<std::vector<float>>&patterns);
            void storedata();
            void energyFunction();

    };
}