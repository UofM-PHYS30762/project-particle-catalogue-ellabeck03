#ifndef NEUTRINO_H
#define NEUTRINO_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "lepton.h"
#include "fourmomentum.h"
#include "particle.h"

using std::string;

class Neutrino : public Lepton
{
protected:
    bool has_interacted;
    std::string flavour;
    int charge{0};

public:
    //default constructor
    Neutrino();

    //parameterised constructor
    Neutrino(double mass_in, const FourMomentum& four_momentum_in, bool has_interacted_in, std::string flavour_in);

    //getters
    bool get_interaction_status() const;
    std::string get_flavour() const;
    double get_charge() const override;
    std::string get_type() const override;

    //setters
    void set_interaction_status(bool has_interacted_in);
    void set_flavour(std::string flavour_in);

    //destructor
    ~Neutrino() {}

    //validation
    void validate_flavour(std::string flavour_in);

    //other member functions
    virtual void print_data() override;
};

#endif