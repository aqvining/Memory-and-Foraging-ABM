#include <cstdlib> // for srand() and rand()
#include <ctime> // for using time() to gen truly random numbers
#include <iostream> // use basic facilities like cout and cin

//#include "Patch.h"
//#include "Forager.h"	
using namespace std;

double genRandUnifNum(double a, double b); // function prototype
void truncateCoords(Patch patch);
int main(int argc, char* argv[]){ // consider having command line arguments -> argc, argv*[]
      Patch* patchArray = new[argc-1] Patch; //create the number of patches typed on the command line 
      for(int i = 1; i < argc; i++){ //skip first argument b/c it's the executable name
         patchArray[i] = Patch(argv*[i]); // i doubt this works but the idea is to create in this array of patches a patch object with the name entered on the command line
      }
// map containing all patches mapped to a key for patch number
      map PatchList<string, Patch> x = {{"1", Patch Patch("PatchA")}, {"2", Patch Patch("PatchB")}, 
                                   {"3", Patch Patch("PatchC")}, {"4", Patch Patch("Patch D")}};
    cout<<"Successfully randomly generated patchs\n";
    for(int patchNum = 0; patchNum < patchArray.size(); patchNum++){
       truncateCoords(patchArray[patchNum]);  
    }
    
    for(int j = 0; j < patchArray.size(); j++){
       if(patchArray[j].location[0] > 0 && patchArray[j].location[0] <= 10){
          if(patchArray[j].location[1] > 0 && patchArray[j].location[1] <=10 )
          Patch['1'] = patchArray[j]; // if patch btw (0,0) and (0,10) then put in patch 1
       } //etc 
       else if()
         
    }
   

    Patch PatchA(); // instantiate a Patch using constructor -> can pass energy, xlim and ylim as arguments. 
    Forager ForagerA();

    return 0;
} //I'll probably move this main function to another file soon and create header files and stuff

//this function tries to randomly generate numbers on the uniform distribution 
double genRandUnifNum(double a = 0.0, double b = 10.0){
	 srand(time(0)); // initialize random seed, this might need to belong in the main function or global IDK
	   //normally we wouldn't do so much with this next line, but we trying to randomly generate doubles, not ints. 
       double randNum = a + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(a-b)));
       return randNum;
}
void truncateCoords(Patch patch){
  patch.location[0] = static_cast<int> patch.location[0];
  patch.location[1] = static_cast<int> patch.location[1];
}






 /* 
  modify main function so you can put user input for number of functions and create patchList array with all those patches in it
  create a map (python dictionary), patchFinder(), that tells you grid cell (1,1) or something points to patchList[1,2,5]
  and 1,2; points to [0,3]

and function attached to map that takes location, truncates it, and returns what its mapped to. 

 */

//*************************************Wesley's idea:
//use JSON for key value pairs and do some importing stuff where u import the JSON file into C++. 


























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