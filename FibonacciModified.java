import java.math.BigInteger;
import java.util.Scanner;

class FibonacciModified {
   private BigInteger t1;
   private BigInteger t2;
   private int end;

   public void Solve() {
      try(Scanner scanner = new Scanner(System.in);){
         t1 = scanner.nextBigInteger();
         t2 = scanner.nextBigInteger();
         end = scanner.nextInt();
         
         BigInteger sum = new BigInteger("0");
         for(int i=3; i<=end; ++i){
            sum = t1.add(t2.pow(2));
            t1 = t2;
            t2 = sum;
         }
         
         System.out.println(sum.toString());
      }
   }
}

public class Solution {
   public static void main(String args[]) throws Exception {
      FibonacciModified solver = new FibonacciModified();
      solver.Solve();
   }
}
