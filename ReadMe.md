# Hopfield Neural Networks

- hopfield neural networks were first presented in 1982 by John Hopfield in his **"Neural Network and physical systems with emergent collective computational abilities"** paper, the initial network is quite rudimentary and relatively easy to implement, but the intuition behind the network, how it came into existence makes it a fascinating study.

- During a series of paper between the formative years of AI/ML, modern hopfield networks were introduced and in **"Hopfield Networks Is All You Need"** paper, a novel architecture was introduced which generalises the transformer architecture.

- I will be implementing a comprehensive class of Hopfield networks , starting from the primitive models, and progressing to the modern hopfield networks.

## Intuition

- You might have heard many qoutes which always tries to convey something along the following lines, **"Alone we can do so little;together we can do so much"**, apparently its a universal thing.

- Computational properites of any system whether it may be physical system, complex system ,even our neurological system, all these properties or phenomena emerges from the interaction of the elementary units of the system.

- For instance, lets take [**game of life**](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) as our initial example: Its a zero player game, meaning that its evolution is determined by its initial state or configuration, at every time step, each cell interact with its neighbouring eight cell based on the just 4 rules, you might think, its quite facile, right?, but thats the beauty of it, even due to the presence of those four rules, the emergent behaviour of the game of life is quite complex.

- The point here I am trying to make is that the complex behaviour or the computational properties of this game is emerged from simple interaction between the elementary units of the game.

- with this we can conclude one of the intuition behind hopfield network along the following lines,<br>
  **"Computation properties are a spontaneous result of the interaction of the elementary particles in a physical/neuronal system."**

- Now, lets say you met your friend today, had a long chat till the evening, and he left afterwards, and on the next day you saw your friend in the market from a distance and that too his side face, but still you recognized him, right?, your eyes did not collected enough information about him, and yet you recognized him.This is because your brain has the ability to fill in the missing information and reconstruct the complete image of your friend based on partial cues.

- This phenomenon is known as **"pattern completion"** or **"associative memory,"** and it's one of the key inspirations behind Hopfield networks. Your brain stores patterns (in this case, the memory of your friend) and can recall the entire pattern even when presented with incomplete or noisy input.

## Motive

- All modelling is based on details, in many physical systems, the emergent collective properties is insensitive to the details inserted in it, even though the details of the neural structure of our brain are myriad, we are still able to mimic its behaviour upto some extent though artificial intelligence.
