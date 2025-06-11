/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to EACH of your types. 
 
 2) inside these new member functions, use while() and for() loops to do something interesting 
         a) example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
    Your code should produce a lot of console output now.

 5) Remember to use pre-increment/decrement in your loops. 
 You can learn why post-increment/decrement is not ideal here:
 https://en.cppreference.com/w/cpp/language/operator_incdec 
 
 6) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //1), 2c) 
    {
        Bar bar(startingVal);                //2a)
        while( bar.num < threshold )         //2a) 
        { 
            ++bar.num;                    //2a), 5)
            std::cout << "  increasing bar.num: " << bar.num << std::endl; //4)
            if( bar.num >= threshold )       //2b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //3) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //4) 
    return 0;
}
}

//call Example::main() in main()



struct MIDIKeyboard //1
{
    MIDIKeyboard();

    int numOfKeys;
    std::string keySize;
    std::string brandName;
    bool arpeggiator = true;
    bool stepSequencer = false;
    

    void transmitDigitalSignal();
    void controlVirtualInstruments(std::string intrumentName);
    void triggerLoops();
    void recordLoops(int stepCount = 16);
};

MIDIKeyboard::MIDIKeyboard() :
numOfKeys(37),
keySize("mini")
{
    brandName = "Novation Launchkey Mini";
    std::cout << "\nMIDIKeyboard being constructed!" << std::endl;
}

void MIDIKeyboard::transmitDigitalSignal()
{
    std::cout << "\n" << brandName << " transmit digital signal!" << std::endl;
}

void MIDIKeyboard::controlVirtualInstruments(std::string intrumentName)
{
    std::cout << "\nAdjust " << intrumentName << std::endl;
}

void MIDIKeyboard::triggerLoops()
{
    std::cout << "\nTrigger loops" << std::endl;

}

void MIDIKeyboard::recordLoops(int stepCount)
{
    int layerNum = 1;
    while(layerNum <= stepCount)
    {
        std::cout << "\n[Loop] The step sequencer is recording layer [" << layerNum << "]" << std::endl;
        ++layerNum;

        if(layerNum > stepCount)
            std::cout << "\n[Loop] The step sequencer has ran out of layers to record" << std::endl;
    }
}

struct CoffeeMachine //2
{
    CoffeeMachine();

    float waterTankCapacity, beanHopperCapacity, espressoShotVolume;
    int brewStrength;
    double steamTemperature = 150.0;

    void grindCoffeeBeans();
    void brewEspresso();
    void steamMilk();
    void extractEspresso(int extractTime = 25);
        
};

CoffeeMachine::CoffeeMachine() :
waterTankCapacity(1.7f),
beanHopperCapacity(1.2f),
espressoShotVolume(0.5f),
brewStrength(3)
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
    std::cout << "\nSteam milk at " << steamTemperature << " degrees" << std::endl;
}

void CoffeeMachine::extractEspresso(int extractTime)
{
    for(int i = 0; i < extractTime; ++i)
    {
        std::cout << "\n[Loop] Extraction will be complete in " << extractTime - i << " seconds" << std::endl;
    }
    std::cout << "\n[Loop] Extraction complete!" << std::endl;
}

struct Skateboard //3
{
    Skateboard();

    int truckTurningAngle = 65;
    float wheelSize;
    double deckLength;
    std::string wheelHardness;
    std::string bearingType = "barrel";

    void performTricks(std::string trickName);
    void rollOverRamps();
    void carveAlongCurves();
};

Skateboard::Skateboard() :
wheelSize(89.0f),
deckLength(115.0),
wheelHardness("medium")
{
    std::cout << "\nSkateboard being construted!" << std::endl;
}

void Skateboard::performTricks(std::string trickName)
{
    std::cout << "\nPerform " << trickName << " on a " << deckLength << " mm long board" << std::endl;

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
    int numOfSections;
    bool isQuantized;

    struct VirtualStudioTechnology
    {
        VirtualStudioTechnology();

        std::string vstName;
        std::string vstManufacturer;
        std::string vstType;
        bool supportsMIDI = true;
        int numOfPresets;

        void acceptMIDIInput();
        void outputAudio(double outputVolume = 80.0);
        std::string changePreset(std::string presetName);
    };

    
    void playBackComposition();
    void applyAudioEffects(std::string effectName, VirtualStudioTechnology vstInUse);    
    void quantizeNotes();

    VirtualStudioTechnology virtualGuitar;

};

DAWProject::VirtualStudioTechnology::VirtualStudioTechnology() :
vstName("Superior Drummer"),
vstManufacturer("Toontrack"),
vstType("virtual instrument")
{
    numOfPresets = 100;
    std::cout << "\nVirtualStudioTechnology being constructed!" << std::endl;
}

