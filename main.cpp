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
    MIDIKeyboard();

    int numOfKeys = 37;
    std::string brandName = "Novation Launchkey Mini";
    bool arpeggiator = true;
    bool stepSequencer = false;
    std::string keySize = "mini";

    void transmitDigitalSignal();
    void controlVirtualInstruments(std::string intrumentName);
    void triggerLoops();
};

MIDIKeyboard::MIDIKeyboard()
{
    std::cout << "\nMIDIKeyboard being constructed!" << std::endl;
}

void MIDIKeyboard::transmitDigitalSignal()
{
    std::cout << "\nTransmit digital signal!" << std::endl;
}

void MIDIKeyboard::controlVirtualInstruments(std::string intrumentName)
{
    std::cout << "\nAdjust " << intrumentName << std::endl;
}

void MIDIKeyboard::triggerLoops()
{
    std::cout << "\nTrigger loops" << std::endl;
}

struct CoffeeMachine //2
{
    CoffeeMachine();

    float waterTankCapacity =1.7f;
    float beanHopperCapacity = 1.2f;
    float espressoShotVolume = 0.5f;
    int brewStrength = 3;
    double steamTemperature = 150.0;

    void grindCoffeeBeans();
    void brewEspresso();
    void steamMilk();
};

CoffeeMachine::CoffeeMachine()
{
    std::cout << "\nCoffeeMachine being constructed!" << std::endl;
}

void CoffeeMachine::grindCoffeeBeans()
{
    std::cout << "\nGrind coffee beans" << std::endl;
}

void CoffeeMachine::brewEspresso()
{
    std::cout << "\nBrew espresso" << std::endl;
}

void CoffeeMachine::steamMilk()
{
    std::cout << "\nSteam milk" << std::endl;
}

struct Skateboard //3
{
    Skateboard();

    double deckLength = 115.0;
    float wheelSize = 89.0f;
    std::string wheelHardness = "medium";
    int truckTurningAngle = 65;
    std::string bearingType = "barrel";

    void performTricks(std::string trickName);
    void rollOverRamps();
    void carveAlongCurves();
};

Skateboard::Skateboard()
{
    std::cout << "\nSkateboard being construted!" << std::endl;
}

void Skateboard::performTricks(std::string trickName)
{
    std::cout << "\nPerform " << trickName << std::endl;
}

void Skateboard::rollOverRamps()
{
    std::cout << "\nRoll over ramps" << std::endl;
}

void Skateboard::carveAlongCurves()
{
    std::cout << "\nCarve along curves" << std::endl;
}

struct DAWProject //4, Nested UDT
{
    DAWProject();

    std::string timeSignature = "3/4";
    std::string musicalMode = "minor";
    std::string keySignature = "A";
    int numOfSections = 120;
    bool isQuantized = true;

    struct VirtualStudioTechnology
    {
        VirtualStudioTechnology();

        std::string vstName = "Superior Drummer";
        std::string vstManufacturer = "Toontrack";
        std::string vstType = "virtual instrument";
        bool supportsMIDI = true;
        int numOfPresets = 100;

        void acceptMIDIInput();
        void outputAudio(double outputVolume = 80.0);
        std::string changePreset(std::string presetName);
    };

    
    void playBackComposition();
    void applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse);    
    void quantizeNotes();

    VirtualStudioTechnology virtualGuitar;

};

DAWProject::VirtualStudioTechnology::VirtualStudioTechnology()
{
    std::cout << "\nVirtualStudioTechnology being constructed!" << std::endl;
}

DAWProject::DAWProject()
{
    std::cout << "\nDAWProject being constructed!" << std::endl;
}

void DAWProject::playBackComposition()
{
    std::cout << "\nPlay back composition" << std::endl;
}

void DAWProject::applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse)
{
    std::cout << "\nApply " << effectName << " of " << vstInUse.vstName << std::endl;
}

void DAWProject::quantizeNotes()
{
    std::cout << "\nQuantize notes" << std::endl;
}

