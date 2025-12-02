// 순열 생성
// depth 있는 dfs로 가능할듯
// m개만큼 최대 depth 조건 설정, 1~n중에 현재보다 큰 수들 전부로 dfs호출

using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;

namespace algorithm_study
{
    class main
    {
        static int N,M;
        static int[] sequence;
        public static void Main(String[] args)
        {
            string[] input = Console.ReadLine().Split();
            N = int.Parse(input[0]);
            M = int.Parse(input[1]);
            sequence = new int[M];
            DFS(1, 0);
            return;
        }

        public static void DFS(int n, int depth) { 
            if (depth == M)
            {
                Print();
                return;
            }
            for (int i = n; i <= N; i++)
            {
                sequence[depth] = i;
                DFS(i + 1, depth + 1);
            }
        }

        public static void Print()
        {
            Console.WriteLine(string.Join(" ",sequence));
        }
    }
}
