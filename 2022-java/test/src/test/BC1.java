package test;
import java.io.*;

public class BC1 {
	public static void main(String args[]) throws Exception{
		BufferedReader buf;
		buf = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("请输入整数n:");
		int n = Integer.parseInt(buf.readLine());
		double result=getSum(n);
		System.out.println("前"+n+"项的和为"+result);
	}
	    //在此完成getSum方法的编写
	public static double getSum(int n) {
		double sum=0;
		for(int i=1;i<=n;i++) {
			sum+=1.0*i/(i+1);
		}
		return sum;
	}
}

