import java.applet.*;
import java.awt.*;
public class GC4 extends Applet{
    String[] xPoints = {"上海","北京","莫斯科","伦敦","纽约","首尔","东京","马德里"};
    int yuanPoints = {673,608,437,402,380,331,309,293};
    String yPoints ;
    public void paint( Graphics ) {
      g.drawLine(100,500,550,500);//绘制横轴
      g.drawLine(100,500,100,90);//绘制纵轴
      g.setColor(Color.blue); 
      Font font=Font("隶书",Font.PLAIN,24);
      g.setFont(font);
      g.drawString("全球主要城市地铁里程示意图（单位：千米）", 120, 50); 
      Font font1=new Font("宋体",Font.PLAIN,14);
      g.setFont(font1);
      for(int i=0;i<=7;i++){
           g.drawRect(50*i+150,780-yuanPoints[i],10,yuanPoints[i]-280);
           yPoints=""+yuanPoints[i];
           g.drawString(yPoints,50*i+140, 770-yuanPoints[i]); 
     	}
     	Font font2=new Font("宋体",Font.PLAIN,14);
       	g.setFont(font2);
     	String s="";
     	for (int i=0;i<=7;i++)
     		s+=xPoints[i]+"   ";
     	g.drawString(s,130, 520); 
     }
}
