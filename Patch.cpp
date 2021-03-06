
#include <assert.h> // to use assert function
#include <cstdlib> // for srand() and rand()
#include <ctime> // for using time() to gen truly random numbers
#include <iostream> // use basic facilities like cout and cin

using namespace std;

//Patch class definition, 
class Patch {
	  private:  // Here are the data types, and they private b/c we want to use ENSCAPULATION,
              // or hiding important info from the user to make this data only accessible to us, the developers. 
	          // we can allow the user to make use of these in a safe way through getter and setter methods
	         // which will be explained in the public section
    	double location[2]; // location is coordinate pair, so should be array 
    	int energy = 0;
      public: 
    	//constructor prototype here and definition outside of class definition b/c its big so we save computing powerS
        Patch(){ //default constructor definition
        	location =  {0.0,0.0};  
        	energy = 0;
        }
        Patch(double xLim = 0.0 , double yLim =10.0, int Energy= 5); // special constructor (OVERLOADED) we will actually use
        //"generic" methods 
        void output(Patch patch); // I created this on my own to just display all the components of a patch object
        void growth(Patch patch);
        

        //setter methods: let u set the values of the data members
        void setLocation(double Location[2]){ //is there any better way to do this? like a pass by reference or something?
             location[0] = Location[0];
             location[1] = Location[1];
             // have to use subscripting. 
        }
        void setEnergy(int Energy){
        	energy = Energy;
        }
        //getter methods: let you see the values of the data members and use them. 
        double* getLocation(){
            return location;
        }
        int getEnergy(){
         	return energy;
        }
        //deconstructor, I don't think we need to really elaborate this guy b/c it just deallocates
         	              // all memory allocated by the constructor. 	
        ~Patch(){
        	cout<< "Patch destroyed :D\n";
        } 
};// end a class definition with a semicolon

//Patch implementation Code

/************************************
*  Custom Patch Constructor          *
*************************************/

//Constructor class definition defined outside of class definition
Patch::Patch(double xLim = 0.0 , double yLim =10.0, int Energy= 5){ // default values on fleeek
            assert(xLim < 0.0 && yLim < 0.0); // do checks real quick -> if want to be exactly as R code just need if() statement with cout
            location[0] = genRandUnifNum(-1 * xLim, xLim); //use subscripts to assign each location to the array
            location[1] = genRandUnifNum(-1 * yLim,yLim); //idk about how you "name" an array (what the equivalent of what we think is an R vector) in c++, you just
            setEnergy(Energy);
            cout << "You just created a patch\n";
            Patch::output(); // maybe I should use "this" in front?
            cout<< "\n";	
}
//output definition, if want to display newly created object, just pass it to this method after invoking Patch(). 
void Patch::output(){
	cout<<"Location: ("<< location[0]<<","<<location[1]<<")\n";
	cout<< "Energy: "<< energy<<endl;
}

/************************************
*  Growth Method Definition         *
*************************************/
void Patch::growth(){
	energy +=1;
	Patch::output(); // maybe need "this" keyword at front?
}
/************************************
*  Extraction Method Definition     *
*************************************/
void Patch::extraction(){
   energy = 4 * energy / 5.0; 
   Patch::output(); // maybe need "this" keyword at front
}





/*
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

    // lol I chose to abandon the below code for basic C functions srand() and rand() to generate random (I think uniform) numbers 
   
	// random_device rd;  //Will be used to obtain a seed for the random number engine -> CYRUS NOTE: this is actually PSEUDO-random, not random,
 //    		           // I need to find a way to seed it with the current time so it is truly random. 
 //    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd() -> CYRUS NOTE: 
 //    uniform_real_distribution<> dis((double)a, (double)b); // create uniform random number generator between a and b
 //                                                           // notice that I typecast a and b as doubles because the uniform real distribution
 //                                                           // function only accepts doubles as arguments and outputs doubles too. 
 //    xlim = dis(gen); // idk what gen or dis does lmao
 //    ylim = dis(gen);
		  
}*/

                 // in good practice, we make a separate file for the class definition and a header file for the 
                // class prototype (which we would call "PatchConstructor.h")

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
