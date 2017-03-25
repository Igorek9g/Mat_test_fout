#include "loader.hh"

int main(int argc, char** argv) {
    G4Loader *g4Loader = new G4Loader(argc,argv);

    delete g4Loader;
    return 0;
}