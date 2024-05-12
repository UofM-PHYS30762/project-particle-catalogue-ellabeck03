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
    double rest_mass{2.3};

public:
    // default constructor
    Quark();

    // parameterised constructor
    Quark(FourMomentum& four_momentum_in, std::string flavour_in, std::string colour_in);

    // getters
    double get_baryon_number() const;
    std::string get_flavour() const;
    std::string get_colour() const;
    std::string get_type() const override;

    // setters
    void set_colour(std::string colour_in);

    // destructor
    ~Quark() {}

    // other member functions
    void antiparticle() override;
    void print_data() override;
    void validate_colour(std::string colour_in);
    double determine_rest_mass(const std::string& flavour_in);
    double determine_charge(const std::string& flavour_in);


};

#endif
