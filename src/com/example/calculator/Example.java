package com.example.calculator;

public class Example{

public  native char []Java_com_example_calculator_Example_add(char a[],char b[]);
public  native char []Java_com_example_calculator_Example_subtract(char a[],char b[]);
public native char []Java_com_example_calculator_Example_multiply(char a[],char b[]);
public native char []Java_com_example_calculator_Example_divide(char a[],char b[]);



static{
	
	
	System.load("D:/Spice/Calculator/addition.dll");
	System.load("D:/Spice/Calculator/subtract.dll");
	System.load("D:/Spice/Calculator/divide.dll");
	System.load("D:/Spice/Calculator/multiply.dll");
	
    
    //System.loadLibrary("addition");
    //System.loadLibrary("subtract");
    //System.loadLibrary("multiply");
    //System.loadLibrary("divide");
   // System.load("D:/Spice/Calculator/src/com/example/calculator/multiply.dll");
   // System.load("D:/Spice/Calculator/src/com/example/calculator/divide.dll");
	   }
public static void main(String argv[])
{
int i,length=0;

//Example example=new Example();

//char num1[]={54,50};
//char num2[]={50,53};

// char c[]=example.add(num1,num2);

//while(c[length]!='\0')
//length++;

//System.out.print("Answer=");
//for(i=0;i<length;i++)
 //{
 //System.out.print(c[i]);
 //}
 }
 }
