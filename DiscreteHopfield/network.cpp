#include<stdio.h>
#include<vector>
#include<iostream>
#include<random>
#include<algorithm>
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

void updateNeuron(std::vector<std::vector<float>>&weightMat,std::vector<bool>&networkState,std::vector<float>&neuronThreshold,int neuron){
/*  
randomly shuffle the networkstate vector and then update the state of the neuron, to induce asynchronous beheaviour and randomness.
*/
    float weightSum = 0.0;

    for (int j = 0;j<networkState.size();j++){
        weightSum += (weightMat[neuron][j]*networkState[j]); 
    }
    networkState[neuron] = (weightSum > neuronThreshold[neuron]) ? 1 : 0;

}


void updateFunc(std::vector<std::vector<float>>&weightMat,std::vector<bool>&networkState,std::vector<float>&neuronThreshold){
    
    std::vector<int>neuronIds(networkState.size());
    std::iota(neuronIds.begin(),neuronIds.end(),0);
    
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(neuronIds),std::end(neuronIds),rng);
    
    for (auto Id :neuronIds)
        updateNeuron(weightMat,networkState,neuronThreshold,Id);


}

int main(){

int numNeuron = 6;
std::vector<bool>networkState(numNeuron,0);
std::vector<float>neuronThreshold(numNeuron,0);
std::vector<std::vector<float>>weightMat(numNeuron, std::vector<float>(numNeuron, 0));


for(int i = 0 ;i<weightMat[0].size();i++){
    for(int j = 0 ;j<weightMat.size();j++){
        std::cout<<weightMat[i][j]<<" ";
    }
    std::cout<<"\n";
}

return 0;
}