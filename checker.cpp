#include <assert.h>

bool isInsideLimit(float value,int lowerlimit, int upperlimit)
{
    return !(value<lowerlimit || value>upperlimit);
}

bool vitalsAreOk(float bpm, float spo2, float respRate)
{
  return (isInsideLimit(bpm,70,150) && isInsideLimit(spo2,90,100) && isInsideLimit(respRate,30,95));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  return 0;
}
