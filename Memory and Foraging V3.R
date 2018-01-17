###~~~Memory and Foraging Agent Based Model Version 3~~~###
#The goal of this agent based model is to allow flexible and efficient exploration of the impact of spatial memory an animal foraging.
#It will allow for manipulation of memory size, accuracy, and properties such as learning or forgetting rules.
#The model will incorporate aspects of optiomal foraging theory into the animal behavior, and additional allow for different
#navigational decision strategies. The model will then measure overall foraging efficiency given the different memory and
#navigation properties.

##Version 3.01 Notes:
#allowing agent to hav a diff memory of environment resources than actually is there


setClass("Forager", 
         slots= list(
           location = "numeric", # named vector of x and y
           memory = "numeric", #data frame with columns: patch name, x location, y location, resource value at departure, 
           #time since last visit, expected value
           optForageThresh = "numeric") #slot for optimal foraging threshold, where the animal will leave if it stops gaining
         # a certain amount of energy and will leave the current resource
) 
#define dem subclasses
setClass("Agent1", contains = "Forager")
setClass("Agent2", contains = "Forager")

#constructor of agent 1
agent1 <- function

#bunny <- new('Forager', location = , memory = c(runif(1,rangeMin, rangeMax),runif(1,rangeMin, rangeMax)),
#	         optForageThresh = runif(1,0,8))