#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

bool esEncuestaValida(eph_h th, eph_i ti) {
    return false;
}

// Ok!
vector<int> histHabitacional(eph_h th, eph_i ti, int region) {
    vector<int> res = {};
    if (region <= 6 && region > 0) {
        int maxHab = maxCantHab(th, region);
        int hab = 1;
        while (hab <= maxHab) {
            res.push_back(cantHogaresCasaConNHabitaciones(th, region, hab));
            hab++;
        }
    } else {}
    return res;
}


vector<float> laCasaEstaQuedandoChica(eph_h th, eph_i ti) {
    vector<float> res(CANTIDAD_DE_REGIONES);
    return res;
}

bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i) {
    return false;
}


void ordenarRegionYCodusu(eph_h &th, eph_i &ti) {
    return;
}

// Idea: - Crear funcion que ordene por ingreso de menor a mayor a th.
//       - Crear funcion que calcule la cantidad maxima de veces que aparece la diferencia de ingresos.
//
vector<hogar> muestraHomogenea(eph_h th, eph_i ti) {
    vector<hogar> res = {};
    int difMax = cantMaxDif(th, ti);


    return res;
}

int cant(int dif, eph_h th, eph_i ti) {
    int h = 0;
    int c = 0;
    int s = 0;
    while(s<th.size()){
    while (h < th.size() && h!=s){
        if (ingresos(th[h], ti) - ingresos(th[s], ti) == dif)){
            c++;
        } else{}
        h++;
    }
    s++
    }
    return c;
}

int maxCant(eph_h th,eph_i ti){
    int h = 0;


}





//Ok!
void corregirRegion(eph_h &th, eph_i ti) {
    int filas = 0;
    eph_h th0 = th;
    while (filas < th0.size()) {
        if (th0[filas][REGION] == 1) {
            th[filas][REGION] = 5;
        } else {
            th[filas][REGION] = th0[filas][REGION];
        }
        filas++;
    }
    return;
}

// Casi ok!
float indiceGini(eph_h th, eph_i ti) {
    float res = 0.0;
    if (tablaHogaresOrdenadaPorIngresosPerCapita(th, ti)) {
        res = areaObservada(th, ti) / areaIgualdadTotal;
    } else {}
    return res;
}
