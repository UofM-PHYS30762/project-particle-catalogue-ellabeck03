#ifndef ELECTRON_H
#define ELECTRON_H

#include "lepton.h"
#include <vector>

class Electron : public Lepton 
{
protected:
    std::vector<double> deposited_energies; // Energies deposited in calorimeter layers

public:
    // Constructors
    Electron();
    Electron(double mass_in, const FourMomentum& four_momentum_in, const std::vector<double>& deposited_energies_in);

    // Getters
    const std::vector<double>& get_deposited_energies() const;
    std::string get_type() const override;

    // Setters
    void set_deposited_energies(const std::vector<double>& deposited_energies);

    //Destructor
    ~Electron() {}

    // Validation
    void validate_deposited_energies(const std::vector<double>& deposited_energies);

    // Override print_data to include electron-specific information
    void print_data() override;
};

#endif // ELECTRON_H