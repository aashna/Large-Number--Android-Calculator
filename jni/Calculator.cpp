#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10000
#include <android/log.h>
#include <jni.h>

extern "C" {
     JNIEXPORT jstring JNICALL Java_com_example_Calculator_MainActivity_stringFromJNICPP(JNIEnv * env, jobject obj);
 };

 JNIEXPORT jstring JNICALL Java_com_example_Calculator_MainActivity_stringFromJNICPP(JNIEnv * env, jobject obj)
 {
	 return env->NewStringUTF("Hello From CPP");
 }
