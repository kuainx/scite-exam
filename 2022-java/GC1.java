
public class GC1 {
  public static void main(String[] args) {
    int member_point;
    char grade;     
    member_point=Math.random()*1000;   
    
    if (member_point>=700)
    	grade='A';
    
    else if (500<=member_point || member_point<700)   
    	grade='B';
    
    else
    	grade=C;  
    
    System.out.println("��Ա���� �ǣ� "+member_point+" �ȼ��ǣ� "+grade);
  }
}
