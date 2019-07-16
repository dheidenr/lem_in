
#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "libft.h"
#include "queue.h"


#define MAXV 4000
#define FALSE 0
#define TRUE 1
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct s_edgenode{
	int		y;
	int 		weight;
	struct s_edgenode *next;
}				t_edgenode;

typedef	struct {
	t_edgenode		*edges[MAXV + 1];
	int 		degree[MAXV + 1];
	int 		nvertices;
	int 		nedges;
	int		directed;
	unsigned char color[MAXV + 1];
	int 		parent[MAXV + 1];
	int 		entry_time[MAXV + 1];
	int 		exit_time[MAXV + 1];
	unsigned char	finished;
}				graph;

void			initialize_graph(graph *g, int directed);
void			insert_edge(graph *g, int x, int y, int directed);
void			print_graph(graph *g);
void			read_graph(graph *g, int directed);
void			random_graph(graph *g, int directed, int nvertices, unsigned int r, int edges);
void			initialize_bfs_search(graph *g);
void			initialize_dfs_search(graph *g);
void			bfs(graph *g, int start);
void			dfs(graph *g, int v);
void			dfs2(graph *g, int v);

t_queue	*shortest_bfs_path_search(graph *g, int start, int end);




void			test_1_graph(graph *g, int directed);
void			test_too_path_graph(graph *g, int directed);
#endif
