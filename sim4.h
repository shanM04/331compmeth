#ifndef SIM4_H
#define SIM4_H

#include "track4.h"

class sim4 : public track4 {
private:
    int particleID;
    int parentID;

public:
    sim4(double px, double py, double pz, double E, int pid, int parent);
    
    int getParticleID() const;
    int getParentID() const;
};

#endif // SIM4_H
