#include <stdio.h>
#include <stdlib.h>

#include "vtk.h"
#include "common.h"

#ifdef BLOOD
#include "blood.h"
#endif

#ifdef BRUSSELATOR
#include "brusselator.h"
#endif

#ifdef MORFOGENES
#include "morfogenes.h"
#endif

matrix_t getAm(node_t u)
{
	matrix_t M = {
		.a11 = 1.0 / 12.0 - dt * d / 2.0 / h / h - dt / 24.0 * dfdu(u),
		.a12 = - dt / 24.0 * dfdv(u),
		.a21 = - dt / 24.0 * dgdu(u),
		.a22 = 1.0 / 12.0 - dt * D / 2 / h / h - dt / 24.0 * dgdv(u)
	};
	return M;
}

matrix_t getBm(node_t u)
{
	matrix_t M = {
		.a11 = 5.0 / 6.0 + dt * d / h / h - 5.0 * dt / 12.0 * dfdu(u),
		.a12 = - 5.0 * dt / 12.0 * dfdv(u),
		.a21 = - 5.0 * dt / 22.0 * dgdu(u),
		.a22 = 5.0 / 6.0 + dt * D / h / h - 5.0 * dt / 12.0 * dgdv(u)
	};
	return M;
}

matrix_t getCm(node_t u)
{
	return getAm(u);
}

node_t getFm(node_t u_1, node_t u, node_t u1, node_t uk_1, node_t uk, node_t uk1)
{
	node_t M = {
		.u =
		- 1.0 / 12.0 * (uk1.u - u1.u) - 10.0 / 12.0 * (uk.u - u.u) - 1.0 / 12.0 * (uk_1.u - u1.u) +
		d * dt / 2.0 / h / h * (uk1.u - 2.0 * uk.u + uk_1.u + u1.u - 2.0 * u.u + u_1.u) +
		dt / 24.0 * f(u1) + 10.0 * dt / 24.0 * f(u) + dt / 24.0 * f(u_1) +
		dt / 24.0 * f(uk1) + 10.0 * dt / 24.0 * f(uk) + dt / 24.0 * f(uk_1),
		.v =
		- 1.0 / 12.0 * (uk1.v - u1.v) - 10.0 / 12.0 * (uk.v - u.v) - 1.0 / 12.0 * (uk_1.v - u1.v) +
		D * dt / 2.0 / h / h * (uk1.v - 2.0 * uk.v + uk_1.v + u1.v - 2.0 * u.v + u_1.v) +
		dt / 24.0 * g(u1) + 10.0 * dt / 24.0 * g(u) + dt / 24.0 * g(u_1) +
		dt / 24.0 * g(uk1) + 10.0 * dt / 24.0 * g(uk) + dt / 24.0 * g(uk_1)
	};
	return M;
}

/* Явная схема первого порядка точности. */
void first_order(node_t *u, node_t *u1)
{
	int i;

	/* Граничные условия. */
	u[0]     = u[1];
	u[N - 1] = u[N - 2];
	for (i = 1; i < N - 1; i++) {
		u1[i].u = u[i].u + dt * d / h / h * (u[i - 1].u - 2.0 * u[i].u + u[i + 1].u) + dt * f(u[i]);
		u1[i].v = u[i].v + dt * D / h / h * (u[i - 1].v - 2.0 * u[i].v + u[i + 1].v) + dt * g(u[i]);
	}

	/* Значения на границах. */
	u1[0]     = u1[1];
	u1[N - 1] = u1[N - 2];
}

