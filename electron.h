#ifndef ELECTRON_H
#define ELECTRON_H

#include "lepton.h"
#include <vector>

class Electron : public Lepton 
{
protected:
    std::vector<double> deposited_energies; // energies deposited in calorimeter layers
    double rest_mass{0.511};

public:
    // default constructor
    Electron();

    //parameterised constructor
    Electron(FourMomentum& four_momentum_in, const std::vector<double>& deposited_energies_in);

    // getters
    const std::vector<double>& get_deposited_energies() const;
    std::string get_type() const override;

    // setters
    void set_deposited_energies(const std::vector<double>& deposited_energies);

    // destructor
    ~Electron() {}

    // other member functions
    void validate_deposited_energies(const std::vector<double>& deposited_energies);
    void print_data() override;
};

#endif // ELECTRON_H