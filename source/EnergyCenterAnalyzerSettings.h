#ifndef ENERGYCENTER_ANALYZER_SETTINGS
#define ENERGYCENTER_ANALYZER_SETTINGS

#include <AnalyzerSettings.h>
#include <AnalyzerTypes.h>

class EnergyCenterAnalyzerSettings : public AnalyzerSettings
{
public:
	EnergyCenterAnalyzerSettings();
	virtual ~EnergyCenterAnalyzerSettings();

	virtual bool SetSettingsFromInterfaces();
	void UpdateInterfacesFromSettings();
	virtual void LoadSettings( const char* settings );
	virtual const char* SaveSettings();

	
	Channel mInputChannel;
	U32 mBitRate;

protected:
	std::auto_ptr< AnalyzerSettingInterfaceChannel >	mInputChannelInterface;
	std::auto_ptr< AnalyzerSettingInterfaceInteger >	mBitRateInterface;
};

#endif //ENERGYCENTER_ANALYZER_SETTINGS
