#ifndef LEPTON_H
#define LEPTON_H

#include "particle.h"
#include "fourmomentum.h"

class Lepton : public Particle 
{
private:
    int lepton_number; 

public:
    // Constructors
    Lepton();  // Default constructor
    Lepton(double mass, const FourMomentum& fourMomentum, int leptonNumber);

    // Getter
    int get_lepton_number() const;

    void antiparticle() override;
    void print_data() override;

};

#endif