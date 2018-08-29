#ifndef ENERGYCENTER_ANALYZER_H
#define ENERGYCENTER_ANALYZER_H

#include <Analyzer.h>
#include "EnergyCenterAnalyzerResults.h"
#include "EnergyCenterSimulationDataGenerator.h"

class EnergyCenterAnalyzerSettings;
class ANALYZER_EXPORT EnergyCenterAnalyzer : public Analyzer2
{
public:
	EnergyCenterAnalyzer();
	virtual ~EnergyCenterAnalyzer();

	virtual void SetupResults();
	virtual void WorkerThread();

	virtual U32 GenerateSimulationData( U64 newest_sample_requested, U32 sample_rate, SimulationChannelDescriptor** simulation_channels );
	virtual U32 GetMinimumSampleRateHz();

	virtual const char* GetAnalyzerName() const;
	virtual bool NeedsRerun();

protected: //vars
	std::auto_ptr< EnergyCenterAnalyzerSettings > mSettings;
	std::auto_ptr< EnergyCenterAnalyzerResults > mResults;
	AnalyzerChannelData* mSerial;

	EnergyCenterSimulationDataGenerator mSimulationDataGenerator;
	bool mSimulationInitilized;

	//Serial analysis vars:
	U32 mSampleRateHz;
	U32 mStartOfStopBitOffset;
	U32 mEndOfStopBitOffset;
};

extern "C" ANALYZER_EXPORT const char* __cdecl GetAnalyzerName();
extern "C" ANALYZER_EXPORT Analyzer* __cdecl CreateAnalyzer( );
extern "C" ANALYZER_EXPORT void __cdecl DestroyAnalyzer( Analyzer* analyzer );

#endif //ENERGYCENTER_ANALYZER_H
