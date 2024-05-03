#ifndef GLUON_H
#define GLUON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "particle.h"

using std::string;

class Gluon : public Particle
{
private:
    std::vector<std::string> colours;

public:
    //default constructor
    Gluon();
    //parameterised constructor
    Gluon(double mass_in, const FourMomentum& four_momentum_in, std::vector<std::string> colours_in);

    //getters
    std::vector<std::string> get_colours() const;

    void antiparticle() override;
    void print_data() override;
    
};

#endif