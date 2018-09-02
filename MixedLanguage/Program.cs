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

            // 純粋C++/CLIのDLLコール
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

            // ネイティブC++をラッパしたC++/CLIのDLLコール
            using (var nat = new NativeWrapper(10, 2))
            {
                Console.WriteLine($"  From NativeC++");
                Console.WriteLine($"  Value={nat.GetInt()}");
                Console.WriteLine($"  String={nat.GetStringWrap("★")}");
            }
            Console.WriteLine($"--------------------------------------------");

            Console.ReadKey();
            Console.WriteLine($"C# End");
        }
    }
}
