#include<stdio.h>
#include<string.h>
#include<math.h>
#define SIZE 10000
#include <jni.h>
#include <android/log.h>
#define LOGD(...) __android_log_write(ANDROID_LOG_ERROR, "AASHNA",__VA_ARGS__);



JNIEXPORT jcharArray JNICALL Java_com_example_calculator_MainActivity_divide
  (JNIEnv * env, jobject thisobj, jcharArray j4, jcharArray j5)
  {
  	 jchar *a = (*env)->GetCharArrayElements(env, j4, NULL);
  	 jchar *b = (*env)->GetCharArrayElements(env, j5, NULL);	 
  	 jsize lena=(*env)->GetArrayLength(env,j4);
     jsize lenb=(*env)->GetArrayLength(env,j5);    

     __android_log_print(ANDROID_LOG_ERROR, "AASHNA","a=%s",a);
     __android_log_print(ANDROID_LOG_ERROR, "AASHNA","b=%s",b);

    __android_log_print(ANDROID_LOG_ERROR, "AASHNA","lena=%d",lena);

    __android_log_print(ANDROID_LOG_ERROR, "AASHNA","lenb=%d",lenb);


    jint i,j,qu=0,k=0,g=0,flag=0,q[SIZE],m,check,ms,t=0,gh=0,re=0,h,inttemp[lena],inta[lena+1],gx,var;
    jchar remain[SIZE];
    jchar quotient[SIZE];
	jchar remainder[SIZE], test[2],temp[SIZE];temp[gh++]=a[0];remain[re++]=a[0];temp[gh]='\0';remain[re]='\0';
    __android_log_print(ANDROID_LOG_ERROR, "AASHNA","temp=%s",temp);
    for(i=0;i<lena;i++)
     {    
	 
	    //int checkcmp=compare(b,temp);     
         jint lentemp=0;
         while(temp[lentemp]!='\0')
         lentemp++;
         
	     jint cmp=0;
         if(lenb<lentemp)
         cmp=-1;         
         else if(lenb>lentemp)
         cmp=1;        
         else if(lenb==lentemp)                              
         {    
          jint inj,intab,intcd,eq=0;
          for(inj=0;inj<lenb;inj++)
          {
                   intab=b[inj]-48;
                   intcd=temp[inj]-48;
                    if(intab<intcd)
                    {
                    cmp=-1;
                    break;
                    }
                    else if(intab>intcd)
                    {
                    cmp=1;
                    break;
                    }
                    else if(intab==intcd)
                    eq++;                
          }         eq=eq+50;
          if(eq==(lenb+50))
          cmp=eq;                  
       }
         __android_log_print(ANDROID_LOG_ERROR, "AASHNA","cmp=%d",cmp);
       if((cmp==-1)||(cmp==(lenb+50)))                        //if divisor<=dividend  
        { 

          for(j=1 ;j<=10;j++)
          {         
           test[0]=j+48;
           test[1]='\0';
           __android_log_print(ANDROID_LOG_ERROR, "AASHNA","test=%s",test);
           //strcpy(product,multiply(b,test));
           jchar product[SIZE];
           jchar c[SIZE];
           jchar mul_temp[SIZE];
           jint len1=0,len2=0;
           jint j,k=0,x=0,y,tn;
           jint r=0;
           jint sum=0;
    
         //  while(b[len1]!='\0')
           //len1++;
           len1=lenb;
           while(test[len2]!='\0')
           len2++;
  
           __android_log_print(ANDROID_LOG_ERROR, "AASHNA","len1=%d",len1);
           __android_log_print(ANDROID_LOG_ERROR, "AASHNA","len2=%d",len2);

           for(y=0;y<len1;y++)          //char to int..
           {
           b[y]=b[y]-48;}
           for(y=0;y<len2;y++)
           {
           test[y]=test[y]-48;}
        
           for(y=len2-1;y>=0;y--)           
          {
           r=0;
           for(j=len1-1;j>=0;j--)
           {
             mul_temp[k++]=(test[y]*b[j]+r)%10;        //multiplying and adding carry
             r=(test[y]*b[j]+r)/10;
             __android_log_print(ANDROID_LOG_ERROR, "AASHNA","mul_temp[%d]=%d",k-1,mul_temp[k-1]);
           }
            mul_temp[k++]=r;
            x++;
            for(tn=0;tn<x;tn++)
            {mul_temp[k++]=0;}
           }    
           k=0;r=0;
    
           for(y=0;y<len1;y++)          //int to char..
           {
           b[y]=b[y]+48;
       }
           for(y=0;y<len2;y++)  
		   {        //int to char
           test[y]=test[y]+48; 
	}
    
          for(y=0;y<len1+len2;y++)
          {
          sum=0;
          tn=0;
          for(j=1;j<=len2;j++)
          {
             if(y<len1+j)
             sum=sum+mul_temp[tn+y];
             __android_log_print(ANDROID_LOG_ERROR, "AASHNA","sum=%d",sum);
             tn+=j+len1;
          }
          c[k++]=(sum+r)%10;           
          r=(sum+r)/10;                 //storing carry of sum
          }
           c[k]=r;
           j=0;
           for(y=k-1;y>=0;y--)
           {__android_log_print(ANDROID_LOG_ERROR, "AASHNA","c[%d]=%d",y,c[y]);
        	   product[j++]=c[y]+48;
           __android_log_print(ANDROID_LOG_ERROR, "AASHNA","product[%d]=%c",j-1,product[j-1]);
		  }            //converting back to char..
           product[j]='\0';
           if(product[0]==48) 
           {
            for(y=0;y<j-1;y++) 
             {
             product[y]=product[y+1];
             __android_log_print(ANDROID_LOG_ERROR, "AASHNA","product[%d]=%c",y,product[y]);
            }
             product[j-1]='\0';                 
            }    

		      jint lenp=0;
		      while(product[lenp]!='\0')
		      {
		      lenp++;}
             
            // int cmpprod=(compare(product,temp));
              
			   jint cmprod=0;
               if(lenp<lentemp)
               cmprod=-1;         
               else if(lenp>lentemp)
               cmprod=1;        
               else if(lenp==lentemp)                              
               {    
                jint inj1,intab1,intcd1,eq1=0;
                 for(inj1=0;inj1<lenp;inj1++)
                 {
                   intab1=product[inj1]-48;intcd1=temp[inj1]-48;
                    if(intab1<intcd1)
                    {
                    cmprod=-1;
                    break;
                    }
                    else if(intab1>intcd1)
                    {
                    cmprod=1;
                    break;
                    }
                    else if(intab1==intcd1)
                    eq1++;                
                } eq1=eq1+50;
                  if(eq1==(lentemp+50))
                   cmprod=eq1;                  
              }			
		       

               __android_log_print(ANDROID_LOG_ERROR, "AASHNA","cmprod=%d",cmprod);
              if(cmprod==1)
              { 
                test[0]=test[0]-1;
                __android_log_print(ANDROID_LOG_ERROR, "AASHNA","test=%s",test);
             //   strcpy(remain,subtract(temp,multiply(b,test)));                
                jchar mul[SIZE];
                jchar c[SIZE];
                jchar mul_temp[SIZE];
                jint len1=0,len2=0;
                jint j,k=0,x=0,y,tn;
                jint r=0;
                jint sum=0;
    
               // while(b[len1]!='\0')
                //len1++;
                len1=lenb;
                while(test[len2]!='\0')
                len2++; 
   
                for(y=0;y<len1;y++)          //char to int..
                b[y]=b[y]-48;
                for(y=0;y<len2;y++)
                test[y]=test[y]-48;
        
                for(y=len2-1;y>=0;y--)           
                {
                r=0;
                for(j=len1-1;j>=0;j--)
                 {
                  mul_temp[k++]=(test[y]*b[j]+r)%10;        //multiplying and adding carry
                   r=(test[y]*b[j]+r)/10;
                 }
                mul_temp[k++]=r;
                x++;
                for(tn=0;tn<x;tn++)
                {mul_temp[k++]=0;}
                }   
                k=0;r=0;
    
                for(y=0;y<len1;y++)          //int to char..
                b[y]=b[y]+48;
                for(y=0;y<len2;y++)          //int to char
                test[y]=test[y]+48;        
    
               for(y=0;y<len1+len2;y++)
               {
               sum=0;
               tn=0;
               for(j=1;j<=len2;j++)
               {
               if(i<=len1+j)
                sum=sum+mul_temp[tn+y];             
                tn+=j+len1+1;
               }
                c[k++]=(sum+r)%10;           
                r=(sum+r)/10;                 //storing carry of sum
               }
               c[k]=r;
                j=0;
              for(y=k-1;y>=0;y--)
              {mul[j++]=c[y]+48;
              __android_log_print(ANDROID_LOG_ERROR, "AASHNA","mul[%d]=%c",j,mul[j]);
			  }            //converting back to char..
              mul[j]='\0';
               if(mul[0]==48) 
              {
              for(y=0;y<j-1;y++) 
               mul[y]=mul[y+1];
               mul[j-1]='\0';                 
               }    
             
              
              //subtract(temp,mul)
              jint m,sm,diff[SIZE],check=0;
              jchar tempsub[SIZE]; 
   		      jint cmpsub=0,len11=0,len22=0;
   		      while(temp[len11]!='\0')
   		      len11++;
   		      while(mul[len22]!='\0')
   		      len22++;
              if(len11<len22)
              cmpsub=-1;         
              else if(len11>len22)
              cmpsub=1;        
               else if(len11==len22)                              
              {    
              jint injsub,intabsub,intcdsub,eqsub=0;
              for(injsub=0;injsub<len11;injsub++)
              {
                   intabsub=temp[injsub]-48;intcdsub=mul[injsub]-48;
                    if(intabsub<intcdsub)
                    {
                    cmpsub=-1;
                    break;
                    }
                    else if(intabsub>intcdsub)
                    {
                    cmpsub=1;
                    break;
                    }
                    else if(intabsub==intcdsub)
                    eqsub++;                
               }    eqsub=eqsub+50;
               if(eqsub==(len11+50))
                cmpsub=eqsub;                  
              } 

              __android_log_print(ANDROID_LOG_ERROR, "AASHNA","cmpsub=%d",cmpsub);
              
              if(cmpsub==-1)
              {	
   	          jint kg1=0,kg2=0;   	
   	          while(temp[kg1]!='\0')
   	          {
   	          tempsub[kg1]=temp[kg1];
   	          kg1++;}
	          tempsub[kg1]='\0';
              //strcpy(tempsub,temp);
               kg1=0;
              while(mul[kg1]!='\0')
   	          {
   	          temp[kg1]=mul[kg1];
   	          kg1++;}temp[kg1]='\0';
               //strcpy(temp,mul);
    
              kg1=0;
    	      while(tempsub[kg1]!='\0')
   	          {
   	          mul[kg1]=tempsub[kg1];
   	          kg1++;}mul[kg1]='\0';
   	
             //strcpy(mul,tempsub);
              check=len11;                               //swap len1 and len2
              len11=len22;
              len22=check; 
              }
              char reverse1[SIZE],reverse2[SIZE];
              jint s=0;
              for(k=len11-1;k>=0;k--)
              {
               reverse1[s]=temp[k];
               s++;}
               reverse1[s]='\0';
              //strrev(temp);   
   
              s=0,k=0;
              for(k=len22-1;k>=0;k--)
              {
               reverse2[s]=mul[k];
               s++;}  
			    reverse2[s]='\0';                    //reversing the nos. n1 and n2
               //strrev(mul);  
     
              jint sub_arr1[SIZE],sub_arr2[SIZE];
               for(sm=0;sm<len11;sm++)                  
               {
               sub_arr1[sm]=reverse1[sm]-48;
           }
    
              for(m=0;m<len22;m++)  
              {
              sub_arr2[m]=reverse2[m]-48;
			 }
        
              jint n=len11;                           //loop works for longer length
  
              for(k=0;k<n;k++)
              {
               if((len11==len22)||(k<len11 && k<len22))  
               {
               if(sub_arr1[k]<sub_arr2[k])
                {diff[k]=(10+sub_arr1[k])-sub_arr2[k];
                 sub_arr1[k+1]=sub_arr1[k+1]-1;
				 }
                  else
                 {
                 diff[k]=sub_arr1[k]-sub_arr2[k];

				}
                }
               else if(k>=len22)
               diff[k]=sub_arr1[k];               //if n2 gets finished, difference=rest of n1
              }   
  
              for(j=0;j<k;j++)
              {
              remain[j]=diff[k-j-1]+48;

          }
              remain[k]='\0';
   
              if(remain[0]==48)  
                 {
                 for(j=0;j<k;j++) 
                 remain[j]=remain[j+1];
                 remain[k-1]='\0';}
                 
                if(check!=0)  
                    
                {
                 for(j=0;j<k;j++) 
                 remain[j+1]=remain[j];
                 remain[0]=45;
                 remain[k]='\0';
                }    				           
   // strrev(temp);
    //strrev(mul);                    
               
                re=0;
                while(remain[re]!='\0')
                {

				re++;}
                remain[re++]=a[i+1];                
                remain[re]='\0';       
                 if((remain[0]==48))  
                 {
                 for(var=0;var<re-1;var++) 
                 remain[var]=remain[var+1];
                 remain[re-1]='\0';
                 re=re-1;
                 }  

                while(remain[re]!='\0')
                {

				re++;}
               jint tr;
               for(tr=0;tr<re;tr++)
                {
                temp[tr]=remain[tr];  
               }
                temp[re]='\0';                
               
                 gh=0;
                while(temp[gh]!='\0')
				gh++;
               //gh=strlen(temp);                                                         
                quotient[qu++]=test[0]-48;    
			quotient[qu]='\0';

		    __android_log_print(ANDROID_LOG_ERROR, "AASHNA","quotient[%d]=%d",qu-1,quotient[qu-1]);
                flag=1; 
                break;
              } 
              
             
             else if((cmprod==(lentemp+50)))
              {    
            //   strcpy(remain,subtract(temp,multiply(b,test)));         
            
                    jchar mul[SIZE];
                jchar c[SIZE];
                jchar mul_temp[SIZE];
                jint len1=0,len2=0;
                jint j,k=0,x=0,y,tn;
                jint r=0;
                jint sum=0;
    
                while(b[len1]!='\0')
                len1++;
                while(test[len2]!='\0')
                len2++; 
   
                for(y=0;y<len1;y++)          //char to int..
                b[y]=b[y]-48;
                for(y=0;y<len2;y++)
                test[y]=test[y]-48;
        
                for(y=len2-1;y>=0;y--)           
                {
                r=0;
                for(j=len1-1;j>=0;j--)
                 {
                  mul_temp[k++]=(test[y]*b[j]+r)%10;        //multiplying and adding carry
                   r=(test[y]*b[j]+r)/10;
                 }
                mul_temp[k++]=r;
                x++;
                for(tn=0;tn<x;tn++)
                {mul_temp[k++]=0;}
                }   
                k=0;r=0;
    
                for(y=0;y<len1;y++)          //int to char..
                b[y]=b[y]+48;
                for(y=0;y<len2;y++)          //int to char
                test[y]=test[y]+48;        
    
               for(y=0;y<len1+len2;y++)
               {
               sum=0;
               tn=0;
               for(j=1;j<=len2;j++)
               {
               if(i<=len1+j)
                sum=sum+mul_temp[tn+y];             
                tn+=j+len1+1;
               }
                c[k++]=(sum+r)%10;           
                r=(sum+r)/10;                 //storing carry of sum
               }
               c[k]=r;
                j=0;
              for(y=k-1;y>=0;y--)
              {mul[j++]=c[y]+48;

			   }            //converting back to char..
              mul[j]='\0';
               if(mul[0]==48) 
              {
              for(y=0;y<j-1;y++) 
               mul[y]=mul[y+1];
               mul[j-1]='\0';                 
               }    
             
              
              //subtract(temp,mul)
              jint m,sm,diff[SIZE],check=0;
              jchar tempsub[SIZE]; 
   		      jint cmpsub=0,len11=0,len22=0;
   		      while(temp[len11]!='\0')
   		      len11++;
   		      while(mul[len22]!='\0')
   		      len22++;
              if(len11<len22)
              cmpsub=-1;         
              else if(len11>len22)
              cmpsub=1;        
               else if(len11==len22)                              
              {    
              jint injsub,intabsub,intcdsub,eqsub=0;
              for(injsub=0;injsub<len11;injsub++)
              {
                   intabsub=temp[injsub]-48;intcdsub=mul[injsub]-48;
                    if(intabsub<intcdsub)
                    {
                    cmpsub=-1;
                    break;
                    }
                    else if(intabsub>intcdsub)
                    {
                    cmpsub=1;
                    break;
                    }
                    else if(intabsub==intcdsub)
                    eqsub++;                
               }    eqsub=eqsub+50;
               if(eqsub==(len11+50))
                cmpsub=eqsub;                  
              } 

              
              
              if(cmpsub==-1)
              {	
   	          jint kg1=0,kg2=0;   	
   	          while(temp[kg1]!='\0')
   	          {
   	          tempsub[kg1]=temp[kg1];
   	          kg1++;}
	          tempsub[kg1]='\0';
              //strcpy(tempsub,temp);
               kg1=0;
              while(mul[kg1]!='\0')
   	          {
   	          temp[kg1]=mul[kg1];
   	          kg1++;}temp[kg1]='\0';
               //strcpy(temp,mul);
    
              kg1=0;
    	      while(tempsub[kg1]!='\0')
   	          {
   	          mul[kg1]=tempsub[kg1];
   	          kg1++;}mul[kg1]='\0';
   	
             //strcpy(mul,tempsub);
              check=len11;                               //swap len1 and len2
              len11=len22;
              len22=check; 
              }
              char reverse1[SIZE],reverse2[SIZE];
              jint s=0;
              for(k=len11-1;k>=0;k--)
              {
               reverse1[s]=temp[k];
               s++;}
               reverse1[s]='\0';
              //strrev(temp);   
   
              s=0,k=0;
              for(k=len22-1;k>=0;k--)
              {
               reverse2[s]=mul[k];
               s++;}  
			    reverse2[s]='\0';                    //reversing the nos. n1 and n2
               //strrev(mul);  
     
              jint sub_arr1[SIZE],sub_arr2[SIZE];
               for(sm=0;sm<len11;sm++)                  
               {
               sub_arr1[sm]=reverse1[sm]-48;
           }
    
              for(m=0;m<len22;m++)  
              {
              sub_arr2[m]=reverse2[m]-48;
			 }
        
              jint n=len11;                           //loop works for longer length
  
              for(k=0;k<n;k++)
              {
               if((len11==len22)||(k<len11 && k<len22))  
               {
               if(sub_arr1[k]<sub_arr2[k])
                {diff[k]=(10+sub_arr1[k])-sub_arr2[k];
                 sub_arr1[k+1]=sub_arr1[k+1]-1;
				 }
                  else
                 {
                 diff[k]=sub_arr1[k]-sub_arr2[k];
				 }
                }
               else if(k>=len22)
               diff[k]=sub_arr1[k];               //if n2 gets finished, difference=rest of n1
              }   
  
              for(j=0;j<k;j++)
              {
              remain[j]=diff[k-j-1]+48;
          }
              remain[k]='\0';
   
              if(remain[0]==48)  
                 {
                 for(j=0;j<k;j++) 
                 remain[j]=remain[j+1];
                 remain[k-1]='\0';}
                 
                if(check!=0)  
                    
                {
                 for(j=0;j<k;j++) 
                 remain[j+1]=remain[j];
                 remain[0]=45;
                 remain[k]='\0';
                }          
                          
                re=0;
                while(remain[re]!='\0')
				re++;
              
               remain[re++]=a[i+1];
               remain[re]='\0';
                if(remain[0]==48) 
                 {
                 for(var=0;var<re-1;var++) 
                 remain[var]=remain[var+1];
                 remain[re-1]='\0';
                 re=re-1;
                 } 

             
                jint tr;
                for(tr=0;tr<re;tr++)
                temp[tr]=remain[tr];  
                temp[re]='\0';
              // strcpy(temp,remain);
             
                gh=0;
                while(temp[gh]!='\0')
				gh++;
             
			  // gh=strlen(temp);                                                                                             
              quotient[qu++]= test[0]-48 ;
              quotient[qu]='\0';
              __android_log_print(ANDROID_LOG_ERROR, "AASHNA","quotient[%d]=%d",qu-1,quotient[qu-1]);

              flag=1;        
              break;
             }   
           }            
          }         
        else if(cmp==1)
       {              
               gh=0;
                while(temp[gh]!='\0')
				gh++;
                
                  //gh=strlen(temp);   
                 jint tr;
                 for(tr=0;tr<gh;tr++)
                remain[tr]=temp[tr];  
                remain[gh]='\0';
                 re=0;
                while(remain[re]!='\0')
				re++;
                 // re=strlen(remain);   
                 //strcpy(remain,temp);         
                 remain[re++]=a[i+1]; 
                 remain[re]='\0';
                // re=strlen(remain);         
                 if((remain[0]==48))  
                 {
                 for(var=0;var<re-1;var++) 
                 remain[var]=remain[var+1];
                 remain[re-1]='\0';
                 re=re-1;
                 }  
                 for(tr=0;tr<re;tr++)
                {
                temp[tr]=remain[tr];  

            }
                temp[re]='\0';
              // strcpy(temp,remain);
              
               gh=0;
                while(temp[gh]!='\0')
                {
                	 __android_log_print(ANDROID_LOG_ERROR, "AASHNA","temp[%d]=%c",gh,temp[gh]);
				gh++;
                }

                 if(flag==1)
                 { quotient[qu++]=0;
                 quotient[qu]='\0';
                 __android_log_print(ANDROID_LOG_ERROR, "AASHNA","quotient[%d]=%d",qu-1,quotient[qu-1]);
                 }
       }  
    }  
    jint tr;
     for(tr=0;tr<re;tr++)
                {remainder[tr]=remain[tr];}
                remainder[re]='\0';
      //strcpy(remainder,remain);
                jchar answer[SIZE];
      for(gx=0;gx<qu;gx++)
      {answer[gx]=quotient[gx]+48;

      __android_log_print(ANDROID_LOG_ERROR, "AASHNA","quotient[%d]=%c",gx,quotient[gx]);}
      answer[qu]='\0';
      

      	jcharArray outj=(*env)->NewCharArray(env,SIZE);
	(*env)->SetCharArrayRegion(env,outj,0,qu,answer);
  return outj;  
      
          
}
