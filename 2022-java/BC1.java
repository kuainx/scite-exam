
import java.io.*;

public class BC1 {
	public static void main(String args[]) throws Exception{
		BufferedReader buf;
		buf = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("����������n:");
		int n = Integer.parseInt(buf.readLine());
		double result=getSum(n);
		System.out.println("ǰ"+n+"��ĺ�Ϊ"+result);
	}
	    //�ڴ����getSum�����ı�д
}

