
import java.io.*;
import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class BC4 extends JFrame implements  ActionListener {
	
	private JButton readbnt=new JButton("��ȡ");
	private JButton statbnt=new JButton("ͳ��");
	private JButton clearbnt=new JButton("����");
	private JTextArea jta1=new JTextArea(5,10);
	private JTextArea jta2=new JTextArea(5,10);
	private JLabel jl1=new JLabel("ԭʼ���ݣ�                                      ");
	private JLabel jl2=new JLabel("ͳ�ƽ����");

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
			//�ڴ���Ӵ��룬ʵ�֡���ȡ����ť�Ĺ���
			//��ʾ����ʹ��BufferedReader���readLine�������ж�ȡ���ݣ�ʹ��String���split�����ָ�һ���в�ͬ�е�����
		}
		else if (e.getSource()==statbnt) {
			//�ڴ���Ӵ��룬ʵ�֡�ͳ�ơ���ť�Ĺ���
		}else {
			//�ڴ���Ӵ��룬ʵ�֡����á���ť�Ĺ���
	
		}		
	}
	public static void main(String[] args) {
		BC4 t=new BC4();
		t.setSize(500,300);
		t.setVisible(true);
	}
}
