
#include "networkStructure.hpp"

using namespace HopfieldNetwork;

int Hopfield::activate(double value) {
        return (value >= 0) ? 1 : -1;
    }


void Hopfield::recall(std::vector<int>inputPattern){

    std::vector<int> currentState = inputPattern;

        for (int iter = 0; iter < maxIterations; ++iter) {
            bool stable = true;
            for (int i = 0; i < numNeuron; ++i) {
                double potential = 0.0;
                for (int j = 0; j < numNeuron; ++j) {
                    potential += weightMat[i][j] * currentState[j];
                }
                
                int newState = activate(potential);
                if (newState != currentState[i]) {
                    currentState[i] = newState;
                    stable = false;
                }
            }

            if (stable) break;
        }
        networkState = currentState;
}

void Hopfield::learn(std::vector<std::vector<float>>&patterns){ 
/* 

    Hebbian learning rule to calculate the weight matrix
 */
    for (const auto& pattern : patterns){
        for (int i = 0 ;i<numNeuron;i++){
            for (int j = 0;j<numNeuron;j++){
                if (i != j){
                    /* 
                    converting the pattern into bipolar and calculating oouter product
                     */
                    weightMat[i][j] += (2 * pattern[i] - 1) * (2 * pattern[j] - 1);
                }
            }
        }
    }
    // Normalize weights by number of patterns
    for (auto& row : weightMat) {
        for (float& weight : row) {
            weight /= patterns.size();
        }
    }


}
   

void Hopfield:: networkStateShow(){
    std::cout<<"\n"<<"Recalled Pattern: ";
    for(auto val :networkState){
            std::cout<<val<<" ";

    }
}

void Hopfield::energyFunction(){
    
    for(int i = 0;i<numNeuron;i++){
        for(int j =0; j<numNeuron;j++)
            if (i!= j)
                energy += (weightMat[i][j] * networkState[i] * networkState[j]);
    }

    energy = -0.5*energy;
}