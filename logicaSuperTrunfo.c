#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.
//Teste larissa

int main() {
    //variaveis para preenchimentos das cartas, com vetor para que possem ser armazenados 2 valores diferentes usando a mesma variavel
    char pais[2][50];
    char estado[2][50];
    char cod_cidade[2][4];
    char nome[2][50];
    unsigned int pop[2]; //população
    float area[2];
    float pib[2];
    unsigned int p_tur[2]; // ponto turistico

    //Variaveis que farão calculos com base nos dados inseridos
    float dens_pop[2]; //Desidade populacional
    float per_cap[2]; //PIB per capita
    float poder[2]; //super poder das cartas

    int escolha; //Escolha do menu interativo 

    printf("--------------- MENU INTERATIVO --------------- \n \n");
    printf("O que gostaria de fazer? \n");
    printf("1 - Iniciar o jogo \n");
    printf("2 - Regras \n");
    printf("3 - Sair \n");
    scanf("%d \n", &escolha);

    switch (escolha) {
        case 1: //Iniciando o jogo 
            // Cadastro das Cartas:
            printf("REGISTRO DE CARTAS PARA O JOGO SUPER TRUNFO \n \n");

            //a estrutura de repetição for vai rodar 2 vezes e armazenar o dados inseridos nos vetores.
            for (int i = 0; i < 2; i++) {
                printf("Qual o país da %dº carta?\n", i);
                scanf("%s", &pais[i]);

                printf("Qual estado deste pais e referente a %dº carta?\n", i);
                scanf("%s", &estado[i], "\n \n");

                printf("Insira o código da cidade da %dº carta?\n", i);
                printf("Obs: Lembrando que o código em questão, deve conter:\n");
                printf("- a letra referente ao estado, sendo elas de A-H \n");
                printf("- e o número referente a cidade, sendo eles de 001-004 \n");
                printf("EX: A001, B002, C003 \n");
                scanf("%s", &cod_cidade[i]);

                printf("Qual a cidade da %dº carta?\n", i);
                scanf("%s", &nome[i]);

                printf("Qual o numero de habitantes da cidade em questão?\n");
                scanf("%u", &pop[i]);

                printf("Qual a área da cidade?\n");
                scanf("%f", &area[i]);

                printf("Qual o valor do PIB desta cidade?\n");
                scanf("%f", &pib[i]);

                printf("A cidade em questão tem quantos pontos turisticos?\n");
                scanf("%u", &p_tur[i]);

                //calcula o super densidade pop., PIB per capita e poder
                dens_pop[i]= pop[i] / area[i];
                per_cap[i]= pib[i] / pop[i];
                poder[i] = pop[i] + area[i] + pib[i] + p_tur[i] + dens_pop[i] + per_cap[i];
            }

            //comparação das cartas
            printf("--------------- COMPARAÇÃO DA PROPRIEDADE --------------- \n \n");

            //escolha aleatoria da propriedade a ser comparada
            int pc; //Aqui ficara armazenada a escolha do computador em relação as prorpiedades
            srand(time(0));
            pc = rand() % 7 + 1;

            switch (pc){
                case 1: //Compara população
                    if (pop[0] > pop[1]) { //População da primeira carta inserida é maior
                        printf("*** COMPARANDO POPULAÇÃO *** \n");
                        printf("%s - %u > %s - %u \n", cod_cidade[0],pop[0],cod_cidade[1], pop[1]);
                        printf("A carta %s venceu \n",cod_cidade[0]);
                    } else if (pop[0] == pop[1]){ //População das cartas empataram
                        printf("*** COMPARANDO POPULAÇÃO *** \n");
                        printf("%s - %u = %s - %u \n", cod_cidade[0],pop[0],cod_cidade[1], pop[1]);
                        printf("As cartas empataram \n");
                    } else{ // População da segunda carta é maior
                        printf("*** COMPARANDO POPULAÇÃO *** \n");
                        printf("%s - %u > %s - %u \n", cod_cidade[1],pop[1],cod_cidade[0], pop[0]);
                        printf("A carta %s venceu \n",cod_cidade[1]);
                    }
                    break;
                
                case 2: //Compara área
                    if (area[0] > area[1]) { //Área primeira carta inserida é maior
                        printf("*** COMPARANDO ÁREA *** \n");
                        printf("%s - %.2f > %s - %.2f \n", cod_cidade[0],area[0],cod_cidade[1], area[1]);
                        printf("A carta %s venceu \n",cod_cidade[0]);
                    } else if (area[0] == area[1]){ //Área das cartas empataram
                        printf("*** COMPARANDO ÁREA *** \n");
                        printf("%s - %.2f = %s - %.2f \n", cod_cidade[0],area[0],cod_cidade[1], area[1]);
                        printf("As cartas empataram \n");
                    } else{
                        printf("*** COMPARANDO ÁREA *** \n"); //Área da segunda carta inserida é maior
                        printf("%s = %.2f > %s = %.2f \n", cod_cidade[1],area[1],cod_cidade[0], area[0]);
                        printf("A carta %s venceu \n",cod_cidade[1]);
                    }
                    break;

                case 3: //Compara PIB
                    if (pib[0] > pib[1]) { //PIB da primeira carta inserida é maior
                        printf("*** COMPARANDO PIB*** \n");
                        printf("%s - %.2f > %s - %.2f \n", cod_cidade[0],pib[0],cod_cidade[1], pib[1]);
                        printf("A carta %s venceu \n",cod_cidade[0]);
                    } else if (pib[0] == pib[1]){ //PIB das cartas empataram
                        printf("*** COMPARANDO PIB*** \n");
                        printf("%s - %.2f = %s - %.2f \n", cod_cidade[0],pib[0],cod_cidade[1], pib[1]);
                        printf("As cartas empataram \n");
                    } else{ //PIB da segunda carta inserida é maior
                        printf("*** COMPARANDO PIB*** \n");
                        printf("%s - %.2f > %s - %.2f \n", cod_cidade[1],pib[1],cod_cidade[0], pib[0]);
                        printf("A carta %s venceu \n",cod_cidade[1]);
                    }
                    break;
                
                case 4: //Compara ponto turistico
                    if (p_tur[0] > p_tur[1]) { //Ponto turistico da primeira carta inserida é maior
                        printf("*** COMPARANDO PONTO TURISTICO *** \n");
                        printf("%s - %u > %s - %u \n", cod_cidade[0],p_tur[0],cod_cidade[1], p_tur[1]);
                        printf("A carta %s venceu \n",cod_cidade[0]);
                    } else if (p_tur[0] == p_tur[1]){ //Ponto turistico das cartas empataram
                        printf("*** COMPARANDO PONTO TURISTICO *** \n");
                        printf("%s - %u = %s - %u \n", cod_cidade[0],p_tur[0],cod_cidade[1], p_tur[1]);
                        printf("As cartas empataram \n");
                    } else{ //Ponto turistico da segunda carta inserida é maior
                        printf("*** COMPARANDO PONTO TURISTICO *** \n");
                        printf("%s - %u > %s - %u \n", cod_cidade[1],p_tur[1],cod_cidade[0], p_tur[0]);
                        printf("A carta %s venceu \n",cod_cidade[1]);
                    }
                    break;

                case 5: //Compara densidade populacional
                    if (dens_pop[0] < dens_pop[1]) { //Densidade populacional da primeira carta é menor
                        printf("*** COMPARANDO DENSIDADE POPULACIONAL *** \n");
                        printf("%s - %.2f < %s - %.2f \n", cod_cidade[0],dens_pop[0],cod_cidade[1], dens_pop[1]);
                        printf("A carta %s venceu \n",cod_cidade[0]);
                    } else if (dens_pop[0] == dens_pop[1]){ //Densidade populacional das cartas empataram
                        printf("*** COMPARANDO DENSIDADE POPULACIONAL *** \n");
                        printf("%s - %.2f = %s - %.2f \n", cod_cidade[0],dens_pop[0],cod_cidade[1], dens_pop[1]);
                        printf("As cartas empataram \n");
                    } else{ //Densidade populacional da segunda carta inserida é menor
                        printf("*** COMPARANDO DENSIDADE POPULACIONAL *** \n");
                        printf("%s - %.2f < %s - %.2f \n", cod_cidade[1],dens_pop[1],cod_cidade[0], dens_pop[0]);
                        printf("A carta %s venceu \n",cod_cidade[1]);
                    }
                    break;

                case 6: //Compara PIB per capita
                    if (per_cap[0] > per_cap[1]) { //PIB per capita da primeira carta é maior
                        printf("*** COMPARANDO PIB PER CAPITA *** \n");
                        printf("%s - %.2f > %s - %.2f \n", cod_cidade[0],per_cap[0],cod_cidade[1], per_cap[1]);
                        printf("A carta %s venceu \n",cod_cidade[0]);
                    } else if (per_cap[0] == per_cap[1]){ //PIB per capita das cartas empataram
                        printf("*** COMPARANDO PIB PER CAPITA *** \n");
                        printf("%s - %.2f = %s - %.2f \n", cod_cidade[0],per_cap[0],cod_cidade[1], per_cap[1]);
                        printf("As cartas empataram \n");
                    } else{ //PIB per capita da segunda carta inserida é maior
                        printf("*** COMPARANDO PIB PER CAPITA *** \n");
                        printf("%s - %.2f > %s - %.2f \n", cod_cidade[1],per_cap[1],cod_cidade[0], per_cap[0]);
                        printf("A carta %s venceu \n",cod_cidade[1]);
                    }
                    break;

                case 7: //Compara super poder
                    if (poder[0] > poder[1]) { //Super poder da primeira carta inserida é maior
                        printf("*** COMPARA SUPER PODER *** \n");
                        printf("%s - %.2f > %s - %.2f \n", cod_cidade[0],poder[0],cod_cidade[1], poder[1]);
                        printf("A carta %s venceu \n",cod_cidade[0]);
                    } else if (per_cap[0] == per_cap[1]){ //Super poder das cartas empataram
                        printf("*** COMPARA SUPER PODER *** \n");
                        printf("%s - %.2f = %s - %.2f \n", cod_cidade[0],poder[0],cod_cidade[1], poder[1]);
                        printf("As cartas empataram \n");
                    } else{ //Super poder da segunda carta é maior
                        printf("*** COMPARA SUPER PODER *** \n");
                        printf("%s - %.2f > %s - %.2f \n", cod_cidade[1],poder[1],cod_cidade[0], poder[0]);
                        printf("A carta %s venceu \n",cod_cidade[1]);
                    }
                    break;

                default:
                    break;
                }

            break;
        
        case 2:
            printf("*** REGRAS: ***\n");
            printf("1- Cadastre a carta com base nas propriedades pedidas; \n");
            printf("2- Após o cadastro, será escolhida de forma aleatoria qual prorpiedade será comparada; \n");
            printf("3- a carta com o valor da propriedade maior vence, exceto pela densidade populacional, que vence o menor valor.");
            break;
        
        case 3:
            printf("*** SAINDO... ***");
            break;
        
        default:
            printf("*** ESCOLHA INVÁLIDA ***");
            break;
    }
}