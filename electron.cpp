#include "electron.h"
#include <iostream>
#include <stdexcept>

// Default constructor
Electron::Electron() : Lepton(0.511, FourMomentum(), 1), deposited_energies(4, 0.0) {}

// Parameterized constructor
Electron::Electron(double mass_in, const FourMomentum& four_momentum_in, const std::vector<double>& deposited_energies_in)
    : Lepton(mass_in, four_momentum_in, 1)  // Set lepton number for electron
{
    set_deposited_energies(deposited_energies_in);
}

// Getters
const std::vector<double>& Electron::get_deposited_energies() const {
    return deposited_energies;
}

// Setters
void Electron::set_deposited_energies(const std::vector<double>& deposited_energies_in) {
    validate_deposited_energies(deposited_energies_in);
    deposited_energies = deposited_energies_in;
}

// Validation function
void Electron::validate_deposited_energies(const std::vector<double>& deposited_energies) {
    if (deposited_energies.size() != 4) {
        throw std::invalid_argument("Error: Incorrect number of calorimeter layers.");
    }

    double sum = 0.0;
    for (double energy : deposited_energies) {
        sum += energy;
    }
    if (std::abs(sum - get_four_momentum().get_energy()) > 1e-6) {
        throw std::invalid_argument("Error: Total energy deposited does not match electron's energy.");
    }
}

// Print data method override
void Electron::print_data() {
    std::cout << "Particle type: " << (get_antiparticle_status() ? "Positron" : "Electron") << std::endl;
    Lepton::print_data();  // Call the base class print_data
    std::cout << "Deposited energies: ";
    for (double energy : deposited_energies) {
        std::cout << energy << " MeV ";
    }
    std::cout << std::endl;
}