using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shared
{

    public static class SharedInfo
    {

        /// <summary>
        /// Data used for calculations
        /// </summary>
        public static readonly int[] Data = new[] {
            154541521, 1259, 4521, 3658, 3234, 545, 5452331, 5451211,
            545454, 55121, 654521, 6526320, 5454, 5485412, 6521, 454521545,
            545412151, 5415121, 545451, 56215, 4, 54845121, 87854,
            54515121, 545121, 44111, 212121, 544884
        };

        /// <summary>
        /// Returns 0 + 1 + 2 + ... + num
        /// </summary>
        /// <param name="num">Upper bound of summation</param>
        /// <returns>Result of summation</returns>
        public static long SumFromZero(this int num)
        {
            long result = 0;
            for (int i = 1; i <= num; i++)
                result += i;

            return result;
        }

    }
}
