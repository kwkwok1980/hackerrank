import java.io.*;
import java.util.*;
import java.util.Scanner;
import java.util.function.Consumer;
import java.util.function.IntConsumer;


public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        String s = scanner.next();
        int k = scanner.nextInt();
        
        StringBuffer sb = new StringBuffer();
        
        IntConsumer consumer = (c) -> {
            if (c >= 'A' && c <= 'Z'){
                c = 'A' + (c-'A'+k)%26;
                sb.append((char)c);
            }
            else if (c >= 'a' && c <= 'z'){
                c = 'a' + (c-'a'+k)%26;
                sb.append((char)c);
            }
            else{
                sb.append((char)c);    
            }
        };
        
        s.chars().forEach(consumer);
        System.out.println(sb.toString());
    }
}
