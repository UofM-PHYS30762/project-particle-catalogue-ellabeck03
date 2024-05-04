#ifndef TAU_H
#define TAU_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "lepton.h"
#include "fourmomentum.h"
#include "particle.h"

using std::string;

class Tau : public Lepton
{
private:
    std::vector<std::shared_ptr<Particle>> decay_particles;

public:
    //default constructor
    Tau();

    //parametrised constructor
    Tau(double mass_in, const FourMomentum& four_momentum_in);

    //getters
    std::vector<std::shared_ptr<Particle>> get_decay_particles();
    std::string get_type() const override;

    //destructor
    ~Tau() {}

    //function to add a decay lepton
    void add_decay_particle(std::shared_ptr<Particle> particle_in);
    void validate_decay();

    //other member functions
    virtual void print_data() override;
};

#endif