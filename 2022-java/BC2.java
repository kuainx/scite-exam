
import java.util.*;
class Sister
{
	private String name;    //选手姓名
	private int scoreb;     //“美丽展示”得分
	private int scoret;     //“才艺比拼”得分
    private double score;   //总分
	public Sister(String name,int beauty,int talent){//姓名，颜值和才艺分数
		this.name=name;
		this.scoreb=beauty;		
		this.scoret=talent;	
		this.score=0;//总分初始为0
	}
	public void calScore() { 
       //在此处定义方法体
       //计算颜值与才艺的综合分数("美丽展示"得分×0.55+"才艺比拼"得分×0.45),并写入成员变量
		
	}
	public void addScore(){//加上运气分，运气分随机产生，为0~9的整数
		 //在此处定义方法体
	}
	
	public String toString() { //获取对象的相关信息
        //在此处定义方法体
	}
	public  String getMax(Sister sis){ //获取总分较高者
		//在此处定义方法体，方法返回总分较高者的姓名
               //两人总分相同时，返回由两人姓名连接而成的字符串
     }
}	

public class BC2 {
	public static void main(String[] args){
		Sister sis1=new Sister("杨玉环",87,88);
		sis1.calScore();
		sis1.addScore();
		System.out.println(sis1.toString());
		Sister sis2=new Sister("西施",87,84);
		sis2.calScore();
		sis2.addScore();
		System.out.println(sis2.toString());
		System.out.println("乘风破浪的姐姐为:"+sis1.getMax(sis2));
	}	
}