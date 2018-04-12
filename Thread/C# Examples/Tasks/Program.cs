using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Shared;

namespace Tasks
{
    class Program
    {
        static void Main(string[] args)
        {

            DoTasksAsync().GetAwaiter().GetResult();

            Console.WriteLine("Press [Enter] to exit...");
            Console.Read();

        }

        static async Task DoTasksAsync()
        {
            
            await Task.WhenAll(GetTasks());
        }

        static IEnumerable<Task> GetTasks()
        {
            foreach (var item in SharedInfo.Data) yield return Task.Run(() =>
            {
                Console.WriteLine($"Result of Sum for [0 to {item}] is: {item.SumFromZero()}");
            });
        }
    }
}
