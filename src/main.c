#define a 0x5F
#define B 0x7C
#define c 0x39
#define d 0x5E
#define e 0x7B
#define f 0x71
#define g 0x6F
#define h 0x74
#define i 0x06
#define j 0x0E
#define k 0x76
#define l 0x38
#define m 0x4F
#define n 0x37
#define o 0x3F
#define p 0x73
#define q 0x67
#define r 0x31
#define s 0x6D
#define t 0x78
#define u 0x7E
#define v 0x66
#define W 0x79
#define x 0xEA
#define y 0x6E
#define z 0x5B
#define sp 0x00

#include "stm32f4xx.h"


int main(void)
{
RCC->AHB1ENR=0x87;
RCC->APB2ENR|=RCC_APB2ENR_TIM10EN;
RCC->APB2ENR|=RCC_APB2ENR_TIM11EN;

GPIOC->MODER&=~GPIO_MODER_MODER0;
GPIOC->MODER|=GPIO_MODER_MODER0_0;

GPIOC->MODER&=~GPIO_MODER_MODER1;
GPIOC->MODER|=GPIO_MODER_MODER1_0;

GPIOC->MODER&=~GPIO_MODER_MODER2;
GPIOC->MODER|=GPIO_MODER_MODER2_0;

GPIOC->MODER&=~GPIO_MODER_MODER3;
GPIOC->MODER|=GPIO_MODER_MODER3_0;

GPIOC->MODER&=~GPIO_MODER_MODER4;
GPIOC->MODER|=GPIO_MODER_MODER4_0;

GPIOC->MODER&=~GPIO_MODER_MODER5;
GPIOC->MODER|=GPIO_MODER_MODER5_0;

GPIOC->MODER&=~GPIO_MODER_MODER6;
GPIOC->MODER|=GPIO_MODER_MODER6_0;

GPIOA->MODER&=~GPIO_MODER_MODER0;
GPIOA->MODER|=GPIO_MODER_MODER0_0;

GPIOA->MODER&=~GPIO_MODER_MODER1;
GPIOA->MODER|=GPIO_MODER_MODER1_0;

GPIOB->MODER&=~GPIO_MODER_MODER1;
GPIOB->MODER|=GPIO_MODER_MODER1_0;

GPIOB->MODER&=~GPIO_MODER_MODER0;
GPIOB->MODER|=GPIO_MODER_MODER0_0;

TIM10->PSC=16000;
TIM10->ARR=1;

TIM11->PSC=16000;
TIM11->ARR=1000;

TIM10->CR1|=TIM_CR1_CEN;
TIM11->CR1|=TIM_CR1_CEN;

int TamanhoFrase=21;//número de caracteres na frase
int frase[]={sp,sp,sp,sp,f,e,l,i,z,sp,a,n,i,v,e,r,s,a,r,i,o,sp,sp,sp,sp};//caracteres da frase

int display[]={0b0001,0b0010,0b0100,0b1000};//controle do acionamento do display
int display1[]={0b0100,0b1000,0b0001,0b0010};//controle do acionamento do display
int crt=0;
int crt1=0;

  while (1)
  {
	  if(TIM10->SR&TIM_SR_UIF)
	    {
		  TIM10->SR&=~TIM_SR_UIF;
		  GPIOC->ODR=frase[crt+crt1];//soma caracter atual mais índice do display correspondente
		  GPIOA->ODR=display[crt1];//acionamento do display
		  GPIOB->ODR=display1[crt1];//acionamento do display
		  crt1++;
		  if (crt1>3)
		  	  crt1=0;
	    }

	  if(TIM11->SR&TIM_SR_UIF)
	  	    {
	  		  TIM11->SR&=~TIM_SR_UIF;
	  		  crt++;
	  		  if (crt>(TamanhoFrase-1))
	  		  {
	  			 crt=0;
	  		  }

	  	    }
  }
}
