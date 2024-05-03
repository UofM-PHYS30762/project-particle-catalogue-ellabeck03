#ifndef MUON_H
#define MUON_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "lepton.h"
#include "fourmomentum.h"
#include "particle.h"

using std::string;

class Muon : public Lepton
{
protected:
    bool is_isolated;

public:
    //default constructor
    Muon();

    //parameterised constructor
    Muon(double mass_in, const FourMomentum& four_momentum_in, bool is_isolated_in);

    //getters
    bool get_isolation_status() const;

    //setters
    void set_isolation_status(bool is_isolated_in);

    //other member functions
    virtual void print_data() override;

};

#endif