
import java.util.*;
class Sister
{
	private String name;    //ѡ������
	private int scoreb;     //������չʾ���÷�
	private int scoret;     //�����ձ�ƴ���÷�
    private double score;   //�ܷ�
	public Sister(String name,int beauty,int talent){//��������ֵ�Ͳ��շ���
		this.name=name;
		this.scoreb=beauty;		
		this.scoret=talent;	
		this.score=0;//�ֳܷ�ʼΪ0
	}
	public void calScore() { 
       //�ڴ˴����巽����
       //������ֵ����յ��ۺϷ���("����չʾ"�÷֡�0.55+"���ձ�ƴ"�÷֡�0.45),��д���Ա����
		
	}
	public void addScore(){//���������֣����������������Ϊ0~9������
		 //�ڴ˴����巽����
	}
	
	public String toString() { //��ȡ����������Ϣ
        //�ڴ˴����巽����
	}
	public  String getMax(Sister sis){ //��ȡ�ֽܷϸ���
		//�ڴ˴����巽���壬���������ֽܷϸ��ߵ�����
               //�����ܷ���ͬʱ�������������������Ӷ��ɵ��ַ���
     }
}	

public class BC2 {
	public static void main(String[] args){
		Sister sis1=new Sister("����",87,88);
		sis1.calScore();
		sis1.addScore();
		System.out.println(sis1.toString());
		Sister sis2=new Sister("��ʩ",87,84);
		sis2.calScore();
		sis2.addScore();
		System.out.println(sis2.toString());
		System.out.println("�˷����˵Ľ��Ϊ:"+sis1.getMax(sis2));
	}	
}