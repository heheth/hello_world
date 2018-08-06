//#include "stm32f10x.h"
#include "delay.h"//为引用延时初始化与延时函数
#include "stm32f10x_it.h"
/************************************************
 ALIENTEK 战舰STM32F103开发板实验0
 工程模板
 注意，这是手册中的新建工程章节使用的main文件 
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

/*
void Delay(u32 count)
{
  u32 i=0;
  for(;i<count;i++);
 }
int main(void)
{	
	GPIO_InitTypeDef  GPIO_InitStructure;
	 
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOE, ENABLE);	    //使能PB,PE端口时钟
  
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;			    //LED0-->PB.5 端口配置
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	 //推挽输出
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	 //IO口速度为50MHz
  GPIO_Init(GPIOB, &GPIO_InitStructure);			     //初始化GPIOB.5
  GPIO_SetBits(GPIOB,GPIO_Pin_5);					//PB.5 输出高
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;	            //LED1-->PE.5推挽输出
  GPIO_Init(GPIOE, &GPIO_InitStructure);	  	       //初始化GPIO
  GPIO_SetBits(GPIOE,GPIO_Pin_5); 			 //PE.5 输出高 	  
  
	while(1)
  {
	  GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	  GPIO_SetBits(GPIOE,GPIO_Pin_5);
		Delay(3000000);
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		Delay(3000000);
  }
}
//*/ //原本的函数

//以下为自己写的函数
int main(void)
{
	GPIO_InitTypeDef  GPIO_InitStructure;//定义结构体
	delay_init();//初始化延时
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//初始化时钟，一般在使用引脚的时候都要初始化，APB2是高频的
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE,ENABLE);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	//先做好赋值，再传递给函数
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	GPIO_Init(GPIOE,&GPIO_InitStructure);
	GPIO_SetBits(GPIOE,GPIO_Pin_5);//setbit的作用是置位1
	GPIO_SetBits(GPIOB,GPIO_Pin_5);
	
	while(1)
  {
	  GPIO_ResetBits(GPIOB,GPIO_Pin_5);
	  GPIO_SetBits(GPIOE,GPIO_Pin_5);
		delay_ms(500);//延时xxx毫秒
		
		GPIO_SetBits(GPIOB,GPIO_Pin_5);
		GPIO_ResetBits(GPIOE,GPIO_Pin_5);
		delay_ms(500);
  }
}
