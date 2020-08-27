#include <assert.h>

bool is_check_bpm(float bpm)
{
    return !(bpm < 70 || bpm > 150);
}

bool is_check_spo(float spo2)
{
    return !(spo2 < 90);
}

bool is_check_respRate(float respRate)
{
    return !(respRate < 30 || respRate > 95);
}

bool vitalsAreOk(float bpm, float spo2, float respRate)
{
  return (is_check_bpm(bpm) && is_check_spo(spo2) && is_check_respRate(respRate));
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  return 0;
}
