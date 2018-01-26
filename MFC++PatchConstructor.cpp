//HEYYYYYY
/* We up in here doing C++ shit now, translating Alex's and Sam's R code into C++ to do the hard work and be fast af
We starting with the Patch class/constructor.
LETS GET POPPIN'!
*/
#include <assert.h> // to use assert function
#include <iostream> // use basic facilities like cout and cin
#include <random> // to generate random 
using namespace std;

double genRandNum(int a, int b); // function prototype

//Patch class definition, 
class Patch {
	  private:  // Here are the data types, and they private b/c we want to use ENSCAPULATION,
              // or hiding important info from the user to make this data only accessible to us, the developers. 
	          // we can allow the user to make use of these in a safe way through getter and setter methods
	         // which will be explained in the public section
    	double location[2]; // location is coordinate pair, so should be array 
    	int energy; 
    public: 
    	//constructor
        Patch(double xLim = 0 , double yLim =10, int Energy= 5){
            if(xLim < 0.0 || yLim < 0.0){
               assert("must enter a positive value for xlim and ylim"); // just like "stop" in R, but need to change the syntax lolw
            }     
             setLocation(xLim, yLim);
            
             setEnergy(Energy);
             cout << 
        }
        //getters and setters
        void setLocation(double xLim, double yLim){
           location[0] = genRandNum(-1 * xLim, xLim); //use subscripts to assign each location to the array
           location[1] = genRandNum(-1 * yLim,ylim); //idk about how you "name" an array (what the equivalent of what we think is an R vector) in c++, you just
             // have to use subscripting. 
        }
        void setEnergy(int Energy){
        	energy = Energy;
        }
        double* getLocation(){

        }
       


        virtual ~Patch(){} //deconstructor, I don't think we need to really elaborate this guy b/c it just deallocates
         	              // all memory allocated by the constructor. 	
        
  
     
}; // end a class definition with a semicolon
  

int main(){
   // lets start here and randomly generate xlim and ylim
	int a,b; // I'm letting you enter integers for convenience, but if you cool with doubles, let me know and I'll change this. 
    cout<<"Enter a and b for the uniform distribution!\n";
    cout<<"Do \"a\" first: ";
    cin>>a;
    cout<<"Now input \"b\": ";
    cin>>b;
    /*I used code on this website: http://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
    *to help me create the randomly generated uniform distribution
    */
   
    Patch patchA(); // instantiate a Patch using constructor -> can pass energy, xlim and ylim as arguments. 


    return 0;
}  //I'll probably move this main function to another file soon and create header files and stuff

double genRandNum(int a = 0, int b = 10){
	random_device rd;  //Will be used to obtain a seed for the random number engine -> CYRUS NOTE: this is actually PSEUDO-random, not random,
    		           // I need to find a way to seed it with the current time so it is truly random. 
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd() -> CYRUS NOTE: 
    uniform_real_distribution<> dis((double)a, (double)b); // create uniform random number generator between a and b
                                                           // notice that I typecast a and b as doubles because the uniform real distribution
                                                           // function only accepts doubles as arguments and outputs doubles too. 
    xlim = dis(gen); // idk what gen or dis does lmao
    ylim = dis(gen);
}

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
