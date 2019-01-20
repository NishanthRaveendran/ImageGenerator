# ImageGenerator
This program intakes an image, and then recreates that image using an iterative process with a genetic algorithm. (2S03 Principles of Programming Final Project)

### How the algorithm works

The program generates a population of random PPM images to start. 
It then compares all of the generated images to the original image and selects the most similar image. 
This image is taken and used as a base for the next generation of random images. 
The algorithm mutates the similar image, creating a whole new population of images. 
This process is repeated, creating a more accurate image every generation.

| Original Image        | Image Generation          | Final Image    |
| ------------- |:-------------:| :--------: |
| <img src="https://github.com/NishanthRaveendran/ImageGenerator/blob/master/escher.jpg" width="250" height="250"> | <img src="https://github.com/NishanthRaveendran/ImageGenerator/blob/master/eshergenerate.gif" width="250" height="250"> | <img src="https://github.com/NishanthRaveendran/ImageGenerator/blob/master/escherfinal.jpg" width="250" height="250"> |

The population size and number of generations can be tweaked, where having a larger population and more generations provides better results. But for the sake of time, I used a population of 5000 and 100 generations to create this image.

#### Key Concepts
* Object Oriented Programming
* Genetic Algorithm
