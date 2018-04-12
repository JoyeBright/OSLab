using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shared;

namespace ParallelLinq
{
    class Program
    {

        static void Main(string[] args)
        {

            // Maximum number of Processors I want to use: Minimum of 512 and Enviroment.ProcessorCount
            int maxProcessorUsage = Math.Min(512, Environment.ProcessorCount);

            var parallelQuery = from item
                                in SharedInfo.Data
                                    .AsParallel() // Make Query Parallel
                                    .WithExecutionMode(ParallelExecutionMode.ForceParallelism) // Do not optimize PLinq to Normal Linq
                                    .WithDegreeOfParallelism(maxProcessorUsage)
                                select item;

            parallelQuery.ForAll(item =>
            {
                Console.WriteLine($"Result of Sum for [0 to {item}] is: {item.SumFromZero()}");
            });

            Console.WriteLine("Press [Enter] to exit...");
            Console.Read();

        }
    }
}
