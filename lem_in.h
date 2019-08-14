
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
	int			y;
	int 		weight;
	int 		turn;
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
	int 			parents[MAXV + 1];
	unsigned char	finished;
}				graph;

typedef struct	s_context
{
	int 			entry_time[MAXV + 1];
	int 			exit_time[MAXV + 1];
	int long 		short_paths[MAXV + 1];
	unsigned char	v_in[MAXV + 1];
	unsigned char	v_out[MAXV + 1];
	t_edgenode		*edgenode;
}				t_context;

typedef  struct	s_edgepoint
{
	int x;
	int y;
}				t_edgepoint;

typedef struct s_path
{
	int			vertex;
	struct s_path *next;
}				t_path;

typedef	struct		s_beam
{
	t_path			*path;
	struct s_beam	*next;
}					t_beam;

void			initialize_graph(graph *g, int directed);
void			insert_edge(graph *g, int x, int y, int directed);
void			insert_edge_weight(graph *g, t_edgepoint *edgepoint, int directed,
																	int weight);
void			print_graph(graph *g);
void			read_graph(graph *g, int directed);
void			random_graph(graph *g, int directed, int nvertices, unsigned int r, int edges);
void			initialize_bfs_search(graph *g);
void			initialize_dfs_search(graph *g, t_context *context);
void			initialize_dijkstra_search(graph *g, t_context* context);
void			initialize_bellman_ford_search(graph *g, t_context* context, int start);
void			bfs(graph *g, int start);
void			dfs(graph *g, t_context *context, int v);
void			dfs2(graph *g, t_context *context, int v);
void			dijkstra(graph *g, int start);
int				bellman_ford(graph *g, t_context *context, int start);
t_queue			*shortest_bfs_path_search(graph *g, int start, int end);
void			print_path_start_end(int start, int end, int *parents);
t_queue			*qfind_path(int start, int end, int parents[], t_queue **q);
t_path			*find_path(int start, int end, int parents[], t_path **path);

void			test_1_graph(graph *g, int directed);
void			test_too_path_graph(graph *g, int directed);
void			test_24_4_graph_bellman_ford(graph *g, int directed);
void			test_too_path_graph_suurballe(graph *g, int directed);

t_beam			*suurballe(graph *g, t_context *context, int start, int end);
graph*			graphdub(graph* g);
void			remove_edge(graph *g, t_edgepoint edgepoint, int directed);
void			reverse_edge_and_weight(graph *g, t_edgepoint edp);
int			 	get_weight_edge(graph *g, t_edgepoint *edp);
void			print_beam(t_beam *beam);
void			print_path(t_path *path);

t_edgenode* 	get_edgenode(graph *g, t_edgepoint *edp);
void	add_path_to_beam(t_beam **beam, t_path **path);
void	add_vertex_to_path(t_path **path, int vertex);
#endif
