// Hasan Raza
// Non-Recursive DFS Algorithm using Stack and Adjacency List
// Pre-Defined Vertice and Adjacency List 
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <stack>

   // Predefined global vertices
   const std::vector<int> vertices = {10, 20, 30, 40, 50, 60};

   // Adjacency list representation
   const std::vector<std::vector<int>> ajacencyList = {
       {1, 2},      // vertex 0 (10) connected to vertices 1 and 2
       {3, 4},      // vertex 1 (20) connected to vertices 3 and 4
       {4},         // vertex 2 (30) connected to vertex 4
       {5},         // vertex 3 (40) connected to vertex 5
       {5},         // vertex 4 (50) connected to vertex 5
       {}           // vertex 5 (60) has no connections
   };

void nonRecursiveDFS() {
   std::cout << "Performing Depth-First Search:" << std::endl;

   int numVertices = vertices.size();              // Total number of vertices
   std::vector<bool> visited(numVertices, false);  // Visited tracking, adds nodes that we have visited to the visited vector
   std::stack<int> dfsStack;                       // Stack for DFS
   dfsStack.push(0);                               // Begins dfs algorithm by adding the position of the first index of the vertice vector into stack

   while (!dfsStack.empty()) {
       int currentVertex = dfsStack.top();         // Save position of first vertex in stack to "currentVertex"
       dfsStack.pop();                             // Removes top of stack before we can push any new vertexs

       if (!visited[currentVertex]) {              // Process if not visited
           visited[currentVertex] = true;          // Mark as visited and print
           std::cout << "Visited vertex: " << vertices[currentVertex] << std::endl;

           // Push unvisited adjacent vertices onto stack, repeats if more than one
           for (int i = ajacencyList[currentVertex].size() - 1; i >= 0; --i) {
               int connectedVertex = ajacencyList[currentVertex][i];           // Saves an adjacent vertex to connected vertex

               if (!visited[connectedVertex]) {
                   dfsStack.push(connectedVertex); // Pushes the neighbors/connected vertices of the most recently visited node to the top of the stack
               }
           }
       }
   }
};

void generateSequence(int N) {
   std::priority_queue<int, std::vector<int>, std::greater<int>> pq; // Priority queue to get numbers in ascending order because we want to always use the smallest number first for our calculations.
   std::set<int> seen;  // To avoid duplicates
  
   // We will first insert 1 into the priority queue because the first number is: 2^0 * 3^0 = 1
   pq.push(1);
   seen.insert(1);
  
   std::cout << "First " << N << " numbers in sequence: ";
  
   while (N>0) {
       N--;
      
       int curr = pq.top();    // Gets first/smallest number from priority queue to multiply by 2 and 3
       pq.pop();               // Pops it to prevent doing it again
       std::cout << curr << (N > 0 ? ", " : "");    // Prints the number
      
       // Generates the next possible numbers by multiplying by 2 and 3
       if (seen.find(curr * 2) == seen.end()) // Checks if the number we are currently handling is in the set of already used numbers, meaning we've already had that result
       {
           pq.push(curr * 2);
           seen.insert(curr * 2);
       }
       if (seen.find(curr * 3) == seen.end())
       {
           pq.push(curr * 3);
           seen.insert(curr * 3);
       }
   }
   std::cout << std::endl;
}


int main() {
   nonRecursiveDFS();

   int N;
   std::cout << "Enter N: ";
   std::cin >> N;
   generateSequence(N);

   return 0;
}


// Output Below:
// Performing Depth-First Search:
// Visited vertex: 10
// Visited vertex: 20
// Visited vertex: 40
// Visited vertex: 60
// Visited vertex: 50
// Visited vertex: 30