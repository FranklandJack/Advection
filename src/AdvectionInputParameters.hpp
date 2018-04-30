#ifndef AdvectionInputParameters_hpp
#define AdvectionInputParameters_hpp
#include <iostream>
#include <iomanip>
/**
 *\file
 *\class AdvectionInputParameters
 *\brief Class for easily handling input parameters of Cahn-Hilliard differential equation solver.
 *
 * This class essentially just holds some values and has an operator to easily output
 * them to a stream.
 */
class AdvectionInputParameters
{
public:

	/// Spatial discretisation step.
    double spaceStep;

    /// Temporal discretisation step.
    double timeStep;

    /// M positive constant from Cahn-Hilliard equation.
    double velocity;

    /// \phi_0 initial value of order parameter.
    double initialValue;

    /// Maximum magnitude of initial noise.
    double noise;

    /// Number of steps to evolve equation for.
    int totalSteps;

    /// Number of rows in square lattice domain.
    int domain;

    /// Name of output directory to save any output into.
    std::string outputName;

    /**
	 *\brief operator<< overload for outputting the results.
	 *\param out std::ostream reference that is the stream being outputted to.
	 *\param params constant AdvectionInputParameters instance to be output.
	 *\return std::ostream reference so the operator can be chained.
	 *
	 * Results will be output in a formatted table for easy viewing in the command line or a file.
	 */
    friend std::ostream& operator<<(std::ostream& out, const AdvectionInputParameters& params);

};
#endif /* AdvectionInputParameters_hpp */
