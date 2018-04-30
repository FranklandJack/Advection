#ifndef CHLattice_hpp
#define CHLattice_hpp

#include <vector>
#include <random>
#include <iostream>
#include <math.h>

class AdvectionLattice {
private:
  int m_length;
  std::vector<double> m_data;
  double m_v;
  double m_dx;

public:
  AdvectionLattice(int length, double velocity, double dt);
  void initialise(double initialValue, double noise, std::default_random_engine &generator);
  double& operator[](int index);
  const double& operator[](int index) const;
  double nextValue(int index, double dt) const;
  friend void update(AdvectionLattice &currentLattice, AdvectionLattice &updateLattice, double dt);
  friend std::ostream& operator<<(std::ostream& out, const AdvectionLattice &lattice);
  void printComoving(std::ostream& out, double t) const;


};

#endif
