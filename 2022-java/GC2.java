
import java.io.*;

public class GC2 {
	public static void main(String args[]) throws IOException {
		String product[]={"ñ��","Χ��","����", "����","����"} ; 
		double price={25.8,19.0, 88.8,128.0,236.6};   
		System.out.println("��Ʒ     �۸�");
		for( int i=0;i<5;i++);
			System.out.println(product[i]+"     " +price[i]+"Ԫ");
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.print("��������Ʒ���ƣ�");
	    String s = br.readLine();   
        int n=findProduct(s,product[]);   
        if(n>0)
        	System.out.println("�۸��ǣ�"+price[n]+"Ԫ");	
        else
        	System.out.println("û���ҵ���Ʒ��" +s);
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


