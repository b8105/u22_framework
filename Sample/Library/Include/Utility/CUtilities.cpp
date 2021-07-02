#include "CUtilities.h"

#include "../Framework/Framework.h"


float u22::utility::CUtilities::GetFrameSecond(void) {
    return u22::Framework::GetInfomation().clock->GetFrameSecond();
}

float u22::utility::CUtilities::GetFPS(void) {
    return u22::Framework::GetInfomation().clock->GetFPS();
}
