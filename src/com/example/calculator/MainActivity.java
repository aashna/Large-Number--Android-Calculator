package com.example.calculator;


import android.os.Bundle;

import android.app.Activity;
import android.view.Menu;
import android.view.View;
import android.view.Window;
import android.view.View.OnClickListener;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;



public class MainActivity extends Activity implements View.OnClickListener{
	
	
	
	
	
	
	
	public  native char []add(char a[],char b[]);
	public  native char []subtract(char a[],char b[]);
	public native char []multiply(char a[],char b[]);
	public native char []divide(char a[],char b[]);
	
	
	
	
	//static{
	//	System.load("D:/Spice/Calculator/src/addition.dll");
//		System.load("D:/Spice/Calculator/src/subtract.dll");
//		System.load("D:/Spice/Calculator/src/divide.dll");
//		System.load("D:/Spice/Calculator/src/multiply.dll");
	//}
	
	Button add,sub,mul,div,b1,b2,b3,b4,b5,b6,b7,b8,b9,b0,bdec,beq,bclr,bbkspace,rev,pi;
	EditText display1,display2;
	TextView op,ans;
	char sum[];
	int flag=0;
	int check_op=0;
	String str=null;
	String str1=null;
	

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
		requestWindowFeature(Window.FEATURE_NO_TITLE);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
		
		setContentView(R.layout.activity_main);
		 

   System.loadLibrary("Calculator");
   
