#include "easy.h"
struct TIMCTL;
struct TIMER;
int SetTimer(struct TIMCTL *ctl, int ot,int nt){
    int lnm = 0;
    for(int i = 0;;i++){
        if(ctl->timer[i].used == 1){
            lnm = i;
            lnm++;
            if(lnm == max_time){
                return -1;
            }
        }else{
            break;
        }
    }
    ctl->timer[lnm].number = lnm;
    ctl->timer[lnm].overtime = ot;
    ctl->timer[lnm].nowtime = nt;
    ctl->timer[lnm].timecr0 = 0x0001;
    ctl->hz = 1;
    ctl->timer[lnm].used = 1;
    ctl->usingt++;
    if(ctl->usingt == max_time){
        return -1;
    }
    return lnm;
}
int CleanTimer(struct TIMCTL *ctl,int nm){
    if(ctl->usingt == 0){
        return -1;
    }
    ctl->usingt--;
    ctl->timer[nm].used = 0;
    ctl->timer[nm].overtime = NULL;
    ctl->timer[nm].nowtime = NULL;
    ctl->timer[nm].number = NULL;
}
int JmpTimer(struct TIMCTL *ctl,int nm){
    if(ctl->timer[nm].timecr0 == 0x0010){
        CleanTimer(ctl, nm);
        return -1;
    }
    ctl->timer[nm].timecr0 = 0x0100;
    ctl->started--;
    ctl->paused++;
    return 0;
}
int InTimer(struct TIMCTL *ctl,int nm){
    int time;
    if(ctl->timer[nm].timecr0 == 0x0010){
        CleanTimer(ctl, nm);
        return -1;
    }
    ctl->timer[nm].timecr0 = 0x1000;
    ctl->paused--;
    ctl->started++;
    for(int a = ctl->timer[nm].nowtime;a < ctl->timer[nm].overtime;a++){
        time = a;
    }
    return time;
}
