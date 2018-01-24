###~~~Memory and Foraging Agent Based Model Version 3~~~###
#The goal of this agent based model is to allow flexible and efficient exploration of the impact of spatial memory an animal foraging.
#It will allow for manipulation of memory size, accuracy, and properties such as learning or forgetting rules.
#The model will incorporate aspects of optiomal foraging theory into the animal behavior, and additional allow for different
#navigational decision strategies. The model will then measure overall foraging efficiency given the different memory and
#navigation properties.

##Version 3.01 Notes:

#~~ 1. Setup ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

#~~~~ 1a. Class creation and constructor functions
setClass("patchA", slots = list(location = 'numeric', energy = 'numeric'))  #sets class structure for patch type A

PatchA <- function(xlim, ylim) {                                  #constructor for patchA class
  ###input: "xlim" = maximum value for x coordinate of patch
  ###       "ylim" = maximum value for y coordinate of patch
  ###output: object of class patchA
  ###description: The location slot of output object will have x,y coordinates drawn from a uniform distribution between -xlim and xlim, and -ylim and ylim
  ###             The energy slot of output will have value of 5
  newPatchA <- new("patchA", location = c(runif(1, -xlim, xlim), runif(1, -ylim, ylim)), 
                   energy = 5)
  names(newPatchA@location) <- c('x', 'y')
  newPatchA
}

#~~~~ 1b. Methods
setGeneric("growth", function(x) standardGeneric("growth"))                 #creates generic function "growth" from which methods for patch resource growth can be built
setMethod(f = "growth", signature = "patchA", definition = function(x) {    #growth method for patch type A
  ###input: object of class "patchA"
  ###output: input object with energy slot increased by 1
  x@energy <- x@energy + 1
  x})

setGeneric("extraction", function(x) standardGeneric("extraction"))         #creates generic function "extraction" from which methods for patch resource growth can be built
setMethod(f = "extraction", signature = "patchA", definition = function(x) {    #extraction method for patch type A
  ###input: object of class "patchA"
  ###output: input object with energy slot decreased by 20%
  x@energy <- 4 * x@energy/5
  x})

#~~~~ 1c. Calculation Tools

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

PatchCreator <- function(numPatches, xlim, ylim){
  
}
