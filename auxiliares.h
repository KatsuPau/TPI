//
// Created by leticia on 07/05/19.
//

#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esValida(eph_h th, eph_i ti);
int cantHogaresCasaConNHabitaciones(eph_h th, int region,int hab);
int maxCantHab(eph_h th, int region);
float proporcionTeleworking(vector<vector<int> > k1,vector<vector<int> > k2);
bool tablaHogaresOrdenadaPorIngresosPerCapita(eph_h th,eph_i ti);
double areaObservada(eph_h th, eph_i ti);
double integralDeIngresosObservados(eph_h th,eph_i ti);
double ingresosPerCapita(hogar h, eph_i ti);
double ingresosHasta(int n,eph_h th, eph_i ti);
double cantHabitantes2(hogar h,eph_i ti);
float proporcionDeCasasConHC(eph_h th,eph_i ti, int region);
eph_h ordenarPorIngreso(eph_h &th,eph_i ti);
double ingresos(hogar h, eph_i ti);
eph_h swap1(eph_h,int i,int k);
int indiceMinimoIngreso(eph_h &th, int i, int h, eph_i ti);


#endif //SOLUCION_AUXILIARES_H
