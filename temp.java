import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int t = scanner.nextInt();
        
        Map<Integer, List<A>> grid = new HashMap<>(n);
        for (int i=0; i<t; ++i){
            int r = scanner.nextInt();
            int c1 = scanner.nextInt();
            int c2 = scanner.nextInt();
            A a = new A();
            a.c1 = c1;
            a.c2 = c2;
            
            List<A> row = grid.computeIfAbsent(r, ArrayList<A>::new);
            row.add(a);
        }
        scanner.close();
        
        Comparator<A> c = (a1, a2) ->
        {
        	if (a1.c1 < a2.c1)
        	{
        		return -1;
        	}
        	else if (a1.c1 > a2.c1)
        	{
        		return 1;
        	}
        	else
        	{
        		if (a1.c2 < a2.c2)
        		{
        			return -1;
        		}
        		else if (a1.c2 > a2.c2)
        		{
        			return 1;
        		}
        		else
        		{
        			return 0;
        		}
        	}
        };
        
        grid.values().forEach(row -> row.sort(c));
        
        
        
        
        int free = n*m - grid.values().stream().flatMap(r -> r.stream()).mapToInt(a->{return a.c2- a.c1 + 1;}).sum();
        System.out.println(free);
        
    }
}

class A
{
    public int c1;
    public int c2;
    
    public boolean merge(A a){
        if (a.c1 <= c1)
        {
            if (a.c2 >= c1 && a.c2 <= c2)
            {
                c1 = a.c1;
                return true;
            }
            else if (a.c2 >= c2)
            {
            	c1 = a.c1;
            	c2 = a.c2;
                return true;
            }
        }
        else if (a.c1 >= c1 && a.c1 <= c2)
        {
            if (a.c2 <= c2)
            {
            	return true;
            }
            else
            {
                c2 = a.c2;
                return true;
            }
        }
        return false;
    }
}
