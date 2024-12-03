#include "networkStructure.cpp"


int main(){

    int numNeuron = 4;

    HopfieldNetwork::Hopfield dummyNetwork(numNeuron);
    
    std::vector<std::vector<float>>patterns = {
        {1,1,-1,1},
        {-1,1,-1,-1}};

    dummyNetwork.learn(patterns);

    //  1 bit off from pattern 2
    std::vector<int>testPattern={-1,-1,-1,-1};
    std::cout<<"Test Pattern with noise: ";
    for (auto val:testPattern){
        std::cout<<val<<" ";
    }
    std::cout<<"\n"<<"Pattern in memory: ";

    for(int i = 0;i<patterns[0].size();i++){
        std::cout<<patterns[1][i]<<" ";
    }
    dummyNetwork.recall(testPattern);
    dummyNetwork.networkStateShow();

    return 0;

}

