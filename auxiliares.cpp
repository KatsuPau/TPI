//
// Created by Ralo on 14/04/2019.
//
#include "definiciones.h"
#include "auxiliares.h"

int cantHogaresCasaConNHabitaciones(eph_h th, int region,int hab){
    int hogar = 0;
    int cant = 0;
    while(hogar<th.size()){
        if(th[hogar][IV1] == 1 && th[hogar][REGION] == region && th[hogar][IV2] == hab){
            cant = cant + 1;
            hogar++;
        } else {
            hogar++;
        }
    }
    return cant;
}



// Ok
int maxCantHab(eph_h th, int region){
    int maxHab = th[0][IV2];
    int hogar = 0;
    while(hogar < th.size()){
        if(th[hogar][IV2] >= maxHab && th[hogar][REGION] == region){
            maxHab = th[hogar][IV2];
        } else{
        }
        hogar++;
    }
    return maxHab;
}


bool tablaHogaresOrdenadaPorIngresosPerCapita(eph_h th,eph_i ti){
     bool res = true;
     int i = 0;
     while(i<th.size()){
         if(ingresosPerCapita(th[i],ti) <= ingresosPerCapita(th[i+1],ti)){
             i++;
         } else{
             res = false;
             break;
         }
     }
     return res;
}

int ingresosPerCapita(hogar h,eph_i ti){
    int res = (ingresos(h,ti) / cantHabitantes(h,ti));
    return res;
}

int ingresos(hogar h,eph_i ti){
    int i = 0;
    int ingreso = 0;
    while(i<ti.size()){
        if(ti[i][INDCODUSU]=h[HOGCODUSU] && ti[i][p47T]>-1){
            ingreso = ingreso + ti[i][p47T];
        } else {
            // skip
        }
        i++;
    }
    return ingreso;
}

int cantHabitantes(hogar h,eph_i ti){
    int i = 0;
    int cant = 0;
    while(i<ti.size()){
        if(ti[i][INDCODUSU] = h[HOGCODUSU]){
            cant = cant + 1;
        } else{
            //skip
        }
        i++;
    }
    return cant;
}

int areaObservada(eph_h th, eph_i ti){
    return areaIgualdadTotal -  integralDeIngresosObservados(th,ti);

}

int integralDeIngresosObservados(eph_h th,eph_i ti){
    int res = 0;
    int i = 0;
    int n = th.size();
    int m = 1/n;
    while(i<n){
        res = (ingresosHasta(i-1,th,ti)/ingresosHasta(n,th,ti))+(ingresosPerCapita(th[i],ti)/ingresosHasta(n,th,ti));
        i=i+1;
    }
    return m*res;
}

int ingresosHasta(int n,eph_h th, eph_i ti){
    int i = 0;
    int ing = 0;
    while(i<n){
           ing = ingresosPerCapita(th[i],ti);
           i++;
    }
    return ing;
}