DAWProject::DAWProject() :
numOfSections(120),
isQuantized(true)
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
    std::cout << "\nAre the MIDI notes quantized? " << (isQuantized? "Yes":"No") << std::endl;
}

void DAWProject::VirtualStudioTechnology::acceptMIDIInput()
{
    std::cout << "\nCurrent VST accepts MIDI input? " << (supportsMIDI? "Yes":"No") << std::endl;
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

    int numOfMonitorSpeakers, numOfMicrophones, numOfInstrumentStands;
    double stageWidth = 40;
    double stageDepth = 20;

    void supportPerformerSetup();
    void transmitSoundToFOHSystem();
    void provideStageMonitoring();
};

Stage::Stage() :
numOfMonitorSpeakers(10),
numOfMicrophones(20),
numOfInstrumentStands(20)
{
    std::cout << "\nStage being construted!" << std::endl;
}

void Stage::supportPerformerSetup()
{
    std::cout << "\nSupport performer setup" << std::endl;
}

void Stage::transmitSoundToFOHSystem()
{
    std::cout << "\nTransmit sound to FOH system with " << numOfMicrophones << " microphones"  << std::endl;
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
    std::string brandName;
    std::string typeOfMixingConsole;

    void amplifyInputSignals();
    void routeSoundToAudience();
    void adjustVolumeAndEQSettings();
};

FrontOfHouseAudioSystem::FrontOfHouseAudioSystem() :
brandName("DiGiCo"),
typeOfMixingConsole("sd12")
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
    std::cout << "\nAdjust volume and EQ settings with " << typeOfMixingConsole << " console from " << brandName << std::endl;
}

struct BackstageArea //7
{
    BackstageArea();

    int numOfLockers, numOfDressingRooms, numOfEquimentStorageShelves;
    double backStageSize;
    bool hasEquipmentLoadingAccess = true;
    
    void provideRestingSpaceForPerformers();
    void storeCablesAndInstruments();
    void provideStorageForPersonalBelongings();
};

BackstageArea::BackstageArea() :
numOfLockers(80),
numOfDressingRooms(3),
numOfEquimentStorageShelves(10),
backStageSize(500.0)
{
    std::cout << "\nBackstageArea being constructed!" << std::endl;
}

void BackstageArea::provideRestingSpaceForPerformers()
{
    std::cout << "\nProvide " << backStageSize << " squre metres of resting space for performers" << std::endl;
}

void BackstageArea::storeCablesAndInstruments()
{
    std::cout << "\nStore cables and instruments with "<< numOfEquimentStorageShelves << " storeage shelves" << std::endl;
}

void BackstageArea::provideStorageForPersonalBelongings()
{
    std::cout << "\nProvide storage for personal belongings with " << numOfLockers << " lockers" << std::endl;
}

struct BarCounter //8
{
    BarCounter();
    
    int numOfDrinkOptions, numOfStaffMembers, numOfSeats;
    bool providesNonAlcoholicDrink = true;
    bool hasMerchandiseDisplayArea = true;
    
    void serveDrinksToCustomers();
    void processPayments();
    void sellBandMerchandise();
};

BarCounter::BarCounter():
numOfDrinkOptions(30),
numOfStaffMembers(6),
numOfSeats(10)
{
    std::cout << "\nBarCounter being constructed!" << std::endl;
}

void BarCounter::serveDrinksToCustomers()
{
    std::cout << "\nServe " << numOfDrinkOptions << " kinds of drinks to customers" << std::endl;
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
    int numOfComputerLights =  35;
    int numOfControlChannels = 512;
    double heightOfRig = 10.5;
    std::string lightingConsoleType;

    struct LightingConsole
    {
        LightingConsole();

        int numOfScreens = 3;
        int numOfFaders = 64;
        bool hasInternetConnectivity;
        double weightOfConsole = 120.0;
        std::string consoleName;

        void panAndTiltLights(int lightNumber, double panAngle = 135.0, double tiltAngle = 45.0);
        void adjustLightIntensity(int lightNumber, double intensity = 100.0);
        void changeGoboPattern(int lightNumber, std::string patternName = "star");

    };
    
    void illuminateTheStage();
    void changeLightingColorsAndPatterns(LightingConsole consoleInUse);
    void synchronizeLightingWithMusic(LightingConsole consoleInUse);

    LightingConsole mainConsole;
};

LightingRig::LightingConsole::LightingConsole():
hasInternetConnectivity(true),
consoleName("GrandMA3")
{
    std::cout << "\nLightingConsole being constructed!" << std::endl;
}

