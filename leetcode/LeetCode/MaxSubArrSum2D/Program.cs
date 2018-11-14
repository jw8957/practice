using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MaxSubArrSum2D
{
    class Program
    {
        public static int MaxSubArrSum1D(int[] arr)
        {
            int res = 0;

            if (arr != null && arr.Length > 0)
            {
                int maxEnds = arr[0];
                res = arr[0];

                for (int i = 1; i < arr.Length; i++)
                {
                    if (maxEnds + arr[i] >= arr[i])
                    {
                        maxEnds = maxEnds + arr[i];
                    }
                    else
                    {
                        maxEnds = arr[i];
                    }

                    if (maxEnds >= res)
                    {
                        res = maxEnds;
                    }
                }
            }

            return res;
        }

        static void Main(string[] args)
        {
            int[][] arr = new int[][] 
            {
                new int[] {1, 2, -1, -4, -20},
                new int[] {-8, -3, 4, 2, 1},
                new int[] {3, 8, 10, 1, 3},
                new int[] {-4, -1, 1, 7, -6},
            };


            int maxSum = arr[0][0];

            for (int i = 0; i < arr.Length; i++)
            {
                int[] tmp = new int[arr[i].Length];
                for (int j = 0; j < arr[i].Length; j++)
                {
                    tmp[j] = 0;
                }

                for (int k = i; k < arr.Length; k++)
                {
                    for (int j = 0; j < arr[k].Length; j++)
                    {
                        tmp[j] += arr[k][j];
                    }

                    int cur_max = MaxSubArrSum1D(tmp);
                    if (cur_max >= maxSum)
                    {
                        maxSum = cur_max;
                    }
                }
            }
        }
    }
}
