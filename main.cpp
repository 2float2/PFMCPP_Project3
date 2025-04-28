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
    //5 properties:
    //    1) number of keys (int)
    int numOfKeys = 37;
    //    2) brand name (std::string)
    std::string brandName = "Novation Launchkey Mini";
    //    3) has arpeggiator (bool)
    bool arpeggiator = true;
    //    4) has step sequencer (bool)
    bool stepSequencer = false;
    //    5) key size (std::string)
    std::string keySize = "mini";
    //3 things it can do:
    //    1) transmit digital signal
    void transmitDigitalSignal();
    //    2) control virtual instruments
    void controlVirtualInstruments(std::string intrumentName);
    //    3) trigger loops
    void triggerLoops();
};

struct CoffeeMachine //2
{
    //5 properties:
    //    1) water tank capacity (float)
    float waterTankCapacity =1.7f;
    //    2) bean hopper capacity (float)
    float beanHopperCapacity = 1.2f;
    //    3) espresso shot volume (float)
    float espressoShotVolume = 0.5f;
    //    4) number of brew strength levels (int)
    int brewStrength = 3;
    //    5) steam temperature (double)
    double steamTemperature = 150.0;
    //3 things it can do:
    //    1) grind coffee beans
    void grindCoffeeBeans();
    //    2) brew espresso
    void brewEspresso();
    //    3) steam milk
    void steamMilk();
};

struct Skateboard //3
{
    //5 properties:
    //    1) deck length (double)
    double deckLengther = 115.0;
    //    2) wheel size (float)
    float wheelSize = 89.0f;
    //    3) wheel hardness (std::string)
    std::string wheelHardness = "medium";
    //    4) truck turning angle (int)
    int truckTurningAngle = 65;
    //    5) bearing type (std::string)
    std::string bearingType = "barrel";
    //3 things it can do:
    //    1) perform tricks
    void performTricks(std::string trickName);
    //    2) roll over ramps
    void rollOverRamps();
    //    3) carve along curves
    void carveAlongCurves();
};

struct DAWProject //4, Nested UDT
{
    //5 properties:
    //    1) time signature (std::string)
    std::string timeSignature = "3/4";
    //    2) musical mode (std::string)
    std::string musicalMode = "minor";
    //    3) key signature (std::string)
    std::string keySignature = "A";
    //    4) number of sections (int)
    int numOfSections = 120;
    //    5) is quantized (bool)
    bool isQuantized = true;

    struct VirtualStudioTechnology
    {
        //5 properties:
        std::string vstName = "Superior Drummer";
        std::string vstManufacturer = "Toontrack";
        std::string vstType = "virtual instrument";
        bool supportsMIDI = true;
        int numOfPresets = 100;

        //3 things it can do:
        void acceptMIDIInput();
        void outputAudio(double outputVolume = 80.0);
        void changePreset(std::string presetName);
    };

    //3 things it can do:
    //    1) play back the composition
    void playBackComposition();
    //    2) apply audio effects
    void applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse);    
    //    3) quantize notes
    void quantizeNotes();

    VirtualStudioTechnology virtualGuitar;

};

struct Stage //5
{
    //5 properties:
    //    1) number of monitor speakers (int)
    int numOfMonitorSpeakers = 10;
    //    2) number of microphones (int)
    int numOfMicrophones = 20;
    //    3) number of instrument stands (int)
    int numOfInstrumentStands = 20;
    //    4) stage width (double)
    double stageWidth = 40;
    //    5) stage depth (double)
    double stageDepth =20;
    //3 things it can do:
    //    1) support performer setup
    void supportPerformerSetup();
    //    2) transmit sound to FOH system
    void transmitSoundToFOHSystem();
    //    3) provide stage monitoring
    void provideStageMonitoring();
};

