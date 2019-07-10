
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
#define WHITE 0
#define GRAY 1
#define BLACK 2

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
	unsigned char color[MAXV + 1];
	int 		parent[MAXV + 1];
}				graph;

void	initialize_graph(graph *g, int directed);
void	insert_edge(graph *g, int x, int y, int directed);
void	print_graph(graph *g);
void	read_graph(graph *g, int directed);
void	random_graph(graph *g, int directed, int nvertices, unsigned char r, int edges);
void	initialize_search(graph *g);
void	bfs(graph *g, int start);
#endif
