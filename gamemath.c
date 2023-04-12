/*Game deverá solicitar um nível de dificuldade ao usuário e após
isso gera aleatoriamente um calculo para que possamos informar um resultado.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dificuldade;
    int valor1;
    int valor2;
    int operacao;
    int resultado;
} Calcular;

//Funções
void jogar();

void mostrarInfo(Calcular calc);

int soma(int resposta, Calcular calc);
int subtracao(int resposta, Calcular calc);
int multiplicacao(int resposta, Calcular calc);

int pontos = 0;

int main(void){
    srand(time(NULL));
    jogar();
    return 0;
}

void jogar()
{
    Calcular calc;

    //Dificuldade
    printf("Informe o nivel de dificuldade desejado [1, 2 ou 3]:\n");
    scanf("%d", &calc.dificuldade);

    //gera um int randomico entre 0 e 2.
    calc.operacao = rand() % 3;
    //0 == somar, 1 == subtrair, 2 == multiplicar.

    if(calc.dificuldade == 1){//Fácil
        calc.valor1 = rand() % 11;//0 a 10
        calc.valor2 = rand() % 11;
    }else if(calc.dificuldade == 2){//Médio
        calc.valor1 = rand() % 101;
        calc.valor2 = rand() % 101;
    }else if(calc.dificuldade == 3){//Dificil
        calc.valor1 = rand() % 1001;
        calc.valor2 = rand() % 1001;
    }else{//Muito dificil
        calc.valor1 = rand() % 10001;
        calc.valor2 = rand() % 10001;
    }

    //Reposta do usuário
    int resposta;

    printf("Informe o resultado para a seguinte operacao\n");

    if(calc.operacao == 0)
    {
        printf("%d + %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
    
        if(soma(resposta, calc)){
            pontos = pontos + 1;
            printf("Voce tem %d ponto(s)\n", pontos);
        }
    }
    else if(calc.operacao == 1)
    {
        printf("%d - %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);

        if(subtracao(resposta, calc)){
            pontos = pontos + 1;
            printf("Voce tem %d ponto(s)\n", pontos);
        }
    }
    else if(calc.operacao == 2)
    {
        printf("%d * %d\n", calc.valor1, calc.valor2);
        scanf("%d", &resposta);
        
        if(multiplicacao(resposta, calc)){
            pontos = pontos + 1;
            printf("Voce tem %d ponto(s)", pontos);
        }
    }
    else
    {
        printf("A operacao %d nao e reconhecida.\n", calc.operacao);
    }

    //Recomeçar o jogo
    int continuar;
    printf("Deseja continuar? [1-Sim] [0-Nao]\n");
    scanf("%d", &continuar);

    if(continuar == 1){
        jogar();
    }
    else if(continuar == 0){
        printf("Sua pontuacao foi: %d ponto(s)\n", pontos);
        printf("Ate logo!\n");
        exit(0);
    }
}

void mostrarinfo(Calcular calc)
{
    char opc[25];

    if(calc.operacao == 0){
        sprintf(opc, "Somar");
    }else if(calc.operacao == 1){
        sprintf(opc, "Subtrair");
    }else if(calc.operacao == 2){
        sprintf(opc, "Multiplicar");
    }else{
        printf("Opcao Desconhecida");
    }
    printf("Valor 1: %d\nValor 2: %d\nDificuldade: %d\nOperacao: %s\n", calc.valor1, calc.valor2, calc.dificuldade, opc);
}

int soma(int resposta, Calcular calc)
{
    calc.resultado = calc.valor1 + calc.valor2;
    int certo = 0;//0 = errou; 1 = acertou.

    if(resposta == calc.resultado){
        printf("Resposta correta!\n");
        certo = 1;
    }else{
        printf("Resposta errada!\n");
    }
    printf("%d + %d = %d\n",calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int subtracao(int resposta, Calcular calc)
{
    calc.resultado = calc.valor1 - calc.valor2;
    int certo = 0;

    if(resposta == calc.resultado){
        printf("Resposta correta!\n");
        certo = 1;
    }else{
        printf("Resposta errada!\n");
    }
    printf("%d - %d = %d\n",calc.valor1, calc.valor2, calc.resultado);
    return certo;
}

int multiplicacao(int resposta, Calcular calc)
{
    calc.resultado = calc.valor1 * calc.valor2;
    int certo = 0;

    if(resposta == calc.resultado){
        printf("Resposta correta!\n");
        certo = 1;
    }else{
        printf("Resposta errada!\n");
    }
    printf("%d * %d = %d\n",calc.valor1, calc.valor2, calc.resultado);
    return certo;
}