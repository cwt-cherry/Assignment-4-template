// PHYS 30762 Programming in C++
// Assignment 4
// Practice special functions and operators in C++ classes

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include "particle.h"

using std::string;

// Implementation of functions goes here

// Define variable
const double speed_of_light = 2.9979245e8; // Unit of m/s

// Random velocity generating function
double random_energy() 
{
  return static_cast<double>(std::rand()) / RAND_MAX * speed_of_light;
}

// Main program
int main()
{
  particle p;

  // Create the following particles: 
  // two electrons, four muons, one antielectron, one antimuon 
  // Use the parameterised constructor to do these
  particle electron1("electron", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle electron2("electron", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle electron3("positron", 1, true, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon1("muon", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon2("muon", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon3("muon", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon4("muon", -1, false, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());
  particle muon5("antimuon", 1, true, random_energy(), p.get_momentum_x(), p.get_momentum_y(), p.get_momentum_z());

  std::vector<particle> particles;

  particles.push_back(electron1);
  particles.push_back(electron2);
  particles.push_back(electron3);
  particles.push_back(muon1);
  particles.push_back(muon2);
  particles.push_back(muon3);
  particles.push_back(muon4);
  particles.push_back(muon5);

  // (optional but nice) Print out the data from all the particles (put them in a vector)

  // Sum the four-momenta of the two electrons 
  // Do the dot product of the first two four-muons

  // Assignment operator of an electron to a new electron
  // Copy constructor of the first muon to a new muon
  // Move the antielectron into another antielectron using the move constructor 
  // Assign the antimuon to another antimuon using the move assignment

  // (optional but nice) Here or at the end of each step, print the new particle info
  // to convince yourself that you have used all special functions and operations correctly

  return 0;
}