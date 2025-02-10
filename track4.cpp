#include "track4.h"

track4::track4(double px, double py, double pz, double E) : px(px), py(py), pz(pz), E(E) {}

double track4::pt() const {
    return std::sqrt(px * px + py * py);
}

double track4::eta() const {
    double theta = std::atan2(pt(), pz);
    return -std::log(std::tan(theta / 2.0));
}
