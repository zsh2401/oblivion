#include "fx.h"
#include "linkedlist.h"
#include <functional>
namespace graph
{
typedef size_t VexId;
typedef size_t ArcInfo;
namespace linked
{
typedef struct __arc
{
    VexId vexId;
    ArcInfo info;
    __arc *next;
} Arc;
typedef struct __vex
{
    data_t data;
    VexId id;
    Arc *arcs;
} Vex;
typedef struct __graph
{
    Vex *vexs;
} Graph;
typedef std::function<void(VexId id, data_t data)> Visitor;
void init(Graph &g);

VexId appendVex(Graph g, data_t data);
void removeVex(Graph g, VexId targetId);

void appendArc(Graph g, VexId srcId, VexId destId);
void removeArc(Graph g, VexId srcId, VexId destId);
void removeArcBetween(Graph, VexId leftId, VexId rightId);

Vex *findVexById(Graph g, VexId id);
data_t findDataById(Graph g, VexId id);

Arc *arcsOf(Graph g, VexId vexId);
Vex *vexsOf(Graph g);

size_t numberOfVexs(Graph g);
size_t numberOfArcs(Graph g);

void dfs(Graph g, Visitor visitor);
void bfs(Graph g, Visitor visitor);

void destory(Graph &g);
} // namespace linked
} // namespace graph