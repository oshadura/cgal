#ifndef CGAL_SEGMENT_VORONOI_DIAGRAM_DATA_STRUCTURE_2_H
#define CGAL_SEGMENT_VORONOI_DIAGRAM_DATA_STRUCTURE_2_H

#include <CGAL/Apollonius_graph_data_structure_2.h>


CGAL_BEGIN_NAMESPACE

template <class Vb, class Fb>
class Segment_Voronoi_diagram_data_structure_2
  : public Apollonius_graph_data_structure_2<Vb, Fb>
{
private:
  typedef Apollonius_graph_data_structure_2<Vb,Fb>   Base;

public:
  typedef Segment_Voronoi_diagram_data_structure_2<Vb, Fb>    Tds;
  typedef typename Base::Tds_base                             Tds_base;

  //  typedef typename Vb::template Rebind_TDS<Tds>::Other  Vertex_base;
  //  typedef typename Fb::template Rebind_TDS<Tds>::Other  Face_base;

};


CGAL_END_NAMESPACE

#endif // CGAL_SEGMENT_VORONOI_DIAGRAM_DATA_STRUCTURE_2_H

