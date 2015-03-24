/*
 * filter.h
 *
 *  Created on: 25 сент. 2014 г.
 *      Author: Kreyl
 */

#ifndef FILTER_H_
#define FILTER_H_

#include "cmd_uart.h"

// ==== Example ====
//#define FILTER_SZ   4
//extern const FirSettings_t<FILTER_SZ> Coef = {
//        1000, // coef divider
//        {1,2,3,4}
//};
//
//FilterFir_t<FILTER_SZ, Coef> Filter;

template <uint32_t Sz>
struct FirSettings_t {
    int32_t Divider;
    int32_t a[Sz];
};


template <uint32_t Sz, FirSettings_t<Sz> const& Coef>
class FilterFir_t {
private:
    int32_t x[Sz-1], W;
public:
    int32_t AddAndCalc(int32_t x0) {
//        Uart.Printf("\r %d   ", x0);
        // Calculate filter
        int32_t *a = (int32_t*)&Coef.a[0];
        int32_t rslt = x0 * a[0], R = W;
        for(uint32_t i=1; i<Sz; i++) {
            rslt += x[R] * a[i];
//            Uart.Printf("x%u=%d; ", R, x[R], i);
            if(++R >= Sz-1) R = 0;
        }
        // Add value to buffer
        if(W == 0) W = Sz - 2;
        else W--;
        x[W] = x0;
//        Uart.Printf("rslt=%d", rslt);
        return rslt / Coef.Divider;
    }
};



#endif /* FILTER_H_ */
