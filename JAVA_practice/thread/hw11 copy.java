import java.util.Date;
import java.util.Scanner;

public class hw11
{
    
    static int[][] B;
    static int[][] C;
    static int[][] A;
    static int n;
    static int index;
    static int threadCount;
    static long startTime;
	private static Scanner in;
    
    public static void main(String[] args) throws MyException, InterruptedException{
    	while(true){
    		try{
    			in = new Scanner(System.in);
    			n = in.nextInt();
    			if (n % 2 != 0){
    				throw new MyException();
    			}
    			break;
    		}catch(MyException e){
    			System.out.println("N needs to be the number which can divided by 2");
    		}
    	}
        B = new int[n][n];
        C = new int[n][n];
        A = new int[n][n];
        
        
        //随机初始化矩阵a,b
        B = fill(n);
        C = fill(n);
        startTime = new Date().getTime();
        
        //输出a,b
        //printMatrix(B);
        //printMatrix(C);
        
        //创建线程,数量 <= 4
        for(int i=0; i<4; i++)
        {
            if(index < n)
            {
                Thread t = new Thread(new MyThread());
                t.start();
            }else 
            {
                break;
            }
        }
        
        //等待结束后输出
        while(threadCount!=0)
        {
            Thread.sleep(1);
        }
        //printMatrix(A);
        long finishTime = new Date().getTime();
        System.out.println("Finished, time is "+(finishTime-startTime)+"ms");
    }
    
    static void printMatrix(int[][] x)
    {
        for (int i=0; i<x.length; i++)
        {
            for(int j=0; j<x[i].length; j++)
            {
                System.out.print(x[i][j]+" ");
            }
            System.out.println("");
        }
        System.out.println("");
    }
    
    static int [][] fill(int n)
    {
    	int[][] x;
    	x = new int [n][n];
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                x[i][j] = (int) (Math.random()*2);
            }
        }
        return x;
    }

    synchronized static int getTask()
    {
        if(index < n)
        {
            return index++;
        }
        return -1;
    }

}


class MyThread implements Runnable
{
    int task;
    @Override
    public void run()
    {
        hw11.threadCount++;
        while( (task = hw11.getTask()) != -1 )
        {
            System.out.println("Thread: "+Thread.currentThread().getName()+"\tstart to calculate "+(task+1)+" row");
            for(int i=0; i<hw11.n; i++)
            {
                for(int j=0; j<hw11.n; j++)
                {
                    hw11.A[task][i] += hw11.B[task][j] * hw11.C[j][i];
                }
            }
        }
        hw11.threadCount--;
    }
}