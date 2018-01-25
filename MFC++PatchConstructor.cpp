//HEYYYYYY
/* We up in here doing C++ shit now, translating Alex's and Sam's R code into C++ to do the hard work and be fast af
We starting with the Patch class/constructor.
LETS GET POPPIN'!
*/
#include <iostream>
using namespace std;


//Patch class definition, 
class Patch {
    public: 
    	//constructor
        Patch(){

        } 
        virtual ~Patch(); //deconstructor
        
    private:
       int xLim,yLim; // the data types, we use ENSCAPULATION, or hiding important info from the user to make this 
       		          // data only accessible to us, the developers. 
}; // end a class definition with a semicolon
  

int main(){return 0;} // this is just here to show that all C++ programs need a main function; I'll probably remove it later though

                      // in good practice, we make a separate file for the class definition and a header file for the 
                      // class prototype (which we would call "PatchConstructor.cpp")











/*PatchA <- function(xlim, ylim) {                                  #constructor for patchA class
  ###input: "xlim" = maximum value for x coordinate of patch
  ###       "ylim" = maximum value for y coordinate of patch
  ###output: object of class patchA
  ###description: The location slot of output object will have x,y coordinates drawn from a uniform distribution between -xlim and xlim, and -ylim and ylim
  ###             The energy slot of output will have value of 5
  if(xlim <0 | ylim<0)
  {
    stop("must enter a positive value for xlim and ylim")
  }
  newPatchA <- new("patchA", location = c(runif(1, -xlim, xlim), runif(1, -ylim, ylim)), 
                   energy = 5)
  names(newPatchA@location) <- c('x', 'y')
  newPatchA
}*/