void DAWProject::VirtualStudioTechnology::acceptMIDIInput()
{
    std::cout << "\nAccept MIDI input" << std::endl;
}

void DAWProject::VirtualStudioTechnology::outputAudio(double outputVolume)
{
    std::cout << "\nOutput audio at " << outputVolume << "db" << std::endl;
}

std::string DAWProject::VirtualStudioTechnology::changePreset(std::string presetName)
{
    return presetName;
}

struct Stage //5
{
    Stage();

    int numOfMonitorSpeakers = 10;
    int numOfMicrophones = 20;
    int numOfInstrumentStands = 20;
    double stageWidth = 40;
    double stageDepth =20;

    void supportPerformerSetup();
    void transmitSoundToFOHSystem();
    void provideStageMonitoring();
};

Stage::Stage()
{
    std::cout << "\nStage being construted!" << std::endl;
}

void Stage::supportPerformerSetup()
{
    std::cout << "\nSupport performer setup" << std::endl;
}

void Stage::transmitSoundToFOHSystem()
{
    std::cout << "\nTransmit sound to FOH system" << std::endl;
}

void Stage::provideStageMonitoring()
{
    std::cout << "\nProvide stage monitoring" << std::endl;
}

struct FrontOfHouseAudioSystem //6
{
    FrontOfHouseAudioSystem();

    int numOfAudioChannels = 12;
    int numOfSpeakers = 10;
    float outputWattage = 1000.0f;
    std::string brandName = "DiGiCo";
    std::string typeOfMixingConsole = "sd12";

    void amplifyInputSignals();
    void routeSoundToAudience();
    void adjustVolumeAndEQSettings();
};

FrontOfHouseAudioSystem::FrontOfHouseAudioSystem()
{
    std::cout << "\nFrontOfHouseAudioSystem being construted!" << std::endl;
}

void FrontOfHouseAudioSystem::amplifyInputSignals()
{
    std::cout << "\nAmplify input signals" << std::endl;
}

void FrontOfHouseAudioSystem::routeSoundToAudience()
{
    std::cout << "\nRoute sound to audience" << std::endl;
}

void FrontOfHouseAudioSystem::adjustVolumeAndEQSettings()
{
    std::cout << "\nAdjust volume and EQ settings" << std::endl;
}

struct BackstageArea //7
{
    BackstageArea();

    int numOfLockers = 80;
    int numOfDressingRooms =3;
    double backStageSize = 500.0;
    int numOfEquimentStorageShelves = 10;
    bool hasEquipmentLoadingAccess = true;
    
    void provideRestingSpaceForPerformers();
    void storeCablesAndInstruments();
    void provideStorageForPersonalBelongings();
};

BackstageArea::BackstageArea()
{
    std::cout << "\nBackstageArea being constructed!" << std::endl;
}

void BackstageArea::provideRestingSpaceForPerformers()
{
    std::cout << "\nProvide resting space for performers" << std::endl;
}

void BackstageArea::storeCablesAndInstruments()
{
    std::cout << "\nStore cables and instruments" << std::endl;
}

void BackstageArea::provideStorageForPersonalBelongings()
{
    std::cout << "\nProvide storage for personal belongings" << std::endl;
}

struct BarCounter //8
{
    BarCounter();
    
    int numOfDrinkOptions = 30;
    int numOfStaffMembers = 6;
    int numOfSeats = 10;
    bool providesNonAlcoholicDrink = true;
    bool hasMerchandiseDisplayArea = true;
    
    void serveDrinksToCustomers();
    void processPayments();
    void sellBandMerchandise();
};

BarCounter::BarCounter()
{
    std::cout << "\nBarCounter being constructed!" << std::endl;
}

void BarCounter::serveDrinksToCustomers()
{
    std::cout << "\nServe drinks to customers" << std::endl;
}

void BarCounter::processPayments()
{
    std::cout << "\nProcess payments" << std::endl;
}

