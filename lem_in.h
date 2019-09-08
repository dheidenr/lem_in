
#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "libft.h"
#include "queue.h"
//#include "aqueue.h"


#define MAXV 8000
#define FALSE 0
#define TRUE 1
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define	START 1
#define END 5
#define END_SPACE 1
#define NOT_END_SPACE 0

typedef struct s_edgenode
{
	int			y;
	int 		weight;
	int 		turn;
	char 		isolate;
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
	int				in_out_vertices;
	char			**names;
	int 			start;
	int 			end;
	int 			global_ants;
	int 			finish_ants;
	int 			flag;
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
	int 		ant;
	struct s_path *next;
}				t_path;

typedef	struct		s_beam
{
	t_path			*path;
	size_t			length;
	size_t			ants;
	char 			isolate;
	struct s_beam	*next;
}					t_beam;

typedef	struct		s_beams
{
	t_beam			*beam;
	size_t			number_steps;
	struct s_beams	*next;
}					t_beams;

void			initialize_graph(graph *g, t_context *context, int directed);
void			insert_edge(graph *g, int x, int y, int directed);
void			insert_edge_weight(graph *g, t_edgepoint *edgepoint, int directed,
																	int weight);
void			print_graph(graph *g);
void			print_array_graph(int array[], graph *g, char *str);
void			read_graph(graph *g, t_context *context, int directed);
void			random_graph(graph *g, t_context *context, int directed, int nvertices, unsigned int r, int edges);
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

void			test_1_graph(graph *g, t_context *context, int directed);
void			test_too_path_graph(graph *g, t_context *context, int directed);
void			test_24_4_graph_bellman_ford(graph *g, t_context *context, int directed);
void			test_too_path_graph_suurballe(graph *g, t_context *context, int directed);
void			test_too_path_graph_suurballe_extreme(graph *g, t_context *context, int directed);
void			test_too_path_graph_suurballe_wiki(graph *g, t_context *context, int directed);
void			test_three_path_graph_suurballe_little(graph *g, t_context *context, int directed);

t_beam			*suurballe(graph *g, t_context *context, int start, int end);
graph*			graphdub(graph* g);
void			remove_edge(graph *g, t_edgepoint edgepoint, int directed);
void			reverse_edge_and_weight(graph *g, t_edgepoint edp);
int			 	get_weight_edge(graph *g, t_edgepoint *edp);
void			print_beam(t_beam *beam);
void			print_path(t_path *path);

void			duplicate_all_vertexes_graph(graph *g, t_context *context, int start, int end);
void			duplicate_vertex(graph *g, t_context *context, int vertex);
size_t			get_length_path(t_path *path);
t_edgenode* 	get_edgenode(graph *g, t_edgepoint *edp);
void			add_path_to_beam(t_beam **beam, t_path **path, size_t len);
size_t			get_length_paths(t_beam *beam);
size_t			get_length_beam(t_beam *beam);
void			prepare_beam_ants(size_t global_ants, t_beam *beam);
void			ants_go_the_paths(t_beam *beam, t_context *context);
void			add_vertex_to_path(t_path **path, int vertex);
t_beam			*get_min_length_beam(t_beam	*beam);
t_beam			*get_next_min_length_beam_and_isolate(t_beam *beam);
void			input(graph *g, t_context *context);
void			output(t_beam *beam, t_context *context);
//utilits
size_t	ft_charcount(char const *s, char c);
void	clearing_structures(graph *g, t_context *context, t_beam *beam);
void	clear_path(t_path *path);
void	clear_graph(graph *g);
void	error();

//Trash
void	test();

#endif
