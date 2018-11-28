import java.util.Scanner;


public class MarsExploration 
{
   static int marsExploration(String s) 
   {
      String sos = new String("SOS");
      int count = 0;
      for (int i=0; i<s.length(); i=i+3)
      {
         for (int j=0; j<3; ++j)
         {
            if (sos.charAt(j) != s.charAt(i+j))
            {
               ++count;
            }
         }
      }
      return count;
   }
   
   public static void main(String[] args)
   {
      String input = "SOSSPSSQSSOR";
      System.out.println(marsExploration(input));
   }
   
}


