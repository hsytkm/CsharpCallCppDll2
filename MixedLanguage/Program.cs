using CppCliDll;
using System;
using System.Runtime.InteropServices;

// C++/CLIラッピング入門 https://qiita.com/Convert314/items/0171811eabd69042e540
namespace MixedLanguage
{
    class Program
    {
        private static readonly string TestDataPath = @"C:\Users\t_hos\source\repos\_data\_test\test.bin";

        static void Main(string[] args)
        {
            Console.WriteLine($"C# Main");
            Console.WriteLine($"--------------------------------------------");

            Console.WriteLine($"純粋C++/CLIのDLLコール");
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

            Console.WriteLine($"ネイティブC++をラッパしたC++/CLIのDLLコール");
            using (var nat = new NativeWrapper(10, 2))
            {
                Console.WriteLine($"From NativeC++");

                // 基本
                Console.WriteLine($" *基本*");
                var x1 = nat.GetInt();
                nat.SetInt(1234);
                var x2 = nat.GetInt();
                Console.WriteLine($"  Value={x1} → {x2}");
                Console.WriteLine($"  String={nat.GetStringWrap("★")}");

                // Pet
                Console.WriteLine($" *Pet*");
                //var pet = nat.GetPetClass();
                var petType = nat.GetPetType();
                var petTypeStr = Enum.GetName(typeof(NativeWrapper.PetTypeWrap), petType);
                var petName = nat.GetPetName();
                var petAge = nat.GetPetAge();
                Console.WriteLine($"  Pet: {petTypeStr} / {petName} / {petAge}");

                // BinReader
                Console.WriteLine($" *BinReader*");
                nat.WrapSetFilePath(TestDataPath);          // ファイル設定
                nat.WrapReadFileBinary();                   // バイナリをDLL内で読み込み
                var binSize = nat.WrapGetBinarySize();      // DLL内のバイナリサイズを受け取る
                var ptr = nat.WrapGetBinaryPointer();       // DLLからバイナリのポインタを受け取る

                // マネージ配列にコピー
                byte[] managedArray = new byte[binSize];
                Marshal.Copy(ptr, managedArray, 0, binSize);
            }
            Console.WriteLine($"--------------------------------------------");

            Console.ReadKey();
            Console.WriteLine($"C# End");
        }

        //private static BitmapImage LoadImage(byte[] imageData)
        //{
        //    if (imageData == null || imageData.Length == 0) return null;
        //    var image = new BitmapImage();
        //    using (var mem = new MemoryStream(imageData))
        //    {
        //        mem.Position = 0;
        //        image.BeginInit();
        //        image.CreateOptions = BitmapCreateOptions.PreservePixelFormat;
        //        image.CacheOption = BitmapCacheOption.OnLoad;
        //        image.UriSource = null;
        //        image.StreamSource = mem;
        //        image.EndInit();
        //    }
        //    image.Freeze();
        //    return image;
        //}
    }
}
