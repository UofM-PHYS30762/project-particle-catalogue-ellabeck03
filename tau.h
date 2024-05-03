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
    bool is_leptonic_decay;
    std::vector<std::shared_ptr<Lepton>> decay_leptons;

public:
    //default constructor
    Tau();

    //parametrised constructor
    Tau(double mass_in, const FourMomentum& four_momentum_in, bool is_leptonic_in);

    //getters
    bool get_decay_status() const;
    std::vector<std::shared_ptr<Lepton>> get_decay_leptons();

    //setters
    void set_decay_status(bool is_leptonic_in);

    //function to add a decay lepton
    void add_decay_lepton(std::shared_ptr<Lepton> decay_lepton_in);

    //other member functions
    virtual void print_data() override;
};

#endif