#ifndef ENERGYCENTER_SIMULATION_DATA_GENERATOR
#define ENERGYCENTER_SIMULATION_DATA_GENERATOR

#include <SimulationChannelDescriptor.h>
#include <string>
class EnergyCenterAnalyzerSettings;

class EnergyCenterSimulationDataGenerator
{
public:
	EnergyCenterSimulationDataGenerator();
	~EnergyCenterSimulationDataGenerator();

	void Initialize( U32 simulation_sample_rate, EnergyCenterAnalyzerSettings* settings );
	U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channel );

protected:
	EnergyCenterAnalyzerSettings* mSettings;
	U32 mSimulationSampleRateHz;

protected:
	void CreateSerialByte();
	std::string mSerialText;
	U32 mStringIndex;

	SimulationChannelDescriptor mSerialSimulationData;

};
#endif //ENERGYCENTER_SIMULATION_DATA_GENERATOR