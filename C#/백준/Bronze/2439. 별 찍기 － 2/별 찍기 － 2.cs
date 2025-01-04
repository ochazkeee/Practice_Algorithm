using System;

class Program
{
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        
        for (int i = N-1 ;i >=0 ;i--){
            for (int j=0;j<i;j++){
                Console.Write(" ");
            }
            for (int j=i;j<N;j++){
                Console.Write("*");
            }
            Console.WriteLine();
        }
    }
}
