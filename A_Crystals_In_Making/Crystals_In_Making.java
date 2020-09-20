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
 

public class Crystals_In_Making {
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
            long  n = in.nextInt();
            int ans = 0;
            while(n>0){
                n &= n-1;
                ans++;
            }
            out.println(ans);
            return;
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
 
        public long nextInt() {
            return Long.parseLong(next());
        }
 
    }
}