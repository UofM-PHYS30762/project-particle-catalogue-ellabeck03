#ifndef FOURMOMENTUM_H
#define FOURMOMENTUM_H

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using std::string;

class FourMomentum
{
private:
    const double light_speed{2.99792458e8};
    double energy;
    std::vector<double> momentum;

public:
    //default constructor
    FourMomentum();

    //parameterised constructor
    FourMomentum(double energy_in, const std::vector<double>& momentum_in);

    //setters
    void set_energy(const double energy_in);
    void set_momentum(const std::vector<double>& momentum_in);

    //assignment operator
    FourMomentum& operator=(const FourMomentum& other);

    //move operator
    FourMomentum& operator=(FourMomentum&& other);

    //copy constructor
    FourMomentum(const FourMomentum& other);

    //move constructor
    FourMomentum(FourMomentum&& other);

    //destructor
    ~FourMomentum() {}

    //getter functions
    double get_energy() const;
    std::vector<double> get_momentum() const;


    //other member functions
    void validate_energy(const double energy_in);
    double invariant_mass() const;

    //friend functions
    friend std::vector<double> sum_four_vectors(const FourMomentum& momentum1, const FourMomentum& momentum2);
    friend double dot_product(const FourMomentum& momentum1, const FourMomentum& momentum2);

};

#endif