// PHYS 30762 Programming in C++
// Project 2: Particle Catalogue
// Ella Beck


#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include <chrono>

#include "particle.h"
#include "fourmomentum.h"
#include "electron.h"
#include "muon.h"
#include "tau.h"
#include "neutrino.h"
#include "quark.h"
#include "gluon.h"
#include "non_colour_boson.h"
#include "catalogue.h"

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
  auto start = std::chrono::high_resolution_clock::now();

  //instantiate four-momentum of all particles
  FourMomentum electron1_momentum(20.0, {11.5432, 11.5432, 11.5432});
  FourMomentum muon1_momentum(200, {98.0264, 98.0264, 98.0264});
  FourMomentum tau1_momentum(2000, {529.865, 529.865, 529.865});
  FourMomentum neutrino1_momentum(40, {21.2897, 21.2897, 21.2897});
  FourMomentum neutrino2_momentum(40, {23.094, 23.094, 23.094});
  FourMomentum neutrino3_momentum(40, {23.0938, 23.0938, 23.0938});
  FourMomentum quark1_momentum(5000, {1584.05, 1584.05, 1584.05});
  FourMomentum quark2_momentum(5000, {0.01, 0.02, 0.03});
  FourMomentum quark3_momentum(100, {18.0278, 18.0278, 18.0278});
  FourMomentum quark4_momentum(1500, {456.207, 456.207, 456.207});
  FourMomentum quark5_momentum(5, {0.80829, 0.80829, 0.80829});
  FourMomentum quark6_momentum(3, {1.17757, 1.17757, 1.17757});
  FourMomentum gluon1_momentum(100, {57.735, 57.735, 57.735});
  FourMomentum higgs1_momentum(140000, {35232.6, 35232.6, 35232.6});
  FourMomentum w1_momentum(90000, {23351.2, 23351.2, 23351.2});
  FourMomentum z1_momentum(100000, {23682.3, 23682.3, 23682.3});
  FourMomentum photon1_momentum(10, {5.7735, 5.7735, 5.7735});


  //instantiate particles (and antiparticles), create shared pointers for them all

  Electron electron1(electron1_momentum, {5, 5, 5, 5});
  std::shared_ptr<Electron> electron1_ptr = std::make_shared<Electron>(electron1);
  electron1.antiparticle();
  std::shared_ptr<Electron> electron1_ptr2 = std::make_shared<Electron>(electron1);

  Muon muon1(muon1_momentum, false);
  std::shared_ptr<Muon> muon1_ptr = std::make_shared<Muon>(muon1);
  muon1.antiparticle();
  std::shared_ptr<Muon> muon1_ptr2 = std::make_shared<Muon>(muon1);

  Neutrino neutrino1(neutrino1_momentum, true, "tau");
  std::shared_ptr<Neutrino> neutrino1_ptr = std::make_shared<Neutrino>(neutrino1);
  neutrino1.antiparticle();
  std::shared_ptr<Neutrino> neutrino1_ptr2 = std::make_shared<Neutrino>(neutrino1);

  Neutrino neutrino2(neutrino2_momentum, true, "electron");
  std::shared_ptr<Neutrino> neutrino2_ptr = std::make_shared<Neutrino>(neutrino2);
  neutrino2.antiparticle();
  std::shared_ptr<Neutrino> neutrino2_ptr2 = std::make_shared<Neutrino>(neutrino2);

  Neutrino neutrino3(neutrino3_momentum, true, "muon");
  std::shared_ptr<Neutrino> neutrino3_ptr = std::make_shared<Neutrino>(neutrino3);
  neutrino3.antiparticle();
  std::shared_ptr<Neutrino> neutrino3_ptr2 = std::make_shared<Neutrino>(neutrino3);

  Quark quark1(quark1_momentum, "bottom", "red");
  std::shared_ptr<Quark> quark1_ptr = std::make_shared<Quark>(quark1);
  quark1.antiparticle();
  std::shared_ptr<Quark> quark1_ptr2 = std::make_shared<Quark>(quark1);

  Quark quark2(quark2_momentum, "top", "green");//this momentum needs to be adjusted: does not create correct invariant mass
  std::shared_ptr<Quark> quark2_ptr = std::make_shared<Quark>(quark2);
  quark2.antiparticle();
  std::shared_ptr<Quark> quark2_ptr2 = std::make_shared<Quark>(quark2);

  Quark quark3(quark3_momentum, "strange", "blue");
  std::shared_ptr<Quark> quark3_ptr = std::make_shared<Quark>(quark3);
  quark3.antiparticle();
  std::shared_ptr<Quark> quark3_ptr2 = std::make_shared<Quark>(quark3);

  Quark quark4(quark4_momentum, "charm", "red");
  std::shared_ptr<Quark> quark4_ptr = std::make_shared<Quark>(quark4);
  quark4.antiparticle();
  std::shared_ptr<Quark> quark4_ptr2 = std::make_shared<Quark>(quark4);

  Quark quark5(quark5_momentum, "down", "green");
  std::shared_ptr<Quark> quark5_ptr = std::make_shared<Quark>(quark5);
  quark5.antiparticle();
  std::shared_ptr<Quark> quark5_ptr2 = std::make_shared<Quark>(quark5);

  Quark quark6(quark6_momentum, "up", "blue");
  std::shared_ptr<Quark> quark6_ptr = std::make_shared<Quark>(quark6);
  quark6.antiparticle();
  std::shared_ptr<Quark> quark6_ptr2 = std::make_shared<Quark>(quark6);

  Tau tau1(tau1_momentum);
  std::shared_ptr<Tau> tau1_ptr = std::make_shared<Tau>(tau1);
  tau1.antiparticle();
  std::shared_ptr<Tau> tau1_ptr2 = std::make_shared<Tau>(tau1);

  Gluon gluon1(gluon1_momentum, {"antigreen", "blue"});
  gluon1.antiparticle();//gluon is its own antiparticle, only 1 pointer used

  NonColourBoson higgs1(higgs1_momentum, "Higgs");
  //add decay particles to show that the validation is working (will print a statement in the terminal if successful)
  higgs1.add_decay_particle(quark1_ptr);
  higgs1.add_decay_particle(quark1_ptr2);

  NonColourBoson w1(w1_momentum, "W+");
  std::shared_ptr<NonColourBoson> w1_ptr = std::make_shared<NonColourBoson>(w1);
  w1.antiparticle();
  std::shared_ptr<NonColourBoson> w1_ptr2 = std::make_shared<NonColourBoson>(w1);

  NonColourBoson z1(z1_momentum, "Z");
  NonColourBoson photon1(photon1_momentum, "photon");


  // create catalogue and add particles
  ParticleCatalogue catalogue;

  catalogue.add_particle(electron1_ptr2);
  catalogue.add_particle(electron1_ptr);
  catalogue.add_particle(muon1_ptr);
  catalogue.add_particle(muon1_ptr2);
  catalogue.add_particle(tau1_ptr);
  catalogue.add_particle(tau1_ptr2);
  catalogue.add_particle(neutrino1_ptr);
  catalogue.add_particle(neutrino1_ptr2);
  catalogue.add_particle(neutrino2_ptr);
  catalogue.add_particle(neutrino2_ptr2);
  catalogue.add_particle(neutrino3_ptr);
  catalogue.add_particle(neutrino3_ptr2);
  catalogue.add_particle(quark1_ptr);
  catalogue.add_particle(quark1_ptr2);
  catalogue.add_particle(quark2_ptr);
  catalogue.add_particle(quark2_ptr2);
  catalogue.add_particle(quark3_ptr);
  catalogue.add_particle(quark3_ptr2);
  catalogue.add_particle(quark4_ptr);
  catalogue.add_particle(quark4_ptr2);
  catalogue.add_particle(quark5_ptr);
  catalogue.add_particle(quark5_ptr2);
  catalogue.add_particle(quark6_ptr);
  catalogue.add_particle(quark6_ptr2);
  catalogue.add_particle(std::make_shared<Gluon>(gluon1));
  catalogue.add_particle(std::make_shared<NonColourBoson>(higgs1));
  catalogue.add_particle(w1_ptr);
  catalogue.add_particle(w1_ptr2);
  catalogue.add_particle(std::make_shared<NonColourBoson>(z1));
  catalogue.add_particle(std::make_shared<NonColourBoson>(photon1));

  // find total number of particles
  std::cout << "--------------" << std::endl;
  std::cout << "Total number of particles: " << catalogue.get_particle_number() << std::endl;
  std::cout << "--------------" << std::endl;
  catalogue.print_particles();
  std::cout << "--------------" << std::endl;

  // find number of each particle
  std::cout << "--------------" << std::endl;
  auto electrons = catalogue.get_particles_of_type("electron");
  std::cout << "Number of electrons: " << electrons.size() << std::endl;

  auto muons = catalogue.get_particles_of_type("muon");
  std::cout << "Number of muons: " << muons.size() << std::endl;

  auto taus = catalogue.get_particles_of_type("tau");
  std::cout << "Number of taus: " << taus.size() << std::endl;

  auto neutrinos = catalogue.get_particles_of_type("neutrino");
  std::cout << "Number of neutrinos: " << neutrinos.size() << std::endl;

  auto quarks = catalogue.get_particles_of_type("quark");
  std::cout << "Number of quarks: " << quarks.size() << std::endl;

  auto gluons = catalogue.get_particles_of_type("gluon");
  std::cout << "Number of gluons: " << gluons.size() << std::endl;

  //finding the flavour of each (non-gluon) boson in order to be counted
  size_t higgs = 0;
  size_t w = 0;
  size_t z = 0;
  size_t photons = 0;
  auto bosons = catalogue.get_particles_of_type("boson");
  for (const auto& boson : bosons) 
  {
    auto nonColourBosonPtr = std::dynamic_pointer_cast<NonColourBoson>(boson);
    if (nonColourBosonPtr && nonColourBosonPtr->get_flavour() == "Higgs") {higgs++;}
    else if (nonColourBosonPtr && nonColourBosonPtr->get_flavour() == "Z") {z++;}
    else if (nonColourBosonPtr && nonColourBosonPtr->get_flavour() == "photon") {photons++;}
    else if ((nonColourBosonPtr) && (nonColourBosonPtr->get_flavour() == "W-" || nonColourBosonPtr->get_flavour() == "W+")) {w++;}
  }

  std::cout << "Number of photons: " << photons << std::endl;
  std::cout << "Number of Z bosons: " << z << std::endl;
  std::cout << "Number of W+/W- bosons: " << w << std::endl;
  std::cout << "Number of Higgs bosons: " << higgs << std::endl;
  std::cout << "--------------" << std::endl;

  // Sum of all momenta in the catalogue
  std::cout << "--------------" << std::endl;
  FourMomentum total_momentum = catalogue.sum_momenta();
  std::cout << "Total Four Momentum: (" << total_momentum.get_energy();
  std::vector<double> momentum = total_momentum.get_momentum();
  std::cout << ", p = (" << momentum[0] << ", " << momentum[1] << ", " << momentum[2] << "))" << std::endl;
  std::cout << "--------------" << std::endl;

  // Retrieve sub-catalogue of electrons
  std::vector<std::shared_ptr<Particle>> sub_catalogue = catalogue.get_particles_of_type("electron");

  // Print data of each electron particle
  std::cout << "Sub-catalogue of electrons:" << std::endl;
  for (const auto& electron : sub_catalogue)
  {
      electron->print_data();
  }


  auto end = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << "Execution time: " << duration << " ms" << std::endl;

  return 0;
}