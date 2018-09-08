using CppCliDll;
using System;
using System.Runtime.InteropServices;

namespace MixedLanguage
{
    class Program
    {
        private static readonly string TestDataPath = @"C:\Users\t_hos\source\repos\_data\_test\test.bin";

        static void Main(string[] args)
        {
            Console.WriteLine($"ネイティブC++をラッパしたC++/CLIのDLLコール" + Environment.NewLine);

            using (var nat = new PetWrapper())
            {
                //var pet = nat.GetPetClass();  // クラス取得不可(アクセスレベルでビルド通らない)
                var petType = nat.GetPetType();
                var petTypeStr = Enum.GetName(typeof(PetWrapper.PetTypeWrap), petType);
                var petName = nat.GetPetName();
                var petAge = nat.GetPetAge();
                Console.WriteLine($"  Pet: {petTypeStr} / {petName} / {petAge}");
            }
            Console.WriteLine(Environment.NewLine);

            using (var nat = new BinReaderWrapper())
            {
                nat.WrapSetFilePath(TestDataPath);          // ファイル設定
                nat.WrapReadFileBinary();                   // バイナリをDLL内で読み込み
                var binSize = nat.WrapGetBinarySize();      // DLL内のバイナリサイズを受け取る
                var ptr = nat.WrapGetBinaryPointer();       // DLLからバイナリのポインタを受け取る

                // マネージ配列にコピー
                byte[] managedArray = new byte[binSize];
                Marshal.Copy(ptr, managedArray, 0, binSize);

                // バイナリのコンソール表示
                for (int i = 0; i < managedArray.Length; i++)
                {
                    Console.Write($"0x{managedArray[i]:x2} ");
                    if (0 == ((i+1) % 8)) Console.WriteLine();
                }
                Console.WriteLine();
            }

            Console.ReadKey();
        }

    }
}
