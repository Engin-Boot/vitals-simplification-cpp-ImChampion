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

// Range checker
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
    int bpm, spo2, respRate, ecg, bodyTemp, gluco,
    bloodPressure,eeg,heartRate;
};


class VitalsIntegrator
{
private:
    RangeChecker bpmChecker, spo2Checker,
    respRateChecker, ecgChecker, bodyTempChecker,
    glucoChecker,bloodPressure,eegChecker,heartRateChecker;

public:
    VitalsIntegrator(Alert* alertPtr):
         bpmChecker("Pulse Rate",70, 150, alertPtr),
         spo2Checker("spo2",90,101,alertPtr),
         respRateChecker("respRate",30,95,alertPtr),
         ecgChecker("ecg",50,100,alertPtr),
         bodyTempChecker("bodyTemp",75, 100, alertPtr),
         glucoChecker("gluco",500,100,alertPtr),
         bloodPressure("bloodPressure",30,95,alertPtr),
         eegChecker("eeg",50,100,alertPtr),
         heartRateChecker("heartRate",70,101,alertPtr)
    {}

    void checkAllVitals(struct vitalParameter parameters)
    {

     bpmChecker.checkAgainstRange(parameters.bpm);
     spo2Checker.checkAgainstRange(parameters.spo2);
     respRateChecker.checkAgainstRange(parameters.respRate);
     ecgChecker.checkAgainstRange(parameters.ecg);
     bodyTempChecker.checkAgainstRange(parameters.bodyTemp);
     glucoChecker.checkAgainstRange(parameters.gluco);
     bloodPressure.checkAgainstRange(parameters.bloodPressure);
     eegChecker.checkAgainstRange(parameters.eeg);
     heartRateChecker.checkAgainstRange(parameters.heartRate);

    }
};



bool vitalisInsideLimit(float value,int lowerlimit, int upperlimit)
{
    return (value > lowerlimit && value < upperlimit);
}
bool vitalsAreOk(float bpm, float spo2, float respRate)
{
    AlertWithSMS smsAlerter;

  RangeChecker bpmChecker("pulse rate",70,150,&smsAlerter);
  bpmChecker.checkAgainstRange(bpm);

   RangeChecker spo2Checker("spo2",70,150,&smsAlerter);
  bpmChecker.checkAgainstRange(spo2);

   RangeChecker respChecker("resp rate",70,150,&smsAlerter);
  bpmChecker.checkAgainstRange(bpm);

  return (vitalisInsideLimit(bpm,70,150) &&
           vitalisInsideLimit(spo2,90,100) &&
          vitalisInsideLimit(respRate,30,95));
}


int main()
{
    struct vitalParameter parameters{55,91,300,500,500,30,70,80,60};
     AlertWithSound alerter;
    VitalsIntegrator vitals(&alerter);
    vitals.checkAllVitals(parameters);
    
  return 0;
}
