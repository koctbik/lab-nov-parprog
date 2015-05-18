#ifndef BRUSSELATOR_H
#define BRUSSELATOR_H

#include <stdlib.h>

#include "common.h"

/* Параметры. */
#define q 1.0
#define K2 0.25
#define K 0.5
#define p 1.0

/* Коефициенты диффузии. */
#define d 0.001
#define D 0.1

/* Параметры расчетной области. */
#define A 0.5
#define N 100
#define h (A / N)

/* Число шагов. */
#define S 10000

/* Число шагов по нелинейности. */
#define NS 10

/* Шаг по времени. */
#define dt 0.0001


/* Функции правой части. */
double f(const node_t x)
{
	return p * x.u * x.u / x.v - K * x.u;
}

double g(const node_t x)
{
	return q * x.u * x.u - K2 * x.v;
}

/* Производные. */
double dfdu(const node_t x)
{
    return 2.0 * p * x.u / x.v - K;
}
double dgdu(const node_t x)
{
    return 2.0 * q * x.u;
}
double dfdv(const node_t x)
{
    return -p * x.u * x.u / x.v / x.v;
}
double dgdv(const node_t x)
{
    return -K2;
}


/* Начальное условие. */
void init(node_t *u)
{
	int i;
	for (i = 0; i < N; i++) {
		u[i].u = 1.0 / 8.0;
		u[i].v = 1.0 / 16.0;

		/* Возмущения. */
		u[i].u *= (0.9 + 0.2 * (double)rand() / RAND_MAX);
		u[i].v *= (0.9 + 0.2 * (double)rand() / RAND_MAX);
	}
}

#endif // BRUSSELATOR_H
