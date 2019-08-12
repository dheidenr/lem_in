
#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "libft.h"
#include "queue.h"


#define MAXV 8000
#define FALSE 0
#define TRUE 1
#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct s_edgenode
{
	int		y;
	int 		weight;
	struct s_edgenode *next;
}				t_edgenode;

typedef	struct
{
	t_edgenode		*edges[MAXV + 1];
	int				degree[MAXV + 1]; //Степень
	int				nvertices;
	int				nedges;
	int				directed; //Направленный?
	unsigned char	color[MAXV + 1];
	int 			parent[MAXV + 1];
	int 			entry_time[MAXV + 1];
	int 			exit_time[MAXV + 1];
	int long 		short_paths[MAXV + 1];
	unsigned char	finished;
}				graph;

typedef  struct	s_edgepoint
{
	int x;
	int y;
}				t_edgepoint;

void			initialize_graph(graph *g, int directed);
void			insert_edge(graph *g, int x, int y, int directed);
void			insert_edge_weight(graph *g, t_edgepoint *edgepoint, int directed,
																	int weight);

void			print_graph(graph *g);
void			read_graph(graph *g, int directed);
void			random_graph(graph *g, int directed, int nvertices, unsigned int r, int edges);
void			initialize_bfs_search(graph *g);
void			initialize_dfs_search(graph *g);
void			initialize_dijkstra_search(graph *g);
void			initialize_bellman_ford_search(graph *g, int start);
void			bfs(graph *g, int start);
void			dfs(graph *g, int v);
void			dfs2(graph *g, int v);
void			dijkstra(graph *g, int start);
int				bellman_ford(graph *g, int start);
t_queue			*shortest_bfs_path_search(graph *g, int start, int end);
void			find_path(int start, int end, int *parents);
t_queue	*qfind_path(int start, int end, int parents[], t_queue **q);

void			test_1_graph(graph *g, int directed);
void			test_too_path_graph(graph *g, int directed);
void			test_24_4_graph_bellman_ford(graph *g, int directed);
void			test_too_path_graph_suurballe(graph *g, int directed);

void			suurballe(graph *g, int start, int end);
graph*			graphdub(graph* g);
void			remove_edge(graph *g, t_edgepoint edgepoint, int directed);

#endif
