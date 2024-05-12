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
    std::string flavour;
    std::vector<std::shared_ptr<Particle>> decay_particles;
    double rest_mass{0};

public:
    // default constructor
    NonColourBoson();

    // parameterised constructor
    NonColourBoson(FourMomentum& four_momentum_in, std::string flavour_in);

    // getters
    std::string get_flavour() const;
    std::vector<std::shared_ptr<Particle>> get_decay_particles();
    std::string get_type() const override;

    // destructor
    ~NonColourBoson() {}

    // function to add a decay particle
    void add_decay_particle(std::shared_ptr<Particle> decay_lepton_in);

    // non-member functions
    virtual void antiparticle() override;
    virtual void print_data() override;
    void validate_decay() const;
    double determine_rest_mass(const std::string& flavour_in);
    double determine_charge(const std::string& flavour_in);
    int determine_spin(const std::string& spin_in);
};

#endif