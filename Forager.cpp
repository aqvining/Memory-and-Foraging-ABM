#include <assert.h> // to use assert function
#include <cstdlib> // for srand() and rand()
#include <ctime> // for using time() to gen truly random numbers
#include <iostream> // use basic facilities like cout and cin
#include <string> // to declare strings for naming and stuff

using namespace std;

class Forager{
   private:
    	double location[2]; // location is coordinate pair, so should be array 
    	int optForageThresh;     
   public:
      Forager(){ location[2] = {0.0,0.0};optForageThresh = 0;  } // default constructor prototype
      //custom constructor prototype
      Forager(double location[2] = {genRandUnifNum(), genRandUnifNum()}, Memory memory, optForageThresh = 0);

      struct Memory{
         String patchName = "grass";
         double xLocation = genRandUnifNum();
         double yLocation = genRandUnifNum(); 
         int resourceValAtDeparture = 3;
         int  timeSinceLastVisit  = 46;
         int expectedValue = 87;
      };
      Memory memory; // need to instantiate struct inside class so we can refer to inside pieces of the struct from 
                       // operators on the class object

      //setters
      void setLocation(double Location[2]){
         location[0] = Location[0];
         location[1] = Location[1];
      }
      void setOptForageThresh(int thresh){
         optForageThresh = thresh;
      }
      /*void setMemory(Memory* memInput){
         *memory.xLocation = *memInput.xLocation;
         *memory.yLocation = *memInput.yLocation;
         *memory.resourceValAtDeparture = *memInput.resourceValAtDeparture;
         *memory.timeSinceLastVisit = *memInput.timeSinceLastVisit;
         *memory.expectedValue = *memInput.expectedValue;
      }*/
      //getters
      double* getLocation(){
         return location;
      }
      int getoptForageThresh(){
      	return optForageThresh;
      }
     /* Memory getMemory(){
      	return memory; 
      }*/
      ~Forager(){//deconstructor
      	cout<<"Forager destroyed\n";
      } 
};
Forager::Forager(double Location[2] = {genRandUnifNum(), genRandUnifNum()}, Memory memInput, OptForageThresh = 0){
   assert(optForageThresh > 0);
   location[0] = Location[0];
   location[1] = Location[1];
   optForageThresh = OptForageThresh;
   memory.xLocation = memInput.xLocation;
   memory.yLocation = memInput.yLocation;
   memory.resourceValAtDeparture = memInput.resourceValAtDeparture;
   memory.timeSinceLastVisit = memInput.timeSinceLastVisit;
   memory.expectedValue = memInput.expectedValue;
   cout<<"Forager created\n";
}
/*
//this function randomly generates numbers on the uniform distribution 
double genRandUnifNum(double a = 0.0, double b = 10.0){
	// random_device rd;  //Will be used to obtain a seed for the random number engine -> CYRUS NOTE: this is actually PSEUDO-random, not random,
 //    		           // I need to find a way to seed it with the current time so it is truly random. 
 //    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd() -> CYRUS NOTE: 
 //    uniform_real_distribution<> dis((double)a, (double)b); // create uniform random number generator between a and b
 //                                                           // notice that I typecast a and b as doubles because the uniform real distribution
 //                                                           // function only accepts doubles as arguments and outputs doubles too. 
 //    xlim = dis(gen); // idk what gen or dis does lmao
 //    ylim = dis(gen);
	// lol I chose to abandon the above code for basic C functions srand() and rand() to generate random (I think uniform) numbers 
	   srand(time(0)); // initialize random seed, this might need to belong in the main function or global IDK
	   //normally we wouldn't do so much with this next line, but we trying to randomly generate doubles, not ints. 
       double randNum = a + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX/(a-b))); // heavily borrowed from stack overflow
       return randNum;
}


*/