void BarCounter::sellBandMerchandise()
{
    std::cout << "\nSell band merchandise" << std::endl;
}

struct LightingRig //9, Nested UDT
{
    LightingRig();

    int numOfTraditionalLights = 12;
    int numOfComputerLights = 35;
    int numOfControlChannels = 512;
    std::string lightingConsoleType = "MA Lighting";
    double heightOfRig = 10.5;

    struct LightingConsole
    {
        LightingConsole();

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

    LightingConsole mainConsole;
};

LightingRig::LightingConsole::LightingConsole()
{
    std::cout << "\nLightingConsole being constructed!" << std::endl;
}

LightingRig::LightingRig()
{
    std::cout << "\nLighitngRig being constructed!" << std::endl;
}

void LightingRig::illuminateTheStage()
{
    std::cout << "\nIlluminate the stage" << std::endl;
}

void LightingRig::changeLightingColorsAndPatterns(LightingConsole consoleInUse)
{
    std::cout << "\nChange lighting colors and patterns with " << consoleInUse.consoleName << std::endl;
}

void LightingRig::synchronizeLightingWithMusic(LightingConsole consoleInUse)
{
    std::cout << "\nSynchronize lighting with music using " << consoleInUse.consoleName << std::endl;
}

void LightingRig::LightingConsole::panAndTiltLights(int lightNumber, double panAngle, double tiltAngle)
{
    std::cout << "\nPan and tilt light " << lightNumber << " to " << panAngle << " and " << tiltAngle << std::endl;
}

void LightingRig::LightingConsole::adjustLightIntensity(int lightNumber, double intensity)
{
    std::cout << "\nAdjust the intensity of light " << lightNumber << " to " << intensity << std::endl;
}

void LightingRig::LightingConsole::changeGoboPattern(int lightNumber, std::string patternName)
{
    std::cout << "\nChange the gobo pattern of light " << lightNumber << " to " << patternName << std::endl;
}

struct Livehouse //10
{
    Livehouse();

    Stage stage;
    FrontOfHouseAudioSystem frontOfHouseAudioSystem;
    BackstageArea backstageArea;
    BarCounter barCounter;
    LightingRig lightingRig;
    
