//
// Created by Ralo on 14/04/2019.
//
#include "definiciones.h"
#include "auxiliares.h"

// Ejercicio 1.


int indiceMinimoIngreso(eph_h &vector, int i, unsigned long size, eph_i ti);

bool vacia(vector<vector<int> > t) {
    if (t.size() == 0) {
        return true;
    } else {
        return false;yasgdashd
        sajdg
    }
}

bool esMatriz(vector<vector<int> > t) {
    int i = 0;
    bool result = false;
    while (i < t.size()) {
        if (t[i].size() == t[0].size()) {
            result = true;
        } else {
            result = false;
            break;
        }
        i++;
    }
    return result;
}

bool cantidadCorrectaDeColumnasH(vector<vector<int> > t) {
    bool result = false;
    int i = 0;
    while (i < t.size()) {
        if (t[i].size() == 10) {
            result = true;
        } else {
            result = false;
            break;
        }
        i++;
    }
    return result;
}

bool cantidadCorrectaDeColumnasI(vector<vector<int> > v) {
    bool result = false;
    int i = 0;
    while (i < v.size()) {
        if (v[i].size() == 11) {
            result = true;
        } else {
            result = false;
            break;
        }
        i++;
    }
    return result;
}

bool hayHogarConCodigo(eph_h th, int n) {
    bool result = false;
    int i = 0;
    while (i < th.size()) {
        int j = 0;
        while (j < th[0].size()) {
            if (th[i][HOGCODUSU] == n) {
                result = true;
                break;
            }
            j++;
        }
        i++;
    }
    return result;
}

bool noHayIndividuosSinHogares(eph_h th, eph_i ti) {
    bool result = false;
    int i = 0;
    while (i < ti.size()) {
        int j = 0;
        while (j < ti[0].size()) {
            if (hayHogarConCodigo(th, ti[i][INDCODUSU])) {
                result = true;
                break;
            }
            j++;
        }
        i++;
    }
    return result;
}

bool hayIndividuoConCodigo(eph_i ti, int n) {
    bool result = false;
    int i = 0;
    while (i < ti.size()) {
        int j = 0;
        while (j < ti[0].size()) {
            if (ti[i][INDCODUSU] == n) {
                result = true;
                break;
            }
            j++;
        }
        i++;
    }
    return result;
}

bool noHayHogaresSinIndividuos(eph_h th, eph_i ti) {
    bool result = false;
    int i = 0;
    while (i < th.size()) {
        int j = 0;
        while (j < th[0].size()) {
            if (hayIndividuoConCodigo(ti, th[i][INDCODUSU])) {
                result = true;
                break;
            }
            j++;
        }
        i++;
    }
    return result;
}

bool mismoCodusuYComponente(individuo k, individuo l) {
    bool result = false;
    if (k[INDCODUSU] == l[INDCODUSU] && k[COMPONENTE] == l[COMPONENTE]) {
        result = true;
    }
    return result;
}

bool hayRepetidosI(eph_i ti) {
    bool result = false;
    int n1 = 0;
    while (n1 < ti.size()) {
        int n2 = 0;
        while (n2 < ti.size()) {
            if (n1 != n2 && mismoCodusuYComponente(ti[n1], ti[n2])) {
                result = true;
            }
            n2++;
        }
        n1++;
    }
    return result;
}

bool hayRepetidosH(eph_h th) {
    bool result = false;
    int n1 = 0;
    while (n1 < th.size()) {
        int n2 = 0;
        while (n2 < th.size()) {
            if (n1 != n2 && th[n1][HOGCODUSU] == th[n2][HOGCODUSU]) {
                result = true;
            }
            n2++;
        }
        n1++;
    }
    return result;
}

bool mismoAnioYTrimestre(eph_i ti, eph_h th) {
    bool result = false;
    int i = 0;
    while (i < ti.size()) {
        int anioI = ti[0][2];
        int trimestreI = ti[0][3];
        if (ti[i][INDANIO] == anioI && ti[i][INDTRIMESTRE] == trimestreI) {
            int j = 0;
            while (j < th.size()) {
                if (th[j][HOGANIO] == anioI && th[j][HOGTRIMESTRE] == trimestreI) {
                    result = true;
                }
                j++;
            }
        }
        i++;
    }
    return result;
}

int cantHabitantes(hogar h, eph_i ti) {
    int i = 0;
    int suma = 0;
    while (i < ti.size()) {
        if (h[HOGCODUSU] == ti[i][INDCODUSU]) {
            suma = suma + 1;
        }
        i++;
    }
    return suma;

}

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti) {
    bool result = false;
    int i = 0;
    while (i < th.size()) {
        if (cantHabitantes(th[i], ti) < 21) {
            result = true;
        } else {
            result = false;
        }
        i++;
    }
    return result;
}

bool cantidadValidaDeDormitorios(eph_h th) {
    bool result = false;
    int i = 0;
    while (i < th.size()) {
        hogar h = th[i];
        if (h[7] >= h[8]) {
            result = true;
        } else {
            result = false;
            break;
        }
        i++;
    }
    return result;
}

