// 인접리스트로 입력받고
// dfs, 완전탐색

using System;
using System.Collections.Generic;
using System.IO;

namespace algorithm_study
{
    class main
    {
        struct Node {
            public int edge;
            public int value;
        }

        static List<Node>[] nodes = new List<Node>[100_001];
        static bool[] visited = new bool[100_001]; 
        public static void Main(String[] args)
        {
            for (int i = 0; i < 100_001; i++)
            {
                nodes[i] = new List<Node>();
            }

            int V = int.Parse(Console.ReadLine());
            for (int i = 0; i < V; i++) { 
                string[] num = Console.ReadLine().Trim().Split(' ');
                int v1 = int.Parse(num[0]);
                for (int j=1; j<num.Length-1; j+=2)
                {
                    int v2 = int.Parse(num[j]);
                    int e = int.Parse(num[j+1]);
                    nodes[v1].Add(new Node { edge=v2,value=e });
                    //Console.Write($"{v2}:{e}, ");
                }
            }
            int answer = 0;
            int tmp = 0;
            dfs(1,ref tmp);
            ClearVisited();
            answer = dfs(tmp,ref tmp);

            Console.WriteLine(answer);
            return;
        }

        public static int dfs(int vertex, ref int deepVertex)
        {
            visited[vertex] = true;
            int sum = 0;
            int maxsum = 0;
            deepVertex = vertex;
            foreach (Node node in nodes[vertex])
            {
                if (visited[node.edge]) continue;
                int tmpVertex = 0;
                sum = dfs(node.edge,ref tmpVertex) + node.value;
                maxsum = Math.Max(sum, maxsum);
                if (maxsum == sum) {
                    deepVertex = tmpVertex;
                }
            }
            return maxsum;
        }

        public static void ClearVisited() {
            Array.Clear(visited, 0, visited.Length);
        }
    }
}
