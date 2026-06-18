#include "inc/incense_vec.h"

void print_vec(IncenseVec vec)
{
    printf("木:%2.1f 花:%2.1f 药:%2.1f 凉:%2.1f 甜:%2.1f | ",
           vec.wood, vec.flower, vec.herb, vec.cool, vec.sweet);
    printf("安神:%2.1f 醒神:%2.1f 祛湿:%2.1f 润肺:%2.1f\n",
           vec.calm, vec.refresh, vec.damp, vec.lung);
}