struct FrontOfHouseAudioSystem //6
{
    //5 properties:
    //    1) number of audio channels (int)
    int numOfAudioChannels = 12;
    //    2) number of speakers (int)
    int numOfSpeakers = 10;
    //    3) outpt wattage (float)
    float outputWattage = 1000.0f;
    //    4) type of mixing console (std::string)
    std::string typeOfMixingConsole = "DiGiCo";
    //    5) number of equalizer (int)
    //3 things it can do:
    //    1) amplify input signals
    void amplifyInputSignals();
    //    2) route sound to audience
    void routeSoundToAudience();
    //    3) adjust volume and EQ settings
    void adjustVolumeAndEQSettings();
};

struct BackstageArea //7
{
    //5 properties:
    //    1) number of lockers (int)
    int numOfLockers = 80;
    //    2) number of dressing rooms (int)
    int numOfDressingRooms =3;
    //    3) backstage area size (double)
    double backStageSize = 500.0;
    //    4) number of equiment storage shelves (int)
    int numOfEquimentStorageShelves = 10;
    //    5) has equipment loading access (bool)
    bool hasEquipmentLoadingAccess = true;
    //3 things it can do:
    //    1) provide resting space for performers
    void provideRestingSpaceForPerformers();
    //    2) store cables and instruments
    void storeCablesAndInstruments();
    //    3) provide storage for personal belongings
    void provideStorageForPersonalBelongings();
};

struct BarCounter //8
{
    //5 properties:
    //    1) number of drink options (int)
    int numOfDrinkOptions = 30;
    //    2) number of staff members (int)
    int numOfStaffMembers = 6;
    //    3) number of seats (int)
    int numOfSeats = 10;
    //    4) provides non-alcoholic drink (bool)
    bool providesNonAlcoholicDrink = true;
    //    5) has merchandise display area (bool)
    bool hasMerchandiseDisplayArea = true;
    //3 things it can do:
    //    1) serve drinks to customers
    void serveDrinksToCustomers();
    //    2) process payments
    void processPayments();
    //    3) sell band merchandise
    void sellBandMerchandise();
};

struct LightingRig //9, Nested UDT
{
    //5 properties:
    //    1) number of traditional lights (int)
    int numOfTraditionalLights = 12;
    //    2) number of computer lights (int)
    int numOfComputerLights = 35;
    //    3) number of control channels (int)
    int numOfControlChannels = 512;
    //    4) lighting console type (std::string)
    std::string lightingConsoleType = "MA Lighting";
    //    5) height of rig (double)
    double heightOfRig = 10.5;

    struct LightingConsole
    {
        //5 properties:
        std::string consoleName = "GrandMA3";
        int numOfScreens = 3;
        int numOfFaders = 64;
        bool hasInternetConnectivity = true;
        double weightOfConsole = 120.0;

        //3 things it can do:
        void panAndTiltLights(int lightNumber, double panAngle = 135.0, double tiltAngle = 45.0);
        void adjustLightIntensity(int lightNumber, double intensity = 100.0);
        void changeGoboPattern(int lightNumber, std::string patternName = "star");

    };

    //3 things it can do:
    //    1) illuminate the stage
    void illuminateTheStage();
    //    2) change lighting colors and patterns
    void changeLightingColorsAndPatterns(LightingConsole consoleInUse);
    //    3) synchronize lighting with music
    void synchronizeLightingWithMusic(LightingConsole consoleInUse);

    LightingConsole spareConsole;
};

struct Livehouse //10
{
    //5 properties:
    //    1) stage
    Stage stage;
    //    2) front of house audio system
    FrontOfHouseAudioSystem frontOfHouseAudioSystem;
    //    3) backstage area
    BackstageArea backstageArea;
    //    4) bar counter
    BarCounter barCounter;
    //    5) lighting rig
    LightingRig lightingRig;
    //3 things it can do:
    //    1) host live music performances
    void hostLiveMusicPerformances();
    //    2) serve drinks to attendees
    void serveDrinksToAttendees();
    //    3) mix sound and control stage lighting
    void mixSoundAndControlStageLighting();
};







int main()
{
    std::cout << "good to go!" << std::endl;
}
