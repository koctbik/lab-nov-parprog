#include "Common.h"
#include <time.h>
#include <stdlib.h>

#ifndef BRUSSELATOR_H
#define BRUSSELATOR_H

#define Dv 0.00526
#define Du 0.001052

#define A 6
#define B 10

#define X_MAX 1
#define T_MAX 10
#define MAX_DELTA 0.0001

#define K 100

#define h X_MAX/K
double get_delta(double x)
{
	return x * (double)MAX_DELTA * (double)((double)rand() / (double)RAND_MAX);
}


double f(const node_t node)
{
	return A + node.u*node.u*node.v - (B + 1)*node.u;
}

double g(const node_t node)
{
	return B*node.u - node.u*node.u*node.v;
}

double u0(double x)
{
	return (double)A + (double)get_delta(x);
}

double v0(double x)
{
	return (double)B / A + get_delta(x);
}

double dfdu(const node_t node)
{
	return 2.0 * node.u * node.v - (1.0 + B);
}
double dgdu(const node_t node)
{
	return B - 2.0 * node.u * node.v;
}
double dfdv(const node_t node)
{
	return node.u * node.u;
}
double dgdv(const node_t node)
{
	return -node.u * node.u;
}



// du/dt 3 nodes
double dudt_e(const node_t node, const node_t prev_node, const node_t next_node)
{
	return Du*(prev_node.u - 2 * node.u + next_node.u) / (h*h) + f(node);
}

// du/dt by 3 nodes
double dvdt_e(const node_t node, const node_t prev_node, const node_t next_node)
{
	return Dv*(prev_node.v - 2 * node.v + next_node.v) / (h*h) + g(node);
}

node_t get_node_at(node_t* nodes, int index)
{
	return *(node_t*)(nodes + index*sizeof(node_t));
}

// du/dt by array and element index
double dudt_a(node_t* nodes, int index)
{
	if (index == 0)
	{
		return Du * 2 * (get_node_at(nodes, 1).u - get_node_at(nodes, 0).u) / (h*h) + f(get_node_at(nodes, 0));
	}
	else if (index == K)
	{
		return Du * 2 * (get_node_at(nodes, K).u - get_node_at(nodes, K - 1).u) / (h*h) + f(get_node_at(nodes, K));
	}
	else
	{
		return dudt_e(get_node_at(nodes, index),
			get_node_at(nodes, index - 1),
			get_node_at(nodes, index + 1));
	}
}

// dv/dt by array and element index
double dvdt_a(node_t* nodes, int index)
{
	if (index == 0)
	{
		return Dv * 2 * (get_node_at(nodes, 1).u - get_node_at(nodes, 0).u) / (h*h) + f(get_node_at(nodes, 0));
	}
	else if (index == K)
	{
		return Dv * 2 * (get_node_at(nodes, K).u - get_node_at(nodes, K - 1).u) / (h*h) + f(get_node_at(nodes, K));
	}
	else
	{
		return dvdt_e(get_node_at(nodes, index),
			get_node_at(nodes, index - 1),
			get_node_at(nodes, index + 1));
	}
}

double** get_matrix_A()
{
	//Memory allocation
	double** result = malloc(sizeof(double*) * 2 * (K + 1));
	for (int i = 0; i < 2 * (K + 1); i++)
		{
			result[i] = malloc(sizeof(double) * 2 * (K + 1));
		}

	//Top left block
	for (int i = 0; i < (K + 1); i++)
	{
		for (int j = 0; j < (K + 1); j++)
		{
			if (i == j)
			{
				result[i][j] = -2.0;
			}
			else if (i != 0 && i != K && (i == j + 1 || j == i + 1))
			{
				result[i][j] = 1.0;
			}
			else
			{
				result[i][j] = 0.0;
			}
		}
	}
	result[0][0] = -2;
	result[0][1] = 2;
	result[K][K] = -2;
	result[K][K - 1] = 2;

	//Bottom right block
	for (int i = K + 1; i < 2 * (K + 1); i++)
	{
		for (int j = K + 1; j < 2 * (K + 1); j++)
		{
			if (i == j)
			{
				result[i][j] = -2.0;
			}
			else if (i != K + 1 && i != 2 * K + 1 && (i == j + 1 || j == i + 1))
			{
				result[i][j] = 1.0;
			}
			else
			{
				result[i][j] = 0.0;
			}
		}
	}
	result[K + 1][K + 1] = -2;
	result[K + 1][K + 2] = 2;
	result[2 * K + 1][2 * K + 1] = 2;
	result[2 * K + 1][2 * K] = 2;
	//Top right block
	for (int i = 0; i < (K + 1); i++)
	{
		for (int j = K + 1; j < 2 * (K + 1); j++)
		{
			result[i][j] = 0.0;
		}
	}
	//Bottom left block
	for (int i = K + 1; i < 2 * (K + 1); i++)
	{
		for (int j = 0; j < (K + 1); j++)
		{
			result[i][j] = 0.0;
		}
	}

	return result;
}

//Ѕлочно-диагональна€ матрица в частных производных
double** get_matrix_dfdu(node_t* nodes)
{
	//Memory allocation
	double** result = malloc(sizeof(double*) * 2 * (K + 1));
	for (int i = 0; i < 2 * (K + 1); i++)
	{
		result[i] = malloc(sizeof(double) * 2 * (K + 1));
	}

	//Top left block
	for (int i = 0; i < (K + 1); i++)
	{
		for (int j = 0; j < (K + 1); j++)
		{
			if (i == j)
			{
				result[i][j] = dfdu(nodes[i]);
			}
			else
			{
				result[i][j] = 0.0;
			}
		}
	}

	//Bottom right block
	for (int i = K + 1; i < 2 * (K + 1); i++)
	{
		for (int j = K + 1; j < 2 * (K + 1); j++)
		{
			if (i == j)
			{
				result[i][j] = dgdv(nodes[i]);
			}
			else
			{
				result[i][j] = 0.0;
			}
		}
	}

	//Top right block
	for (int i = 0; i < (K + 1); i++)
	{
		for (int j = K + 1; j < 2 * (K + 1); j++)
		{
			if (i == j-K-1)
			{
				result[i][j] = dfdv(nodes[i]);
			}
			else
			{
				result[i][j] = 0.0;
			}
		}
	}
	//Bottom left block
	for (int i = K + 1; i < 2 * (K + 1); i++)
	{
		for (int j = 0; j < (K + 1); j++)
		{
			if (j == i - K - 1)
			{
				result[i][j] = dfdv(nodes[i]);
			}
			else
			{
				result[i][j] = 0.0;
			}
		}
	}

	return result;
}

double** get_matrix_J(node_t* nodes)
{
	//Memory allocation
	double** result = malloc(sizeof(double*) * 2 * (K + 1));
	for (int i = 0; i < 2 * (K + 1); i++)
	{
		result[i] = malloc(sizeof(double) * 2 * (K + 1));
	}

	double** matrix_A = get_matrix_A();
	double** matrix_dfdu = get_matrix_dfdu(nodes);

	for (int i = 0; i < 2 * (K + 1); i++)
	{
		for (int j = 0; j < 2 * (K + 1); j++)
		{
			result[i][j] = matrix_A[i][j] + matrix_dfdu[i][j];
		}
	}

	return result;
}

double** get_matrix_B(node_t* nodes, double tau)
{
	//«десь i - по всей видимости, мнима€ единица
	//return E - (1+i)*tau*get_matrix_J(nodes)/2.0;
}
#endif //BRUSSELATOR_H