/*
    author: KRHero
    IDE: VSCode
*/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Stack;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
 

public class Minimized_Way {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Tasker task = new Tasker();
        long t = in.nextInt();
        while(t-->0){
            task.solve(in,out);
        }
        out.close();
    }

    static class Tasker{

        public void solve(InputReader in, PrintWriter out){
            int  n = in.nextInt();
            long[] arr = new long[n];
            long[] val = new long[n];
            int[] xMax = new int[n];
            int[] xMin = new int[n];
            for(int i = 0;i<n;i++){
                arr[i] = in.nextLong();
                xMax[i] = -1;
                xMin[i] = -1;
            }
            for(int i = 0;i<n;i++){
                val[i] = in.nextLong();
            }
            Stack<Integer> s = new Stack<Integer>();
            Stack<Integer> s1 = new Stack<Integer>();
            s.push(n-1);
            s1.push(n-1);
            for(int i = n-2;i>=0;i--){
                while(!s.isEmpty() && arr[s.peek()]<arr[i]) s.pop();
                if(!s.isEmpty()){
                    xMax[i] = s.peek();
                }
                s.push(i);
                while(!s1.isEmpty() && arr[s1.peek()]>=arr[i]) s1.pop();
                if(!s1.isEmpty()){
                    xMin[i] = s1.peek();
                }
                s1.push(i);
            }
            long[] dp = new long[n];
            for(int i = 0;i<n;i++) dp[i] = Long.MAX_VALUE;
            dp[0] = val[0];
            for(int i = 0;i<n-1;i++){
                if(xMax[i]!=-1) dp[xMax[i]] = Math.min(dp[xMax[i]],val[xMax[i]] + dp[i]);
                if(xMin[i]!=-1) dp[xMin[i]] = Math.min(dp[xMin[i]],val[xMin[i]] + dp[i]);
            }
            out.println(dp[n-1]);
        }
    }    
 
    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
 
        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }
 
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
 
        public long nextLong() {
            return Long.parseLong(next());
        }
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
    }
}