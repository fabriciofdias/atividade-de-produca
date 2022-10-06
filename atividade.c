#include <stdio.h>
#include <math.h>
#include <string.h>

//https://github.com/fabriciofdias/atividade-de-producao.git
// foi importada a biblioteca math.h, para usar alguma das funções dela, como o pow(presente na potencialização) e o sqrt
//fonte: http://linguagemc.com.br/a-biblioteca-math-h/
//-/-----------------------------------------------------------------------------------------------------------------------------

// Primeira função criada é a soma, onde primeiro voce botara o a quantidade de valores a serem somados, assim recebendo esse quantidade ele ira
// calcular pra você a operação

void soma (int cont) {
    float resultado, aux;
    for(int i=0; i < cont; i++){
        printf("Digite o valor a ser somado:\n");
        scanf("%f", &aux);
        resultado = resultado + aux;
    }
    printf("O resultado da soma e %.2f\n", resultado);
}

// A função divisão recebe dois valores, ou seja o dividendo e o divisor, assim retornando o resultado da divisão
// foi usado if para não dar erro se o usuario colocar o 0 na divisão

void divisao () {
    float valor1, valor2 = 0;
    printf("Digite o dividendo:\n");
    scanf("%f", &valor1);
      
    printf("Digite o divisor:\n");
    scanf("%f", &valor2);

    if (valor2 == 0 ){
        printf("Não é possivel fazer a divisão por 0");
    } else {
        float resultado = valor1 / valor2;
        printf("O resultado da divisao e: %.2f\n",resultado);
    }
}

// função multiplicação, onde recebe valor1 e valor2, retornando o resultado de uma conta de multiplicação

void multiplicacao () {
    float valor1, valor2 = 0;
    printf("Valor 1:\n");
    scanf("%f", &valor1);
      
    printf("valor 2:\n");
    scanf("%f", &valor2);

    float resultado = valor1 * valor2;
    printf("O resultado da multiplicacao e: %.2f\n",resultado);
}

// a função da subtração é simples também assim como as outras recebe valor1 e valor2 e retorna o resultado de uma subtração

void subtracao () {
    float valor1, valor2;
    printf("Valor 1:\n");
    scanf("%f", &valor1);
      
    printf("valor 2:\n");
    scanf("%f", &valor2);

    float resultado = valor1 - valor2;
    printf("O resultado da diferenca e: %.2f\n",resultado);
}

// a função potenciação ja tem alguns diferenciais, ou seja, foi utilizado if para que não de algum erro na hora que o usuario for bota algum 0
// pois na potenciação nem o valor1 nem o valor 2 podem receber 0, e tambem foi utilizado o pow da biblioteca <math.h> onde ela mesma faz a potenciação

void potenciacao () {
    float valor1, valor2;
    printf("Valor 1:\n");
    scanf("%f", &valor1);
      
    printf("valor 2:\n");
    scanf("%f", &valor2);

    if (valor1 == 0 && valor2 == 0 ){
    
        printf("Erro: resultado indefinido");
    
    } else {
    
        double resultado = pow(valor1, valor2);
        printf("O resultado da potenciacao e: %.2f\n",resultado);  
    
    }
}

// a função radiciação tambem foi utilizado if, só que dessa vez para que o usuario insra apenas numeros maiores ou igual a 0 pois a calc não faz
// calculos de valores negativos, e também foi utilizado a biblioteca sqrt, a mesma que calcula raiz quadrada

void radiciacao () {
    float valor1;
    printf("Digite o valor da base da raiz:\n");
    scanf("%f", &valor1);

    if ( valor1 < 0 ){
        
        printf("Erro: A calculadora apenas calcula valores reais. Por favor, insira numero maiores ou iguais a 0");

    } else {

        double resultado = sqrt(valor1);
        printf("O resultado da radiciacao e: %.2f\n", resultado);

    }

}

// aqui a função main, onde seria um menu com mas opções de operadores que deseja escolher, utilizando o while, para manter o programa,
// rodando, até que o usuario aperte o 0 para forçar a parada do while

int main(void){
    char simbolo[5];
    int continuar = 1;
    int cont;

    printf("Fabricio Fernandes Dias\n");
    printf("Matricula 202214542\n");
    printf("Analise e desenvolvimento de sistemas\n");
    printf("Universidade LaSalle\n");
    printf("atividade de produçao 01\n");

    do
    {
        printf("\n\tCalculadora:\n\n");
        printf("< + > Somar um valor\n");
        printf("< / > Dividir um valor\n");
        printf("< r > Aplicar raiz quadrada\n");
        printf("< ^ > Calcular uma potencia\n");
        printf("< * > Multiplicacao\n");
        printf("< - > Subtrair dois numeros\n");
        printf("< 0 > Sair\n");

        scanf("%s", &simbolo);
        printf("\n%c\n", simbolo);

        // Se o valor inserido for +, chama a função de soma e imprime o valor.
        // Se o valor inserido for *, chama a função de multiplicação e imprime o valor.
        // Se o valor inserido for /, chama a função de divisão e imprime o valor.
        // Se o valor inserido for r, chama a função de radiciação e imprime o valor.
        // Se o valor inserido for ^, chama a função de potenciação e imprime o valor.
        // Se o valor inserido for -, chama a função de subtração e imprime o valor.

        
        if( strcmp(simbolo, "+") == 0) {
            printf("Digite o numero de operandos\n");
            scanf("%d", &cont);
            if ( cont <= 1 ){
                printf("Erro: E necessario que haja 2 ou mais nmeros para serem somados");
            } else {
                soma(cont);
            }
        } else if ( strcmp(simbolo, "*") == 0) {
            multiplicacao();
        } else if ( strcmp(simbolo, "r") == 0) {
            radiciacao();
        } else if ( strcmp(simbolo, "^") == 0) {
            potenciacao();
        } else if ( strcmp(simbolo, "/") == 0) {
            divisao();
        } else if ( strcmp(simbolo, "-") == 0) {
            subtracao();      
        } else if ( strcmp(simbolo, "0") == 0){
            continuar = 0;
            printf("Saindo do programa...\n");
        } else {
            printf("Opcao invalida\n");
        }
    } while(continuar);
}