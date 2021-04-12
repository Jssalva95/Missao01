//declara as bibliotecas 
#include <LiquidCrystal.h>
#include <Keypad.h>
//cria a matriz de caracteres do display 16x2
const byte linhas = 4; 
const byte colunas = 4; 
char tecla[linhas][colunas] = {
  {'1','2','3','A'},
  {'4','5','6','+'},
  {'7','8','9','-'},
  {'*','0','=','/'}
};
// declarando pinos de entrada e saida no arduino
byte pinLinhas[linhas] = {A2, A3, A4, A5}; 
byte pinColunas[colunas] = {8, 9, 10, 11}; 
// criar uma funcao teclado
Keypad Teclado = Keypad( makeKeymap(tecla), pinLinhas, pinColunas, linhas, colunas );
// inicia as portas do display
LiquidCrystal lcd(13,12,4,3,2,1); 
String X,Y;
byte z=0;
char a;
long dado1,dado2,rpt1;
double dado3,dado4,rpt2;
void setup(){
  lcd.begin(16,2); 
}
//le a infomacao do teclado atraves da funcao, identifica e apresenta na tela 
void loop(){
  char chave = Teclado.getKey();
  if (chave=='0'||chave=='1'||chave=='2'||chave=='3'||chave=='4'||chave=='5'||chave=='6'||chave=='7'||chave=='8'||chave=='9'){
    
      if(z==0){
        lcd.print(chave);
        X+=chave;
        dado1=X.toInt();
      }
      
      else if(z==1){
        lcd.print(chave);
        Y+=chave;
        dado2=Y.toInt();
      }
   
  }
// limpa a tela e os dados do display
  if(chave=='A'){

      Y="";
      X="";
      dado1=0;
      dado2=0;
      dado3=0;
      dado4=0;
      z=0;
      rpt1=0;
      rpt2=0;
      lcd.clear();
  }
//funcao soma e apresenta solucao na tela
  else if(chave=='='&&a=='+'){
    z++;
    lcd.setCursor(0,2);
    rpt1=dado1+dado2;
    lcd.print("ANS=");
    lcd.print(rpt1);
  }
//funcao subtracao e apresenta na tela
  else if(chave=='='&&a=='-'){
    z++;
    lcd.setCursor(0,2);
    rpt1=dado1-dado2;
    lcd.print("ANS=");
    lcd.print(rpt1);
  }
//funcao do produto e apresenta na tela
  else if(chave=='='&&a=='*'){
    z++;
    lcd.setCursor(0,2);
    rpt1=dado1*dado2;
    lcd.print("ANS=");
    lcd.print(rpt1);
  }
//funcao divisao e apresenta na tela
  else if(chave=='='&&a=='/'){
    z++;
    lcd.setCursor(0,2);
    dado3=dado1;
    dado4=dado2;
    lcd.print("ANS=");
    rpt2=(dado3/dado4);
    lcd.print(rpt2);
  }
//funcao que recebe o valor do teclado e atribui a variavel "a" para computar o operador escolhido
  else if((chave=='+'||chave=='-'||chave=='*'||chave=='/')&&(z==0)){
    z++;
    a=chave;
    lcd.print(a);
  }
}