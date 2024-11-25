
#include "networkStructure.hpp"

using namespace HopfieldNetwork;

void Hopfield::updateNeuronState(int neuron){
    float weightSum = 0.0f;

        for (int j = 0;j<networkState.size();j++){
        weightSum += (weightMat[neuron][j]*networkState[j]); 
    }
    networkState[neuron] = (weightSum > neuronThreshold[neuron]) ? 1 : 0;
}

void Hopfield::updateFunc(){
    std::vector<int>neuronIds(networkState.size());
    std::iota(neuronIds.begin(),neuronIds.end(),0);
    
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(neuronIds),std::end(neuronIds),rng);
    
    for (auto Id :neuronIds)
        updateNeuronState(Id);
}

void Hopfield::learn(std::vector<std::vector<float>>&patterns){
    
/* 

    Hebbian learning rule to update the weight matrix
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
   
void Hopfield::weightedSum(std::vector<bool>inputPattern,std::vector<std::vector<float>>&patterns){
    /* 
    ∑ⱼ Tᵢⱼ Vⱼₛ' = ∑ₛ (2Vᵢₛ - 1)[∑ⱼ Vⱼₛ'(2Vⱼₛ - 1)] ≡ Hᵢₛ'
     */
    for (int i = 0;i<numNeuron;i++){
        float sum = 0.0f;
        for (const auto& pattern: patterns){
            float innerSum = 0.0f;
            for(int j = 0;j<numNeuron;j++){
                innerSum +=(2*pattern[i]-1) * inputPattern[j];
            }
            sum += (2*pattern[i]-1)*innerSum;
        }
        weightedSumVec[i] = sum;
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