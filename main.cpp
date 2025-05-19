/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.




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

void MIDIKeyboard::transmitDigitalSignal()
{
    std::cout << "Transmit digital signal" << std::endl;
}

void MIDIKeyboard::controlVirtualInstruments(std::string intrumentName)
{
    std::cout << "Adjust " << intrumentName << std::endl;
}

void MIDIKeyboard::triggerLoops()
{
    std::cout << "Trigger loops" << std::endl;
}

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

void CoffeeMachine::grindCoffeeBeans()
{
    std::cout << "Grind coffee beans" << std::endl;
}

void CoffeeMachine::brewEspresso()
{
    std::cout << "Brew espresso" << std::endl;
}

void CoffeeMachine::steamMilk()
{
    std::cout << "Steam milk" << std::endl;
}

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

void Skateboard::performTricks(std::string trickName)
{
    std::cout << "Perform " << trickName << std::endl;
}

void Skateboard::rollOverRamps()
{
    std::cout << "Roll over ramps" << std::endl;
}

void Skateboard::carveAlongCurves()
{
    std::cout << "Carve along curves" << std::endl;
}

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

void DAWProject::playBackComposition()
{
    std::cout << "Play back composition" << std::endl;
}

void DAWProject::applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse)
{
    std::cout << "Apply " << effectName << " of " << vstInUse.vstName << std::endl;
}

void DAWProject::quantizeNotes()
{
    std::cout << "Quantize notes" << std::endl;
}

void DAWProject::VirtualStudioTechnology::acceptMIDIInput()
{
    std::cout << "Accept MIDI input" << std::endl;
}

void DAWProject::VirtualStudioTechnology::outputAudio(double outputVolume)
{
    std::cout << "Output audio at " << outputVolume << "db" << std::endl;
}

void DAWProject::VirtualStudioTechnology::changePreset(std::string presetName)
{
    std::cout << "Change preset to" << presetName << std::endl;
}

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

void Stage::supportPerformerSetup()
{
    std::cout << "Support performer setup" << std::endl;
}

void Stage::transmitSoundToFOHSystem()
{
    std::cout << "Transmit sound to FOH system" << std::endl;
}

void Stage::provideStageMonitoring()
{
    std::cout << "Provide stage monitoring" << std::endl;
}

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

void FrontOfHouseAudioSystem::amplifyInputSignals()
{
    std::cout << "Amplify input signals" << std::endl;
}

void FrontOfHouseAudioSystem::routeSoundToAudience()
{
    std::cout << "Route sound to audience" << std::endl;
}

void FrontOfHouseAudioSystem::adjustVolumeAndEQSettings()
{
    std::cout << "Adjust volume and EQ settings" << std::endl;
}

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

void BackstageArea::provideRestingSpaceForPerformers()
{
    std::cout << "Provide resting space for performers" << std::endl;
}

void BackstageArea::storeCablesAndInstruments()
{
    std::cout << "Store cables and instruments" << std::endl;
}

void BackstageArea::provideStorageForPersonalBelongings()
{
    std::cout << "Provide storage for personal belongings" << std::endl;
}

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

void BarCounter::serveDrinksToCustomers()
{
    std::cout << "Serve drinks to customers" << std::endl;
}

void BarCounter::processPayments()
{
    std::cout << "Process payments" << std::endl;
}

void BarCounter::sellBandMerchandise()
{
    std::cout << "Sell band merchandise" << std::endl;
}

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

void LightingRig::illuminateTheStage()
{
    std::cout << "Illuminate the stage" << std::endl;
}

void LightingRig::changeLightingColorsAndPatterns(LightingConsole consoleInUse)
{
    std::cout << "Change lighting colors and patterns with " << consoleInUse.consoleName << std::endl;
}

void LightingRig::synchronizeLightingWithMusic(LightingConsole consoleInUse)
{
    std::cout << "Synchronize lighting with music using " << consoleInUse.consoleName << std::endl;
}

void LightingRig::LightingConsole::panAndTiltLights(int lightNumber, double panAngle, double tiltAngle)
{
    std::cout << "Pan and tilt light " << lightNumber << " to " << panAngle << " and " << tiltAngle << std::endl;
}

void LightingRig::LightingConsole::adjustLightIntensity(int lightNumber, double intensity)
{
    std::cout << "Adjust the intensity of light " << lightNumber << " to " << intensity << std::endl;
}

void LightingRig::LightingConsole::changeGoboPattern(int lightNumber, std::string patternName)
{
    std::cout << "Change the gobo pattern of light " << lightNumber << " to " << patternName << std::endl;
}

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

void Livehouse::hostLiveMusicPerformances()
{
    std::cout << "Host live music performances" << std::endl;
}

void Livehouse::serveDrinksToAttendees()
{
    std::cout << "Serve drinks to attendees" << std::endl;
}

void Livehouse::mixSoundAndControlStageLighting()
{
    std::cout << "Mix sound and control stage lighting" << std::endl;
}

int main()
{
    Example::main();

    //add your ocde here:
    
    
    std::cout << "good to go!" << std::endl;
}
