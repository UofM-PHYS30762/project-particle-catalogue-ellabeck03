#ifndef LEPTON_H
#define LEPTON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "particle.h"
#include "fourmomentum.h"

using std::string;

class Lepton : public Particle 
{
private:
    int lepton_number; 

public:
    // Constructors
    Lepton();  // Default constructor
    Lepton(double mass_in, const FourMomentum& four_momentum_in, int lepton_number_in);

    // Getter
    int get_lepton_number() const;

    void antiparticle() override;
    void print_data() override;

};

#endif