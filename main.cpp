#include <cstdlib> // for srand() and rand()
#include <ctime> // for using time() to gen truly random numbers
#include <iostream> // use basic facilities like cout and cin

//#include "Patch.h"
//#include "Forager.h"	
using namespace std;

double genRandUnifNum(double a, double b); // function prototype

int main(){
    Patch PatchA(); // instantiate a Patch using constructor -> can pass energy, xlim and ylim as arguments. 
    Forager ForagerA();
    return 0;
}  //I'll probably move this main function to another file soon and create header files and stuff

//this function tries to randomly generate numbers on the uniform distribution 
double genRandUnifNum(double a = 0.0, double b = 10.0){
	 srand(time(0)); // initialize random seed, this might need to belong in the main function or global IDK
	   //normally we wouldn't do so much with this next line, but we trying to randomly generate doubles, not ints. 
       double randNum = a + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(a-b)));
       return randNum;
}


// Alex's code
/*
#~~ 2. Main Function ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
runSimulation <- function(numForager, numPatch, t, xSize, ySize){
  ###input: numForager should be a named vector where each name is a forager class and each value is the number of that forager class to be created
  ###       numPatch should be named vector where each name is a patch class and each value is the number of that patch class to be created
  ###       t = time steps to run simulation
  ###       xlim and ylim are the field size of the x and y coordinates respectively
  ###output: A list of length two. The first element contains a list of foragers for each time step, the second element a list of patches
  ###description: Architecture of simulation. Applies methods to all foragers and patches over a series of time steps
  data <- list(vector("list", t), vector("list", t))
  foragers <- createObjects(numForager)
  patches <- createObjects(numPatch)
  data[[1]][[1]] <- foragers
  data[[2]][[1]] <- patches
  for (step in 2:t) {
    foragers <- apply(foragers, move, patches = patches)
    consumers <- getConsumers(foragers, patches) #gets indices of each forager that is on a patch
    foragers[consumers] <- apply(foragers[consumers], consume, patches = patches) #updates each forager that extracts resources
    depleted <- getDepletions(consumers, patches) #gets indices of each patch that was consumed
    patches[depleted] <- apply(patches[depleted], extraction) #updates each patch that has been consumed (check functionality for multiple consumptions on single patch)
    data[[1]][[step]] <- foragers
    data[[2]][[step]] <- patches
  }
  return(data)
}
*/