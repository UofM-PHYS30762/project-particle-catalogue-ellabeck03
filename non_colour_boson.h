#ifndef NON_COLOUR_BOSON_H
#define NON_COLOUR_BOSON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<memory>

#include "particle.h"
#include "fourmomentum.h"

using std::string;

class NonColourBoson : public Particle
{
private:
    std::string type;
    std::vector<std::shared_ptr<Particle>> decay_particles;

public:
    //default constructor
    NonColourBoson();

    //parameterised constructor
    NonColourBoson(double mass_in, const FourMomentum& four_momentum_in, std::string type_in);

    //getters
    std::string get_type() const;
    std::vector<std::shared_ptr<Particle>> get_decay_particles();

    //function to add a decay particle
    void add_decay_particle(std::shared_ptr<Particle> decay_lepton_in);

    virtual void antiparticle() override;
    virtual void print_data() override;
};

#endif