		initialize();
		 add.setOnClickListener(this);	
		 sub.setOnClickListener(this);	
		 mul.setOnClickListener(this);	
		 div.setOnClickListener(this);	
		 b0.setOnClickListener(this);	
		 b1.setOnClickListener(this);	
		 b2.setOnClickListener(this);	
		 b3.setOnClickListener(this);	
		 b4.setOnClickListener(this);	
		 b5.setOnClickListener(this);	
		 b6.setOnClickListener(this);	
		 b7.setOnClickListener(this);	
		 b8.setOnClickListener(this);	
		 b9.setOnClickListener(this);	
		 bclr.setOnClickListener(this);	
		 bbkspace.setOnClickListener(this);	
		 beq.setOnClickListener(this);	
		 bdec.setOnClickListener(this);	
		 rev.setOnClickListener(this);
		 pi.setOnClickListener(this);
		 
	}
	
	protected void initialize()
	{
	 
	add=(Button)findViewById(R.id.buttonAdd);
	sub=(Button)findViewById(R.id.buttonSubtract);
	mul=(Button)findViewById(R.id.buttonMultiply);
	div=(Button)findViewById(R.id.buttonDivide);
	b1=(Button)findViewById(R.id.button1);
	b2=(Button)findViewById(R.id.button2);
	b3=(Button)findViewById(R.id.button3);
	b4=(Button)findViewById(R.id.button4);
	b5=(Button)findViewById(R.id.button5);
	b6=(Button)findViewById(R.id.button6);
	b7=(Button)findViewById(R.id.button7);
	b8=(Button)findViewById(R.id.button8);
	b9=(Button)findViewById(R.id.button9);
	b0=(Button)findViewById(R.id.button0);
	bdec=(Button)findViewById(R.id.buttondec);
	beq=(Button)findViewById(R.id.buttonequals);
	bclr=(Button)findViewById(R.id.buttonClear);
	rev=(Button)findViewById(R.id.reverse);
	pi=(Button)findViewById(R.id.pi);
	bbkspace=(Button)findViewById(R.id.buttonBackspace);
	display1=(EditText)findViewById(R.id.num1);
	display2=(EditText)findViewById(R.id.num2);
	op=(TextView)findViewById(R.id.operator);
	ans=(TextView)findViewById(R.id.answer);
	}
	
	public void onClick(View v) {
		// TODO Auto-generated method stub
		
		switch(v.getId()){
			    
		case R.id.buttonAdd:
		    op.setText("+");
		    ans.setText("+");
		    flag=1;
		    check_op=1;
		    break;
		    
		case R.id.buttonSubtract:
			op.setText("-");
			ans.setText("-");
			flag=1;
			check_op=1;
			break;
		case R.id.buttonMultiply:
			op.setText("×");
			ans.setText("×");
			flag=1;
			check_op=1;
			break;
		case R.id.buttonDivide:
			op.setText("/");
			ans.setText("/");
			flag=1;
			check_op=1;
			break;
		case R.id.buttonClear:
			if(flag==0)
			{display1.setText("");
			flag=0;}
			
			else if(flag==1)
				{display2.setText("");
			   flag=1;}
			    
			else if(flag==2)
				{ans.setText("");
			    display1.setText("");
			    display2.setText("");
			    flag=0;}
			break;
			
		case R.id.reverse:
			if(flag==0)
			{display1.setText(String.valueOf(divide((String.valueOf("1").toCharArray()),(String.valueOf(display1.getText())).toCharArray())));
			}
			
			else if(flag==1)
				{display2.setText(String.valueOf(divide((String.valueOf("1").toCharArray()),(String.valueOf(display2.getText())).toCharArray())));
			   }
			    
			else if(flag==2)
				{
				ans.setText(String.valueOf(divide((String.valueOf("1").toCharArray()),(String.valueOf(ans.getText())).toCharArray())));
			    }
			break;
			
		case R.id.pi:
			if(flag==0)
			{display1.setText("3.14");
			ans.setText("3.14");}
			
			
			else if(flag==1)
				{display2.setText("3.14");
			ans.setText("3.14");}	   		    
			break;
		case R.id.button1:
			if(flag==0)
			{display1.setText((display1.getText().toString())+"1");
			ans.setText((ans.getText().toString())+"1");}
			
			else if(flag==1)
			{display2.setText((display2.getText().toString())+"1");
			
			if(check_op==1)
			{ans.setText("");	
			check_op=0;
			}
			
			ans.setText((ans.getText().toString())+"1");
			}
			break;
		case R.id.button2:	
			  if(flag==0)
			{display1.setText((display1.getText().toString())+""+"2");
			  ans.setText((ans.getText().toString())+""+"2");}
			else if(flag==1)
			{display2.setText((display2.getText().toString())+""+"2");
			if(check_op==1)
			{ans.setText("");	
			check_op=0;
			}
			 ans.setText((ans.getText().toString())+""+"2");}
			
			break;
			
		case R.id.button3:			
			if(flag==0)
			{display1.setText(String.valueOf(display1.getText())+""+String.valueOf(b3.getText()));	
			 ans.setText((ans.getText().toString())+""+"3");}
			else if(flag==1)
				{display2.setText(String.valueOf(display2.getText())+""+String.valueOf(b3.getText()));
				if(check_op==1)
				{ans.setText("");	
				check_op=0;
				}
				 ans.setText((ans.getText().toString())+""+"3");
				}
			break;
		case R.id.button4:
			if(flag==0)
			{display1.setText(String.valueOf(display1.getText())+""+String.valueOf(b4.getText()));
			 ans.setText((ans.getText().toString())+""+"4");
			}
			else if(flag==1)
			{display2.setText(String.valueOf(display2.getText())+""+String.valueOf(b4.getText()));
			if(check_op==1)
			{ans.setText("");	
			check_op=0;
			}
			 ans.setText((ans.getText().toString())+""+"4");
			}
			break;
		case R.id.button5:
			if(flag==0)
			{display1.setText(String.valueOf(display1.getText())+""+String.valueOf(b5.getText()));	
			 ans.setText((ans.getText().toString())+""+"5");
			}
			else if(flag==1)
				{display2.setText(String.valueOf(display2.getText())+""+String.valueOf(b5.getText()));
				if(check_op==1)
				{ans.setText("");	
				check_op=0;
				}
				 ans.setText((ans.getText().toString())+""+"5");
				}
			break;
		case R.id.button6:
			if(flag==0)
			{display1.setText(String.valueOf(display1.getText())+""+String.valueOf(b6.getText()));
			 ans.setText((ans.getText().toString())+""+"6");
			}
			else if(flag==1)
			{display2.setText(String.valueOf(display2.getText())+""+String.valueOf(b6.getText()));
			if(check_op==1)
			{ans.setText("");	
			check_op=0;
			}
			 ans.setText((ans.getText().toString())+""+"6");
			}
			break;
		case R.id.button7:
			if(flag==0)
			{display1.setText(String.valueOf(display1.getText())+""+String.valueOf(b7.getText()));	
			 ans.setText((ans.getText().toString())+""+"7");
			}
			else if(flag==1)
				{display2.setText(String.valueOf(display2.getText())+""+String.valueOf(b7.getText()));
				if(check_op==1)
				{ans.setText("");	
				check_op=0;
				}
				 ans.setText((ans.getText().toString())+""+"7");
				}
			break;
		case R.id.button8:
			if(flag==0)
			{display1.setText(String.valueOf(display1.getText())+""+String.valueOf(b8.getText()));
			 ans.setText((ans.getText().toString())+""+"8");
			}
			else if(flag==1)
				{display2.setText(String.valueOf(display2.getText())+""+String.valueOf(b8.getText()));	
				if(check_op==1)
				{ans.setText("");	
				check_op=0;
				}
				 ans.setText((ans.getText().toString())+""+"8");
				}
			break;
		case R.id.button9:
			if(flag==0)
			{display1.setText(String.valueOf(display1.getText())+""+String.valueOf(b9.getText()));
			 ans.setText((ans.getText().toString())+""+"9");
			}
			else if(flag==1)
			{	display2.setText(String.valueOf(display2.getText())+""+String.valueOf(b9.getText()));	
			if(check_op==1)
			{ans.setText("");	
			check_op=0;
			}
			 ans.setText((ans.getText().toString())+""+"9");
			}
			break;
		case R.id.button0:
			if(flag==0)
			{display1.setText(String.valueOf(display1.getText())+""+String.valueOf(b0.getText()));
			 ans.setText((ans.getText().toString())+""+"0");
			}
			if(flag==1)
			{display2.setText(String.valueOf(display2.getText())+""+String.valueOf(b0.getText()));
			if(check_op==1)
			{ans.setText("");	
			check_op=0;
			}
			 ans.setText((ans.getText().toString())+""+"0");
			}
			break;
		case R.id.buttondec:
			if(flag==0)
			{display1.setText(String.valueOf(display1.getText())+""+".");
			 ans.setText((ans.getText().toString())+""+".");
			}
			else if(flag==1)
				{display2.setText(String.valueOf(display2.getText())+""+".");
				if(check_op==1)
				{ans.setText("");	
				check_op=0;
				}
				 ans.setText((ans.getText().toString())+""+".");
				}
			break;
		
			
		case R.id.buttonBackspace:
			if(flag==0)
			{
				str=display1.getText().toString().trim();
			   if(str.length()!=0){
			    str=str.substring(0,str.length()-1); 
			    display1.setText(str);
			   }
			}
			else if(flag==1)
			{str=display2.getText().toString().trim();
			   if(str.length()!=0){
				    str=str.substring(0,str.length()-1); 
				    display2.setText(str);}
			}
			str1=ans.getText().toString().trim();
			   if(str1.length()!=0){
				    str1=str1.substring(0,str1.length()-1); 
				    ans.setText(str1);}
			break;
		case R.id.buttonequals:
			flag=2;			
			if(op.getText()=="+")
				sum=add((String.valueOf(display1.getText()).toCharArray()),(String.valueOf(display2.getText())).toCharArray());
			else if(op.getText()=="-")
				sum=subtract((String.valueOf(display1.getText()).toCharArray()),(String.valueOf(display2.getText())).toCharArray());
			else if(op.getText()=="×")
				sum=multiply((String.valueOf(display1.getText()).toCharArray()),(String.valueOf(display2.getText())).toCharArray());
			else if(op.getText()=="/")
				sum=divide((String.valueOf(display1.getText()).toCharArray()),(String.valueOf(display2.getText())).toCharArray());
			//sum=divide(num1,num2);
			ans.setText(String.valueOf(sum)); 
			//ans.setText(String.valueOf(sum.length));
			break;
		}
	};		
		

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.main, menu);
		return true;
	}

	
}
