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
    double rest_mass{0};

public:
    //default constructor
    Gluon();
    //parameterised constructor
    Gluon(double mass_in, FourMomentum& four_momentum_in, std::vector<std::string> colours_in);

    //getters
    std::vector<std::string> get_colours() const;
    std::string get_type() const override;

    //setters
    void set_colours(std::vector<std::string> colours_in);

    //other member functions
    void antiparticle() override;
    void print_data() override;
    void validate_colours(std::vector<std::string> colours_in);

    //destructor
    ~Gluon() {}
    
};

#endif