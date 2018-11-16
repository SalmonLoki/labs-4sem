import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;


public class Hrom {

    static class rebroABC{
        int a;
        int b;
        int c;
        boolean bool;
        rebroABC(int a, int b, int c, boolean bool){
            this.a = a;
            this.b = b;
            this.c = c;
            this.bool = bool;
        }
    }

    public static void main(String[] args) throws IOException {

        ArrayList<rebroABC> rABC = new ArrayList<>();

        BufferedReader br = new BufferedReader(new FileReader("snails.in"));
        PrintWriter pr = new PrintWriter("snails.out");
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());//кол-во вершин
        int m = Integer.parseInt(st.nextToken()); //кол-во ребер


        HashMap<Integer,Integer>[] C = new HashMap[n];
        for (int i = 0; i < n ; i++)
            C[i] = new HashMap<>();
        HashMap<Integer,Integer>[] F = new HashMap[n];
        for (int i = 0; i < n ; i++)
            F[i] = new HashMap<>();

        int a,b,c;
        for (int  i = 0; i < m; i++){ //описания ребер
            StringTokenizer st2  = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st2.nextToken());
            b = Integer.parseInt(st2.nextToken()); //номера вершин, которые соединяет данное ребро
            c = 1;//пропускная способность

            if (a < b)
                rABC.add(new rebroABC(a-1,b-1, c, true));
            else rABC.add(new rebroABC(b-1,a-1, c, false));

            if (a > b) {int x  = a; a = b; b = x;}

            if (C[a-1].get(b-1) == null) {
                C[a - 1].put(b - 1, c);
                C[b - 1].put(a - 1, c);  /////////
                F[a - 1].put(b-1, 0);
                F[b - 1].put(a-1, 0);
            }
            else {
                C[a-1].put(b-1, C[a-1].get(b-1) + c);
                C[b - 1].put(a - 1, C[b-1].get(a-1) + c);/////////
            }

        }

        //ищем дополняющий путь: путь из s в t по ребрам, у которых остаточная пропускн.сп. положительна
        //если доп.путь найден, увеличиваем поток по этому пути
        //если не найден, то нашли макс.поток
        //доп.путь ищем в ширину/глубину
        //если  нашли доп.путь, увеличиваем поток: с - наименьшая из остат.способн. по доп. пути; для каждого ребра пути(u, v) :
        //Fuv += c; Fvu -= c;

        for (;;) { //ищем дополняющий путь
            int[] from = new int[n];
            Arrays.fill(from, -1);
            int[] q = new int[n];
            int h = 0;
            int t = 0;
            q[t++] = 0;
            from[0] = 0;

            for (int cur; h < t; ) { //ищем дополняющий путь: путь из s в t по ребрам, у которых остаточная пропускн.сп. положительна
                cur = q[h++];
                for (int v = 0; v < n; v++) {
                    if (C[cur].get(v) != null) {
                        if ((from[v] == -1) && (C[cur].get(v) - F[cur].get(v) > 0)) {
                            q[t++] = v;
                            from[v] = cur;
                        }
                    }
                }
            }
            if (from[n - 1] == -1) break; //если не найден, то нашли макс.поток => выходим из цикла

            //если  нашли доп.путь, увеличиваем поток: с - наименьшая из остат.способн. по доп. пути; для каждого ребра пути(u, v) :
            //Fuv += c; Fvu -= c;

            //ищем cf - наименьшая из остат.способн. по доп. пути;
            int cf = Integer.MAX_VALUE;
            for (int cur = n - 1; cur != 0; ) {
                int prev = from[cur];
                cf = Math.min(cf, C[prev].get(cur) - F[prev].get(cur));
                cur = prev;
            }
            //увеличиваем поток  Fuv += c; Fvu -= c;
            for (int cur = n-1; cur!=0; ) {
                int prev = from[cur];
                F[prev].put(cur, F[prev].get(cur) + cf);
                F[cur].put(prev, F[cur].get(prev) - cf);
                cur = prev;
            }
        }



        int sum = 0;
        for (int i = 0; i<n; i++){
            if (F[0].get(i) != null)
                if (F[0].get(i) > 0)
                    sum += F[0].get(i);
        }
        pr.println(sum);

        for (int i  = 0; i < m ; i++){
            rebroABC reb = rABC.get(i);
            int a1 = reb.a;
            int b1 = reb.b;
            int c1 = reb.c;
            boolean bool = reb.bool;

            if (F[a1].get(b1) < 0) {
                int t = a1;
                a1 = b1;
                b1 = t;
                bool = !bool;
            }

            if (F[a1].get(b1) == 0)
                pr.println("0");
            else {
                if (F[a1].get(b1) <= c1) {
                    if (bool)
                        pr.println(F[a1].get(b1));
                    else
                        pr.println("-" + F[a1].get(b1));
                    F[a1].put(b1, 0);

                } else {

                    if (bool)
                        pr.println(c1);

                    else
                        pr.println("-" + c1);
                    F[a1].put(b1, F[a1].get(b1) - c1);
                }
            }
        }

        pr.close();
    }

}
