#include <iostream>
#include "track4.h"
#include "sim4.h"

int main() {
    track4 track(3.0, 4.0, 5.0, 10.0);
    std::cout << "track4 pT: " << track.pt() << std::endl;
    std::cout << "track4 eta: " << track.eta() << std::endl;

    sim4 simTrack(3.0, 4.0, 5.0, 10.0, 11, 22);
    std::cout << "Simulated Particle ID: " << simTrack.getParticleID() << std::endl;
    std::cout << "Parent Particle ID: " << simTrack.getParentID() << std::endl;

    return 0;
}