/* Прогонка первого порядка точности. */
void progonka1(node_t *u, node_t *u1)
{
	int i;
	/* Прогоночные коефициенты. */
	matrix_t *Pm = (matrix_t*)malloc(sizeof(matrix_t) * N);
	node_t *Qm   = (node_t*)malloc(sizeof(node_t) * N);

	/* Граничные условия. */
	u[0]     = u[1];
	u[N - 1] = u[N - 2];

	u1[0]     = u1[1];
	u1[N - 1] = u1[N - 2];

	/* Постоянные матрицы. */
	matrix_t Am = { .a11 = dt * d / h / h, .a12 = 0.0, .a21 = 0.0, .a22 = dt * D / h / h };
	matrix_t Bm = { .a11 = -1.0 - 2.0 * dt * d / h / h, .a12 = 0.0, .a21 = 0.0, .a22 = -1.0 - 2.0 * dt * D / h / h };
	matrix_t Cm = { .a11 = dt * d / h / h, .a12 = 0.0, .a21 = 0.0, .a22 = dt * D / h / h };

	matrix_t Bm_1 = minv(Bm);

	/* Левая граница. */
	Pm[0].a11 = 1.0;
	Pm[0].a12 = 0.0;
	Pm[0].a21 = 0.0;
	Pm[0].a22 = 1.0;

	Qm[0].u = Qm[0].v = 0.0;
	/* Прямой ход. */
	for (i = 1; i < N; i++) {
		node_t Fi = {
			.u = -u[i].u - dt * f(u[i]),
			.v = -u[i].v - dt * g(u[i]),
		};
		matrix_t G = minv(madd(mmmul(Am, Pm[i - 1]), Bm));
		Pm[i] = mscale(mmmul(G, Cm), -1.0);
		Qm[i] = mvmul(G, vadd(Fi, 1.0, mvmul(Am, Qm[i - 1]), -1.0));
	}

	/* Обратный ход. */
	for (i = N - 2; i >= 0; i--) {
		u1[i] = vadd(mvmul(Pm[i], u1[i + 1]), 1.0, Qm[i], 1.0);
	}

	free(Pm);
	free(Qm);
}

void progonka2_nl(node_t *u, node_t *u1, node_t *du)
{
	int i;
	/* Прогоночные коефициенты. */
	matrix_t *Pm = (matrix_t*)malloc(sizeof(matrix_t) * N);
	node_t *Qm   = (node_t*)malloc(sizeof(node_t) * N);

	/* Левая граница. */
	node_t F0 = getFm(u[1], u[0], u[1], u1[1], u1[0], u1[1]);
	matrix_t B0 = getBm(u1[0]);
	matrix_t C0 = getCm(u1[1]);

	matrix_t B0_1 = minv(B0);

	Pm[0] = mscale(mmmul(B0_1, C0), -1.0);
	Qm[0] = mvmul(B0_1, F0);

	/* Прямой ход. */
	for (i = 1; i < N; i++) {
		int j1 = i + 1;
		if (i == N - 1) j1 = i - 1;
		node_t Fi = getFm(u[i-1], u[i], u[j1], u1[i-1], u1[i], u1[j1]);
		matrix_t Ai = getAm(u1[i-1]);
		matrix_t Bi = getBm(u1[i]);
		matrix_t Ci = getCm(u1[j1]);
		matrix_t G = minv(madd(mmmul(Ai, Pm[i - 1]), Bi));
		Pm[i] = mscale(mmmul(G, Ci), -1.0);
		Qm[i] = mvmul(G, vadd(Fi, 1.0, mvmul(Ai, Qm[i - 1]), -1.0));
	}
	du[N - 1] = Qm[N - 1];

	/* Обратный ход. */
	for (i = N - 2; i >= 0; i--) {
		du[i] = vadd(mvmul(Pm[i], du[i + 1]), 1.0, Qm[i], 1.0);
	}

	free(Pm);
	free(Qm);
}

/* Прогонка 2-4 порядка точности. */
void progonka2(node_t *u, node_t *u1)
{
	node_t *du  = (node_t*)malloc(sizeof(node_t) * N);
	int i, j;
	for (i = 0; i < N; i++) {
		u1[i] = u[i];
	}
	for (i = 0; i < NS; i++) {
		progonka2_nl(u, u1, du);
		for (j = 0; j < N; j++) {
			u1[j].u += du[j].u;
			u1[j].v += du[j].v;
		}
	}
	free(du);
}

double *sercalc()
{
	node_t *u  = (node_t*)malloc(sizeof(node_t) * N);
	node_t *u1 = (node_t*)malloc(sizeof(node_t) * N);
	node_t *temp;
	int i;
	char buf[256];
	const char *save[2] = {"u", "v"};

	init(u);
	init(u1);

	for (i = 0; i < S; i++) {
		/* Сохраняем посчитанные значения. */
		sprintf(buf, "res/data_%06d.vtk", i);
		write_to_vtk2((double*)u, buf, save, N, 0.0, h, 2);

		/* Обновляем значение. */
		progonka2(u, u1);
		//progonka1(u, u1);
		//first_order(u, u1);

		/* Меняем местами временной слой. */
		temp = u;
		u = u1;
		u1 = temp;
	}

	free(u);
	free(u1);
	return 0x0;
}
