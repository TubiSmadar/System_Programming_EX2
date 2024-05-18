#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test + operator")
{
    ariel::Graph g;
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    
    g.loadGraph(graph);
    g1.loadGraph(graph1);
    g = g + g;
    CHECK(g == g1);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g1.loadGraph(graph2);
    // Different sizes graphs
    CHECK_THROWS(g+g1);
}

TEST_CASE("Test - operator")
{
    ariel::Graph g;
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    
    g.loadGraph(graph1);
    g1.loadGraph(graph);
    g = g - g1;
    // Check equality
    CHECK(g == g1);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g1.loadGraph(graph2);
    // Different sizes graphs
    CHECK_THROWS(g+g1);
    // Check greater
    CHECK(g1>g);
    // Check smaller
    CHECK(g<g1);
    // Check greater equal
    CHECK(g1>=g);
}

TEST_CASE("Test += operator")
{
    ariel::Graph g;
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    
    g.loadGraph(graph);
    g1.loadGraph(graph1);
    g += g;
    CHECK(g == g1);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g1.loadGraph(graph2);
    // Different sizes graphs
    CHECK_THROWS(g+=g1);
}

TEST_CASE("Test -= operator")
{
    ariel::Graph g;
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph1 = {
        {0, 2, 0},
        {2, 0, 2},
        {0, 2, 0}};
    
    g.loadGraph(graph);
    g1.loadGraph(graph1);
    g1 -= g;
    CHECK(g == g1);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g1.loadGraph(graph2);
    // Different sizes graphs
    CHECK_THROWS(g-=g1);
}

TEST_CASE("Test +() operator")
{
    ariel::Graph g;
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    g1.loadGraph(graph);

    g = +g;
    // Check equality
    CHECK(g == g1);
}
TEST_CASE("Test -() operator")
{
    ariel::Graph g;
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, -1},
        {0, 1, 0}};    
    vector<vector<int>> graph1 = {
        {0, -1, 0},
        {-1, 0, 1},
        {0, -1, 0}};
    g.loadGraph(graph);
    g1.loadGraph(graph);

    g = -g;
    // Check equality
    CHECK(g == g1);
}

TEST_CASE("Test >,<,>=,<=,==,!= operators")
{
    ariel::Graph g1, g2, g3;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}};
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};

    g1.loadGraph(graph1);
    g2.loadGraph(graph2);
    g3.loadGraph(graph3);

    CHECK((g1 < g2) == true);  
    CHECK((g1 > g2) == false);
    CHECK((g1 <= g2) == true);
    CHECK((g1 >= g2) == false);
    CHECK((g1 == g3) == true);  
    CHECK((g1 != g2) == true);  
}

TEST_CASE("Test ++ operators") 
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    ariel::Graph gCopyPost = g++;
    vector<vector<int>> expectedGraphPost = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}};
    ariel::Graph expectedPost;
    expectedPost.loadGraph(expectedGraphPost);

    CHECK(g == expectedPost);
    CHECK(gCopyPost != g);

    vector<vector<int>> expectedGraphPre = {
        {2, 3, 2},
        {3, 2, 3},
        {2, 3, 2}};
    ariel::Graph expectedPre;
    expectedPre.loadGraph(expectedGraphPre);

    CHECK(g == expectedPre);
}

TEST_CASE("Test -- operators")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {1, 2, 1},
        {2, 1, 2},
        {1, 2, 1}};
    g.loadGraph(graph);

    ariel::Graph gCopyPost = g--;
    vector<vector<int>> expectedGraphPost = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    ariel::Graph expectedPost;
    expectedPost.loadGraph(expectedGraphPost);

    CHECK(g == expectedPost);
    CHECK(gCopyPost != g);
    --g;
    vector<vector<int>> expectedGraphPre = {
        {-1, 0, -1},
        {0, -1, 0},
        {-1, 0, -1}};
    ariel::Graph expectedPre;
    expectedPre.loadGraph(expectedGraphPre);

    CHECK(g == expectedPre);
}

