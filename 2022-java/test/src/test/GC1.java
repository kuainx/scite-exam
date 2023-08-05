package test;
public class GC1 {
  public static void main(String[] args) {
    int member_point;
    char grade;     
    member_point=(int) (Math.random()*1000);   //...
    
    if (member_point>=700)
    	grade='A';
    
    else if (500<=member_point && member_point<700)   //...
    	grade='B';
    
    else
    	grade='C';  //...
    
    System.out.println("会员积分 是： "+member_point+" 等级是： "+grade);
  }
}
