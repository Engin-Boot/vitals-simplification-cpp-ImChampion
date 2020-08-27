#include <assert.h>

/*bool bpmIsOk(float bpm) {
  return (bpm >= 70 && bpm <= 150);
}
bool spo2IsOk(float spo2) {
  return (spo2 >= 90);
}
bool respRateIsOk(float respRate) {
  return (respRate >= 30 && respRate <= 95);
}*/

bool vitalisInsideLimit(float value,int lowerlimit, int upperlimit)
{
    return (value>=lowerlimit && value<=upperlimit);
}

bool vitalsAreOk(float bpm, float spo2, float respRate)
{
  return (vitalisInsideLimit(bpm,70,150) && vitalisInsideLimit(spo2,90,100) && vitalisInsideLimit(respRate,30,95));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  assert(vitalsAreOk(100,91,100) == false);
  
  return 0;
}
