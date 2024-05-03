// PHYS 30762 Programming in C++
// Project
// Particle Catalogue


#include<iostream>
#include<string>
#include<vector>
#include<cmath>

#include "fourmomentum.h"
#include "electron.h"
#include "muon.h"
#include "tau.h"
#include "neutrino.h"
#include "quark.h"
#include "gluon.h"
#include "non_colour_boson.h"

using std::string;

//non-member functions
std::vector<double> sum_four_vectors(const FourMomentum& momentum1, const FourMomentum& momentum2)
{
  std::vector<double> summed_momentum;

  double summed_energy = momentum1.get_energy() + momentum2.get_energy();
  summed_momentum.push_back(summed_energy);

  for(size_t i=0; i<momentum1.get_momentum().size(); ++i)
  {
    summed_momentum.push_back(momentum1.get_momentum()[i] + momentum2.get_momentum()[i]);
  }

  return summed_momentum;
}

double dot_product(const FourMomentum& momentum1, const FourMomentum& momentum2)
{
  double four_momentum_dot_product = momentum1.get_energy() * momentum2.get_energy();

  for(size_t i=0; i<momentum1.get_momentum().size(); ++i)
  {
    four_momentum_dot_product -= (momentum1.get_momentum()[i] * momentum2.get_momentum()[i]);
  }

  return four_momentum_dot_product;
}


int main()
{
  std::vector<Lepton*> lepton_pointers;

  FourMomentum electron1_momentum(20.0, {1.0, 2.0, 3.0});
  FourMomentum muon1_momentum(200, {3.0, 4.0, 5.0});
  FourMomentum tau1_momentum(2000, {4.0, 5.0, 6.0});
  FourMomentum neutrino1_momentum(2, {0.1, 0.2, 0.3});
  FourMomentum quark1_momentum(0.2, {0.01, 0.02, 0.03});
  FourMomentum gluon1_momentum(100, {5.0, 6.0, 7.0});
  FourMomentum W1_momentum(400, {8.0, 9.0, 10.0});

  Electron electron1(0.511, electron1_momentum, {5, 5, 5, 5});
  electron1.print_data();
  std::shared_ptr<Particle> electron1_ptr = std::make_shared<Particle>(electron1);

  Muon muon1(106, muon1_momentum, false);
  muon1.print_data();

  Tau tau1(1011, tau1_momentum, false);
  tau1.print_data();

  Neutrino neutrino1(0.5, neutrino1_momentum, true, "electron");
  neutrino1.print_data();

  Quark quark1(0.1, quark1_momentum, "down", "red");
  quark1.antiparticle();
  quark1.print_data();

  Gluon gluon1(50, gluon1_momentum, {"green", "antiblue"});
  gluon1.antiparticle();
  gluon1.print_data();

  NonColourBoson w1(200, W1_momentum, "W+");
  w1.add_decay_particle(electron1_ptr);
  w1.print_data();


  return 0;
}