TEST_CASE("Test * operators")
{
    ariel::Graph g1, g2;
    vector<vector<int>> graph1 = {
        {1, 2},
        {3, 4}};
    vector<vector<int>> graph2 = {
        {2, 0},
        {1, 2}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    ariel::Graph resultGraph = g1 * g2;
    vector<vector<int>> expectedGraph = {
        {4, 4},
        {10, 8}};
    ariel::Graph expected;
    expected.loadGraph(expectedGraph);

    CHECK(resultGraph == expected);

    int scalar = 2;
    ariel::Graph resultScalar = g1 * scalar;
    vector<vector<int>> expectedGraphScalar = {
        {2, 4},
        {6, 8}};
    ariel::Graph expectedScalar;
    expectedScalar.loadGraph(expectedGraphScalar);

    CHECK(resultScalar == expectedScalar);
}

TEST_CASE("Test << operator")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);

    std::ostringstream os;
    os << g;
    std::string output = os.str();
    std::string expectedOutput = 
        "Adjacency Matrix:\n"
        "0 1 0 \n"
        "1 0 1 \n"
        "0 1 0 \n";

    CHECK(output == expectedOutput);
}
TEST_CASE("Test * operators")
{
    ariel::Graph g1, g2;
    vector<vector<int>> graph1 = {
        {1, 2},
        {3, 4}};
    vector<vector<int>> graph2 = {
        {2, 0},
        {1, 2}};
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    //Testing graph multiplication operator
        ariel::Graph result = g1 * g2;
        vector<vector<int>> expectedGraph = {
            {4, 4},
            {10, 8}};
        ariel::Graph expected;
        expected.loadGraph(expectedGraph);

        CHECK(result == expected);
    

    //Testing graph-scalar multiplication operator
        int number = 2;
        ariel::Graph result1 = g1 * number;
        vector<vector<int>> expectedGraph1 = {
            {2, 4},
            {6, 8}};
        ariel::Graph expected1;
        expected1.loadGraph(expectedGraph1);

        CHECK(result1 == expected1);

        vector<vector<int>> errorGraph = {
            {2, 4, 0},
            {6, 8, 4},
            {1, 0, 0}};
        expected1.loadGraph(errorGraph);
        CHECK_THROWS(expected1 * g1);
}

TEST_CASE("Test << operator")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);


    std::ostringstream os;
    os << g;
    std::string output = os.str();
    std::string expectedOutput = 
        "Adjacency Matrix:\n"
        "0 1 0 \n"
        "1 0 1 \n"
        "0 1 0 \n";
        
    CHECK(output == expectedOutput);
}

/*
####################################Exercise 1 Tests####################################
No changes!
*/
TEST_CASE("Test isContainsCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    // Directed graph without cycles.
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "No cycle found");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    // Directed graph with cycles.
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "The cycle is: 0->1->2->0");

    vector<vector<int>> graph3 = {{0, 1, 0, 1, 1}, 
                                  {1, 0, 1, 0, 0}, 
                                  {0, 1, 0, 1, 0}, 
                                  {1, 0, 1, 0, 0}, 
                                  {1, 0, 0, 0, 0}};
    g.loadGraph(graph3);
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "The cycle is: 0->1->2->3->0");
    
    vector<vector<int>> graph4 = {{0, 1, 0, 0, 0},
                                  {0, 0, 0, 1, 1}, 
                                  {0, 1, 0, 0, 0}, 
                                  {0, 0, 1, 0, 0}, 
                                  {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    // Undirected graph with cycle
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "The cycle is: 1->3->2->1");
    
    vector<vector<int>> graph5 = {{0, 1}, 
                                  {3, 0}};
    g.loadGraph(graph5);
    // Undirected graph with cycle of 2 nodes.
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "The cycle is: 0->1->0");

    vector<vector<int>> graph6 = {{0}};
    g.loadGraph(graph6);
    // Graph with one vertex no edges.
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "No cycle found");
  
    vector<vector<int>> graph7 = {{1}};
    g.loadGraph(graph7);
    // Graph with one vertex cyclic edge.
    CHECK(ariel::Algorithms::cycleToString(ariel::Algorithms::isContainsCycle(g)) == "The cycle is: 0->0");


}
TEST_CASE("Test isBipartite")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph);
    // Base case of bipartite graph.
    CHECK(ariel::Algorithms::bipartiteGraphToString(ariel::Algorithms::isBipartite(g)) == "Group 1: 0 2 \nGroup 2: 1 \n");

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    // Disonnected graph not bipartite.
    CHECK(ariel::Algorithms::bipartiteGraphToString(ariel::Algorithms::isBipartite(g)) == "Graph is not bipartite!\n");

    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3);
    // Connected graph not bipartite.
    CHECK(ariel::Algorithms::bipartiteGraphToString(ariel::Algorithms::isBipartite(g)) == "Graph is not bipartite!\n");
     
    vector<vector<int>> graph6 = {{0}};
    g.loadGraph(graph6);
    // Graph with one vertex no edges.
    CHECK(ariel::Algorithms::bipartiteGraphToString(ariel::Algorithms::isBipartite(g)) == "Group 1: 0 \nGroup 2: \n");

    vector<vector<int>> graph7 = {{1}};
    g.loadGraph(graph7);
    // Graph with one vertex cyclic edge.
    CHECK(ariel::Algorithms::bipartiteGraphToString(ariel::Algorithms::isBipartite(g)) == "Graph is not bipartite!\n");

}

