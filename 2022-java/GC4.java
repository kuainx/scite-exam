import java.applet.*;
import java.awt.*;
public class GC4 extends Applet{
    String[] xPoints = {"�Ϻ�","����","Ī˹��","�׶�","ŦԼ","�׶�","����","�����"};
    int yuanPoints = {673,608,437,402,380,331,309,293};
    String yPoints ;
    public void paint( Graphics ) {
      g.drawLine(100,500,550,500);//���ƺ���
      g.drawLine(100,500,100,90);//��������
      g.setColor(Color.blue); 
      Font font=Font("����",Font.PLAIN,24);
      g.setFont(font);
      g.drawString("ȫ����Ҫ���е������ʾ��ͼ����λ��ǧ�ף�", 120, 50); 
      Font font1=new Font("����",Font.PLAIN,14);
      g.setFont(font1);
      for(int i=0;i<=7;i++){
           g.drawRect(50*i+150,780-yuanPoints[i],10,yuanPoints[i]-280);
           yPoints=""+yuanPoints[i];
           g.drawString(yPoints,50*i+140, 770-yuanPoints[i]); 
     	}
     	Font font2=new Font("����",Font.PLAIN,14);
       	g.setFont(font2);
     	String s="";
     	for (int i=0;i<=7;i++)
     		s+=xPoints[i]+"   ";
     	g.drawString(s,130, 520); 
     }
}
