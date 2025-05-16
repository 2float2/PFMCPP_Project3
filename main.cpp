 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Feet
{
    void stepForward()
    {
        std::cout << "Step forward" << std::endl;
    }
    int stepSize()
    {
        return 8;
    }
};

struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;
    Feet leftFoot;
    Feet rightFoot;

    void run(int howFast, bool startWithLeftFoot);
};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    distanceTraveled += leftFoot.stepSize() + rightFoot.stepSize();
}

 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct MIDIKeyboard //1
{
    int numOfKeys = 37;
    std::string brandName = "Novation Launchkey Mini";
    bool arpeggiator = true;
    bool stepSequencer = false;
    std::string keySize = "mini";

    void transmitDigitalSignal();
    void controlVirtualInstruments(std::string intrumentName);
    void triggerLoops();
};

struct CoffeeMachine //2
{
    float waterTankCapacity =1.7f;
    float beanHopperCapacity = 1.2f;
    float espressoShotVolume = 0.5f;
    int brewStrength = 3;
    double steamTemperature = 150.0;

    void grindCoffeeBeans();
    void brewEspresso();
    void steamMilk();
};

struct Skateboard //3
{
    double deckLengther = 115.0;
    float wheelSize = 89.0f;
    std::string wheelHardness = "medium";
    int truckTurningAngle = 65;
    std::string bearingType = "barrel";

    void performTricks(std::string trickName);
    void rollOverRamps();
    void carveAlongCurves();
};

struct DAWProject //4, Nested UDT
{
    std::string timeSignature = "3/4";
    std::string musicalMode = "minor";
    std::string keySignature = "A";
    int numOfSections = 120;
    bool isQuantized = true;

    struct VirtualStudioTechnology
    {
        std::string vstName = "Superior Drummer";
        std::string vstManufacturer = "Toontrack";
        std::string vstType = "virtual instrument";
        bool supportsMIDI = true;
        int numOfPresets = 100;

        void acceptMIDIInput();
        void outputAudio(double outputVolume = 80.0);
        void changePreset(std::string presetName);
    };

    
    void playBackComposition();
    void applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse);    
    void quantizeNotes();

    VirtualStudioTechnology virtualGuitar;

};

struct Stage //5
{
    int numOfMonitorSpeakers = 10;
    int numOfMicrophones = 20;
    int numOfInstrumentStands = 20;
    double stageWidth = 40;
    double stageDepth =20;

    void supportPerformerSetup();
    void transmitSoundToFOHSystem();
    void provideStageMonitoring();
};

struct FrontOfHouseAudioSystem //6
{
    int numOfAudioChannels = 12;
    int numOfSpeakers = 10;
    float outputWattage = 1000.0f;
    std::string brandName = "DiGiCo";
    std::string typeOfMixingConsole = "sd12";

    void amplifyInputSignals();
    void routeSoundToAudience();
    void adjustVolumeAndEQSettings();
};

struct BackstageArea //7
{
    int numOfLockers = 80;
    int numOfDressingRooms =3;
    double backStageSize = 500.0;
    int numOfEquimentStorageShelves = 10;
    bool hasEquipmentLoadingAccess = true;
    
    void provideRestingSpaceForPerformers();
    void storeCablesAndInstruments();
    void provideStorageForPersonalBelongings();
};

struct BarCounter //8
{
    int numOfDrinkOptions = 30;
    int numOfStaffMembers = 6;
    int numOfSeats = 10;
    bool providesNonAlcoholicDrink = true;
    bool hasMerchandiseDisplayArea = true;
    
    void serveDrinksToCustomers();
    void processPayments();
    void sellBandMerchandise();
};

struct LightingRig //9, Nested UDT
{
    int numOfTraditionalLights = 12;
    int numOfComputerLights = 35;
    int numOfControlChannels = 512;
    std::string lightingConsoleType = "MA Lighting";
    double heightOfRig = 10.5;

    struct LightingConsole
    {
        std::string consoleName = "GrandMA3";
        int numOfScreens = 3;
        int numOfFaders = 64;
        bool hasInternetConnectivity = true;
        double weightOfConsole = 120.0;

        void panAndTiltLights(int lightNumber, double panAngle = 135.0, double tiltAngle = 45.0);
        void adjustLightIntensity(int lightNumber, double intensity = 100.0);
        void changeGoboPattern(int lightNumber, std::string patternName = "star");

    };
    
    void illuminateTheStage();
    void changeLightingColorsAndPatterns(LightingConsole consoleInUse);
    void synchronizeLightingWithMusic(LightingConsole consoleInUse);

    LightingConsole spareConsole;
};

struct Livehouse //10
{
    Stage stage;
    FrontOfHouseAudioSystem frontOfHouseAudioSystem;
    BackstageArea backstageArea;
    BarCounter barCounter;
    LightingRig lightingRig;
    
    void hostLiveMusicPerformances();
    void serveDrinksToAttendees();
    void mixSoundAndControlStageLighting();
};







int main()
{
    std::cout << "good to go!" << std::endl;
}
