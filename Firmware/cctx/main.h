/*
 * main.h
 *
 *  Created on: 28 ����. 2014 �.
 *      Author: Kreyl
 */

#ifndef MAIN_H_
#define MAIN_H_

class App_t {
private:

public:
    Thread *PThd;
    bool LightIsOn;
    int32_t Lt = 100;
    // Inner use
    void ITask();
};

extern App_t App;

#endif /* MAIN_H_ */
