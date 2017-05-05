import java.io.*;
import java.util.*;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        int k = scanner.nextInt();
        
        StringBuffer sb = new StringBuffer();
        
        s.chars().forEach(
            (c) -> {
                if (c >= 'A' && c <= 'Z')
                {
                    c = 'A' + (c-'A'+k)%26;
                    sb.append((char)c);
                }
                else if (c >= 'a' && c <= 'z')
                {
                    c = 'a' + (c-'a'+k)%26;
                    sb.append((char)c);
                }
                else
                {
                    sb.append((char)c);    
                }
            }
        );
        
        /*
        for(int i=0; i<n; ++i)
        {
            int c = s.charAt(i);
            if (c >= 'A' && c <= 'Z')
            {
                c = 'A' + (c-'A'+k)%26;
                sb.append((char)c);
            }
            else if (c >= 'a' && c <= 'z')
            {
                c = 'a' + (c-'a'+k)%26;
                sb.append((char)c);
            }
            else
            {
                sb.append((char)c);    
            }
        }
        */
        System.out.println(sb.toString());
    }
}
