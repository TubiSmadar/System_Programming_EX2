/*
 * 315638577
 * gunslokij@gmail.com
*/
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

using namespace std;

namespace ariel{
    class Graph {
        private:
            std::vector<std::vector<int>> adjMatrix; 
            size_t numVertices;

        public:
            Graph();
            Graph(const std::vector<std::vector<int>>&, size_t);

            void loadGraph(const std::vector<std::vector<int>> &matrix);
            void printGraph();
            std::vector<std::vector<int>> getAdjMatrix() const;
            size_t getNumVertices() const;

            // Overloading the addition operator (+) to add two graphs
            Graph operator+(const Graph& other) const;

            // Overloading the compound addition operator (+=) to add another graph to this graph
            Graph& operator+=(const Graph& other);
            
            // Overloading the unary plus operator (+) to return a copy of the graph
            Graph operator+() const; 

           // Overloading the submission operator (-) to add two graphs
            Graph operator-(const Graph& other) const;

            // Overloading the compound submission operator (-=) to add another graph to this graph
            Graph& operator-=(const Graph& other);
            
            // Overloading the unary minus operator (-) to return a copy of the graph
            Graph operator-() const;

            // Overloading the greater operator (>) to return boolean
            bool operator>(const Graph& other)const;

            // Overloading the smaller operator (<) to return boolean
            bool operator<(const Graph& other)const;

            // Overloading the greater equal operator (>=) to return boolean
            bool operator>=(const Graph& other)const;

            // Overloading the smaller equal operator (<=) to return boolean
            bool operator<=(const Graph& other)const;

            // Overloading the equals operator (==) to return boolean
            bool operator==(const Graph& other)const;

            // Overloading the not equals operator (!=) to return boolean
            bool operator!=(const Graph& other)const;

            // Overloading the increment operator (++) to return graph
            Graph operator++(int);

            // Overloading the increment operator (++) to return graph
            Graph& operator++();
                        
            // Overloading the decrecment operator (--) to return graph
            Graph operator--(int);

            // Overloading the increment operator (--) to return graph
            Graph& operator--();

            // Overloading the multiplication operator (*) to return graph
            Graph operator*(const Graph&)const;

            // Overloading the multiplication operator (*) to return graph
            Graph operator*(int)const;

            // Overloading the output operator (<<) to return ostream
            friend std::ostream& operator<<(std::ostream& os, const Graph& graph);


    };
}

#endif
