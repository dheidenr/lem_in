
#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "libft.h"

#define MAXV 1000
#define FALSE 0
#define TRUE 1
typedef struct {
	int		y;
	int 		weight;
	struct edgenode *next;
}				edgenode;

typedef	struct {
	edgenode		*edges[MAXV + 1];
	int 		degree[MAXV + 1];
	int 		nvertices;
	int 		nedges;
	int		directed;
}				graph;

void	initialize_graph(graph *g, int directed);
void	insert_edge(graph *g, int x, int y, int directed);
void	print_graph(graph *g);
void	read_graph(graph *g, int directed);
void	random_graph(graph *g, int directed);

#endif