bool lugarTrabajo(individuo i) {
    if (i[PP04G] > 0 && i[PP04G] >= 10) {
        return true;
    }
}

bool individuoValido(individuo i) {
    if ((i[INDCODUSU] > 0) && (i[COMPONENTE] > 0) && (i[INDTRIMESTRE] > 0 && i[INDTRIMESTRE] <= 4) &&
        (i[CH4] == 1 || i[CH4] == 2)
        && (i[CH6] >= 0) && (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1) && (i[ESTADO] >= -1 && i[ESTADO] <= 1) &&
        (i[CAT_OCUP] >= 0 && i[CAT_OCUP] <= 4) && (i[p47T] == -1 || i[p47T] >= 0) && lugarTrabajo(i)) {
        return true;
    } else {
        return false;
    }
}

bool valoresEnRangoI(eph_i ti) {
    bool result = false;
    int i = 0;
    while (i < ti.size()) {
        if (individuoValido(ti[i])) {
            result = true;
        } else {
            result = false;
            break;
        }
        i++;
    }
    return result;
}

bool hogarValido(hogar h) {
    if ((h[HOGCODUSU] > 0) && (h[HOGTRIMESTRE] > 0 && h[HOGTRIMESTRE] <= 4) &&
        (h[II7] == 1 || h[II7] == 2 || h[II7] == 3) &&
        (h[REGION] >= 1 && h[REGION] <= 6) && (h[MAS_500] == 0 || h[MAS_500] == 1) && (h[IV1] > 0 && h[IV1] <= 5) &&
        (h[IV2] > 0)
        && (h[II2] >= 1) && (h[II3] == 1 || h[II3] == 2)) {
        return true;
    } else {
        return false;
    }
}

bool valoresEnRangoH(eph_h th) {
    bool result = false;
    int i = 0;
    while (i < th.size()) {
        if (hogarValido(th[i])) {
            result = true;
        } else {
            result = false;
            break;
        }
        i++;
    }
    return result;
}

bool esValida(eph_h th, eph_i ti) {
    bool result = false;
    if (!vacia(th) && !vacia(ti) && esMatriz(th) && esMatriz(ti) && cantidadCorrectaDeColumnasH(th) &&
        cantidadCorrectaDeColumnasI(ti) && noHayIndividuosSinHogares(ti, th) && noHayHogaresSinIndividuos(ti, th)
        && !hayRepetidosI(ti) && !hayRepetidosH(th) && mismoAnioYTrimestre(ti, th) && menosDe21MiembrosPorHogar(th, ti)
        && cantidadValidaDeDormitorios(th) && valoresEnRangoI(ti) && valoresEnRangoH(th)) {
        result = true;
    } else {
        result = false;
    }
    return result;
}

// Ejercicio 2.


int cantHogaresCasaConNHabitaciones(eph_h th, int region, int hab) {
    int hogar = 0;
    int cant = 0;
    while (hogar < th.size()) {
        if (th[hogar][IV1] == 1 && th[hogar][REGION] == region && th[hogar][IV2] == hab) {
            cant = cant + 1;
            hogar++;
        } else {
            hogar++;
        }
    }
    return cant;
}


int maxCantHab(eph_h th, int region) {
    int maxHab = th[0][IV2];
    int hogar = 0;
    while (hogar < th.size()) {
        if (th[hogar][IV2] >= maxHab && th[hogar][REGION] == region) {
            maxHab = th[hogar][IV2];
        } else {
        }
        hogar++;
    }
    return maxHab;
}


// Ejercicio 3.

// EJERCICIO 3
int cantHogValidos(eph_h th, int region) {
    int i = 0;
    int suma = 0;
    while (i < th.size()) {
        if (th[i][IV1] == 1 && th[i][REGION] == region && th[i][MAS_500] == 0) {
            suma = suma + 1;
        }
        i++;
    }
    return suma;
}

float cantHogConHacimientoCritico(eph_h th, eph_i ti, int region) {
    int i = 0;
    float suma = 0.0;
    while (i < th.size()) {
        if (th[i][IV1] == 1 && th[i][REGION] == region && th[i][MAS_500] == 0 &&
            cantHabitantes(th[i], ti) > (3 * th[i][II2])) {
            suma = suma + 1;
        }
        i++;
    }
    return suma;
}

float proporcionDeCasasConHC(eph_h th, eph_i ti, int region) {
    float p = 0.0;
    if (cantHogValidos(th, region) > 0) {
        p = cantHogConHacimientoCritico(th, ti, region) / (cantHogValidos(th, region));
    }
    return p;
}


//EJERCICIO 4
vector<vector<int> > filtrarHogares(vector<vector<int> > v) {
    int i = 0;
    vector<vector<int> > res;
    while (i < v.size()) {
        if ((v[i][IV1] == 1 || v[i][IV1] == 2) && v[i][II3] == 1 && v[i][MAS_500] == 1) {
            res.push_back(v[i]);
        }
        i++;
    }
    return res;
}

