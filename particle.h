#ifndef PARTICLE_H
#define PARTICLE_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"

using std::string;

class Particle
{
protected:
    const double light_speed{1};
    double charge;
    double spin;
    double mass;
    FourMomentum four_momentum;
    bool antiparticle_status;

public:
    //default constructor
    Particle();

    //parameterised constructor
    Particle(double mass_in, const FourMomentum& four_momentum_in, double charge_in, double spin_in);

    //getters
    virtual double get_charge() const;
    virtual double get_spin() const;
    double get_mass();
    const FourMomentum& get_four_momentum() const;
    bool get_antiparticle_status() const;
    virtual std::string get_flavor() const { return "none"; }

    //setters
    void set_mass(double mass_in);
    void set_four_momentum(FourMomentum& four_momentum_in);
    
    //other member functions
    virtual void antiparticle();
    virtual void print_data();
};

#endif