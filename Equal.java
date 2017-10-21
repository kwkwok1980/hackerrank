import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

class Equal {

	private int T;
	private int N;
	private List<Integer> colleagues;

	public Equal() {
		colleagues = new ArrayList<>();
	}

	public void run() {
		try (Scanner scanner = new Scanner(System.in)) {
			T = scanner.nextInt();
			// System.out.println("T[" + T + "]");
			for (int t = 0; t < T; ++t) {
				N = scanner.nextInt();
				// System.out.println("N[" + N + "]");

				colleagues.clear();
				for (int n = 0; n < N; ++n) {
					int c = scanner.nextInt();
					colleagues.add(c);
				}
				Solve();
			}
		}
	}

	public void Solve() {
		int nMax = Collections.max(colleagues);
		List<Integer> values = new ArrayList<Integer>();
		for (int i=0; i<N; ++i){
			int nValue = nMax - colleagues.get(i);
			values.add(nValue);
		}
		
        nMax = Collections.max(values);
        List<Integer> maxValues = new ArrayList<>();
        maxValues.add(nMax);
        maxValues.add(nMax+1);
        maxValues.add(nMax+2);
        maxValues.add(nMax+5);
        
        List<Integer> steps = new ArrayList<>();
        for(int m=0; m<4; ++m){
        	nMax = maxValues.get(m);
        	int nStep = 0;
    		for (int i=0; i<N; ++i){
    			int nDiff = nMax - values.get(i);
    			while (nDiff != 0)
    			{
    				if (nDiff >=5)
    				{
    					nDiff = nDiff -5;
    				}
    				else if (nDiff >=2)
    				{
    					nDiff = nDiff - 2;
    				}
    				else
    				{
    					nDiff = nDiff - 1;
    				}
    				++nStep;
    			}
    		}
    		steps.add(nStep);
        }
		
		System.out.println(Collections.min(steps));
	}
}

public class Solution {
    public static void main(String args[] ) throws Exception {
        Equal equal = new Equal();
		equal.run();
    }
}
