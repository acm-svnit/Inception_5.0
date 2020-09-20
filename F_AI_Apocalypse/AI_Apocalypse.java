/*
    author: KRHero
    IDE: VSCode
*/
import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.InputStream;
 

public class AI_Apocalypse {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = in.nextInt();
        String x;
        try{
            if(n==2){
                
                out.write("A 1\n");
                out.flush();
                x = in.next();
                out.write("A 1\n");
                out.flush();
                System.out.flush();
                x = in.next();            
            }

            for(int i = 2;i<=n-1;i++){
                out.write("A "+i+"\n");
                out.flush();
                x = in.next();
                if(x.equals("Yes")) return;
            }

            for(int i = n-1;i>=2;i--){
                out.write("A "+i+"\n");
                out.flush();
                x = in.next();
                if(x.equals("Yes")) return;
            }
        }catch(Exception e){
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
 
        public int nextInt() {
            return Integer.parseInt(next());
        }
 
    }
}