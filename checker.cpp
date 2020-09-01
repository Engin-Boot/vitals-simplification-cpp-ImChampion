#include <assert.h>
#include<bits/stdc++.h>

using namespace std;

class Alert
{
    public:
    virtual void raiseAlert(const char* vitalName,const char* level)=0;  //It tell that

};
class AlertWithSMS: public Alert
{
public:
    void raiseAlert(const char* vitalName,const char* level)
    {

        cout<<"SMS: "<<vitalName<<" "<<level<<endl;
    }
};

class AlertWithSound: public Alert
{
public:
    void raiseAlert(const char* vitalName,const char* level)
    {

        cout<<"Sound: "<<vitalName<<" "<<level<<endl;
    }

};

class RangeChecker
{
private:
    int lower,upper;
    const char* vitalName;
    Alert* alerter;
public:
    RangeChecker(const char* name,int low,int up,Alert* alerterPtr)
    {
        vitalName=name;
        lower=low;
        upper=up;
        alerter=alerterPtr;
    }
    void checkAgainstRange(float value)
    {
        if(value < lower)
        {

            alerter->raiseAlert(vitalName,"Too Low");
        }
        else if(value > upper)
        {

            alerter->raiseAlert(vitalName,"Too High");
        }
    }

};
class VitalsIntegrator
{
private:
    RangeChecker bpmChecker, spo2Checker, respRateChecker,
    ecgChecker, bodyTempChecker, glucoseChecker,
    bloodPressureChecker,eegChecker,heartRateChecker;

public:
    //pROVIDING lIMIT TO VITAL PARAMETERS

    VitalsIntegrator(Alert* alertPtr):
         bpmChecker("Pulse Rate",70, 150, alertPtr),
         spo2Checker("spo2",90,101,alertPtr),
         respRateChecker("respRate",30,95,alertPtr),
         ecgChecker("ecg",120,200,alertPtr),

         bodyTempChecker("bodyTemp",97, 99, alertPtr),
         glucoseChecker("gluco",72,100,alertPtr),
         bloodPressureChecker("bloodPressure",91,120,alertPtr),
         eegChecker("eeg",7.5,13,alertPtr),

         heartRateChecker("heartRate",60,100,alertPtr)
    {}

    void checkAllVitals(map<string,int> &parameters)
    {
        //cout<<parameters["heartRate"];
		if(parameters["bpm"])
			bpmChecker.checkAgainstRange(parameters["bpm"]);

		if(parameters["spo2"])
			spo2Checker.checkAgainstRange(parameters["spo2"]);

		if(parameters["respRate"])
			respRateChecker.checkAgainstRange(parameters["respRate"]);

		if(parameters["ecg"])
			ecgChecker.checkAgainstRange(parameters["ecg"]);

		if(parameters["bodyTemp"])
			bodyTempChecker.checkAgainstRange(parameters["bodyTemp"]);

		if(parameters["glucose"])
			glucoseChecker.checkAgainstRange(parameters["glucose"]);

		if(parameters["bloodPressure"])
			bloodPressureChecker.checkAgainstRange(parameters["bloodPressure"]);

		if(parameters["eeg"])
			eegChecker.checkAgainstRange(parameters["eeg"]);

		if(parameters["heartRate"])
			heartRateChecker.checkAgainstRange(parameters["heartRate"]);
    }
};

int main()
{

	map<string,int> vitalParameter_patient1;
	vitalParameter_patient1["bpm"] = 75;
	vitalParameter_patient1["spo2"] = 91;
	vitalParameter_patient1["respRate"] = 60;
	vitalParameter_patient1["ecg"] = 150;
	vitalParameter_patient1["bodyTemp"] = 98;
	vitalParameter_patient1["glucose"] = 98;
	vitalParameter_patient1["bloodPressure"] = 100;
	vitalParameter_patient1["eeg"] = 10;
	vitalParameter_patient1["heartRate"] = 200;

	//Patient 2 do not require reading of EEG and Heart rate
	map<string,int> vitalParameter_patient2;
	vitalParameter_patient2["bpm"] = 444;
	vitalParameter_patient2["spo2"] = 120;
	vitalParameter_patient2["respRate"] = 655;
	vitalParameter_patient2["ecg"] = 150;
	vitalParameter_patient2["bodyTemp"] = 98;
	vitalParameter_patient2["glucose"] = 98;
	vitalParameter_patient2["bloodPressure"] = 100;

    AlertWithSound alerter;
    VitalsIntegrator vitals(&alerter);
    cout<<"Patient 1 Vital Parameters Result"<<endl;
    vitals.checkAllVitals(vitalParameter_patient1);
    cout<<"\nPatient 2 Vital Parameters Result"<<endl;
    vitals.checkAllVitals(vitalParameter_patient2);

    return 0;
}
