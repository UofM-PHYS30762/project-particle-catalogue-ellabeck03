#ifndef QUARK_H
#define QUARK_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "particle.h"

using std::string;

class Quark : public Particle
{
private:
    double baryon_number{0.33333333};
    std::string flavour;
    std::string colour;

public:
  // constructors
  //default constructor
    Quark();
    Quark(double mass_in, const FourMomentum& four_momentum_in, std::string flavour_in, std::string colour_in);

    // Getters
    double get_baryon_number() const;
    std::string get_flavour() const;
    std::string get_colour() const;

    void antiparticle() override;
    void print_data() override;


};

#endif
