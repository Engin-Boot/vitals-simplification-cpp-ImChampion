#include <assert.h>
#include<iostream>
using namespace std;

class Alert
{
    public:
    virtual void raiseAlert(const char* vitalName,const char* level) ;  //It tell that

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

struct vitalParameter
{
    float bpm, spo2, respRate, ecg, bodyTemp, glucose,
    bloodPressure,eeg,heartRate;
};


class VitalsIntegrator
{
private:
    RangeChecker bpmChecker, spo2Checker, respRateChecker,
    ecgChecker, bodyTempChecker, glucoseChecker,
    bloodPressure,eegChecker,heartRateChecker;

public:
    VitalsIntegrator(Alert* alertPtr):
         bpmChecker("Pulse Rate",70, 150, alertPtr),
         spo2Checker("spo2",90,101,alertPtr),
         respRateChecker("respRate",30,95,alertPtr),
         ecgChecker("ecg",120,200,alertPtr),

         bodyTempChecker("bodyTemp",97, 99, alertPtr),
         glucoseChecker("gluco",72,100,alertPtr),
         bloodPressure("bloodPressure",91,120,alertPtr),
         eegChecker("eeg",7.5,13,alertPtr),

         heartRateChecker("heartRate",60,100,alertPtr)
    {}

    void checkAllVitals(struct vitalParameter parameters)
    {

     bpmChecker.checkAgainstRange(parameters.bpm);
     spo2Checker.checkAgainstRange(parameters.spo2);
     respRateChecker.checkAgainstRange(parameters.respRate);
     ecgChecker.checkAgainstRange(parameters.ecg);

     bodyTempChecker.checkAgainstRange(parameters.bodyTemp);
     glucoseChecker.checkAgainstRange(parameters.glucose);
     bloodPressure.checkAgainstRange(parameters.bloodPressure);
     eegChecker.checkAgainstRange(parameters.eeg);

     heartRateChecker.checkAgainstRange(parameters.heartRate);
    }
};

int main()
{
   struct vitalParameter patient1{75,91,60,210,98,98,100,10,80};
   struct vitalParameter patient2{75,120,60,150,98,98,100,15,80};


    AlertWithSound alerter1;
    AlertWithSMS alerter2;
    VitalsIntegrator vitals(&alerter2);
    cout<<"Patient 1 Vital Parameter Result"<<endl;
    vitals.checkAllVitals(patient1);
    cout<<"Now Result of Patient 2"<<endl;
    VitalsIntegrator vitals2(&alerter1);
    vitals2.checkAllVitals(patient2);

    return 0;
}
