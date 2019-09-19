
#include "lem_in.h"

char 	is_exist_edge(graph *g, t_edgepoint *edp)
{
	t_edgenode *edgenode;

	edgenode = g->edges[edp->x];
	while(edgenode)
	{
		if (edgenode->y == edp->y)
			return (1);
		edgenode = edgenode->next;
	}
	return (0);
}

t_edgenode* 	get_edgenode(graph *g, t_edgepoint *edp)
{
	t_edgenode *edgenode;

	edgenode = g->edges[edp->x];
	while(edgenode)
	{
		if (edgenode->y == edp->y)
			return (edgenode);
		edgenode = edgenode->next;
	}
	return (NULL);
}

void	reverse_edge_and_weight(graph *g, t_edgepoint edp)
{
	t_edgepoint reversive_edge;
	t_edgenode	*edgenode;
	int 		turn_plus;

	turn_plus = 0;
	reversive_edge.x = edp.y;
	reversive_edge.y = edp.x;
	if (!is_exist_edge(g, &reversive_edge))
	{
		edgenode = get_edgenode(g, &edp);
		if (edgenode)
			turn_plus = edgenode->turn;

		insert_edge_weight(g, &reversive_edge, TRUE, -get_weight_edge(g, &edp));
		edgenode = get_edgenode(g, &reversive_edge);
		edgenode->turn += turn_plus;
		edgenode->turn++;
	}
	else
	{
		edgenode = get_edgenode(g, &reversive_edge);
		edgenode->weight *= -1;
	}
	remove_edge(g, edp, TRUE);
}