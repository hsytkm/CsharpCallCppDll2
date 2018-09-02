using CppCliDll;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MixedLanguage
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine($"C# Main");

            using (var dll = new CliDll(10, 2))
            {
                var x = dll.GetInt();
                Console.WriteLine($"FromC++/CLI  Value={x}");
            }

            Console.ReadKey();
            Console.WriteLine($"C# End");
        }
    }
}
