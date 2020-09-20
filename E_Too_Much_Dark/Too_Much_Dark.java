/*
    author: KRHero
    IDE: VSCode
*/
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.StringTokenizer;
 

public class Too_Much_Dark {
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

        public int[] level;
        public int[] marthaThere;
        public int[] parents;
        int martha = 0;
        int[][] edges; 
        int[] p;

        public void solve(InputReader in, PrintWriter out){
            int n = in.nextInt();  

            p = new int[n];  

            edges = new int[n][];

            int[] from = new int[n-1];
            int[] to = new int[n-1];

            level = new int[n];
            marthaThere = new int[n];
            parents = new int[n];

            for(int i = 0;i<n;i++ ){
                level[i] = 0;
                marthaThere[i] = 0;
                parents[i] = -1;
            }   

            for(int i = 0;i<n-1;i++){
                from[i] = in.nextInt();
                from[i]--;
                to[i] = in.nextInt();
                to[i]--;
            }


            for (int i : from) p[i]++;
            for (int i : to) p[i]++;

            for (int i = 0; i < n; i++) edges[i] = new int[p[i]];

            for (int i = 0; i < from.length; i++) {
                edges[from[i]][--p[from[i]]] = to[i];
                edges[to[i]][--p[to[i]]] = from[i];
            }

            int x,y;
            x = in.nextInt();
            y = in.nextInt();
            if(x==y){
                out.println("0");
                return;
            }    
            x--;
            y--;
            martha = y;
            this.dfs(x,-1,0,0); 
            
            int val = (int)Math.ceil((double)(level[y] + 1 )/2.0);
            int ans = val;
            int temp = 0;
            for(int i =0;i<n;i++){
                //out.println(i+ " " + level[i] + " " + marthaThere[i]);
                if(level[i]==val && marthaThere[i]==1){
                    int var = this.dfs1(i,parents[i]);
                    temp = Math.max(temp,var);
                }
            }
            ans += temp;
            out.println(ans);
            return;
        }

        public void dfs(int node, int parent,int depth,int flag){
            level[node] = depth;
            marthaThere[node] = flag;
            parents[node] = parent;
            if(node==martha) {
                flag = 1;
                marthaThere[node] = 1;
            }
            for(int i : edges[node]){
                if(parent==i) continue;
                this.dfs(i,node,depth+1,flag);
                if(marthaThere[i]==1) marthaThere[node] = 1;
            }
            return;
        }

        public int dfs1(int node,int parent){
            if(edges[node].length==1) return 0;
            int ans = 0;
            for(int i : edges[node]){
                if(i==parent) continue;
                ans = Math.max(ans,dfs1(i,node));
            }
            return ans + 1;
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