//Вариант 2
//Реализовать составную геометрию представленную на рисунке

#include <G4Sphere.hh>
#include <G4Colour.hh>
#include <G4Orb.hh>
#include "DetGeometry.hh"
#include "G4SystemOfUnits.hh"

#include <G4PhysicalConstants.hh>
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"

#include "G4NistManager.hh"

#include "G4PVPlacement.hh"

#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Tubs.hh"
#include "G4Para.hh"
#include "G4VisAttributes.hh"
#include "globals.hh"
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4Isotope.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4UnitsTable.hh"


#include "G4VUserDetectorConstruction.hh"

DetGeometry::DetGeometry() {
    world_sizeXYZ   = 50 * m;
    nist            = G4NistManager::Instance();
    world_mat       = nist->FindOrBuildMaterial("G4_AIR");
    solidWorld      = new G4Box("solWorld", 0.5*world_sizeXYZ, 0.5*world_sizeXYZ, 0.5*world_sizeXYZ);
    logicWorld      = new G4LogicalVolume(solidWorld, world_mat, "logWorld");
    physWorld       = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "phyWorld", 0, false, 0);
    G4cout<<"Geometry of detector is build successfully\t\t\t\t\t\tOK!!!"<<G4endl;
}

DetGeometry::~DetGeometry() {}

G4VPhysicalVolume* DetGeometry::Construct(){
    G4Material * material       = nist->FindOrBuildMaterial("G4_Fe");


    //G4Material* LaBr3 = nist->FindOrBuildMaterial("G4_Fe");


    //G4Material* AMG2 = nist->FindOrBuildMaterial("G4_ALANINE");

    /*G4NistManager* man = G4NistManager::Instance();
    man->SetVerbose(1);*/

    G4double zLa= 57, roLa=6.15, neLa=139-57, someLa1=501, someLa2=12345;
    G4String nLa="Lanthan", oLa="La";


    G4Material* eFe  = nist->FindOrBuildMaterial("G4_Fe");
    G4Material* eSi  = nist->FindOrBuildMaterial("G4_Si");
    G4Material* eMn = nist->FindOrBuildMaterial("G4_Mn");
    G4Material* eCr  = nist->FindOrBuildMaterial("G4_Cr");
    G4Material* eTi  = nist->FindOrBuildMaterial("G4_Ti");
    G4Material* eAl  = nist->FindOrBuildMaterial("G4_Al");
    G4Material* eCu  = nist->FindOrBuildMaterial("G4_Cu");
    G4Material* eMg  = nist->FindOrBuildMaterial("G4_Mg");
    G4Material* eZn = nist->FindOrBuildMaterial("G4_Zn");

    G4Material* eLa  = nist->FindOrBuildMaterial("G4_La");
    G4Material* eBr  = nist->FindOrBuildMaterial("G4_Br");

    G4Material *AMG2 = new G4Material ("AMG2", 2.700*g/cm3,9);
    AMG2->AddMaterial(eFe,0.05);
    AMG2->AddMaterial(eSi,0.05);
    AMG2->AddMaterial(eMn,0.05);
    AMG2->AddMaterial(eCr,0.05);
    AMG2->AddMaterial(eTi,0.01);
    AMG2->AddMaterial(eAl,0.975);
    AMG2->AddMaterial(eCu,0.01);
    AMG2->AddMaterial(eMg,0.02);
    AMG2->AddMaterial(eZn,0.01);

    G4Material *LaBr3 = new G4Material ("LaBr3", 5.08*g/cm3,2);
    LaBr3->AddMaterial(eLa,0.25);
    LaBr3->AddMaterial(eBr,0.75);

    //G4double aLa=2*g/mole
    G4Isotope* La57 = new G4Isotope("La57", 57, 139, 139*g/mole);
    G4Isotope* Br35 = new G4Isotope("Br35", 35, 79, 179*g/mole);

    G4Element* elLa  = new G4Element("La", "LB3", 1);
    elLa->AddIsotope(La57, 1);
    G4Element* elBr3  = new G4Element("Br3", "LB3", 1);
    elBr3->AddIsotope(Br35, 1);

    G4Material *mLaBr3 = new G4Material ("Isotopes", 5.08*g/cm3,2);
    mLaBr3->AddElement(elLa,25*perCent);
    mLaBr3->AddElement(elBr3,75*perCent);






    /*G4Material *elH = nist->FindOrBuildMaterial("G4_H");
    G4Material *elC = nist->FindOrBuildMaterial("G4_C");

    G4Material *HC = new G4Material ("HC", 5*g/cm3,2);
    HC->AddMaterial(elH,0.95);
    HC->AddMaterial(elC,0.05);
*/



    G4Sphere* sph = new G4Sphere ("1",100*mm, 150*mm, 0, pi*2, 0, pi*2);
    G4LogicalVolume* one = new G4LogicalVolume (sph, mLaBr3, "smth");
    G4VisAttributes* GR = new G4VisAttributes (G4Colour::Green());
    one->SetVisAttributes(GR);

    G4Box* bx = new G4Box ("2",100*mm, 100*mm, 100*mm);
    G4LogicalVolume* two = new G4LogicalVolume (bx, LaBr3, "smth2");
    G4VisAttributes* BL = new G4VisAttributes (G4Colour::Blue());
    two->SetVisAttributes(BL);

    G4Tubs* tub = new G4Tubs ("1",100*mm, 150*mm, 200*mm, 0, pi*2);
    G4LogicalVolume* three = new G4LogicalVolume (tub, AMG2, "smth3");
    G4VisAttributes* VL = new G4VisAttributes (G4Colour::Magenta());
    three->SetVisAttributes(VL);





    new G4PVPlacement(0, G4ThreeVector(100* cm, 0 *cm, 0*cm), one, "1", logicWorld, false, 0);
    new G4PVPlacement(0, G4ThreeVector(0* cm, 100 *cm, 0*cm), two, "2", logicWorld, false, 0);
    new G4PVPlacement(0, G4ThreeVector(0* cm, 0 *cm, 100*cm), three, "3", logicWorld, false, 0);



    std::cout<<nLa<<"\t"<<oLa<<"\t"<<zLa<<"\t"<<roLa<<"\t"<<neLa<<"\t"<<someLa1<<"\t"<<someLa2<<"\n";

    std::ofstream fout ("/home/student/smth.txt");
    fout<<nLa<<"\t"<<oLa<<"\t"<<zLa<<"\t"<<roLa<<"\t"<<neLa<<"\t"<<someLa1<<"\t"<<someLa2<<"\n";


    return physWorld;
}


