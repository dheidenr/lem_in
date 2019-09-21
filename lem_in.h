/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 13:08:37 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/21 13:08:40 by dheidenr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
#define LEM_IN_LEM_IN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "libft.h"

#define MAXV 16000
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
	char 		isolate;
	struct s_edgenode *next;
}				t_edgenode;

typedef struct s_path
{
	int				vertex;
	int 			ant;
	struct s_path	*next;
}					t_path;

typedef	struct		s_beam
{
	t_path			*path;
	size_t			length;
	size_t			ants;
	char 			isolate;
	struct s_beam	*next;
}					t_beam;

typedef	struct		s_graph
{
	t_edgenode		*edges[MAXV + 1];
	int				degree[MAXV + 1]; //Степень
	int				nvertices;
	int				nedges;
	int				directed; //Направленный?
	unsigned char	color[MAXV + 1];
	int 			parents[MAXV + 1];

}					t_graph;


typedef	struct		s_beams
{
	t_beam			*beam;
	float			number_steps;
	struct s_beams	*next;
}					t_beams;

typedef struct	s_context
{
	int 			entry_time[MAXV + 1];
	int 			exit_time[MAXV + 1];
	int long 		short_paths[MAXV + 1];
	unsigned char	v_in[MAXV + 1];
	unsigned int	v_out[MAXV + 1];
	int				in_out_vertices;
	char			**names;
	int 			start;
	int 			end;
	int 			global_ants;
	int 			finish_ants;
	int 			flag;
	int 			verify;
	int 			debug;
	int 			fd;
	t_beam			*free_beam;
	t_beams			*free_beams;
	t_edgenode		*edgenode;
}				t_context;

typedef  struct	s_edgepoint
{
	int x;
	int y;
}				t_edgepoint;

typedef	struct	s_support_edge
{
	t_edgenode	*edge;
	t_edgenode	*prev_edge;
	t_edgenode	*reverse_edge;
	t_edgepoint edp;
	t_edgepoint *rev_edp;
	t_edgenode	*tmp_edge;
	int 		flag;
}				t_support_edge;

typedef	struct	s_support_beam
{
	t_path		*path;
	t_beam		*beam;
	t_beam		*tmp_beam;
	t_beam		*true_beam;
	t_context	*context;
}				t_support_beam;

typedef	struct	s_compact
{
	t_graph		*g;
	t_context	*c;
}				t_compact;


t_beam			*find_true_beam(t_graph *g, t_beam *fake_beam,
								  t_edgepoint start_end);
void			initialize_graph(t_graph *g, t_context *context, int directed);
void			insert_edge(t_graph *g, int x, int y, int directed);
void			insert_edge_weight(t_graph *g, t_edgepoint *edgepoint, int directed,
								   int weight);
void			initialize_bfs_search(t_graph *g);
void			bfs(t_graph *g, int start);

t_path			*find_path(int start, int end, int parents[], t_path **path);

t_beam			*suurballe(t_graph *g, t_context *context, int start, int end);
void	duplicate_all_vertexes_graph(t_graph *g, t_context *context, int start,
									 int end);
t_graph*			graphdub(t_graph* g);
void			remove_edge(t_graph *g, t_edgepoint edgepoint, int directed);
void			remove_fake_vertex(t_graph *g, t_context *context, int vertex,
								   t_path **path);
void			remove_fake_vertexes(t_graph *g,
									 t_context *context, t_path **path);
void			reverse_path(t_graph *g, t_path *path);
void			reverse_edge_and_weight(t_graph *g, t_edgepoint edp);
int			 	get_weight_edge(t_graph *g, t_edgepoint *edp);
void			print_beam(t_beam *beam);
void			print_path(t_path *path);

void			duplicate_all_vertexes_graph(t_graph *g, t_context *context, int start, int end);
void			duplicate_vertex(t_graph *g, t_context *context, int vertex);
size_t			get_length_path(t_path *path);
t_edgenode* 	get_edgenode(t_graph *g, t_edgepoint *edp);
void			add_path_to_beam(t_beam **beam, t_path **path, size_t len);
size_t			get_length_paths(t_beam *beam);
size_t			get_length_beam(t_beam *beam);
void			prepare_beam_ants(size_t global_ants, t_beam *beam);
void			ants_go_the_paths(t_beam *beam, t_context *context);
void			add_vertex_to_path(t_path **path, int vertex);
t_beam			*get_min_length_beam(t_beam	*beam);
t_beam			*get_next_min_length_beam_and_isolate(t_beam *beam);
void			input(t_graph *g, t_context *context);
void			output(t_beam *beam, t_context *context);

t_beam	*find_optimal_beam(t_graph *g, t_context *context, t_beam *beam,
							 t_edgepoint start_end);
t_path	*get_path(t_path *path, size_t step);
void	offset_path(t_beam *beam, t_context *context);
void 	swap_paths(t_beam *one, t_beam *two);
int 	ending_room(int *ending, t_context *context, char ***line, t_graph *g);
size_t	pulling_room(t_graph *g, t_context *context, char **line);
char 	pulling_link(t_graph *g, t_context *context, char **line);
int 	print_gnl(const int fd, char **line);
int 	is_elements_of_path_in_beam(t_beam *beam, t_path *path);
float	get_number_steps(t_context *context, t_beam **beam);
void	sort_by_lengths(t_beam *beam);
t_beam	*get_min_number_steps_beam(t_beams	*beams);
void	clear_beams(t_beams *beams);
void	clear_beam(t_beam *beam);
size_t	ft_charcount(char const *s, char c);
void	clearing_structures(t_graph *g, t_context *context, t_beams *beams);
void	clear_path(t_path *path);
void	clear_graph(t_graph *g);
void	error();

void		no_isolate_all_edges_of_beam(t_graph *g, t_beam *beam);
t_edgepoint	*reverse_edgepoint(t_edgepoint *edgepoint,
													t_edgepoint *reverse_edge);

void	isolate_edgenode(t_edgenode *edgenode, char isolate);
void 	isolate_all_edges(t_graph *g);
void 	turn_to_zero_all_edges(t_graph *g);

#endif
