/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()



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
