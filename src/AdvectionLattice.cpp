#include "AdvectionLattice.hpp"

AdvectionLattice::AdvectionLattice(int length, double velocity, double dx) :
 m_length(length),
 m_v(velocity),
 m_dx(dx),
 m_data(length,0.0)

{
  // Initialise the lattice with an appropriate exponential.
  for(int i = 0; i < m_length; ++i)
  {
    m_data[i] = std::exp(-10.0*std::pow(i*m_dx-2,2));
  }

}
void AdvectionLattice::initialise(double initialValue, double noise, std::default_random_engine &generator)
{
  static std::uniform_real_distribution<double> distribution(-noise,noise);

	for(auto &phi : m_data)
	{
		phi = initialValue + distribution(generator);
	}
}
double& AdvectionLattice::operator[](int index)
{
    index = (index + m_length) % m_length;
    return m_data[index];
}
const double& AdvectionLattice::operator[](int index) const
{
  index = (index + m_length) % m_length;
  return m_data[index];
}
double AdvectionLattice::nextValue(int i, double dt) const
{
  return ((*this)[i+1] + (*this)[i-1])/2.0 + ((m_v*dt)/(2.0*m_dx))*((*this)[i+1]-(*this)[i-1]);
}
void update(AdvectionLattice &currentLattice, AdvectionLattice &updateLattice, double dt)
{
  for(int i = 0; i < currentLattice.m_length; ++i)
  {
    updateLattice[i] = currentLattice.nextValue(i,dt);
  }
}
std::ostream& operator<<(std::ostream& out, const AdvectionLattice &lattice)
{
  for(int i = 0; i < lattice.m_length*2; ++i)
  {
    out << i*lattice.m_dx << ' ' << lattice[i] << '\n';
  }

  return out;
}

void AdvectionLattice::printComoving(std::ostream& out, double t) const
{
  for(int i = 0; i < m_length*2; ++i)
  {
    out << (i*m_dx-m_v*t) << ' ' << (*this)[i] << '\n';
  }

}
