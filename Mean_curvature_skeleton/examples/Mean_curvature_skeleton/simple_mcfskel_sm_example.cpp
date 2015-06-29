#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_mesh.h>
#include <CGAL/boost/graph/graph_traits_Polyhedron_3.h>
#include <CGAL/boost/graph/properties_Polyhedron_3.h>
#include <CGAL/extract_mean_curvature_flow_skeleton.h>

#include <fstream>

#include <boost/foreach.hpp>

typedef CGAL::Simple_cartesian<double>                        Kernel;
typedef Kernel::Point_3                                       Point;
typedef CGAL::Surface_mesh<Point>                             Triangle_mesh;

typedef boost::graph_traits<Triangle_mesh>::vertex_descriptor    vertex_descriptor;

typedef CGAL::Mean_curvature_flow_skeletonization<Triangle_mesh> Skeletonization;
typedef Skeletonization::Skeleton                             Skeleton;

typedef Skeleton::vertex_descriptor                           Skeleton_vertex;
typedef Skeleton::edge_descriptor                             Skeleton_edge;


// This example extracts a medially centered skeleton from a given mesh.
int main(int argc, char* argv[])
{
  std::ifstream input((argc>1)?argv[1]:"data/sindorelax.off");
  Triangle_mesh tmesh;
  input >> tmesh;

  Skeleton skeleton;

  CGAL::extract_mean_curvature_flow_skeleton(tmesh, skeleton);

  std::cout << "Number of vertices of the skelton: " << boost::num_vertices(skeleton) << "\n";
  std::cout << "Number of edges of the skelton: " << boost::num_edges(skeleton) << "\n";

  // Output all the edges of the skeleton.
  BOOST_FOREACH(Skeleton_edge e, edges(skeleton))
  {
    const Point& s = skeleton[source(e, skeleton)].point;
    const Point& t = skeleton[target(e, skeleton)].point;
    std::cout << s << " " << t << "\n";
  }

  // Output skeleton points and the corresponding surface points
  BOOST_FOREACH(Skeleton_vertex v, vertices(skeleton))
  {
    std::cout << skeleton[v].point << ": ";

    BOOST_FOREACH(vertex_descriptor vd, skeleton[v].vertices)
      std::cout << get(CGAL::vertex_point, tmesh, vd)  << " ";
    std::cout << "\n";
  }

  return 0;
}

