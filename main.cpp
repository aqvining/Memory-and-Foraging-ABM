#include <cstdlib> // for srand() and rand()
#include <ctime> // for using time() to gen truly random numbers
#include <iostream> // use basic facilities like cout and cin

//#include "Patch.h"
//#include "Forager.h"	
using namespace std;

/* Alex's desired thoughts and notes for 2/14/18

numRows x numCols Patch matrix -> you need to define some kind of double patch pointer

Patch** PatchMatrix = new [numRows] Patch*; // allocate space for rows of matrix
for(int i = 0; i < numRows; i++){
   Patch*[i] = new[numCols] Patch; // allocate space for columns
}

The issue still remains though how do you assign every patch a name or whatever?
If you create a matrix, you will have to use index notation where PatchMatrix[0][0] is the top left corner Patch and 
PatchMatrix[numRows][numCols] is bottom right corner Patch. I guess maybe that's ok since you could just say 
PatchMatrix[0][0] is Patch 0 or A or 1 or whatever and PatchMatrix[0][1] is B or something. 

I'm not sure what you are confused about for the multiple data values thing, but you can just add data members to the 
Patch class and each Patch in the matrix will contain such values. 

make sure that later in code deallocate memory:
for(int j = 0; j < numCols;j++){ //delete columns
   delete[] PatchMatrix*[j];
}
delete [] PatchMatrix; //delete rows
 OR
sticking with current method with 1 patch array(HELL NO)
OR 
alternative methods for reducing complexity fo checking location of every patch that exists
diff info 
-> just putting it out there: linked lists and vectors but those will take time to learn, implement, and have bigger processing time
*/
double genRandUnifNum(double a, double b); // function prototype
void truncateCoords(Patch patch);
int main(int argc, char* argv[]){ // consider having command line arguments = exec name, number of patches, square sides (sets xlim and ylim)
      const int NUMPATCH = static_cast<int>arg*v[1];
      //we will have (0,0) as the center lol
      const int XLIM = static_cast<int>argv*[2];  
      const int YLIM = static_cast<int> argv*[3];
       
      Patch* patchArray = new[NUMPATCH] Patch; //allocate the number of patches typed on the command line into patchArray
      // for(int i = 1; i < argc; i++){ //skip first argument b/c it's the executable name
      //    patchArray[i] = Patch(argv*[i]); // i doubt this works but the idea is to create in this array of patches a patch object with the name entered on the command line
      // } // modify
// map containing all patches mapped to a key for patch number
    map PatchList<string, Patch> x = {{"1", Patch Patch("PatchA")}, {"2", Patch Patch("PatchB")}, 
                                   {"3", Patch Patch("PatchC")}, {"4", Patch Patch("Patch D")}};
    cout<<"Successfully randomly generated patchs\n";
    for(int patchNum = 0; patchNum < patchArray.size(); patchNum++){
       truncateCoords(patchArray[patchNum]);  
    }
    //this is a shit way of assigning patch names
    for(int j = 0; j < patchArray.size(); j++){
       if(patchArray[j].location[0] > 0 && patchArray[j].location[0] <= 1){
          if(patchArray[j].location[1] > 0 && patchArray[j].location[1] <=1 )
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