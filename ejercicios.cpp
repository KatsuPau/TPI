#include "definiciones.h"
#include "ejercicios.h"
#include "auxiliares.h"

// Ok.
bool esEncuestaValida(eph_h th, eph_i ti) {
    if (esValida(th, ti)) {
        return true;
    } else {
        return false;
    }
}


// Ok.
vector<int> histHabitacional(eph_h th, eph_i ti, int region) {
    vector<int> res = {};
    if (region <= 6 && region > 0) {
        int maxHab = maxCantHab(th, region);
        int hab = 0;
        while (hab <= maxHab) {
            res.push_back(cantHogaresCasaConNHabitaciones(th, region, hab));
            hab++;
        }
    } else {}
    return res;
}

// Ok.
vector<float> laCasaEstaQuedandoChica(eph_h th, eph_i ti) {
    vector<float> res(CANTIDAD_DE_REGIONES);
    int i = 0;
    while (i < 6) {
        res[i] = proporcionDeCasasConHC(th, ti, i + 1);
        i++;
    }
    return res;
}

// Ok.
bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i) {
    bool res = false;
    if ((proporcionTeleworking(t2h, t2i)) > (proporcionTeleworking(t1h, t1i))) {
        res = true;

    }
    return res;
}

void ordenarRegionYCodusu(eph_h &th, eph_i &ti) {
    return;
}


vector<hogar> muestraHomogenea(eph_h th, eph_i ti) {
    eph_h res = {};
  //  int i = 0;
    /*
    while (i < res.size()) {
        double diferencia = ingresos(res[i], ti) - ingresos(res[i + 1], ti);
        int j = i + 1;
        while (j < res.size()) {
            if ((ingresos(th[j], ti) - ingresos(th[j] + 1, ti)) == diferencia) {
                j++;
            } else {
            //    quitarJ(res, j);
                j++;
            }
        }
        i++;
    }
       */
    return res;
}


// Ok.
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


// Ok.
double indiceGini(eph_h th, eph_i ti) {
    double res = 0.0;
    if (tablaHogaresOrdenadaPorIngresosPerCapita(th, ti)) {
        res = areaObservada(th, ti) / 0.5;
    } else {}
    return res;
}






