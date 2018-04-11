using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Shared;

namespace Threads
{
    class Program
    {

        static void Main(string[] args)
        {

            StartAllThreads();

        }

        static void StartAllThreads()
        {
            foreach (var item in SharedInfo.Data)
            {
                new Thread(() => Print(item))
                {
                    IsBackground = true,
                    Priority = ThreadPriority.AboveNormal
                }.Start();
            }
        }

        static void Print(int item)
        {
            Console.WriteLine($"Result of Sum for [0 to {item}] is: {item.SumFromZero()}");
        }
    }
}
