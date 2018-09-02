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

            // C++/CLIのみ
            using (var cli = new CppCliClass())
            {
                var mul = cli.Multi(2, 3);      // 掛け算の取得
                var str = cli.ToUpper("abCde"); // 大文字の取得

                Console.WriteLine($"From C++/CLI: {mul} {str}");
            }

            // C++のCLIラッパ
            using (var nat = new NativeWrapper(10, 2))
            {
                var x = nat.GetInt();
                Console.WriteLine($"From NativeC++: Value={x}");
            }

            Console.ReadKey();
            Console.WriteLine($"C# End");
        }
    }
}