vector<vector<int> > filtrarindividuos(vector<vector<int> > v) {
    int i = 0;
    vector<vector<int> > res;
    while (i < v.size()) {
        if (v[i][ESTADO] == 1 && v[i][PP04G] == 6) {
            res.push_back(v[i]);
        }
        i++;
    }
    return res;
}

int cantIndividuosTrabajan(vector<vector<int> > l, vector<vector<int> > m) {
    vector<vector<int> > k = filtrarHogares(l);
    int i = 0;
    int suma = 0;
    while (i < m.size()) {
        int j = 0;
        while (j < k.size()) {
            if (m[i][ESTADO] == 1 && (k[j][HOGCODUSU] == m[i][INDCODUSU])) {
                suma = suma + 1;
            }
            j++;
        }
        i++;
    }
    return suma;
}

float cantidadIndividuosQueTrabajanEnSuVivienda(vector<vector<int> > m, vector<vector<int> > n) {
    vector<vector<int> > k = filtrarHogares(m);
    vector<vector<int> > l = filtrarindividuos(n);
    int i = 0;
    float suma = 0.0;
    while (i < k.size()) {
        int j = 0;
        while (j < l.size()) {
            if (k[i][HOGCODUSU] == l[j][INDCODUSU]) {
                suma = suma + 1;
            }
            j++;
        }
        i++;
    }
    return suma;
}

float proporcionTeleworking(vector<vector<int> > k1, vector<vector<int> > k2) {
    float p = 0.0;
    if (cantIndividuosTrabajan(k1, k2) > 0) {
        p = cantidadIndividuosQueTrabajanEnSuVivienda(k1, k2) / cantIndividuosTrabajan(k1, k2);
    }
    return p;
}


// Ejercicio 8.

// Ok
bool tablaHogaresOrdenadaPorIngresosPerCapita(eph_h th, eph_i ti) {
    bool res = false;
    int i = 0;
    while (i < th.size() - 1) {
        if (ingresosPerCapita(th[i], ti) <= ingresosPerCapita(th[i + 1], ti)) {
            res = true;
            i++;
        } else {
            res = false;
            break;
        }
    }
    return res;
}


double ingresos(hogar h, eph_i ti) {
    int i = 0;
    double ingreso_ = 0.0;
    while (i < ti.size()) {
        if ((ti[i][p47T] > -1) && (h[HOGCODUSU] == ti[i][INDCODUSU])) {
            ingreso_ = ingreso_ + ti[i][p47T];
        } else {
            // skip
        }
        i++;
    }
    return ingreso_;
}

double cantHabitantes2(hogar h, eph_i ti) {
    int i = 0;
    double cant = 0.0;
    while (i < ti.size()) {
        if (ti[i][INDCODUSU] == h[HOGCODUSU]) {
            cant = cant + 1;
        } else {
            //skip
        }
        i++;
    }
    return cant;
}

double areaObservada(eph_h th, eph_i ti) {
    double s = 0.5 - integralDeIngresosObservados(th, ti);
    return s;
}

double integralDeIngresosObservados(eph_h th, eph_i ti) {
    double res = 0.0;
    int i = 0;
    double n = th.size();
    double m = (1.0 / n);
    while (i < n) {
        res = res + (ingresosHasta(i - 1, th, ti) / ingresosHasta(n - 1, th, ti)) +
              (ingresosPerCapita(th[i], ti) / (ingresosHasta(n - 1, th, ti) * (2)));
        i = i + 1;
    }
    return m * res;
}

double ingresosHasta(int n, eph_h th, eph_i ti) {
    int i = 0;
    double ing = 0.0;
    while (i <= n) {
        ing = ing + ingresosPerCapita(th[i], ti);
        i++;
    }
    return ing;
}

double ingresosPerCapita(hogar h, eph_i ti) {
    double s = ingresos(h, ti) / cantHabitantes2(h, ti);
    return s;
}





// Ejercicio 6.




eph_h ordenarPorIngreso(eph_h &th, eph_i ti) {
    int i = 0;
    int n = th.size();
    eph_h res = th;
    while (i < res.size()-1) {
        int ingresoMinimo = indiceMinimoIngreso(res, i, n, ti);
        res.push_back(th[ingresoMinimo]);
        i++;
    }
    return res;
}




int indiceMinimoIngreso(eph_h &th, int i, int h, eph_i ti) {
    int min = i;
    for (int j = i + 1; j < h; j++) {
        if (ingresos(th[i], ti) < ingresos(th[min], ti)){
            min = i;
        }
    }
    return min;
}





eph_h swap(eph_h &th, int i, int k) {
    int j = 0;
    eph_h res = th;
    eph_h th0 = th;
    while (j < th.size()) {
        if (th[j] == th0[i]) {
            res[j] = th0[k];
        } else {
            if (th[j] == th0[k]) {
                res[j] = th0[i];
            }
        }
        j++;
    }
    return res;
}



