TEST_CASE("Test negativeCycle")
{
    ariel::Graph g;
    vector<vector<int>> graph = {{1}};
    g.loadGraph(graph);
    // Graph with one vertex cyclic edge.
    
    // Redirect stdout to a stringstream
    std::ostringstream redirectedOutput;
    std::streambuf* oldStdout = std::cout.rdbuf(redirectedOutput.rdbuf());
    ariel::Algorithms::negativeCycle(g);

    // Restore stdout
    std::cout.rdbuf(oldStdout);

    // Check the content of the stringstream
    CHECK(redirectedOutput.str() == "No negative cycle found!\n");

    vector<vector<int>> graph1 = {{-1}};
    g.loadGraph(graph1);
    // Graph with one vertex negative cyclic edge.
    std::ostringstream redirectedOutput1;
    std::streambuf* oldStdout1 = std::cout.rdbuf(redirectedOutput1.rdbuf());
    ariel::Algorithms::negativeCycle(g);

    // Restore stdout
    std::cout.rdbuf(oldStdout1);

    // Check the content of the stringstream
    CHECK(redirectedOutput1.str() == "Negative cycle found!\n");

    // Graph with both negative and positive cycles.
    vector<vector<int>> graph2 =  {{0, 1, -1, -1},
                                   {1, 0, 0, 2}, 
                                   {-1, 0, 0, -4}, 
                                   {-1, 2, -4, 0}};
    g.loadGraph(graph2);
    // Graph with one vertex cyclic edge.
    std::ostringstream redirectedOutput2;
    std::streambuf* oldStdout2 = std::cout.rdbuf(redirectedOutput2.rdbuf());
    ariel::Algorithms::negativeCycle(g);

    // Restore stdout
    std::cout.rdbuf(oldStdout2);

    // Check the content of the stringstream
    CHECK(redirectedOutput2.str() == "Negative cycle found!\n");

    // Undirected graph with 2 negtive edge
    vector<vector<int>> graph3 = {
        {0, -1, 0},
        {-1, 0, -1},
        {0, -1, 0}};
        g.loadGraph(graph3);
    std::ostringstream redirectedOutput3;
    std::streambuf* oldStdout3 = std::cout.rdbuf(redirectedOutput3.rdbuf());
    ariel::Algorithms::negativeCycle(g);

    // Restore stdout
    std::cout.rdbuf(oldStdout3);

    // Check the content of the stringstream
    CHECK(redirectedOutput3.str() == "No negative cycle found!\n");

    
 

}
TEST_CASE("Test invalid graph")
{
    ariel::Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph));
}
