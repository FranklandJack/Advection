#include "AdvectionInputParameters.hpp"

std::ostream& operator<<(std::ostream& out, const AdvectionInputParameters& params)
{
	int outputColumnWidth = 30;
    out << "Input-Parameters..." << '\n';
    out << std::setw(outputColumnWidth) << std::setfill(' ') << std::left << "Spatial-discretistation: " << std::right << params.spaceStep << '\n';
    out << std::setw(outputColumnWidth) << std::setfill(' ') << std::left << "Temperol-discretistation: " << std::right << params.timeStep << '\n';
    out << std::setw(outputColumnWidth) << std::setfill(' ') << std::left << "v: " << std::right << params.velocity <<'\n';
    out << std::setw(outputColumnWidth) << std::setfill(' ') << std::left << "Initial-value: " << std::right << params.initialValue << '\n';
    out << std::setw(outputColumnWidth) << std::setfill(' ') << std::left << "Initial-noise: " << std::right << params.noise << '\n';
    out << std::setw(outputColumnWidth) << std::setfill(' ') << std::left << "Total-steps: " << std::right << params.totalSteps<< '\n';
		out << std::setw(outputColumnWidth) << std::setfill(' ') << std::left << "Domain: " << std::right << params.domain<< '\n';
    out << std::setw(outputColumnWidth) << std::setfill(' ') << std::left << "Output-directory: " << std::right << params.outputName << '\n';
    return out;
}
