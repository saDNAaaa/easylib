#ifndef _EASY_H_
#define _EASY_H_
#include <iostream>
#define max_time 64
struct TIMER{
    int overtime, nowtime;
    int number, used;
    char timecr0;
};
struct TIMCTL{
    int hz, usingt, started, paused;
    struct TIMER timer[max_time];
    struct TIMER *ptime[max_time];
};
void write_mem(char addr,char data);
char get_mem(char addr);
int SetTimer(struct TIMCTL *ctl,int ot,int nt);
int CleanTimer(struct TIMCTL *ctl, int nm);
int JmpTimer(struct TIMCTL *ctl, int nm);
int InTimer(struct TIMCTL *ctl,int nm);
#endif
