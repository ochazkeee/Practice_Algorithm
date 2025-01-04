using System;

class Program{
    static void Main(string[] args){
        int N = int.Parse(Console.ReadLine());
        int [] steps;
        steps = new int[N+1];
        int [] DP = new int[N+1];
        for (int i=1; i<=N ; i++){
            steps[i] = int.Parse(Console.ReadLine());
        }
        DP[0]=0;
        DP[1]=steps[1];
        if(N>1){
            DP[2]=steps[1]+steps[2];
        }
        for (int i=3;i<=N;i++){
            DP[i] = Math.Max(DP[i-2]+steps[i],DP[i-3]+steps[i-1]+steps[i]);
        }
        Console.WriteLine(DP[N]);
    }
}