    void hostLiveMusicPerformances();
    void serveDrinksToAttendees();
    std::string mixSoundAndControlStageLighting(std::string AudioSystemName = "DiGiCo", std::string LightingConsoleName = "GrandMA3");
};

Livehouse::Livehouse()
{
    std::cout << "\nLivehouse being constructed!" << std::endl;
}

void Livehouse::hostLiveMusicPerformances()
{
    std::cout << "\nHost live music performances" << std::endl;
}

void Livehouse::serveDrinksToAttendees()
{
    std::cout << "\nServe drinks to attendees" << std::endl;
}

std::string Livehouse::mixSoundAndControlStageLighting(std::string AudioSystemName, std::string LightingConsoleName)
{
    return AudioSystemName + " and " + LightingConsoleName;
}

int main()
{
    Example::main();

    //add your code here:
    MIDIKeyboard mdk;
    std::cout << "----------------\n";
    
    CoffeeMachine cfm;
    std::cout << "----------------\n";
    
    Skateboard skb;
    std::cout << "----------------\n";
    
    DAWProject dawp;
    std::cout << "----------------\n";
    
    DAWProject::VirtualStudioTechnology vst;
    std::cout << "----------------\n";
    
    Stage stg;
    std::cout << "----------------\n";
    
    FrontOfHouseAudioSystem foh;
    std::cout << "----------------\n";
    
    BackstageArea bsa;
    std::cout << "----------------\n";
    
    BarCounter bc;
    std::cout << "----------------\n";
    
    LightingRig ltr;
    std::cout << "----------------\n";
    
    LightingRig::LightingConsole lc;
    std::cout << "----------------\n";
    
    Livehouse lvh;
    std::cout << "----------------\n";
    
    
    mdk.transmitDigitalSignal();
    mdk.controlVirtualInstruments("virtual cello");
    mdk.triggerLoops();
    std::cout << "\n[Print] The midiKeyboard has " << mdk.numOfKeys << " keys." << std::endl;
    std::cout << "\n[Print] Is the arpeggiator mode on? " << (mdk.arpeggiator ? "Yes" : "No") << std::endl;
    std::cout << "\n[Print] Is the step sequencer mode on? " << (mdk.stepSequencer ? "Yes" : "No") << std::endl;
    std::cout << "----------------\n";


    
    cfm.grindCoffeeBeans();
    cfm.brewEspresso();
    cfm.steamMilk();
    std::cout << "\n[Print] Current steam temperature is " << cfm.steamTemperature << " degrees." << std::endl;
    std::cout << "----------------\n";


    
    skb.performTricks("Peterpan");
    skb.rollOverRamps();
    skb.carveAlongCurves();
    std::cout << "\n[Print] The deck length of the skateboard is " << skb.deckLength << "mm." << std::endl;
    std::cout << "----------------\n";


    
    dawp.playBackComposition();
    dawp.applyAudioEffects("reverb", dawp.virtualGuitar);
    dawp.quantizeNotes();
    std::cout << "\n[Print] A " << dawp.virtualGuitar.vstName << " is being used." << std::endl;
    std::cout << "\n[Print] Is the project quantized? " << (dawp.isQuantized ? "Yes" : "No") << std::endl;
    std::cout << "----------------\n";


    
    vst.acceptMIDIInput();
    vst.outputAudio();
    vst.changePreset("Punk");
    std::cout << "\n[Print] The preset has been changed to [" << vst.changePreset("Jazz") << "]." << std::endl;
    std::cout << "----------------\n";


    
    stg.supportPerformerSetup();
    stg.transmitSoundToFOHSystem();
    stg.provideStageMonitoring();
    std::cout << "\n[Print] There are " << stg.numOfMonitorSpeakers << " monitor speakers on the stage." << std::endl;
    std::cout << "----------------\n";


    
    foh.amplifyInputSignals();
    foh.routeSoundToAudience();
    foh.adjustVolumeAndEQSettings();
    std::cout << "\n[Print] The output wattage of the FOH system is " << foh.outputWattage << "W." << std::endl;
    std::cout << "----------------\n";


    
    bsa.provideRestingSpaceForPerformers();
    bsa.storeCablesAndInstruments();
    bsa.provideStorageForPersonalBelongings();
    std::cout << "\n[Print] There are " << bsa.numOfLockers << " lockers in the backstage area." << std::endl;
    std::cout << "----------------\n";


    
    bc.serveDrinksToCustomers();
    bc.processPayments();
    bc.sellBandMerchandise();
    std::cout << "\n[Print] There are " << bc.numOfDrinkOptions << " drink options on the bar counter." << std::endl;
    std::cout << "----------------\n";


    
    ltr.illuminateTheStage();
    ltr.changeLightingColorsAndPatterns(ltr.mainConsole);
    ltr.synchronizeLightingWithMusic(ltr.mainConsole);
    std::cout << "\n[Print] The lighting console type is " << ltr.lightingConsoleType << "." << std::endl;
    std::cout << "----------------\n";


    
    lc.panAndTiltLights(5, 135.0, 60.0);
    lc.adjustLightIntensity(1, 100.0);
    lc.changeGoboPattern(2, "star");
    std::cout << "\n[Print] The lighting console has " << lc.numOfFaders << " faders." << std::endl;
    std::cout << "----------------\n";


    
    lvh.hostLiveMusicPerformances();
    lvh.serveDrinksToAttendees();
    lvh.mixSoundAndControlStageLighting();
    std::cout << "\n[Print] The livehouse is using " << lvh.mixSoundAndControlStageLighting() << " consoles to mix sound and control stage lighting." << std::endl;
    std::cout << "----------------\n";


    
    std::cout << "good to go!" << std::endl;
}
