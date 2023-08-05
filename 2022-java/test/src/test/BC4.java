package test;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class BC4 extends JFrame implements  ActionListener {
	
	private JButton readbnt=new JButton("读取");
	private JButton statbnt=new JButton("统计");
	private JButton clearbnt=new JButton("重置");
	private JTextArea jta1=new JTextArea(5,10);
	private JTextArea jta2=new JTextArea(5,10);
	private JLabel jl1=new JLabel("原始数据：                                      ");
	private JLabel jl2=new JLabel("统计结果：");

	BC4(){
		JPanel jp1=new JPanel(new   FlowLayout(FlowLayout.CENTER));
		jp1.add(readbnt);jp1.add(statbnt);jp1.add(clearbnt);
		JPanel jp2=new JPanel(new   FlowLayout(FlowLayout.CENTER));
		jp2.add(jl1);jp2.add(jl2);
		jta1.setLineWrap(true);     	jta1.setEditable(false);
		JScrollPane jsp1=new JScrollPane(jta1);
		jsp1.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		jsp1.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		jta2.setLineWrap(true);     	jta2.setEditable(false);
		JScrollPane jsp2=new JScrollPane(jta2);
		jsp2.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		jsp2.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
		JPanel jp3=new JPanel(new   GridLayout(1,2));
		jp3.add(jsp1);jp3.add(jsp2);
		setLayout(new BorderLayout()); 	
		add(jp2,BorderLayout.NORTH);
		add(jp3,BorderLayout.CENTER);	
		add(jp1,BorderLayout.SOUTH);
		readbnt.addActionListener(this);    	
		statbnt.addActionListener(this);
		clearbnt.addActionListener(this);
	}
	public void actionPerformed(ActionEvent e){	
		if( e.getSource() ==readbnt){
			//在此添加代码，实现“读取”按钮的功能
			//提示：可使用BufferedReader类的readLine方法逐行读取数据，使用String类的split方法分割一行中不同列的数据
			String strpath="H:\\Eclipse\\workspace\\onlinelearning.txt";
			String strAll = "";
			try {
				 BufferedReader reader = new BufferedReader(new FileReader(strpath));
				String str;
				while ((str = reader.readLine()) != null) {
					strAll+=str+"\n";
				}
			} catch (Exception err) {
			}
			jta1.setText(strAll);
			
		}
		else if (e.getSource()==statbnt) {
			//在此添加代码，实现“统计”按钮的功能
			String[] arr=jta1.getText().split("\n");
			int num=0;
			int all=0;
			for(String i:arr) {
				String[] data=i.split("\t");
				num+=1;
				all+=Integer.parseInt(data[2]);
			}
			jta2.setText(String.valueOf(num)+"人\n"+String.valueOf(Math.round(10*all/num)/10.0));		
		}else {
			//在此添加代码，实现“重置”按钮的功能
			jta1.setText("");
			jta2.setText("");
	
		}		
	}
	public static void main(String[] args) {
		BC4 t=new BC4();
		t.setSize(500,300);
		t.setVisible(true);
	}

}


