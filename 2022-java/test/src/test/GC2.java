package test;
import java.io.*;

public class GC2 {
	public static void main(String args[]) throws IOException {
		String product[]={"帽子","围巾","衬衫", "长裤","外套"} ; 
		double[] price={25.8,19.0, 88.8,128.0,236.6};   //...
		System.out.println("商品     价格");
		for( int i=0;i<5;i++)//...
			System.out.println(product[i]+"     " +price[i]+"元");
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("请输入商品名称：");
	    String s = br.readLine();   
        int n=findProduct(s,product);   //...
        if(n>=0)//...
        	System.out.println("价格是："+price[n]+"元");	
        else
        	System.out.println("没有找到商品：" +s);
   }
   public static int  findProduct(String s,String product[]){	
	    for(int i=0;i<5;i++){
			if (s.equals(product[i])){
				return i;
			}
	    }
	    return -1;
   }
}


