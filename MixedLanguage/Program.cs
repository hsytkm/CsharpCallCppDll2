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
            Console.WriteLine($"--------------------------------------------");

            // C++/CLIのみ
            using (var cli = new CppCliClass())
            {
                var mul = cli.Multi(2, 3);      // 掛け算の取得
                var str = cli.ToUpper("abCde"); // 大文字の取得
                var person = cli.GetPersonClass();

                Console.WriteLine($"  From C++/CLI");
                Console.WriteLine($"  Multi={mul} / Upper:{str}");
                Console.WriteLine($"  Name={cli.GetPersonName()} / Age={cli.GetPersonAge()}");
                Console.WriteLine($"  Name={person.GetName()} / Age={person.GetAge()}");

            }
            Console.WriteLine($"--------------------------------------------");

            // C++のCLIラッパ
            using (var nat = new NativeWrapper(10, 2))
            {
                var x = nat.GetInt();
                Console.WriteLine($"  From NativeC++");
                Console.WriteLine($"  Value={x}");
                Console.WriteLine($"  String={nat.GetStringWrap()}");
            }
            Console.WriteLine($"--------------------------------------------");

            Console.ReadKey();
            Console.WriteLine($"C# End");
        }
    }
}
