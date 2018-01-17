#allowing agent to hav a diff memory of environment resources than actually is there


setClass("Forager", 
	     slots= list(
	     	location = "numeric", # named vector of x and y
	     	memory = "numeric", #data frame with columns: patch name, x location, y location, resource value at departure, 
	     	                    #time since last visit, expected value
	     	optForageThresh = "numeric") #slot for optimal foraging threshold, where the animal will leave if it stops gaining
	     									# a certain amount of energy and will leave the current resource
) 
#constructor 
forager<- function(location = c(runif(1,0, 10),runif(1,0, 10)), 
	               memory = data.frame(patchName = "grass", xLocation = runif(1,0,10), yLocation = runif(1,0,10), 
	               	                   resourceValAtDeparture = 3, timeSinceLastVisit  = 46, expectedValue = 87
	               	                   ),
	               optForageThresh = runif(1,0,20)
	               ) 
{
                   if(!length(location) == 2) stop ("location must be length 2")
                   if(!ncol(memory) == 6) stop ("memory should be a data frame with 6 columns")
                   newForager <- new("Forager", location = location, memory = memory, optForageThresh = optForageThresh)
                   names(newForager@location) <- c('x', 'y')
                   names(newForager@memory$xLocation) = 'x'
                   names(newForager@memory$yLocation) = 'y'
                   newForager
}
