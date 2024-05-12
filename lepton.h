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
    // default constructor
    Lepton();

    // parameterised constructor
    Lepton(double rest_mass_in, FourMomentum& four_momentum_in, double charge_in, int lepton_number_in);

    // getters
    int get_lepton_number() const;
    std::string get_type() const override;

    //o ther member functions
    void antiparticle() override;
    void print_data() override;

    // destructor
    ~Lepton() {}
};

#endif