/*
    author: KRHero
    IDE: VSCode
*/
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
 

public class Grand_Line {

    int MAX = 1000005;
    long[] dp = new long[MAX];
    public void setDP(){
        dp[1] = 0;
        for(int i = 2;i<MAX;i++){
            dp[i] = 1;
        }
        for(int i = 2;i<MAX;i++){
            for(int j = 2*i;j<MAX;j+=i){
                dp[j] += dp[i];
            }
        }
    }

    public void solve(InputReader in, PrintWriter out){
        int n = in.nextInt();
        out.println(dp[n]);
        return;
    }

    public static void main(String[] args) {
        Grand_Line g = new Grand_Line();
        g.setDP();
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        long t = in.nextInt();
        while(t-->0){
            g.solve(in,out);
        }
        out.close();

        
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
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
    }
}