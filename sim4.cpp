#include "sim4.h"

sim4::sim4(double px, double py, double pz, double E, int pid, int parent)
    : track4(px, py, pz, E), particleID(pid), parentID(parent) {}

int sim4::getParticleID() const {
    return particleID;
}

int sim4::getParentID() const {
    return parentID;
}
