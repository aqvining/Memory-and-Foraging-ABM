###~~~Memory and Foraging Agent Based Model Version 3~~~###
#The goal of this agent based model is to allow flexible and efficient exploration of the impact of spatial memory an animal foraging.
#It will allow for manipulation of memory size, accuracy, and properties such as learning or forgetting rules.
#The model will incorporate aspects of optiomal foraging theory into the animal behavior, and additional allow for different
#navigational decision strategies. The model will then measure overall foraging efficiency given the different memory and
#navigation properties.

##Version 3.01 Notes:
setGeneric("growth", function(x) standardGeneric("growth"))                 #creates generic function "growth" from which methods for patch resource growth can be built
setGeneric("extraction", function(x) standardGeneric("extraction"))         #creates generic function "extraction" from which methods for patch resource growth can be built
setClass("patchA", slots = list(location = 'numeric', energy = 'numeric'))  #sets class structure for patch type A

setMethod(f = "growth", signature = "patchA", definition = function(x) {    #growth method for patch type A
  ###input: object of class "patchA"
  ###output: input object with energy slot increased by 1
  x@energy <- x@energy + 1
  x})

setMethod(f = "extraction", signature = "patchA", definition = function(x) {    #extraction method for patch type A
  ###input: object of class "patchA"
  ###output: input object with energy slot decreased by 20%
  x@energy <- 4 * x@energy/5
  x})

PatchA <- function(xlim, ylim) {                                                           #constructor for patchA class
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
