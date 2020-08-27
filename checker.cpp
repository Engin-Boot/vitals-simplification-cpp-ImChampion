#include <assert.h>
#include<iostream>
using namespace std;

bool vitalisInsideLimit(float value,int lowerlimit, int upperlimit)
{
    return (value > lowerlimit && value < upperlimit);
}

bool vitalsAreOk(float bpm, float spo2, float respRate)
{
  return (vitalisInsideLimit(bpm,70,150) && vitalisInsideLimit(spo2,90,100) && vitalisInsideLimit(respRate,30,95));
}

int main() {

  assert(vitalisInsideLimit(70, 60, 95) == true);
  assert(vitalisInsideLimit(55, 90, 150) == false); //below lower limit
  assert(vitalisInsideLimit(170, 95, 150) == false); //above upper limit
 cout<<"vitalisInsideLimit is Working Function!"<<endl;

  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(70, 101, 70) == false);
  assert(vitalsAreOk(160,91,30) == false);
   cout<<"vitalsAreOk is Working Function!"<<endl;


  return 0;
}
