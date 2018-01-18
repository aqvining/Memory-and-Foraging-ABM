setClass("foragerA", slots = list(location = "numeric", memory = "data.frame", optForageThresh = "numeric")) #simplified

ForagerA<- function(location = c(runif(1,0, 10),runif(1,0, 10)), #instead of set values (0,10) can you have this take input xlim and ylim, then draw from -xlim to xlim (and same for y)
	               memory = data.frame(patchName = "grass", xLocation = runif(1,0,10), yLocation = runif(1,0,10), 
	               	                   resourceValAtDeparture = 3, timeSinceLastVisit  = 46, expectedValue = 87
	               	                   ), #instead of assigning values to this dataframe, please make it an empty struction
	               optForageThresh = 0 #I changed this to 0 (a naive forager should eat any food available, not knowing if it will find any more)
	               ) 
{
                   if(!length(location) == 2) stop ("location must be length 2") #good checks, thanks
                   if(!ncol(memory) == 6) stop ("memory should be a data frame with 6 columns")
                   newForager <- new("Forager", location = location, memory = memory, optForageThresh = optForageThresh)
                   names(newForager@location) <- c('x', 'y')
                   names(newForager@memory$xLocation) = 'x'
                   names(newForager@memory$yLocation) = 'y'
                   newForager
}