LightingRig::LightingRig():
lightingConsoleType("MA Lighting")
{
    std::cout << "\nLighitngRig being constructed!" << std::endl;
}

void LightingRig::illuminateTheStage()
{
    std::cout << "\nIlluminate the stage from " << heightOfRig << " metres high" << std::endl;
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
    std::cout << "\nChange the gobo pattern of light " << lightNumber << " to "<< consoleName << "'s default pattern: " << patternName << std::endl;
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
    std::cout << "----------------\n";
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
    std::cout << "\n[Member Initialization] The midiKeyboard has " << mdk.numOfKeys << " keys" << std::endl;
    std::cout << "\n[Member Initialization] Is the arpeggiator mode on? " << (mdk.arpeggiator ? "Yes" : "No") << std::endl;
    std::cout << "\n[Member Initialization] Is the step sequencer mode on? " << (mdk.stepSequencer ? "Yes" : "No") << std::endl;
    mdk.recordLoops(16);
    std::cout << "----------------\n";


    
    cfm.grindCoffeeBeans();
    cfm.brewEspresso();
    cfm.steamMilk();
    std::cout << "\n[Member Initialization] Current steam temperature is " << cfm.steamTemperature << " degrees" << std::endl;
    cfm.extractEspresso(20);
    std::cout << "----------------\n";


    
    skb.performTricks("Peterpan");
    skb.rollOverRamps();
    skb.carveAlongCurves();
    std::cout << "\n[Member Initialization] The deck length of the skateboard is " << skb.deckLength << "mm" << std::endl;
    std::cout << "----------------\n";


    
    dawp.playBackComposition();
    dawp.applyAudioEffects("reverb", dawp.virtualGuitar);
    dawp.quantizeNotes();
    std::cout << "\n[Member Initialization] A " << dawp.virtualGuitar.vstName << " is being used" << std::endl;
    std::cout << "\n[Member Initialization] Is the project quantized? " << (dawp.isQuantized ? "Yes" : "No") << std::endl;
    std::cout << "----------------\n";


    
    vst.acceptMIDIInput();
    vst.outputAudio();
    vst.changePreset("Punk");
    std::cout << "\n[Member Initialization] The preset has been changed to [" << vst.changePreset("Jazz") << "]" << std::endl;
    std::cout << "----------------\n";


    
    stg.supportPerformerSetup();
    stg.transmitSoundToFOHSystem();
    stg.provideStageMonitoring();
    std::cout << "\n[Member Initialization] There are " << stg.numOfMonitorSpeakers << " monitor speakers on the stage" << std::endl;
    std::cout << "----------------\n";


    
    foh.amplifyInputSignals();
    foh.routeSoundToAudience();
    foh.adjustVolumeAndEQSettings();
    std::cout << "\n[Member Initialization] The output wattage of the FOH system is " << foh.outputWattage << "W" << std::endl;
    std::cout << "----------------\n";


    
    bsa.provideRestingSpaceForPerformers();
    bsa.storeCablesAndInstruments();
    bsa.provideStorageForPersonalBelongings();
    std::cout << "\n[Member Initialization] There are " << bsa.numOfLockers << " lockers in the backstage area" << std::endl;
    std::cout << "----------------\n";


    
    bc.serveDrinksToCustomers();
    bc.processPayments();
    bc.sellBandMerchandise();
    std::cout << "\n[Member Initialization] There are " << bc.numOfDrinkOptions << " drink options on the bar counter" << std::endl;
    std::cout << "----------------\n";


    
    ltr.illuminateTheStage();
    ltr.changeLightingColorsAndPatterns(ltr.mainConsole);
    ltr.synchronizeLightingWithMusic(ltr.mainConsole);
    std::cout << "\n[Member Initialization] The lighting console type is " << ltr.lightingConsoleType << std::endl;
    std::cout << "----------------\n";


    
    lc.panAndTiltLights(5, 135.0, 60.0);
    lc.adjustLightIntensity(1, 100.0);
    lc.changeGoboPattern(2, "star");
    std::cout << "\n[Member Initialization] The lighting console has " << lc.numOfFaders << " faders" << std::endl;
    std::cout << "----------------\n";


    
    lvh.hostLiveMusicPerformances();
    lvh.serveDrinksToAttendees();
    lvh.mixSoundAndControlStageLighting();
    std::cout << "\n[Member Initialization] The livehouse is using " << lvh.mixSoundAndControlStageLighting() << " consoles to mix sound and control stage lighting" << std::endl;
    std::cout << "----------------\n";


    
    std::cout << "good to go!" << std::endl;
}
