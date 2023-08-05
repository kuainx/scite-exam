package test;
import java.util.HashMap;
import java.util.Scanner;
public class BC3 {
  public static void main(String[] args) {
	System.out.print("请输入字符串：");
	Scanner in=new Scanner(System.in);
	String s=in.nextLine();
	s=s.toLowerCase();
	HashMap<Character,Integer> result=new HashMap<Character,Integer>();
	
//在此添加代码，将程序补充完整
	for(int i=0;i<s.length();i++) {
		char key=s.charAt(i);
		try{
			int num=result.get(key);
			result.put(key, num+1);
		}catch(Exception e){
			result.put(key, 1);
		}
	}
	result.forEach((key, value) -> {
        System.out.println(key + "=" + value);
    });
 }
}
