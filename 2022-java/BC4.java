
import java.io.*;
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
		jta2.setLineWrap(true);     	jta2.setEditable(false);
		JScrollPane jsp2=new JScrollPane(jta2);
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
		}
		else if (e.getSource()==statbnt) {
			//在此添加代码，实现“统计”按钮的功能
		}else {
			//在此添加代码，实现“重置”按钮的功能
	
		}		
	}
	public static void main(String[] args) {
		BC4 t=new BC4();
		t.setSize(500,300);
		t.setVisible(true);
	}
}
