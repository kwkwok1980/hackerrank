import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int k = in.nextInt();
        int[] x = new int[n];
        for(int x_i=0; x_i < n; x_i++){
            x[x_i] =in.nextInt();
        }

        Arrays.sort(x);
        //System.out.println(Arrays.toString(x));
        
        int start = x[0];
        int middle = start + k;
        int end = middle + k;
        
        int count = 1;
        for(int i=0; i<n; ++i)
        {
            if (x[i] > middle)
            {
                if (x[i-1] <= middle)
                {
                    middle = x[i-1];
                    end = middle + k;
                }
            }
            
            if (x[i] > end)
            {
                ++count;
                start = x[i];
                middle = start + k;
                end = middle +k;
            }
        }
        System.out.println(count);
        
    }
}
