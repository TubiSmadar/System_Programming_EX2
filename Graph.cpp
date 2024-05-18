/*
315638577
gunslokij@gmail.com
*/
#include "Graph.hpp"
#include <iostream>

using namespace std;

namespace ariel {
    // Constructor to initialize an empty graph with zero vertices
    Graph::Graph() : adjMatrix(vector<vector<int>>()), numVertices(0) {}

    // Constructor to initialize a graph with provided adjacency matrix and number of vertices
    Graph::Graph(const std::vector<std::vector<int>>& adjMatrix, size_t numVertices) : adjMatrix(adjMatrix), numVertices(numVertices) {}

    // Method to load a graph from a given adjacency matrix
    void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
        // Check if the matrix is square
        size_t size = matrix.size();
        for (size_t i = 0; i < size; ++i) {
            if (matrix[i].size() != size) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }

        // Set the adjacency matrix and number of vertices
        adjMatrix = matrix;
        numVertices = size;
    }

    // Method to print the adjacency matrix of the graph
    void Graph::printGraph() {
        std::cout << "Adjacency Matrix:" << std::endl;
        for (const auto &row : adjMatrix) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << std::endl;
        }
    }

    // Method to get the number of vertices in the graph
    size_t Graph::getNumVertices() const {
        return numVertices;
    }

    // Method to get the adjacency matrix of the graph
    std::vector<std::vector<int>> Graph::getAdjMatrix() const {
        return adjMatrix;
    }

    // Overloading the addition operator (+) to add two graphs
    Graph Graph::operator+(const Graph& other) const {
        // Check if both graphs have the same size
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot add graphs with different sizes");
        }
        // Create a new graph to store the result
        vector<vector<int>> newAdjMatrix;
        newAdjMatrix = this->adjMatrix;
    
        // Iterate over each edge in the graph
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                // Add corresponding edges from both graphs
                newAdjMatrix[i][j] = adjMatrix[i][j] + other.getAdjMatrix()[i][j];
            }
        }
        
        Graph graph;
        graph.loadGraph(newAdjMatrix);
        return graph;
    }
    // Overloading the compound addition operator (+=) to add another graph to this graph
    Graph& Graph::operator+=(const Graph& other) {
        // Check if both graphs have the same size
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot add graphs with different sizes");
        }

        // Create a new graph to store the result
        vector<vector<int>> newAdjMatrix;
        newAdjMatrix = this->adjMatrix;
        // Iterate over each edge in the graph
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                // Add corresponding edges from both graphs
                newAdjMatrix[i][j] += other.getAdjMatrix()[i][j];
            }
        }
        this->loadGraph(newAdjMatrix);

        return *this;
    }
    
    // Overloading the unary plus operator (+) to return a copy of the graph
    Graph Graph::operator+() const {
        return *this; // Return a copy of the current graph
    } 

    // Overloading the subtraction operator (-) to add two graphs
    Graph Graph::operator-(const Graph& other) const {
        // Check if both graphs have the same size
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot add graphs with different sizes");
        }
        // Create a new graph to store the result
        vector<vector<int>> newAdjMatrix;
        newAdjMatrix = this->adjMatrix;
    
        // Iterate over each edge in the graph
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                // Subtract corresponding edges from both graphs
                newAdjMatrix[i][j] = adjMatrix[i][j] - other.getAdjMatrix()[i][j];
            }
        }
        
        Graph graph;
        graph.loadGraph(newAdjMatrix);
        return graph;
    }

    // Overloading the compound subtraction operator (-=) to add another graph to this graph
    Graph& Graph::operator-=(const Graph& other) {
        // Check if both graphs have the same size
        if (numVertices != other.numVertices) {
            throw std::invalid_argument("Cannot subtract graphs with different sizes");
        }

        // Create a new graph to store the result
        vector<vector<int>> newAdjMatrix;
        newAdjMatrix = this->adjMatrix;
        // Iterate over each edge in the graph
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                // Subtract corresponding edges from both graphs
                newAdjMatrix[i][j] -= other.getAdjMatrix()[i][j];
            }
        }
        this->loadGraph(newAdjMatrix);

        return *this;
    }
    // Overloading the unary minus operator (-) to return a copy of the graph
    Graph Graph::operator-() const {
        // Create a new graph to store the result
        vector<vector<int>> newAdjMatrix;
        newAdjMatrix = this->adjMatrix;
        // Iterate over each edge in the graph
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                // Multiply by -1 corresponding edges from graph
                newAdjMatrix[i][j] *= -1;
            }
        }
        Graph graph;
        graph.loadGraph(newAdjMatrix);

        return graph;
    }
    
    // Overloading the greater operator (>) to return boolean
    bool Graph::operator>(const Graph& other) const{
        return other < *(this);
    }

    // Overloading the smaller operator (<) to return boolean
    bool Graph::operator<(const Graph& other) const{
        if (numVertices > other.getNumVertices()) {
            return false;
        }
        std::vector<int> numEdges(2,0);
        for (const auto& row: adjMatrix) {
            for (const auto& val: row) {
                if (val != 0 ){
                    numEdges[0]++;
                }
            }
        }     

        for (const auto& row: other.getAdjMatrix()) {
            for (const auto& val: row) {
                if (val != 0 ){
                    numEdges[1]++;
                }
            }
        }
        return numEdges[0] < numEdges[1];
    }

    bool Graph::operator==(const Graph& other) const{
        if (numVertices != other.getNumVertices())
        {return false;}
        if (!((*this) > other) && !((*this) < other)) {
            return true;
        }
        for (size_t i = 0; i < numVertices; i++) {
            for (size_t j = 0; j < numVertices; j++) {
                if (adjMatrix[i][j] != other.getAdjMatrix()[i][j])
                {return false;}
            }
        }
        return true;
    }

    bool Graph::operator!=(const Graph& other) const{
        return !(*this == other);
    }

    bool Graph::operator>=(const Graph& other) const{
        if (*this > other || *this == other){return true;}
        return false;
    }
    bool Graph::operator<=(const Graph& other) const{
        if (*this < other || *this == other){return true;}
        return false;
    }

    Graph Graph::operator++(int) {
        Graph temp = *(this);
        ++(*(this));
        return temp;
    }

    Graph& Graph::operator++() {
        for (auto& row : adjMatrix) {
            for (auto& val : row) {
                ++val;
            }
        }
        return *(this);
    }
    Graph Graph::operator--(int) {
        Graph temp = *(this);
        --(*(this));
        return temp;
    }

    Graph& Graph::operator--() {
        for (auto& row : adjMatrix) {
            for (auto& val : row) {
                --val;
            }
        }
        return *(this);
    }

    Graph Graph::operator*(const Graph& other) const {
        if (numVertices == 0 || other.getNumVertices() == 0) {
            throw std::invalid_argument("Cannot operate on empty graphs");
        }
        if (numVertices != other.getNumVertices()) {
            throw std::invalid_argument("Cannot multiply graphs with different sizes");
        }
        Graph result;
        vector<vector<int>> matrix(numVertices,std::vector<int>(numVertices, 0));
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                for (size_t k = 0; k < numVertices; ++k) {
                    matrix[i][j] += adjMatrix[i][k] * other.getAdjMatrix()[k][j];
                }
            }
        }
        result.loadGraph(matrix);
        return result;
    }

    Graph Graph::operator*(int number) const {
        Graph result;
        vector<vector<int>> matrix = adjMatrix;
        for (size_t i = 0; i < numVertices; ++i) {
            for (size_t j = 0; j < numVertices; ++j) {
                matrix[i][j] = adjMatrix[i][j] * number;
            }
        }
        result.loadGraph(matrix);
        return result;
    }

    std::ostream& operator<<(std::ostream& os, const Graph& graph) {
        
        os << "Adjacency Matrix:" << std::endl;

        for (const auto& row : graph.getAdjMatrix()) {
            for (const auto& val : row) {
                os << val << " ";
            }
            os << std::endl;
        }
        return os;
    }

}
